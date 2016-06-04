/*******************************************************************************
* File Name: SPIM_Funk.c
* Version 2.50
*
* Description:
*  This file provides all API functionality of the SPI Master component.
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

#if(SPIM_Funk_TX_SOFTWARE_BUF_ENABLED)
    volatile uint8 SPIM_Funk_txBuffer[SPIM_Funk_TX_BUFFER_SIZE];
    volatile uint8 SPIM_Funk_txBufferFull;
    volatile uint8 SPIM_Funk_txBufferRead;
    volatile uint8 SPIM_Funk_txBufferWrite;
#endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_Funk_RX_SOFTWARE_BUF_ENABLED)
    volatile uint8 SPIM_Funk_rxBuffer[SPIM_Funk_RX_BUFFER_SIZE];
    volatile uint8 SPIM_Funk_rxBufferFull;
    volatile uint8 SPIM_Funk_rxBufferRead;
    volatile uint8 SPIM_Funk_rxBufferWrite;
#endif /* (SPIM_Funk_RX_SOFTWARE_BUF_ENABLED) */

uint8 SPIM_Funk_initVar = 0u;

volatile uint8 SPIM_Funk_swStatusTx;
volatile uint8 SPIM_Funk_swStatusRx;


/*******************************************************************************
* Function Name: SPIM_Funk_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default SPIM configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  When this function is called it initializes all of the necessary parameters
*  for execution. i.e. setting the initial interrupt mask, configuring the
*  interrupt service routine, configuring the bit-counter parameters and
*  clearing the FIFO and Status Register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Funk_Init(void) 
{
    /* Initialize the Bit counter */
    SPIM_Funk_COUNTER_PERIOD_REG = SPIM_Funk_BITCTR_INIT;

    /* Init TX ISR  */
    #if(0u != SPIM_Funk_INTERNAL_TX_INT_ENABLED)
        CyIntDisable         (SPIM_Funk_TX_ISR_NUMBER);
        CyIntSetPriority     (SPIM_Funk_TX_ISR_NUMBER,  SPIM_Funk_TX_ISR_PRIORITY);
        (void) CyIntSetVector(SPIM_Funk_TX_ISR_NUMBER, &SPIM_Funk_TX_ISR);
    #endif /* (0u != SPIM_Funk_INTERNAL_TX_INT_ENABLED) */

    /* Init RX ISR  */
    #if(0u != SPIM_Funk_INTERNAL_RX_INT_ENABLED)
        CyIntDisable         (SPIM_Funk_RX_ISR_NUMBER);
        CyIntSetPriority     (SPIM_Funk_RX_ISR_NUMBER,  SPIM_Funk_RX_ISR_PRIORITY);
        (void) CyIntSetVector(SPIM_Funk_RX_ISR_NUMBER, &SPIM_Funk_RX_ISR);
    #endif /* (0u != SPIM_Funk_INTERNAL_RX_INT_ENABLED) */

    /* Clear any stray data from the RX and TX FIFO */
    SPIM_Funk_ClearFIFO();

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

    (void) SPIM_Funk_ReadTxStatus(); /* Clear Tx status and swStatusTx */
    (void) SPIM_Funk_ReadRxStatus(); /* Clear Rx status and swStatusRx */

    /* Configure TX and RX interrupt mask */
    SPIM_Funk_TX_STATUS_MASK_REG = SPIM_Funk_TX_INIT_INTERRUPTS_MASK;
    SPIM_Funk_RX_STATUS_MASK_REG = SPIM_Funk_RX_INIT_INTERRUPTS_MASK;
}


/*******************************************************************************
* Function Name: SPIM_Funk_Enable
********************************************************************************
*
* Summary:
*  Enable SPIM component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIM_Funk_Enable(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPIM_Funk_COUNTER_CONTROL_REG |= SPIM_Funk_CNTR_ENABLE;
    SPIM_Funk_TX_STATUS_ACTL_REG  |= SPIM_Funk_INT_ENABLE;
    SPIM_Funk_RX_STATUS_ACTL_REG  |= SPIM_Funk_INT_ENABLE;
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPIM_Funk_INTERNAL_CLOCK)
        SPIM_Funk_IntClock_Enable();
    #endif /* (0u != SPIM_Funk_INTERNAL_CLOCK) */

    SPIM_Funk_EnableTxInt();
    SPIM_Funk_EnableRxInt();
}


/*******************************************************************************
* Function Name: SPIM_Funk_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_Funk_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Funk_Start(void) 
{
    if(0u == SPIM_Funk_initVar)
    {
        SPIM_Funk_Init();
        SPIM_Funk_initVar = 1u;
    }

    SPIM_Funk_Enable();
}


/*******************************************************************************
* Function Name: SPIM_Funk_Stop
********************************************************************************
*
* Summary:
*  Disable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the clock input to enable operation.
*
*******************************************************************************/
void SPIM_Funk_Stop(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPIM_Funk_TX_STATUS_ACTL_REG &= ((uint8) ~SPIM_Funk_INT_ENABLE);
    SPIM_Funk_RX_STATUS_ACTL_REG &= ((uint8) ~SPIM_Funk_INT_ENABLE);
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPIM_Funk_INTERNAL_CLOCK)
        SPIM_Funk_IntClock_Disable();
    #endif /* (0u != SPIM_Funk_INTERNAL_CLOCK) */

    SPIM_Funk_DisableTxInt();
    SPIM_Funk_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPIM_Funk_EnableTxInt
********************************************************************************
*
* Summary:
*  Enable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_Funk_EnableTxInt(void) 
{
    #if(0u != SPIM_Funk_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(SPIM_Funk_TX_ISR_NUMBER);
    #endif /* (0u != SPIM_Funk_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_Funk_EnableRxInt
********************************************************************************
*
* Summary:
*  Enable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_Funk_EnableRxInt(void) 
{
    #if(0u != SPIM_Funk_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(SPIM_Funk_RX_ISR_NUMBER);
    #endif /* (0u != SPIM_Funk_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_Funk_DisableTxInt
********************************************************************************
*
* Summary:
*  Disable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_Funk_DisableTxInt(void) 
{
    #if(0u != SPIM_Funk_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(SPIM_Funk_TX_ISR_NUMBER);
    #endif /* (0u != SPIM_Funk_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_Funk_DisableRxInt
********************************************************************************
*
* Summary:
*  Disable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_Funk_DisableRxInt(void) 
{
    #if(0u != SPIM_Funk_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(SPIM_Funk_RX_ISR_NUMBER);
    #endif /* (0u != SPIM_Funk_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_Funk_SetTxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPIM_Funk_SetTxInterruptMode(uint8 intSrc) 
{
    SPIM_Funk_TX_STATUS_MASK_REG = intSrc;
}


/*******************************************************************************
* Function Name: SPIM_Funk_SetRxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPIM_Funk_SetRxInterruptMode(uint8 intSrc) 
{
    SPIM_Funk_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: SPIM_Funk_ReadTxStatus
********************************************************************************
*
* Summary:
*  Read the Tx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Tx status register.
*
* Global variables:
*  SPIM_Funk_swStatusTx - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Tx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIM_Funk_ReadTxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPIM_Funk_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPIM_Funk_DisableTxInt();

        tmpStatus = SPIM_Funk_GET_STATUS_TX(SPIM_Funk_swStatusTx);
        SPIM_Funk_swStatusTx = 0u;

        SPIM_Funk_EnableTxInt();

    #else

        tmpStatus = SPIM_Funk_TX_STATUS_REG;

    #endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPIM_Funk_ReadRxStatus
********************************************************************************
*
* Summary:
*  Read the Rx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Rx status register.
*
* Global variables:
*  SPIM_Funk_swStatusRx - used to store in software Rx status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Rx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Rx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIM_Funk_ReadRxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPIM_Funk_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPIM_Funk_DisableRxInt();

        tmpStatus = SPIM_Funk_GET_STATUS_RX(SPIM_Funk_swStatusRx);
        SPIM_Funk_swStatusRx = 0u;

        SPIM_Funk_EnableRxInt();

    #else

        tmpStatus = SPIM_Funk_RX_STATUS_REG;

    #endif /* (SPIM_Funk_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPIM_Funk_WriteTxData
********************************************************************************
*
* Summary:
*  Write a byte of data to be sent across the SPI.
*
* Parameters:
*  txDataByte: The data value to send across the SPI.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_Funk_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  SPIM_Funk_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  SPIM_Funk_txBuffer[SPIM_Funk_TX_BUFFER_SIZE] - used to store
*  data to sending, modified every function call if TX Software Buffer is used.
*
* Theory:
*  Allows the user to transmit any byte of data in a single transfer.
*
* Side Effects:
*  If this function is called again before the previous byte is finished then
*  the next byte will be appended to the transfer with no time between
*  the byte transfers. Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Funk_WriteTxData(uint8 txData) 
{
    #if(SPIM_Funk_TX_SOFTWARE_BUF_ENABLED)

        uint8 tempStatus;
        uint8 tmpTxBufferRead;

        /* Block if TX buffer is FULL: don't overwrite */
        do
        {
            tmpTxBufferRead = SPIM_Funk_txBufferRead;
            if(0u == tmpTxBufferRead)
            {
                tmpTxBufferRead = (SPIM_Funk_TX_BUFFER_SIZE - 1u);
            }
            else
            {
                tmpTxBufferRead--;
            }

        }while(tmpTxBufferRead == SPIM_Funk_txBufferWrite);

        /* Disable TX interrupt to protect global veriables */
        SPIM_Funk_DisableTxInt();

        tempStatus = SPIM_Funk_GET_STATUS_TX(SPIM_Funk_swStatusTx);
        SPIM_Funk_swStatusTx = tempStatus;


        if((SPIM_Funk_txBufferRead == SPIM_Funk_txBufferWrite) &&
           (0u != (SPIM_Funk_swStatusTx & SPIM_Funk_STS_TX_FIFO_NOT_FULL)))
        {
            /* Put data element into the TX FIFO */
            CY_SET_REG8(SPIM_Funk_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the TX software buffer */
            SPIM_Funk_txBufferWrite++;
            if(SPIM_Funk_txBufferWrite >= SPIM_Funk_TX_BUFFER_SIZE)
            {
                SPIM_Funk_txBufferWrite = 0u;
            }

            if(SPIM_Funk_txBufferWrite == SPIM_Funk_txBufferRead)
            {
                SPIM_Funk_txBufferRead++;
                if(SPIM_Funk_txBufferRead >= SPIM_Funk_TX_BUFFER_SIZE)
                {
                    SPIM_Funk_txBufferRead = 0u;
                }
                SPIM_Funk_txBufferFull = 1u;
            }

            SPIM_Funk_txBuffer[SPIM_Funk_txBufferWrite] = txData;

            SPIM_Funk_TX_STATUS_MASK_REG |= SPIM_Funk_STS_TX_FIFO_NOT_FULL;
        }

        SPIM_Funk_EnableTxInt();

    #else
        /* Wait until TX FIFO has a place */
        while(0u == (SPIM_Funk_TX_STATUS_REG & SPIM_Funk_STS_TX_FIFO_NOT_FULL))
        {
        }

        /* Put data element into the TX FIFO */
        CY_SET_REG8(SPIM_Funk_TXDATA_PTR, txData);

    #endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_Funk_ReadRxData
********************************************************************************
*
* Summary:
*  Read the next byte of data received across the SPI.
*
* Parameters:
*  None.
*
* Return:
*  The next byte of data read from the FIFO.
*
* Global variables:
*  SPIM_Funk_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPIM_Funk_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  SPIM_Funk_rxBuffer[SPIM_Funk_RX_BUFFER_SIZE] - used to store
*  received data.
*
* Theory:
*  Allows the user to read a byte of data received.
*
* Side Effects:
*  Will return invalid data if the FIFO is empty. The user should Call
*  GetRxBufferSize() and if it returns a non-zero value then it is safe to call
*  ReadByte() function.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIM_Funk_ReadRxData(void) 
{
    uint8 rxData;

    #if(SPIM_Funk_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPIM_Funk_DisableRxInt();

        if(SPIM_Funk_rxBufferRead != SPIM_Funk_rxBufferWrite)
        {
            if(0u == SPIM_Funk_rxBufferFull)
            {
                SPIM_Funk_rxBufferRead++;
                if(SPIM_Funk_rxBufferRead >= SPIM_Funk_RX_BUFFER_SIZE)
                {
                    SPIM_Funk_rxBufferRead = 0u;
                }
            }
            else
            {
                SPIM_Funk_rxBufferFull = 0u;
            }
        }

        rxData = SPIM_Funk_rxBuffer[SPIM_Funk_rxBufferRead];

        SPIM_Funk_EnableRxInt();

    #else

        rxData = CY_GET_REG8(SPIM_Funk_RXDATA_PTR);

    #endif /* (SPIM_Funk_RX_SOFTWARE_BUF_ENABLED) */

    return(rxData);
}


/*******************************************************************************
* Function Name: SPIM_Funk_GetRxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the RX buffer.
*  If RX Software Buffer not used then function return 0 if FIFO empty or 1 if
*  FIFO not empty. In another case function return size of RX Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the RX buffer.
*
* Global variables:
*  SPIM_Funk_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPIM_Funk_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8 SPIM_Funk_GetRxBufferSize(void) 
{
    uint8 size;

    #if(SPIM_Funk_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPIM_Funk_DisableRxInt();

        if(SPIM_Funk_rxBufferRead == SPIM_Funk_rxBufferWrite)
        {
            size = 0u;
        }
        else if(SPIM_Funk_rxBufferRead < SPIM_Funk_rxBufferWrite)
        {
            size = (SPIM_Funk_rxBufferWrite - SPIM_Funk_rxBufferRead);
        }
        else
        {
            size = (SPIM_Funk_RX_BUFFER_SIZE - SPIM_Funk_rxBufferRead) + SPIM_Funk_rxBufferWrite;
        }

        SPIM_Funk_EnableRxInt();

    #else

        /* We can only know if there is data in the RX FIFO */
        size = (0u != (SPIM_Funk_RX_STATUS_REG & SPIM_Funk_STS_RX_FIFO_NOT_EMPTY)) ? 1u : 0u;

    #endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPIM_Funk_GetTxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the TX buffer.
*  If TX Software Buffer not used then function return 0 - if FIFO empty, 1 - if
*  FIFO not full, 4 - if FIFO full. In another case function return size of TX
*  Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the TX buffer.
*
* Global variables:
*  SPIM_Funk_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIM_Funk_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  SPIM_Funk_GetTxBufferSize(void) 
{
    uint8 size;

    #if(SPIM_Funk_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPIM_Funk_DisableTxInt();

        if(SPIM_Funk_txBufferRead == SPIM_Funk_txBufferWrite)
        {
            size = 0u;
        }
        else if(SPIM_Funk_txBufferRead < SPIM_Funk_txBufferWrite)
        {
            size = (SPIM_Funk_txBufferWrite - SPIM_Funk_txBufferRead);
        }
        else
        {
            size = (SPIM_Funk_TX_BUFFER_SIZE - SPIM_Funk_txBufferRead) + SPIM_Funk_txBufferWrite;
        }

        SPIM_Funk_EnableTxInt();

    #else

        size = SPIM_Funk_TX_STATUS_REG;

        if(0u != (size & SPIM_Funk_STS_TX_FIFO_EMPTY))
        {
            size = 0u;
        }
        else if(0u != (size & SPIM_Funk_STS_TX_FIFO_NOT_FULL))
        {
            size = 1u;
        }
        else
        {
            size = SPIM_Funk_FIFO_SIZE;
        }

    #endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPIM_Funk_ClearRxBuffer
********************************************************************************
*
* Summary:
*  Clear the RX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_Funk_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function
*  call - resets to zero.
*  SPIM_Funk_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any received data not read from the RAM buffer will be lost when overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Funk_ClearRxBuffer(void) 
{
    /* Clear Hardware RX FIFO */
    while(0u !=(SPIM_Funk_RX_STATUS_REG & SPIM_Funk_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG8(SPIM_Funk_RXDATA_PTR);
    }

    #if(SPIM_Funk_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPIM_Funk_DisableRxInt();

        SPIM_Funk_rxBufferFull  = 0u;
        SPIM_Funk_rxBufferRead  = 0u;
        SPIM_Funk_rxBufferWrite = 0u;

        SPIM_Funk_EnableRxInt();
    #endif /* (SPIM_Funk_RX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_Funk_ClearTxBuffer
********************************************************************************
*
* Summary:
*  Clear the TX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_Funk_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  SPIM_Funk_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any data not yet transmitted from the RAM buffer will be lost when
*  overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Funk_ClearTxBuffer(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPIM_Funk_AUX_CONTROL_DP0_REG |= ((uint8)  SPIM_Funk_TX_FIFO_CLR);
    SPIM_Funk_AUX_CONTROL_DP0_REG &= ((uint8) ~SPIM_Funk_TX_FIFO_CLR);

    #if(SPIM_Funk_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPIM_Funk_AUX_CONTROL_DP1_REG |= ((uint8)  SPIM_Funk_TX_FIFO_CLR);
        SPIM_Funk_AUX_CONTROL_DP1_REG &= ((uint8) ~SPIM_Funk_TX_FIFO_CLR);
    #endif /* (SPIM_Funk_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);

    #if(SPIM_Funk_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPIM_Funk_DisableTxInt();

        SPIM_Funk_txBufferFull  = 0u;
        SPIM_Funk_txBufferRead  = 0u;
        SPIM_Funk_txBufferWrite = 0u;

        /* Buffer is EMPTY: disable TX FIFO NOT FULL interrupt */
        SPIM_Funk_TX_STATUS_MASK_REG &= ((uint8) ~SPIM_Funk_STS_TX_FIFO_NOT_FULL);

        SPIM_Funk_EnableTxInt();
    #endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED) */
}


#if(0u != SPIM_Funk_BIDIRECTIONAL_MODE)
    /*******************************************************************************
    * Function Name: SPIM_Funk_TxEnable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to transmit.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPIM_Funk_TxEnable(void) 
    {
        SPIM_Funk_CONTROL_REG |= SPIM_Funk_CTRL_TX_SIGNAL_EN;
    }


    /*******************************************************************************
    * Function Name: SPIM_Funk_TxDisable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to receive.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPIM_Funk_TxDisable(void) 
    {
        SPIM_Funk_CONTROL_REG &= ((uint8) ~SPIM_Funk_CTRL_TX_SIGNAL_EN);
    }

#endif /* (0u != SPIM_Funk_BIDIRECTIONAL_MODE) */


/*******************************************************************************
* Function Name: SPIM_Funk_PutArray
********************************************************************************
*
* Summary:
*  Write available data from ROM/RAM to the TX buffer while space is available
*  in the TX buffer. Keep trying until all data is passed to the TX buffer.
*
* Parameters:
*  *buffer: Pointer to the location in RAM containing the data to send
*  byteCount: The number of bytes to move to the transmit buffer.
*
* Return:
*  None.
*
* Side Effects:
*  Will stay in this routine until all data has been sent.  May get locked in
*  this loop if data is not being initiated by the master if there is not
*  enough room in the TX FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_Funk_PutArray(const uint8 buffer[], uint8 byteCount)
                                                                          
{
    uint8 bufIndex;

    bufIndex = 0u;

    while(byteCount > 0u)
    {
        SPIM_Funk_WriteTxData(buffer[bufIndex]);
        bufIndex++;
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: SPIM_Funk_ClearFIFO
********************************************************************************
*
* Summary:
*  Clear the RX and TX FIFO's of all data for a fresh start.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
void SPIM_Funk_ClearFIFO(void) 
{
    uint8 enableInterrupts;

    /* Clear Hardware RX FIFO */
    while(0u !=(SPIM_Funk_RX_STATUS_REG & SPIM_Funk_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG8(SPIM_Funk_RXDATA_PTR);
    }

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPIM_Funk_AUX_CONTROL_DP0_REG |= ((uint8)  SPIM_Funk_TX_FIFO_CLR);
    SPIM_Funk_AUX_CONTROL_DP0_REG &= ((uint8) ~SPIM_Funk_TX_FIFO_CLR);

    #if(SPIM_Funk_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPIM_Funk_AUX_CONTROL_DP1_REG |= ((uint8)  SPIM_Funk_TX_FIFO_CLR);
        SPIM_Funk_AUX_CONTROL_DP1_REG &= ((uint8) ~SPIM_Funk_TX_FIFO_CLR);
    #endif /* (SPIM_Funk_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/


/*******************************************************************************
* Function Name: SPIM_Funk_EnableInt
********************************************************************************
*
* Summary:
*  Enable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_Funk_EnableInt(void) 
{
    SPIM_Funk_EnableRxInt();
    SPIM_Funk_EnableTxInt();
}


/*******************************************************************************
* Function Name: SPIM_Funk_DisableInt
********************************************************************************
*
* Summary:
*  Disable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_Funk_DisableInt(void) 
{
    SPIM_Funk_DisableTxInt();
    SPIM_Funk_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPIM_Funk_SetInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPIM_Funk_SetInterruptMode(uint8 intSrc) 
{
    SPIM_Funk_TX_STATUS_MASK_REG  = (intSrc & ((uint8) ~SPIM_Funk_STS_SPI_IDLE));
    SPIM_Funk_RX_STATUS_MASK_REG  =  intSrc;
}


/*******************************************************************************
* Function Name: SPIM_Funk_ReadStatus
********************************************************************************
*
* Summary:
*  Read the status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the status register.
*
* Global variables:
*  SPIM_Funk_swStatus - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the status register for error detection
*  and flow control.
*
* Side Effects:
*  Clear status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIM_Funk_ReadStatus(void) 
{
    uint8 tmpStatus;

    #if(SPIM_Funk_TX_SOFTWARE_BUF_ENABLED || SPIM_Funk_RX_SOFTWARE_BUF_ENABLED)

        SPIM_Funk_DisableInt();

        tmpStatus  = SPIM_Funk_GET_STATUS_RX(SPIM_Funk_swStatusRx);
        tmpStatus |= SPIM_Funk_GET_STATUS_TX(SPIM_Funk_swStatusTx);
        tmpStatus &= ((uint8) ~SPIM_Funk_STS_SPI_IDLE);

        SPIM_Funk_swStatusTx = 0u;
        SPIM_Funk_swStatusRx = 0u;

        SPIM_Funk_EnableInt();

    #else

        tmpStatus  = SPIM_Funk_RX_STATUS_REG;
        tmpStatus |= SPIM_Funk_TX_STATUS_REG;
        tmpStatus &= ((uint8) ~SPIM_Funk_STS_SPI_IDLE);

    #endif /* (SPIM_Funk_TX_SOFTWARE_BUF_ENABLED || SPIM_Funk_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/* [] END OF FILE */
