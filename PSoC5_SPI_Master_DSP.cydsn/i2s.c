/*******************************************************************************
* File Name: i2s.c
*
* Version: 0.0 
* Author: Lukas Creutzburg
*
* Description:
*   Interaction with DSP via I2S. Streaming from USB Sound Interface
*
* Copyright:
* Released under Creative Commons Attribution Share-Alike 4.0 license.This 
* allows for both personal and commercial derivative works, as long as they 
* credit freeDSP and release their designs under the same license. The freeDSP 
* brand and freeDSP logo are protected by copyright and cannot be used without 
* formal permission. Please contact Sebastian Merchel for further information.
* https://creativecommons.org/licenses/by-sa/4.0/legalcode
*
*
*******************************************************************************/

#include "i2s.h"

/* Circular buffer for audio stream. */
uint8 soundBuffer[BUFFER_SIZE];
volatile uint16 outIndex = 0u;
volatile uint16 inIndex  = 0u;

/* Variables used to manage DMA. */
volatile uint8 syncDma = 0u;
volatile uint8 syncDmaCounter = 0u;

/* Variable declarations for TxoutDMA. */
uint8 TxOutDmaCh;
uint8 TxOutDmaTd[NUM_OF_BUFFERS];

CY_ISR(TxDmaDone)
{
    /* Move to next buffer location and adjust to be within buffer size. */
    ++outIndex;
    outIndex = (outIndex >= NUM_OF_BUFFERS) ? 0u : outIndex;

    if (outIndex == inIndex)
    {
        /* Stop DMA operation. */
        CyDmaChDisable(TxOutDmaCh);

        /* Enable underflow delayed start. */
        syncDma = 0u;
        syncDmaCounter = 0u;
    }
}

void I2Sinit()
{
    I2S_1_Start();

    
    /* Configure DMA */ 
    DmaTxConfiguration();
    I2S_1_EnableTx();
}

void I2Stest()
{
//not yet implemented!
}


void DmaTxConfiguration(void)
{
    uint8 i;
    /* Initialize DMA channel. */
    TxOutDmaCh = TxDma_DmaInitialize(TX_DMA_BYTES_PER_BURST, TX_DMA_REQUEST_PER_BURST,
                                            HI16(TX_DMA_SRC_BASE), HI16(TX_DMA_DST_BASE));

    /* Allocate transfer descriptors for each buffer chunk. */
    for (i = 0u; i < NUM_OF_BUFFERS; ++i)
    {
        TxOutDmaTd[i] = CyDmaTdAllocate();
    }

    /* Configure DMA transfer descriptors. */
    for (i = 0u; i < (NUM_OF_BUFFERS - 1u); ++i)
    {
        /* Chain current and next DMA transfer descriptors to be in row. */
        CyDmaTdSetConfiguration(TxOutDmaTd[i], TRANSFER_SIZE, TxOutDmaTd[i + 1u],
                                TD_INC_SRC_ADR);
    }
    /* Chain last and 1st DMA transfer descriptors to make cyclic buffer. */
    CyDmaTdSetConfiguration(TxOutDmaTd[NUM_OF_BUFFERS - 1u], TRANSFER_SIZE, TxOutDmaTd[0u],
                                TD_INC_SRC_ADR);


    for (i = 0u; i < NUM_OF_BUFFERS; i++)
    {
        /* Set source and destination addresses. */
        CyDmaTdSetAddress(TxOutDmaTd[i], LO16((uint32) &soundBuffer[i * TRANSFER_SIZE]),
                                           LO16((uint32) I2S_1_TX_CH0_F0_PTR));
    }

    /* Set 1st transfer descriptor to execute. */
    CyDmaChSetInitialTd(TxOutDmaCh, TxOutDmaTd[0u]);
}

void USBrefresh()
{
    uint8 skipNextOut = 0u;
    /* Check if configuration or interface settings are changed. */
    if (0u != USBFS_IsConfigurationChanged())
    {
        /* Check active alternate setting. */
        if ((0u != USBFS_GetConfiguration()) &&
            (0u != USBFS_GetInterfaceSetting(AUDIO_INTERFACE)))
        {
            /* Alternate settings 1: Audio is streaming. */

            /* Reset variables. */
            inIndex  = 0u;
            outIndex = 0u;
            syncDma  = 0u;
            skipNextOut = 0u;
            syncDmaCounter = 0u;

            /* Enable OUT endpoint to receive audio stream. */
            USBFS_EnableOutEP(OUT_EP_NUM);
    }

    if (USBFS_OUT_BUFFER_FULL == USBFS_GetEPState(OUT_EP_NUM))
    {
        if (0u == skipNextOut)
        {
            /* Trigger DMA to copy data from OUT endpoint buffer. */
            USBFS_ReadOutEP(OUT_EP_NUM, &soundBuffer[inIndex * TRANSFER_SIZE],
                                        TRANSFER_SIZE);

            /* Wait until DMA completes copying data from OUT endpoint buffer. */
            while (USBFS_OUT_BUFFER_FULL == USBFS_GetEPState(OUT_EP_NUM))
            {
            }

            /* Move to the next buffer location and adjust to be within
            * buffer size. Lock from DmaDone interruption.
            */
            DmaDone_Disable();
            ++inIndex;
            inIndex = (inIndex >= NUM_OF_BUFFERS) ? 0u : inIndex;
            DmaDone_Enable();
            ++syncDmaCounter;

            /* Enable OUT endpoint to receive data from host. */
            USBFS_EnableOutEP(OUT_EP_NUM);
        }
        else
        {
            /* Ignore received data from host and arm OUT endpoint
            * without reading if overflow is detected.
            */
            USBFS_EnableOutEP(OUT_EP_NUM);
            skipNextOut = 0u;
        }

        /* When internal 32-kHz clock is slower, compare to PC traffic
        * then skip next transfer from PC.
        */
        if (outIndex == inIndex)
        {
            skipNextOut = 1u;
        }
    }

    /* Enable DMA transfers when sound buffer is half-full. */
    if ((0u == syncDma) && (syncDmaCounter == (NUM_OF_BUFFERS / 2u)))
    {
        /* Start DMA operation. */
        CyDmaChEnable(TxOutDmaCh, TX_DMA_ENABLE_PRESERVE_TD);

        /* Disable underflow delayed start. */
        syncDma = 1u;
    }
}
}



/* [] END OF FILE */
