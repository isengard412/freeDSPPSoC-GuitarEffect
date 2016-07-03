/*******************************************************************************
* File Name: EZI2C_PM.c
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

#include "EZI2C_PVT.h"

EZI2C_BACKUP_STRUCT EZI2C_backup =
{
    EZI2C_DISABLED,
    EZI2C_DEFAULT_XCFG,
    EZI2C_DEFAULT_ADDR,
    EZI2C_DEFAULT_CFG,
    EZI2C_DEFAULT_CLKDIV1,
    EZI2C_DEFAULT_CLKDIV2
};

#if (EZI2C_WAKEUP_ENABLED)
    volatile uint8 EZI2C_wakeupSource;
#endif /* (EZI2C_WAKEUP_ENABLED) */


/*******************************************************************************
* Function Name: EZI2C_SaveConfig
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
*  EZI2C_backup - The non-retention registers are saved to.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void EZI2C_SaveConfig(void) 
{
#if (EZI2C_WAKEUP_ENABLED)
    uint8 interruptState;
#endif /* (EZI2C_WAKEUP_ENABLED) */

    /* Store component configuration into backup structure */
    EZI2C_backup.cfg     = EZI2C_CFG_REG;
    EZI2C_backup.xcfg    = EZI2C_XCFG_REG;
    EZI2C_backup.adr     = EZI2C_ADDR_REG;
    EZI2C_backup.clkDiv1 = EZI2C_CLKDIV1_REG;
    EZI2C_backup.clkDiv2 = EZI2C_CLKDIV2_REG;

#if (EZI2C_WAKEUP_ENABLED)
    /* Enable I2C backup regulator */
    interruptState = CyEnterCriticalSection();
    EZI2C_PWRSYS_CR1_REG |= EZI2C_PWRSYS_CR1_I2C_BACKUP;
    CyExitCriticalSection(interruptState);

    /* Wait for completion of the current transaction. The following
    * transactions have to be NACKed until the device enters the low power mode.
    * After a wakeup, the force NACK bit is cleared automatically.
    */
    EZI2C_XCFG_REG |= EZI2C_XCFG_FORCE_NACK;
    while (0u == (EZI2C_XCFG_REG & EZI2C_XCFG_SLEEP_READY))
    {
    }

     /* Setup wakeup interrupt */
    EZI2C_DisableInt();
    EZI2C_wakeupSource = 0u; /* Clear wakeup event */
    (void) CyIntSetVector(EZI2C_ISR_NUMBER, &EZI2C_WAKEUP_ISR);
    EZI2C_EnableInt();
#endif /* (EZI2C_WAKEUP_ENABLED) */
}


/*******************************************************************************
* Function Name: EZI2C_RestoreConfig
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
*  EZI2C_backup - the non-retention registers are restored from.
*
* Reentrant:
*  No.
*
* Side Effects:
*  Calling this function before EZI2C_SaveConfig() or
*  EZI2C_Sleep() may produce unexpected behavior.
*
*******************************************************************************/
void EZI2C_RestoreConfig(void) 
{
    uint8 intState;

    if (0u != (EZI2C_PWRSYS_CR1_I2C_BACKUP & EZI2C_PWRSYS_CR1_REG))
    /* Exit from Sleep */
    {
        /* Disable I2C backup regulator */
        intState = CyEnterCriticalSection();
        EZI2C_PWRSYS_CR1_REG &= (uint8) ~EZI2C_PWRSYS_CR1_I2C_BACKUP;
        CyExitCriticalSection(intState);
    }
    else /* Exit from Hibernate (bit is cleared) or wakeup disabled */
    {
    #if (EZI2C_WAKEUP_ENABLED)
        /* Disable power to I2C block before register restore */
        intState = CyEnterCriticalSection();
        EZI2C_PM_ACT_CFG_REG  &= (uint8) ~EZI2C_ACT_PWR_EN;
        EZI2C_PM_STBY_CFG_REG &= (uint8) ~EZI2C_STBY_PWR_EN;
        CyExitCriticalSection(intState);

        /* Enable component after restore complete */
        EZI2C_backup.enableState = EZI2C_ENABLED;
    #endif /* (EZI2C_WAKEUP_ENABLED) */

        /* Restore component registers: Hibernate disable power */
        EZI2C_CFG_REG     = EZI2C_backup.cfg;
        EZI2C_XCFG_REG    = EZI2C_backup.xcfg;
        EZI2C_ADDR_REG    = EZI2C_backup.adr;
        EZI2C_CLKDIV1_REG = EZI2C_backup.clkDiv1;
        EZI2C_CLKDIV2_REG = EZI2C_backup.clkDiv2;
    }

#if (EZI2C_WAKEUP_ENABLED)
    /* Set I2C interrupt to be pending if component is source of wake up */
    EZI2C_DisableInt();
    (void) CyIntSetVector(EZI2C_ISR_NUMBER, &EZI2C_ISR);
    if (0u != EZI2C_wakeupSource)
    {
        /* Generate interrupt to release I2C bus */
        (void) CyIntSetPending(EZI2C_ISR_NUMBER);
    }
    EZI2C_EnableInt();
#endif /* (EZI2C_WAKEUP_ENABLED) */
}


/*******************************************************************************
* Function Name: EZI2C_Sleep
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
*  EZI2C_backup - The non retention registers are saved to. Changed
*  by EZI2C_SaveConfig() function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void EZI2C_Sleep(void) 
{
#if (EZI2C_WAKEUP_ENABLED)
    /* Do not re-enable component in EZI2C_Wakeup(). It remains enabled as it is wakeup source */
    EZI2C_backup.enableState = EZI2C_DISABLED;
#else
    /* Store component state enabled or disable to restore after wakeup */
    EZI2C_backup.enableState = (EZI2C_PM_ACT_CFG_REG & EZI2C_ACT_PWR_EN);

    if (0u != EZI2C_backup.enableState)
    {
        /* Disable component before enter Sleep */
        EZI2C_Stop();
    }
#endif /* (EZI2C_WAKEUP_ENABLED) */

    EZI2C_SaveConfig();
}


/*******************************************************************************
* Function Name: EZI2C_Wakeup
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
*  EZI2C_backup - The non retention registers are restored from.
*
* Reentrant:
*  No.
*
* Side Effects:
*  Calling this function before EZI2C_SaveConfig() or
*  EZI2C_Sleep() will lead to unpredictable results.
*
*******************************************************************************/
void EZI2C_Wakeup(void) 
{
    EZI2C_RestoreConfig();

    if (0u != EZI2C_backup.enableState)
    {
        /* Enable component as it was enabled before Sleep */
        EZI2C_Enable();
    }
}


/* [] END OF FILE */
