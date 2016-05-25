/*******************************************************************************
* File Name: UART_1_SPI_UART.c
* Version 3.10
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_1_PVT.h"
#include "UART_1_SPI_UART_PVT.h"

/***************************************
*        SPI/UART Private Vars
***************************************/

#if(UART_1_INTERNAL_RX_SW_BUFFER_CONST)
    volatile uint32 UART_1_rxBufferHead;
    volatile uint32 UART_1_rxBufferTail;
    volatile uint8  UART_1_rxBufferOverflow;
#endif /* (UART_1_INTERNAL_RX_SW_BUFFER_CONST) */

#if(UART_1_INTERNAL_TX_SW_BUFFER_CONST)
    volatile uint32 UART_1_txBufferHead;
    volatile uint32 UART_1_txBufferTail;
#endif /* (UART_1_INTERNAL_TX_SW_BUFFER_CONST) */

#if(UART_1_INTERNAL_RX_SW_BUFFER)
    /* Add one element to the buffer to receive full packet. One byte in receive buffer is always empty */
    volatile uint8 UART_1_rxBufferInternal[UART_1_INTERNAL_RX_BUFFER_SIZE];
#endif /* (UART_1_INTERNAL_RX_SW_BUFFER) */

#if(UART_1_INTERNAL_TX_SW_BUFFER)
    volatile uint8 UART_1_txBufferInternal[UART_1_TX_BUFFER_SIZE];
#endif /* (UART_1_INTERNAL_TX_SW_BUFFER) */


#if(UART_1_RX_DIRECTION)
    /*******************************************************************************
    * Function Name: UART_1_SpiUartReadRxData
    ********************************************************************************
    *
    * Summary:
    *  Retrieves the next data element from the receive buffer.
    *   - RX software buffer is disabled: Returns data element retrieved from
    *     RX FIFO. Undefined data will be returned if the RX FIFO is empty.
    *   - RX software buffer is enabled: Returns data element from the software
    *     receive buffer. Zero value is returned if the software receive buffer
    *     is empty.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Next data element from the receive buffer.
    *
    * Global Variables:
    *  Look into UART_1_SpiInit for description.
    *
    *******************************************************************************/
    uint32 UART_1_SpiUartReadRxData(void)
    {
        uint32 rxData = 0u;

    #if (UART_1_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (UART_1_INTERNAL_RX_SW_BUFFER_CONST) */

        #if (UART_1_CHECK_RX_SW_BUFFER)
        {
            if (UART_1_rxBufferHead != UART_1_rxBufferTail)
            {
                /* There is data in RX software buffer */

                /* Calculate index to read from */
                locTail = (UART_1_rxBufferTail + 1u);

                if (UART_1_INTERNAL_RX_BUFFER_SIZE == locTail)
                {
                    locTail = 0u;
                }

                /* Get data from RX software buffer */
                rxData = UART_1_GetWordFromRxBuffer(locTail);

                /* Change index in the buffer */
                UART_1_rxBufferTail = locTail;

                #if (UART_1_CHECK_UART_RTS_CONTROL_FLOW)
                {
                    /* Check if RX Not Empty is disabled in the interrupt */
                    if (0u == (UART_1_INTR_RX_MASK_REG & UART_1_INTR_RX_NOT_EMPTY))
                    {
                        /* Enable RX Not Empty interrupt source to continue
                        * receiving data into software buffer.
                        */
                        UART_1_INTR_RX_MASK_REG |= UART_1_INTR_RX_NOT_EMPTY;
                    }
                }
                #endif

            }
        }
        #else
        {
            /* Read data from RX FIFO */
            rxData = UART_1_RX_FIFO_RD_REG;
        }
        #endif

        return (rxData);
    }


    /*******************************************************************************
    * Function Name: UART_1_SpiUartGetRxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of received data elements in the receive buffer.
    *   - RX software buffer disabled: returns the number of used entries in
    *     RX FIFO.
    *   - RX software buffer enabled: returns the number of elements which were
    *     placed in the receive buffer. This does not include the hardware RX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of received data elements
    *
    *******************************************************************************/
    uint32 UART_1_SpiUartGetRxBufferSize(void)
    {
        uint32 size;
    #if (UART_1_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locHead;
    #endif /* (UART_1_INTERNAL_RX_SW_BUFFER_CONST) */

        #if (UART_1_CHECK_RX_SW_BUFFER)
        {
            locHead = UART_1_rxBufferHead;

            if(locHead >= UART_1_rxBufferTail)
            {
                size = (locHead - UART_1_rxBufferTail);
            }
            else
            {
                size = (locHead + (UART_1_INTERNAL_RX_BUFFER_SIZE - UART_1_rxBufferTail));
            }
        }
        #else
        {
            size = UART_1_GET_RX_FIFO_ENTRIES;
        }
        #endif

        return (size);
    }


    /*******************************************************************************
    * Function Name: UART_1_SpiUartClearRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the receive buffer and RX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_1_SpiUartClearRxBuffer(void)
    {
        #if (UART_1_CHECK_RX_SW_BUFFER)
        {
            /* Lock from component interruption */
            UART_1_DisableInt();

            /* Flush RX software buffer */
            UART_1_rxBufferHead = UART_1_rxBufferTail;
            UART_1_rxBufferOverflow = 0u;

            UART_1_CLEAR_RX_FIFO;
            UART_1_ClearRxInterruptSource(UART_1_INTR_RX_ALL);

            #if (UART_1_CHECK_UART_RTS_CONTROL_FLOW)
            {
                /* Enable RX Not Empty interrupt source to continue receiving
                * data into software buffer.
                */
                UART_1_INTR_RX_MASK_REG |= UART_1_INTR_RX_NOT_EMPTY;
            }
            #endif

            /* Release lock */
            UART_1_EnableInt();
        }
        #else
        {
            UART_1_CLEAR_RX_FIFO;
        }
        #endif
    }

#endif /* (UART_1_RX_DIRECTION) */


#if(UART_1_TX_DIRECTION)
    /*******************************************************************************
    * Function Name: UART_1_SpiUartWriteTxData
    ********************************************************************************
    *
    * Summary:
    *  Places a data entry into the transmit buffer to be sent at the next available
    *  bus time.
    *  This function is blocking and waits until there is space available to put the
    *  requested data in the transmit buffer.
    *
    * Parameters:
    *  txDataByte: the data to be transmitted.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_1_SpiUartWriteTxData(uint32 txData)
    {
    #if (UART_1_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locHead;
    #endif /* (UART_1_INTERNAL_TX_SW_BUFFER_CONST) */

        #if (UART_1_CHECK_TX_SW_BUFFER)
        {
            /* Put data directly into the TX FIFO */
            if ((UART_1_txBufferHead == UART_1_txBufferTail) &&
                (UART_1_SPI_UART_FIFO_SIZE != UART_1_GET_TX_FIFO_ENTRIES))
            {
                /* TX software buffer is empty: put data directly in TX FIFO */
                UART_1_TX_FIFO_WR_REG = txData;
            }
            /* Put data into TX software buffer */
            else
            {
                /* Head index to put data */
                locHead = (UART_1_txBufferHead + 1u);

                /* Adjust TX software buffer index */
                if (UART_1_TX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                /* Wait for space in TX software buffer */
                while (locHead == UART_1_txBufferTail)
                {
                }

                /* TX software buffer has at least one room */

                /* Clear old status of INTR_TX_NOT_FULL. It sets at the end of transfer when TX FIFO is empty. */
                UART_1_ClearTxInterruptSource(UART_1_INTR_TX_NOT_FULL);

                UART_1_PutWordInTxBuffer(locHead, txData);

                UART_1_txBufferHead = locHead;

                /* Check if TX Not Full is disabled in interrupt */
                if (0u == (UART_1_INTR_TX_MASK_REG & UART_1_INTR_TX_NOT_FULL))
                {
                    /* Enable TX Not Full interrupt source to transmit from software buffer */
                    UART_1_INTR_TX_MASK_REG |= (uint32) UART_1_INTR_TX_NOT_FULL;
                }
            }
        }
        #else
        {
            /* Wait until TX FIFO has space to put data element */
            while (UART_1_SPI_UART_FIFO_SIZE == UART_1_GET_TX_FIFO_ENTRIES)
            {
            }

            UART_1_TX_FIFO_WR_REG = txData;
        }
        #endif
    }


    /*******************************************************************************
    * Function Name: UART_1_SpiUartPutArray
    ********************************************************************************
    *
    * Summary:
    *  Places an array of data into the transmit buffer to be sent.
    *  This function is blocking and waits until there is a space available to put
    *  all the requested data in the transmit buffer. The array size can be greater
    *  than transmit buffer size.
    *
    * Parameters:
    *  wrBuf:  pointer to an array with data to be placed in transmit buffer.
    *  count:  number of data elements to be placed in the transmit buffer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_1_SpiUartPutArray(const uint8 wrBuf[], uint32 count)
    {
        uint32 i;

        for (i=0u; i < count; i++)
        {
            UART_1_SpiUartWriteTxData((uint32) wrBuf[i]);
        }
    }


    /*******************************************************************************
    * Function Name: UART_1_SpiUartGetTxBufferSize
    ********************************************************************************
    *
    * Summary:
    * Returns the number of elements currently in the transmit buffer.
    *  - TX software buffer is disabled: returns the number of used entries in
    *    TX FIFO.
    *  - TX software buffer is enabled: returns the number of elements currently
    *    used in the transmit buffer. This number does not include used entries in
    *    the TX FIFO. The transmit buffer size is zero until the TX FIFO is
    *    not full.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of data elements ready to transmit.
    *
    *******************************************************************************/
    uint32 UART_1_SpiUartGetTxBufferSize(void)
    {
        uint32 size;
    #if (UART_1_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (UART_1_INTERNAL_TX_SW_BUFFER_CONST) */

        #if (UART_1_CHECK_TX_SW_BUFFER)
        {
            /* Get current Tail index */
            locTail = UART_1_txBufferTail;

            if (UART_1_txBufferHead >= locTail)
            {
                size = (UART_1_txBufferHead - locTail);
            }
            else
            {
                size = (UART_1_txBufferHead + (UART_1_TX_BUFFER_SIZE - locTail));
            }
        }
        #else
        {
            size = UART_1_GET_TX_FIFO_ENTRIES;
        }
        #endif

        return (size);
    }


    /*******************************************************************************
    * Function Name: UART_1_SpiUartClearTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the transmit buffer and TX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_1_SpiUartClearTxBuffer(void)
    {
        #if (UART_1_CHECK_TX_SW_BUFFER)
        {
            /* Lock from component interruption */
            UART_1_DisableInt();

            /* Flush TX software buffer */
            UART_1_txBufferHead = UART_1_txBufferTail;

            UART_1_INTR_TX_MASK_REG &= (uint32) ~UART_1_INTR_TX_NOT_FULL;
            UART_1_CLEAR_TX_FIFO;
            UART_1_ClearTxInterruptSource(UART_1_INTR_TX_ALL);

            /* Release lock */
            UART_1_EnableInt();
        }
        #else
        {
            UART_1_CLEAR_TX_FIFO;
        }
        #endif
    }

#endif /* (UART_1_TX_DIRECTION) */


/*******************************************************************************
* Function Name: UART_1_SpiUartDisableIntRx
********************************************************************************
*
* Summary:
*  Disables the RX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns the RX interrupt sources enabled before the function call.
*
*******************************************************************************/
uint32 UART_1_SpiUartDisableIntRx(void)
{
    uint32 intSource;

    intSource = UART_1_GetRxInterruptMode();

    UART_1_SetRxInterruptMode(UART_1_NO_INTR_SOURCES);

    return (intSource);
}


/*******************************************************************************
* Function Name: UART_1_SpiUartDisableIntTx
********************************************************************************
*
* Summary:
*  Disables TX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns TX interrupt sources enabled before function call.
*
*******************************************************************************/
uint32 UART_1_SpiUartDisableIntTx(void)
{
    uint32 intSourceMask;

    intSourceMask = UART_1_GetTxInterruptMode();

    UART_1_SetTxInterruptMode(UART_1_NO_INTR_SOURCES);

    return (intSourceMask);
}


#if(UART_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: UART_1_PutWordInRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores a byte/word into the RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  index:      index to store data byte/word in the RX buffer.
    *  rxDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_1_PutWordInRxBuffer(uint32 idx, uint32 rxDataByte)
    {
        /* Put data in buffer */
        if (UART_1_ONE_BYTE_WIDTH == UART_1_rxDataBits)
        {
            UART_1_rxBuffer[idx] = ((uint8) rxDataByte);
        }
        else
        {
            UART_1_rxBuffer[(uint32)(idx << 1u)]      = LO8(LO16(rxDataByte));
            UART_1_rxBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(rxDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: UART_1_GetWordFromRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Returns byte/word read from RX buffer.
    *
    *******************************************************************************/
    uint32 UART_1_GetWordFromRxBuffer(uint32 idx)
    {
        uint32 value;

        if (UART_1_ONE_BYTE_WIDTH == UART_1_rxDataBits)
        {
            value = UART_1_rxBuffer[idx];
        }
        else
        {
            value  = (uint32) UART_1_rxBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32)UART_1_rxBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return (value);
    }


    /*******************************************************************************
    * Function Name: UART_1_PutWordInTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores byte/word into the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  idx:        index to store data byte/word in the TX buffer.
    *  txDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_1_PutWordInTxBuffer(uint32 idx, uint32 txDataByte)
    {
        /* Put data in buffer */
        if (UART_1_ONE_BYTE_WIDTH == UART_1_txDataBits)
        {
            UART_1_txBuffer[idx] = ((uint8) txDataByte);
        }
        else
        {
            UART_1_txBuffer[(uint32)(idx << 1u)]      = LO8(LO16(txDataByte));
            UART_1_txBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(txDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: UART_1_GetWordFromTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  idx: index to get data byte/word from the TX buffer.
    *
    * Return:
    *  Returns byte/word read from the TX buffer.
    *
    *******************************************************************************/
    uint32 UART_1_GetWordFromTxBuffer(uint32 idx)
    {
        uint32 value;

        if (UART_1_ONE_BYTE_WIDTH == UART_1_txDataBits)
        {
            value = (uint32) UART_1_txBuffer[idx];
        }
        else
        {
            value  = (uint32) UART_1_txBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32) UART_1_txBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return (value);
    }

#endif /* (UART_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
