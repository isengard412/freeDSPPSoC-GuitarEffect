/*******************************************************************************
* File Name: SPIM_Funk_PM.c
* Version 2.50
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_Funk_PVT.h"

static SPIM_Funk_BACKUP_STRUCT SPIM_Funk_backup =
{
    SPIM_Funk_DISABLED,
    SPIM_Funk_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIM_Funk_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIM_Funk_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_Funk_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIM_Funk_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_Funk_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIM_Funk_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Funk_Sleep(void) 
{
    /* Save components enable state */
    SPIM_Funk_backup.enableState = ((uint8) SPIM_Funk_IS_ENABLED);

    SPIM_Funk_Stop();
}


/*******************************************************************************
* Function Name: SPIM_Funk_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIM_Funk_backup - used when non-retention registers are restored.
*  SPIM_Funk_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_Funk_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_Funk_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_Funk_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Funk_Wakeup(void) 
{
    #if(SPIM_Funk_RX_SOFTWARE_BUF_ENABLED)
        SPIM_Funk_rxBufferFull  = 0u;
        SPIM_Funk_rxBufferRead  = 0u;
        SPIM_Funk_rxBufferWrite = 0u;
    #endif /* (SPIM_Funk_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_Funk_TX_SOFTWARE_BUF_ENABLED)
        SPIM_Funk_txBufferFull  = 0u;
        SPIM_Funk_txBufferRead  = 0u;
        SPIM_Funk_txBufferWrite = 0u;
    #endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_Funk_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_Funk_backup.enableState)
    {
        SPIM_Funk_Enable();
    }
}


/* [] END OF FILE */
