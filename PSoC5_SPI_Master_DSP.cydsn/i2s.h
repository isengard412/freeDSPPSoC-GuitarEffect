/*******************************************************************************
* File Name: i2s.h
*
* Version: 0.0
* Author: Lukas Creutzburg
*
* Description:
*   Interaction with FreeDSP Insanity
*
* Copyright:
* Released under Creative Commons Attribution Share-Alike 4.0 license.This 
* allows for both personal and commercial derivative works, as long as they 
* credit freeDSP and release their designs under the same license. The freeDSP 
* brand and freeDSP logo are protected by copyright and cannot be used without 
* formal permission. Please contact Sebastian Merchel for further information.
* https://creativecommons.org/licenses/by-sa/4.0/legalcode
*
*******************************************************************************/

#if !defined(CY_I2S_H)
#define CY_I2S_H

#include <project.h>
#include "dsp.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

/* UBSFS device constants. */
#define USBFS_AUDIO_DEVICE          (0u)
#define AUDIO_INTERFACE             (1u)
#define OUT_EP_NUM                  (2u)

/* Audio buffer constants. */
#define TRANSFER_SIZE   (48u)
#define NUM_OF_BUFFERS  (10u)
#define BUFFER_SIZE     (TRANSFER_SIZE * NUM_OF_BUFFERS)

/* DMA Configuration for VDACoutDMA (Memory to VDAC) */
#define TX_DMA_BYTES_PER_BURST    (1u)
#define TX_DMA_REQUEST_PER_BURST  (1u)
#define TX_DMA_DST_BASE           (CYDEV_PERIPH_BASE)
#define TX_DMA_SRC_BASE           (CY_PSOC5LP) ? ((uint32) soundBuffer) : (CYDEV_SRAM_BASE)
#define TX_DMA_ENABLE_PRESERVE_TD (1u)

CY_ISR_PROTO(TxDmaDone);



/*******************************************************************************
* Function Name: I2Sinit
********************************************************************************
*
* Summary:
*  Initialize communication
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void I2Sinit();
void I2Stest();

void DmaTxConfiguration(void);
void USBrefresh();
CY_ISR(TxDmaDone);

#endif /* (CY_I2S_H) */

/* [] END OF FILE */
