/*******************************************************************************
* File Name: SPIS_PM.c
* Version 2.70
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

#include "SPIS_PVT.h"

static SPIS_BACKUP_STRUCT SPIS_backup = 
{
    SPIS_DISABLED,
    SPIS_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIS_SaveConfig
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
void SPIS_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIS_RestoreConfig
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
void SPIS_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIS_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPI Slave Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIS_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_Sleep(void) 
{
    /* Save components enable state */
    if ((SPIS_TX_STATUS_ACTL_REG & SPIS_INT_ENABLE) != 0u)
    {
        SPIS_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        SPIS_backup.enableState = 0u;
    }

    SPIS_Stop();

}


/*******************************************************************************
* Function Name: SPIS_Wakeup
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
*  SPIS_backup - used when non-retention registers are restored.
*  SPIS_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_txBufferRead - modified every function call - resets to
*  zero.
*  SPIS_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_Wakeup(void) 
{
    #if (SPIS_TX_SOFTWARE_BUF_ENABLED)
        SPIS_txBufferFull = 0u;
        SPIS_txBufferRead = 0u;
        SPIS_txBufferWrite = 0u;
    #endif /* SPIS_TX_SOFTWARE_BUF_ENABLED */

    #if (SPIS_RX_SOFTWARE_BUF_ENABLED)
        SPIS_rxBufferFull = 0u;
        SPIS_rxBufferRead = 0u;
        SPIS_rxBufferWrite = 0u;
    #endif /* SPIS_RX_SOFTWARE_BUF_ENABLED */

    SPIS_ClearFIFO();

    /* Restore components block enable state */
    if (SPIS_backup.enableState != 0u)
    {
         /* Components block was enabled */
         SPIS_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
