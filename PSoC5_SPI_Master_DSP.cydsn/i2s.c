/*******************************************************************************
* File Name: i2s.c
*
* Version: 0.0 
* Author: Lukas Creutzburg
*
* Description:
*   Interaction with DSP via I2S
*
*
*******************************************************************************/

#include "i2s.h"

/* Data to be transmitted by Tx */
uint32 txBuff[BUFFER_SIZE];

/* Variable declarations for TxDMA */
uint32 txDmaChan;
uint32 txDmaTd[1u];


void I2Sinit()
{
    int i;
    for(i=0;i<255;i++){
        txBuff[i]=(uint32)(0xFFFFFFFF);
    }
    for(i=255;i<496;i++){
        txBuff[i]=(uint32)(0x00000000);
    }
    I2S_1_Start();
    I2S_1_EnableTx();
    
    /* Configure DMA */ 
    DmaTxConfiguration();
    
    while(0u != (I2S_1_ReadTxStatus() & I2S_1_TX_FIFO_0_NOT_FULL))
    {
        /* Wait for TxDMA to fill Tx FIFO */
    }
    CyDelayUs(1);
    I2S_1_EnableTx();   /* Enable Tx direction */
}

void I2Stest()
{
    //CyDelay(500);
    //DSPi2sInput(0);
    CyDelay(500);
    //DSPi2sInput(1);
}


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
