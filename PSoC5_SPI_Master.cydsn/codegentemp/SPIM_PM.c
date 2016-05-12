/*******************************************************************************
* File Name: SPIM_PM.c
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

#include "SPIM_PVT.h"

static SPIM_BACKUP_STRUCT SPIM_backup =
{
    SPIM_DISABLED,
    SPIM_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIM_SaveConfig
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
void SPIM_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_RestoreConfig
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
void SPIM_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_Sleep
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
*  SPIM_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Sleep(void) 
{
    /* Save components enable state */
    SPIM_backup.enableState = ((uint8) SPIM_IS_ENABLED);

    SPIM_Stop();
}


/*******************************************************************************
* Function Name: SPIM_Wakeup
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
*  SPIM_backup - used when non-retention registers are restored.
*  SPIM_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Wakeup(void) 
{
    #if(SPIM_RX_SOFTWARE_BUF_ENABLED)
        SPIM_rxBufferFull  = 0u;
        SPIM_rxBufferRead  = 0u;
        SPIM_rxBufferWrite = 0u;
    #endif /* (SPIM_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_TX_SOFTWARE_BUF_ENABLED)
        SPIM_txBufferFull  = 0u;
        SPIM_txBufferRead  = 0u;
        SPIM_txBufferWrite = 0u;
    #endif /* (SPIM_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_backup.enableState)
    {
        SPIM_Enable();
    }
}


/* [] END OF FILE */
