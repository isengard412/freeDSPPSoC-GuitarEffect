/*******************************************************************************
* File Name: main.c
*
* Version: 2.0
*
* Description:
*  This is the source code for the example project of the Inter-IC Sound Bus
* (I2S) component.
*
*  Parameters used:
*   Direction:          Tx and Rx
*   WordSelect:         64 bits
*   DataBits:           16 bits
*   DataInterleaving:   Interleaved
*   DMA Request:        Tx and Rx
*   Rx clip detection:  Enabled
*
*  I2S data transfers with a loopback. Tx data is sent from the memory to
*  the Tx FIFO using TxDMA. The data is transmitted on the Tx direction and
*  is received on the Rx direction.
*  RxDMA transfers the data from Rx FIFO to the SRAM buffer.
*  Received data is  displayed on the LCD. 
*  Pressing SW1 on the DVK increments the value of the first element in the
*  transmit buffer. If the value crosses the negative and positive clipping
*  thresholds, the LED1 is turned on.
*
********************************************************************************
* Copyright 2012-2014, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>

#define BUFFER_SIZE                 (4u)
#define	BUTTON_DEBOUNCE_COUNT_MAX	(30u)
#define	USERIO_DISPLAY_REFRESH      (100u)

/* DMA Configuration for RxDMA */
#define RxDMA_BYTES_PER_BURST       (1u)
#define RxDMA_REQUEST_PER_BURST     (1u)
#define RxDMA_SRC_BASE              (CYDEV_PERIPH_BASE)
#define RxDMA_DST_BASE              (CYDEV_SRAM_BASE)

/* DMA Configuration for TxDMA */
#define TxDMA_BYTES_PER_BURST       (1u)
#define TxDMA_REQUEST_PER_BURST     (1u)
#define TxDMA_SRC_BASE              (CYDEV_SRAM_BASE)
#define TxDMA_DST_BASE              (CYDEV_PERIPH_BASE)

/* Function prototypes */
static void DmaTxConfiguration(void);

/* Variable declarations for RxDMA and TxDMA */
static uint8 txDmaChan;
static uint8 txDmaTd[1u];


/* Data to be transmitted by Tx */
uint8 txBuff[BUFFER_SIZE] = {0xCAu, 0xFEu, 0xFAu, 0xCEu};


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  The main function performs the following tasks:
*   1. Starts all components
*   2. Configures the DMA transfer for the Rx and Tx directions
*   3. Enables Rx and Tx directions
*   4. Scans for a button event and increment the first element of txBuff[] if
*      the button was pressed
*   5. Prints out the received data onto the LCD with a user defined refresh
*      rate
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
    uint8 refreshRate = USERIO_DISPLAY_REFRESH;


    I2S_1_Start();
    
    /* Configure DMAs for each direction */ 
    DmaTxConfiguration();


    while(0u != (I2S_1_ReadTxStatus() & I2S_1_TX_FIFO_0_NOT_FULL))
    {
        /* Wait for TxDMA to fill Tx FIFO */
    }
    CyDelayUs(1);
    I2S_1_EnableTx();   /* Enable Tx direction */
   
    for(;;)
    {
        /* Execute following tasks once every millisecond */
        CyDelay(1u);


        if(0u != refreshRate)
        {
            refreshRate--;
        }
        else
        {
            refreshRate = USERIO_DISPLAY_REFRESH;

            /* If SW1 has been pressed, increment the first byte of Tx buffer */
            if(txBuff[0u]<255)
            {
                txBuff[0u]++;
            }
            else
            {
                txBuff[0u]=0;
            }
        }
    }
}


/*******************************************************************************
* Function Name: DmaTxConfiguration
********************************************************************************
*
* Summary:
*  Configures the DMA transfer for the Tx direction.
*   
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DmaTxConfiguration(void)
{
     /* Tx DMA Config
    * Init DMA, 1 byte bursts, each burst requires a request
    */ 
    txDmaChan = TxDMA_DmaInitialize(TxDMA_BYTES_PER_BURST, TxDMA_REQUEST_PER_BURST, 
                                    HI16(TxDMA_SRC_BASE), HI16(TxDMA_DST_BASE));

    txDmaTd[0u] = CyDmaTdAllocate();

    /* Configure this Td chain as follows:
    *  - The TD is looping on itself
    *  - Increment the source address, but not the destination address   
    */
    CyDmaTdSetConfiguration(txDmaTd[0u], BUFFER_SIZE, txDmaTd[0u], TD_INC_SRC_ADR);
    
    /* From the memory to the I2S */
    CyDmaTdSetAddress(txDmaTd[0u], LO16((uint32)txBuff), LO16((uint32)I2S_1_TX_CH0_F0_PTR));

    /* Associate the TD with the channel */
    CyDmaChSetInitialTd(txDmaChan, txDmaTd[0u]);

    /* Enable the channel */
    CyDmaChEnable(txDmaChan, 1u);
}

/* [] END OF FILE */
