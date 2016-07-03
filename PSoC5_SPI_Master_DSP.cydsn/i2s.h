/*******************************************************************************
* File Name: i2s.h
*
* Version: 0.0
* Author: Lukas Creutzburg
*
* Description:
*   Interaction with FreeDSP Insanity
*
*******************************************************************************/

#if !defined(CY_I2S_H)
#define CY_I2S_H

#include <project.h>
#include "dsp.h" //remove later!

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

#define BUFFER_SIZE                 (496u)//(248u)

/* DMA Configuration for TxDMA */
#define TxDMA_BYTES_PER_BURST       (1u)
#define TxDMA_REQUEST_PER_BURST     (1u)
#define TxDMA_SRC_BASE              (CYDEV_SRAM_BASE)
#define TxDMA_DST_BASE              (CYDEV_PERIPH_BASE)





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

#endif /* (CY_I2S_H) */

/* [] END OF FILE */
