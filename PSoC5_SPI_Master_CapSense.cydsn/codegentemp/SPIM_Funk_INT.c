/*******************************************************************************
* File Name: SPIM_Funk_INT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_Funk_PVT.h"
#include "cyapicallbacks.h"

/* User code required at start of ISR */
/* `#START SPIM_Funk_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPIM_Funk_TX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_Funk_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIM_Funk_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  SPIM_Funk_txBuffer[SPIM_Funk_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_Funk_TX_ISR)
{
    #if(SPIM_Funk_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPIM_Funk_TX_ISR_ENTRY_CALLBACK
        SPIM_Funk_TX_ISR_EntryCallback();
    #endif /* SPIM_Funk_TX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPIM_Funk_TX_ISR_START` */

    /* `#END` */
    
    #if(SPIM_Funk_TX_SOFTWARE_BUF_ENABLED)
        /* Check if TX data buffer is not empty and there is space in TX FIFO */
        while(SPIM_Funk_txBufferRead != SPIM_Funk_txBufferWrite)
        {
            tmpStatus = SPIM_Funk_GET_STATUS_TX(SPIM_Funk_swStatusTx);
            SPIM_Funk_swStatusTx = tmpStatus;

            if(0u != (SPIM_Funk_swStatusTx & SPIM_Funk_STS_TX_FIFO_NOT_FULL))
            {
                if(0u == SPIM_Funk_txBufferFull)
                {
                   SPIM_Funk_txBufferRead++;

                    if(SPIM_Funk_txBufferRead >= SPIM_Funk_TX_BUFFER_SIZE)
                    {
                        SPIM_Funk_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPIM_Funk_txBufferFull = 0u;
                }

                /* Put data element into the TX FIFO */
                CY_SET_REG8(SPIM_Funk_TXDATA_PTR, 
                                             SPIM_Funk_txBuffer[SPIM_Funk_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        if(SPIM_Funk_txBufferRead == SPIM_Funk_txBufferWrite)
        {
            /* TX Buffer is EMPTY: disable interrupt on TX NOT FULL */
            SPIM_Funk_TX_STATUS_MASK_REG &= ((uint8) ~SPIM_Funk_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_Funk_TX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_Funk_TX_ISR_EXIT_CALLBACK
        SPIM_Funk_TX_ISR_ExitCallback();
    #endif /* SPIM_Funk_TX_ISR_EXIT_CALLBACK */
}


/*******************************************************************************
* Function Name: SPIM_Funk_RX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_Funk_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPIM_Funk_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPIM_Funk_rxBuffer[SPIM_Funk_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_Funk_RX_ISR)
{
    #if(SPIM_Funk_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint8 rxData;
    #endif /* (SPIM_Funk_RX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPIM_Funk_RX_ISR_ENTRY_CALLBACK
        SPIM_Funk_RX_ISR_EntryCallback();
    #endif /* SPIM_Funk_RX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPIM_Funk_RX_ISR_START` */

    /* `#END` */
    
    #if(SPIM_Funk_RX_SOFTWARE_BUF_ENABLED)

        tmpStatus = SPIM_Funk_GET_STATUS_RX(SPIM_Funk_swStatusRx);
        SPIM_Funk_swStatusRx = tmpStatus;

        /* Check if RX data FIFO has some data to be moved into the RX Buffer */
        while(0u != (SPIM_Funk_swStatusRx & SPIM_Funk_STS_RX_FIFO_NOT_EMPTY))
        {
            rxData = CY_GET_REG8(SPIM_Funk_RXDATA_PTR);

            /* Set next pointer. */
            SPIM_Funk_rxBufferWrite++;
            if(SPIM_Funk_rxBufferWrite >= SPIM_Funk_RX_BUFFER_SIZE)
            {
                SPIM_Funk_rxBufferWrite = 0u;
            }

            if(SPIM_Funk_rxBufferWrite == SPIM_Funk_rxBufferRead)
            {
                SPIM_Funk_rxBufferRead++;
                if(SPIM_Funk_rxBufferRead >= SPIM_Funk_RX_BUFFER_SIZE)
                {
                    SPIM_Funk_rxBufferRead = 0u;
                }

                SPIM_Funk_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            SPIM_Funk_rxBuffer[SPIM_Funk_rxBufferWrite] = rxData;

            tmpStatus = SPIM_Funk_GET_STATUS_RX(SPIM_Funk_swStatusRx);
            SPIM_Funk_swStatusRx = tmpStatus;
        }

    #endif /* (SPIM_Funk_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_Funk_RX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_Funk_RX_ISR_EXIT_CALLBACK
        SPIM_Funk_RX_ISR_ExitCallback();
    #endif /* SPIM_Funk_RX_ISR_EXIT_CALLBACK */
}

/* [] END OF FILE */
