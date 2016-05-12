/*******************************************************************************
* File Name: main.c
*
* Version: 1.10
*
* Description:
*  This is source code for example project of the SPI
*  Slave component.
*  Parameters used:
*   Mode                CPHA == 0, CPOL == 0                
*   Data lines          MOSI+MISO
*   Shift direction     MSB First
*   DataBits:           8 
*   Bit Rate            1Mbit
*   Clock source        External 
*
*  SPI communication test using DMA. 8 bytes are transmitted
*  between SPI Master and SPI Slave.
*  Transmitted and received data are displayed on LCD. 
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>
#include "uart.h"

void DmaTxConfiguration(void);
void DmaRxConfiguration(void);

/* DMA Configuration for DMA_TX */
#define DMA_TX_BYTES_PER_BURST      (1u)
#define DMA_TX_REQUEST_PER_BURST    (1u)
#define DMA_TX_SRC_BASE             (CYDEV_SRAM_BASE)
#define DMA_TX_DST_BASE             (CYDEV_PERIPH_BASE)

/* DMA Configuration for DMA_RX */
#define DMA_RX_BYTES_PER_BURST      (1u)
#define DMA_RX_REQUEST_PER_BURST    (1u)
#define DMA_RX_SRC_BASE             (CYDEV_PERIPH_BASE)
#define DMA_RX_DST_BASE             (CYDEV_SRAM_BASE)

#define BUFFER_SIZE                 (8u)
#define STORE_TD_CFG_ONCMPLT        (1u)

/* Variable declarations for DMA_TX and DMA_RX*/
uint8 txChannel, rxChannel;
uint8 txTD, rxTD;

/* The txBuffer size is equal (BUFFER_SIZE-1) because for SPI Mode where CPHA == 0 and
* CPOL == 0 one byte writes directly in SPI TX FIFO using SPIS_WriteTxDataZero() API.
*/
uint8 txBuffer [BUFFER_SIZE-1] = {0x09u, 0x0Au, 0x0Bu, 0x0Cu, 0x0Du, 0x0Eu, 0x0Fu};
uint8 rxBuffer [BUFFER_SIZE];


/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  Main function performs following functions:
*   1. Starts Character LCD and print project info
*   2. Starts SPI Slave component
*   3. Configures the DMA transfer for RX and TX directions
*   4. Displays the results on Character LCD
*   
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{
    uint8 i;
    
    DmaTxConfiguration();
    DmaRxConfiguration();

    SPIS_Start();
    SPIS_WriteTxDataZero(0x00u);
    
    CyDmaChEnable(rxChannel, STORE_TD_CFG_ONCMPLT);
    CyDmaChEnable(txChannel, STORE_TD_CFG_ONCMPLT);   
    
    //LCD_Start();
    UARTinit();
    //LCD_Position(0u,0u);
    //LCD_PrintString("SPI Slave");
    UARTsendString("SPI Slave\n");
    //LCD_Position(1u,0u);
    //LCD_PrintString("example");
    UARTsendString("example\n");
    
    while(0u == (SPIS_ReadTxStatus() & SPIS_STS_SPI_DONE))
    {
    }
    
    //LCD_ClearDisplay();
    //LCD_Position(0u,0u);
    //LCD_PrintString("Slave Rx data:");
    //LCD_Position(1u,0u);
    UARTsendString("Slave Rx data:\n");
           
    for(i=0u; i<BUFFER_SIZE; i++)
    {
        //LCD_PrintHexUint8(rxBuffer[i]);
        UARTsendNumber(rxBuffer[i]);
    }        
    
    for(;;)
    {
    }
}

/*******************************************************************************
* Function Name: DmaTxConfiguration
********************************************************************************
* Summary:
*  Configures the DMA to manage data transfers from the TX buffer (allocated in 
*  RAM) into SPIS TX FIFO.
*   
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DmaTxConfiguration()
{
    txChannel = DMA_TX_DmaInitialize(DMA_TX_BYTES_PER_BURST, DMA_TX_REQUEST_PER_BURST, 
                                        HI16(DMA_TX_SRC_BASE), HI16(DMA_TX_DST_BASE));

    txTD = CyDmaTdAllocate();

    CyDmaTdSetConfiguration(txTD, (BUFFER_SIZE-1), CY_DMA_DISABLE_TD, TD_INC_SRC_ADR);
    CyDmaTdSetAddress(txTD, LO16((uint32) txBuffer), LO16((uint32) SPIS_TXDATA_PTR));
    CyDmaChSetInitialTd(txChannel, txTD);
}    


/*******************************************************************************
* Function Name: DmaRxConfiguration
********************************************************************************
* Summary:
*  Configures the DMA to manage data transfers from SPIS RX FIFO into the RX 
*  buffer (allocated in RAM).
*   
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DmaRxConfiguration()
{ 
    rxChannel = DMA_RX_DmaInitialize(DMA_RX_BYTES_PER_BURST, DMA_RX_REQUEST_PER_BURST,
                                     HI16(DMA_RX_SRC_BASE), HI16(DMA_RX_DST_BASE));

    rxTD = CyDmaTdAllocate();

    CyDmaTdSetConfiguration(rxTD, BUFFER_SIZE, CY_DMA_DISABLE_TD, TD_INC_DST_ADR);
    CyDmaTdSetAddress(rxTD, LO16((uint32) SPIS_RXDATA_PTR), LO16((uint32) rxBuffer));
    CyDmaChSetInitialTd(rxChannel, rxTD);
}
    
    
/* [] END OF FILE */
