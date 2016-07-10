/*******************************************************************************
* File Name: main.c
*
* Version: 2.0
*
* Description:
*  This USB example project implements a USB Audio Device that connects to the
*  PC via the USB interface. The USB Audio Device does not require a special
*  USB driver, because the USB Audio support is already built into Windows.
*  The device appears in the system as a mono speaker with 8-bit resolution and
*  a sample rate of 32 kHz.
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

/* UBSFS device constants. */
#define USBFS_AUDIO_DEVICE  (0u)
#define AUDIO_INTERFACE     (1u)
#define OUT_EP_NUM          (2u)

/* Audio buffer constants. */
#define TRANSFER_SIZE   (32u)
#define NUM_OF_BUFFERS  (10u)
#define BUFFER_SIZE     (TRANSFER_SIZE * NUM_OF_BUFFERS)

/* Circular buffer for audio stream. */
uint8 soundBuffer[BUFFER_SIZE];
volatile uint16 outIndex = 0u;
volatile uint16 inIndex  = 0u;

/* Variables used to manage DMA. */
volatile uint8 syncDma = 0u;
volatile uint8 syncDmaCounter = 0u;

/* Variable declarations for VDACoutDMA. */
uint8 VdacOutDmaCh;
uint8 VdacOutDmaTd[NUM_OF_BUFFERS];

/* DMA Configuration for VDACoutDMA (Memory to VDAC) */
#define VDAC_DMA_BYTES_PER_BURST    (1u)
#define VDAC_DMA_REQUEST_PER_BURST  (1u)
#define VDAC_DMA_TD_TERMOUT_EN      (VdacDma__TD_TERMOUT_EN)
#define VDAC_DMA_DST_BASE           (CYDEV_PERIPH_BASE)
#define VDAC_DMA_SRC_BASE           (CY_PSOC5LP) ? ((uint32) soundBuffer) : (CYDEV_SRAM_BASE)
#define VDAC_DMA_ENABLE_PRESERVE_TD (1u)

CY_ISR_PROTO(VdacDmaDone);

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*
*  The main function performs the following actions:
*   1. Initializes LCD and VDAC components.
*   2. Configures the DMA channel and transfers the descriptors.
*      The source is souundBuffer (SRAM) and the destination is the VDAC data register.
*   3. Starts the USBFS component and waits until the device is got enumerated
*      by the host.
*   4. When the PC starts streaming, the DMA starts copying data into the VDAC with
*      the 32-kHz frequency. None of the synchronization methods is implemented:
*      If the PC (source) transfers data faster than the device (sink), transfers it  ????
*      to VDAC the extra samples are dropped.
*      If the PC (source) transfers data slower than the device (sink), transfers it  ????
*      to VDAC the transfer is stopped and starts after the buffer is half-full.
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
    uint8 skipNextOut = 0u;

    /* Start LCD display for indication. */
    LCD_Start();
    LCD_PrintString("USB->DMA->DAC");

    /* Start VDAC8 to generate output wave. */
    VDAC8_Start();

    /* Initialize DMA channel. */
    VdacOutDmaCh = VdacDma_DmaInitialize(VDAC_DMA_BYTES_PER_BURST, VDAC_DMA_REQUEST_PER_BURST,
                                            HI16(VDAC_DMA_SRC_BASE), HI16(VDAC_DMA_DST_BASE));

    /* Allocate transfer descriptors for each buffer chunk. */
    for (i = 0u; i < NUM_OF_BUFFERS; ++i)
    {
        VdacOutDmaTd[i] = CyDmaTdAllocate();
    }

    /* Configure DMA transfer descriptors. */
    for (i = 0u; i < (NUM_OF_BUFFERS - 1u); ++i)
    {
        /* Chain current and next DMA transfer descriptors to be in row. */
        CyDmaTdSetConfiguration(VdacOutDmaTd[i], TRANSFER_SIZE, VdacOutDmaTd[i + 1u],
                                (TD_INC_SRC_ADR | VDAC_DMA_TD_TERMOUT_EN));
    }
    /* Chain last and 1st DMA transfer descriptors to make cyclic buffer. */
    CyDmaTdSetConfiguration(VdacOutDmaTd[NUM_OF_BUFFERS - 1u], TRANSFER_SIZE, VdacOutDmaTd[0u],
                                (TD_INC_SRC_ADR | VDAC_DMA_TD_TERMOUT_EN));


    for (i = 0u; i < NUM_OF_BUFFERS; i++)
    {
        /* Set source and destination addresses. */
        CyDmaTdSetAddress(VdacOutDmaTd[i], LO16((uint32) &soundBuffer[i * TRANSFER_SIZE]),
                                           LO16((uint32) VDAC8_Data_PTR));
    }

    /* Set 1st transfer descriptor to execute. */
    CyDmaChSetInitialTd(VdacOutDmaCh, VdacOutDmaTd[0u]);

    /* Start DMA completion interrupt. */
    DmaDone_StartEx(&VdacDmaDone);

    CyGlobalIntEnable;

    /* Start USBFS Operation with 5V operation. */
    USBFS_Start(USBFS_AUDIO_DEVICE, USBFS_5V_OPERATION);

    /* Wait for device enumeration. */
    while (0u == USBFS_GetConfiguration())
    {
    }

    for(;;)
    {
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
            CyDmaChEnable(VdacOutDmaCh, VDAC_DMA_ENABLE_PRESERVE_TD);

            /* Disable underflow delayed start. */
            syncDma = 1u;
        }
    }
}


/*******************************************************************************
* Function Name: VdacDmaDone
********************************************************************************
*
* Summary:
*  The Interrupt Service Routine for a DMA transfer completion event. The DMA is
*  stopped when there is no data to send.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(VdacDmaDone)
{
    /* Move to next buffer location and adjust to be within buffer size. */
    ++outIndex;
    outIndex = (outIndex >= NUM_OF_BUFFERS) ? 0u : outIndex;

    /* When there is no data to transfer to VDAC stop DMA and wait until
	* buffer is half-full to continue operation.
    */
    if (outIndex == inIndex)
    {
        /* Stop DMA operation. */
        CyDmaChDisable(VdacOutDmaCh);

        /* Enable underflow delayed start. */
        syncDma = 0u;
        syncDmaCounter = 0u;
    }
}


/* [] END OF FILE */
