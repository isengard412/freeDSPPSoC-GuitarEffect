/*******************************************************************************
* File Name: EzI2C_PM.c
* Version 2.0
*
* Description:
*  This file contains the API for the proper switching to/from the low power
*  modes.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "EzI2C_PVT.h"

EzI2C_BACKUP_STRUCT EzI2C_backup =
{
    EzI2C_DISABLED,
    EzI2C_DEFAULT_XCFG,
    EzI2C_DEFAULT_ADDR,
    EzI2C_DEFAULT_CFG,
    EzI2C_DEFAULT_CLKDIV1,
    EzI2C_DEFAULT_CLKDIV2
};

#if (EzI2C_WAKEUP_ENABLED)
    volatile uint8 EzI2C_wakeupSource;
#endif /* (EzI2C_WAKEUP_ENABLED) */


/*******************************************************************************
* Function Name: EzI2C_SaveConfig
********************************************************************************
*
* Summary:
*  The Enable wakeup from Sleep Mode selection influences this function
*  implementation:
*   Unchecked: Stores the component non-retention configuration registers.
*   Checked:   Enables backup regulator of the I2C hardware. If a transaction
*              intended for component executes during this function call,
*              it waits until the current transaction is completed and
*              I2C hardware is ready to go to sleep mode. All subsequent
*              I2C traffic is NAKed until the device is put to sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  EzI2C_backup - The non-retention registers are saved to.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void EzI2C_SaveConfig(void) 
{
#if (EzI2C_WAKEUP_ENABLED)
    uint8 interruptState;
#endif /* (EzI2C_WAKEUP_ENABLED) */

    /* Store component configuration into backup structure */
    EzI2C_backup.cfg     = EzI2C_CFG_REG;
    EzI2C_backup.xcfg    = EzI2C_XCFG_REG;
    EzI2C_backup.adr     = EzI2C_ADDR_REG;
    EzI2C_backup.clkDiv1 = EzI2C_CLKDIV1_REG;
    EzI2C_backup.clkDiv2 = EzI2C_CLKDIV2_REG;

#if (EzI2C_WAKEUP_ENABLED)
    /* Enable I2C backup regulator */
    interruptState = CyEnterCriticalSection();
    EzI2C_PWRSYS_CR1_REG |= EzI2C_PWRSYS_CR1_I2C_BACKUP;
    CyExitCriticalSection(interruptState);

    /* Wait for completion of the current transaction. The following
    * transactions have to be NACKed until the device enters the low power mode.
    * After a wakeup, the force NACK bit is cleared automatically.
    */
    EzI2C_XCFG_REG |= EzI2C_XCFG_FORCE_NACK;
    while (0u == (EzI2C_XCFG_REG & EzI2C_XCFG_SLEEP_READY))
    {
    }

     /* Setup wakeup interrupt */
    EzI2C_DisableInt();
    EzI2C_wakeupSource = 0u; /* Clear wakeup event */
    (void) CyIntSetVector(EzI2C_ISR_NUMBER, &EzI2C_WAKEUP_ISR);
    EzI2C_EnableInt();
#endif /* (EzI2C_WAKEUP_ENABLED) */
}


/*******************************************************************************
* Function Name: EzI2C_RestoreConfig
********************************************************************************
*
* Summary:
*  The Enable wakeup from Sleep Mode selection influences this function
*  implementation:
*   Unchecked: Restores the component non-retention configuration registers
*              to the state they were in before I2C_Sleep() or I2C_SaveConfig()
*              was called.
*   Checked:   Disables the backup regulator of the I2C hardware. Sets up the
*              regular component interrupt handler and generates the component
*              interrupt if it was wake up source to release the bus and
*              continue in-coming I2C transaction.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  EzI2C_backup - the non-retention registers are restored from.
*
* Reentrant:
*  No.
*
* Side Effects:
*  Calling this function before EzI2C_SaveConfig() or
*  EzI2C_Sleep() may produce unexpected behavior.
*
*******************************************************************************/
void EzI2C_RestoreConfig(void) 
{
    uint8 intState;

    if (0u != (EzI2C_PWRSYS_CR1_I2C_BACKUP & EzI2C_PWRSYS_CR1_REG))
    /* Exit from Sleep */
    {
        /* Disable I2C backup regulator */
        intState = CyEnterCriticalSection();
        EzI2C_PWRSYS_CR1_REG &= (uint8) ~EzI2C_PWRSYS_CR1_I2C_BACKUP;
        CyExitCriticalSection(intState);
    }
    else /* Exit from Hibernate (bit is cleared) or wakeup disabled */
    {
    #if (EzI2C_WAKEUP_ENABLED)
        /* Disable power to I2C block before register restore */
        intState = CyEnterCriticalSection();
        EzI2C_PM_ACT_CFG_REG  &= (uint8) ~EzI2C_ACT_PWR_EN;
        EzI2C_PM_STBY_CFG_REG &= (uint8) ~EzI2C_STBY_PWR_EN;
        CyExitCriticalSection(intState);

        /* Enable component after restore complete */
        EzI2C_backup.enableState = EzI2C_ENABLED;
    #endif /* (EzI2C_WAKEUP_ENABLED) */

        /* Restore component registers: Hibernate disable power */
        EzI2C_CFG_REG     = EzI2C_backup.cfg;
        EzI2C_XCFG_REG    = EzI2C_backup.xcfg;
        EzI2C_ADDR_REG    = EzI2C_backup.adr;
        EzI2C_CLKDIV1_REG = EzI2C_backup.clkDiv1;
        EzI2C_CLKDIV2_REG = EzI2C_backup.clkDiv2;
    }

#if (EzI2C_WAKEUP_ENABLED)
    /* Set I2C interrupt to be pending if component is source of wake up */
    EzI2C_DisableInt();
    (void) CyIntSetVector(EzI2C_ISR_NUMBER, &EzI2C_ISR);
    if (0u != EzI2C_wakeupSource)
    {
        /* Generate interrupt to release I2C bus */
        (void) CyIntSetPending(EzI2C_ISR_NUMBER);
    }
    EzI2C_EnableInt();
#endif /* (EzI2C_WAKEUP_ENABLED) */
}


/*******************************************************************************
* Function Name: EzI2C_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred method to prepare the component before device enters
*  sleep mode.
*  The Enable wakeup from Sleep Mode selection influences this function
*  implementation:
*   Unchecked: Checks current EZI2C component state, saves it, and disables the
*              component by calling EZI2C_Stop() if it is currently enabled.
*              EZI2C_SaveConfig() is then called to save the component
*              non-retention configuration registers.
*   Checked:   If a transaction intended for component is in progress during
*              this function call, it waits until the current transaction is
*              completed. All subsequent I2C traffic intended for component is
*              NAKed until the device is put to sleep mode. The address match
*              event wakes up the device.
*
*  Call the EZI2C_Sleep() function before calling the CyPmSleep() or the
*  CyPmHibernate() function. Refer to the PSoC Creator System Reference Guide
*  for more information about power-management functions.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  EzI2C_backup - The non retention registers are saved to. Changed
*  by EzI2C_SaveConfig() function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void EzI2C_Sleep(void) 
{
#if (EzI2C_WAKEUP_ENABLED)
    /* Do not re-enable component in EzI2C_Wakeup(). It remains enabled as it is wakeup source */
    EzI2C_backup.enableState = EzI2C_DISABLED;
#else
    /* Store component state enabled or disable to restore after wakeup */
    EzI2C_backup.enableState = (EzI2C_PM_ACT_CFG_REG & EzI2C_ACT_PWR_EN);

    if (0u != EzI2C_backup.enableState)
    {
        /* Disable component before enter Sleep */
        EzI2C_Stop();
    }
#endif /* (EzI2C_WAKEUP_ENABLED) */

    EzI2C_SaveConfig();
}


/*******************************************************************************
* Function Name: EzI2C_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred method to prepare the component for active mode
*  operation (when device exits sleep mode).
*  The Enable wakeup from Sleep Mode selection influences this function
*  implementation:
*   Unchecked: Restores the component non-retention configuration registers
*              by calling EZI2C_RestoreConfig(). If the component was enabled
*              before the EZI2C_Sleep() function was called, EZI2C_Wakeup()
*              re-enables it.
*   Checked:   Disables the backup regulator of I2C hardware. The incoming
*              transaction continues as soon as the regular EZI2C interrupt
*              handler is set up (global interrupts has to be  enabled to
*              service EZI2C component interrupt).
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  EzI2C_backup - The non retention registers are restored from.
*
* Reentrant:
*  No.
*
* Side Effects:
*  Calling this function before EzI2C_SaveConfig() or
*  EzI2C_Sleep() will lead to unpredictable results.
*
*******************************************************************************/
void EzI2C_Wakeup(void) 
{
    EzI2C_RestoreConfig();

    if (0u != EzI2C_backup.enableState)
    {
        /* Enable component as it was enabled before Sleep */
        EzI2C_Enable();
    }
}


/* [] END OF FILE */
