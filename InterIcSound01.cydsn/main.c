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
static void DmaRxConfiguration(void);
static void DmaTxConfiguration(void);
static void ButtonProcess(void);
static void DisplayUpdate(void);

/* Variable declarations for RxDMA and TxDMA */
static uint8 rxDmaChan;
static uint8 rxDmaTd[1u];
static uint8 txDmaChan;
static uint8 txDmaTd[1u];

/* Receive buffer */
static uint8 rxBuff[BUFFER_SIZE];

/* Data to be transmitted by Tx */
uint8 txBuff[BUFFER_SIZE] = {0xCAu, 0xFEu, 0xFAu, 0xCEu};

/* Press button state */
static uint8 buttonPressed = 0u;


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

    LCD_Start();
    LCD_PrintString("TX:");
    LCD_Position(1u, 0u);
    LCD_PrintString("RX:");

    I2S_1_Start();
    
    /* Configure DMAs for each direction */ 
    DmaRxConfiguration();
    DmaTxConfiguration();

    LCD_Position(1u,0u);

    
    I2S_1_EnableRx();

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

        /* Process button related events */
        ButtonProcess();

        if(0u != refreshRate)
        {
            refreshRate--;
        }
        else
        {
            refreshRate = USERIO_DISPLAY_REFRESH;

            /* Print out Tx and Rx data onto LCD */
            DisplayUpdate();

            /* If SW1 has been pressed, increment the first byte of Tx buffer */
            if(0u != buttonPressed)
            {
                txBuff[0u]++;
                buttonPressed = 0u;
            }
        }
    }
}


/*******************************************************************************
* Function Name: DmaRxConfiguration
********************************************************************************
*
* Summary:
*  Configures the DMA transfer for the Rx direction.
*   
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DmaRxConfiguration(void)
{
    /* Rx DMA Config
    * Init DMA, 1 byte bursts, each burst requires a request */
    rxDmaChan = RxDMA_DmaInitialize(RxDMA_BYTES_PER_BURST, RxDMA_REQUEST_PER_BURST,
                                     HI16(RxDMA_SRC_BASE), HI16(RxDMA_DST_BASE));

    rxDmaTd[0u] = CyDmaTdAllocate();
    /* Configure this Td as follows:
    *  - The TD is looping on itself
    *  - Increment the destination address, but not the source address
    */
    CyDmaTdSetConfiguration(rxDmaTd[0], BUFFER_SIZE, rxDmaTd[0u], TD_INC_DST_ADR);

    /* From the I2S to the memory */
    CyDmaTdSetAddress(rxDmaTd[0u], LO16((uint32)I2S_1_RX_CH0_F0_PTR), LO16((uint32)rxBuff));

    /* Associate the TD with the channel */
    CyDmaChSetInitialTd(rxDmaChan, rxDmaTd[0u]);

    /* Enable the channel */
    CyDmaChEnable(rxDmaChan, 1u);
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

/*******************************************************************************
*  Function Name: ButtonProcess
********************************************************************************
*
* Summary:
*	This function performs the button de-bouncing and event detection. 
*	Ideally this should be called on a regular basis that is acceptable for good
*	perceivable de-bounce performance. Just for general guidance, de-bounce 
*	should not be less than 25ms and not more than 100ms. Timings too short 
*	could lead to erroneous button events (i.e. failure to de-bounce), while 
*	too long a time could lead to a perceived poor human real-time response.  
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
static void ButtonProcess(void)
{
    static uint8 debounceCount = BUTTON_DEBOUNCE_COUNT_MAX;

	/* Scan for a button event and maintain a time for debounce */
	if (0u == SW1_Read())		/* pressed */
	{
		/* Decrement the SW1 debounce count until it reaches 0 */
		if (0u != debounceCount)
        {
            debounceCount--;
        }
        else
        {
            /* If the button was pressed for the debounce time, set the flag for
            * the button press */
            if(0u == debounceCount)
            {
                buttonPressed = 1u;
                debounceCount = BUTTON_DEBOUNCE_COUNT_MAX;
            }
        }
    }
}


/*******************************************************************************
*  Function Name: DisplayUpdate
********************************************************************************
*
* Summary:
*  This function prints out the Tx and Rx data onto the LCD.  
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
static void DisplayUpdate(void)
{
    uint8 idx;
    uint8 col;

    /* Set start position for data output */
    col = 4u; 
	for(idx = 0u; idx < BUFFER_SIZE; idx++)
    {
        LCD_Position(0u, col);
        LCD_PrintInt8(txBuff[idx]);
        LCD_Position(1u, col);
        LCD_PrintInt8(rxBuff[idx]);
        col += 3u;
    }
}


/* [] END OF FILE */
