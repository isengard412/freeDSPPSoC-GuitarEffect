/*******************************************************************************
* File Name: IDAC8.c
* Version 2.0
*
* Description:
*  This file provides the power management source code to API for the
*  IDAC8.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include "IDAC8.h"

static IDAC8_backupStruct IDAC8_backup;


/*******************************************************************************
* Function Name: IDAC8_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void IDAC8_SaveConfig(void) 
{
    if (!((IDAC8_CR1 & IDAC8_SRC_MASK) == IDAC8_SRC_UDB))
    {
        IDAC8_backup.data_value = IDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: IDAC8_RestoreConfig
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
*******************************************************************************/
void IDAC8_RestoreConfig(void) 
{
    if (!((IDAC8_CR1 & IDAC8_SRC_MASK) == IDAC8_SRC_UDB))
    {
        if((IDAC8_Strobe & IDAC8_STRB_MASK) == IDAC8_STRB_EN)
        {
            IDAC8_Strobe &= (uint8)(~IDAC8_STRB_MASK);
            IDAC8_Data = IDAC8_backup.data_value;
            IDAC8_Strobe |= IDAC8_STRB_EN;
        }
        else
        {
            IDAC8_Data = IDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: IDAC8_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
* Global variables:
*  IDAC8_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void IDAC8_Sleep(void) 
{
    if(IDAC8_ACT_PWR_EN == (IDAC8_PWRMGR & IDAC8_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        IDAC8_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        IDAC8_backup.enableState = 0u;
    }

    IDAC8_Stop();
    IDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: IDAC8_Wakeup
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
*  IDAC8_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void IDAC8_Wakeup(void) 
{
    IDAC8_RestoreConfig();
    
    if(IDAC8_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        IDAC8_Enable();
        
        /* Set the data register */
        IDAC8_SetValue(IDAC8_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
