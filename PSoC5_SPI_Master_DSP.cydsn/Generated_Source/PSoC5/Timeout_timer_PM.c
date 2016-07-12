/*******************************************************************************
* File Name: Timeout_timer_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timeout_timer.h"

static Timeout_timer_backupStruct Timeout_timer_backup;


/*******************************************************************************
* Function Name: Timeout_timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timeout_timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timeout_timer_SaveConfig(void) 
{
    #if (!Timeout_timer_UsingFixedFunction)
        Timeout_timer_backup.TimerUdb = Timeout_timer_ReadCounter();
        Timeout_timer_backup.InterruptMaskValue = Timeout_timer_STATUS_MASK;
        #if (Timeout_timer_UsingHWCaptureCounter)
            Timeout_timer_backup.TimerCaptureCounter = Timeout_timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timeout_timer_UDB_CONTROL_REG_REMOVED)
            Timeout_timer_backup.TimerControlRegister = Timeout_timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timeout_timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timeout_timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timeout_timer_RestoreConfig(void) 
{   
    #if (!Timeout_timer_UsingFixedFunction)

        Timeout_timer_WriteCounter(Timeout_timer_backup.TimerUdb);
        Timeout_timer_STATUS_MASK =Timeout_timer_backup.InterruptMaskValue;
        #if (Timeout_timer_UsingHWCaptureCounter)
            Timeout_timer_SetCaptureCount(Timeout_timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timeout_timer_UDB_CONTROL_REG_REMOVED)
            Timeout_timer_WriteControlRegister(Timeout_timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timeout_timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timeout_timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timeout_timer_Sleep(void) 
{
    #if(!Timeout_timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timeout_timer_CTRL_ENABLE == (Timeout_timer_CONTROL & Timeout_timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timeout_timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timeout_timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timeout_timer_Stop();
    Timeout_timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Timeout_timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timeout_timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timeout_timer_Wakeup(void) 
{
    Timeout_timer_RestoreConfig();
    #if(!Timeout_timer_UDB_CONTROL_REG_REMOVED)
        if(Timeout_timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timeout_timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
