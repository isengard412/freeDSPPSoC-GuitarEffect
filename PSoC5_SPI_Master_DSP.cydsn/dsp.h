/*******************************************************************************
* File Name: dsp.h
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Interaction with FreeDSP Insanity
*
*******************************************************************************/

#if !defined(CY_DSP_H)
#define CY_DSP_H

#include <project.h>
#include "stdio.h"
#include "spimaster.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

#define E2PROM_HEX_SIZE 544
#define CHIPADDRESS 0x00

#define VOLUME0_ADDR  0x0000 
#define VOLUME1_ADDR  0x0001

/*******************************************************************************
* Function Name: DSPinit
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
void DSPinit();

/*******************************************************************************
* Function Name: SPIsendNumber
********************************************************************************
*
* Summary:
*  Sending a Number via SPI as Master
*
* Parameters:
*  uint16 number
*
* Return:
*  None.
*
*******************************************************************************/
//void SPIsendNumber(uint16);

/*******************************************************************************
* Function Name: SPIsendArray
********************************************************************************
*
* Summary:
*  Sending an Array via SPI as Master
*
* Parameters:
*  uint8 numbers[]
*
* Return:
*  None.
*
*******************************************************************************/
//void SPIsendArray(uint16[]);

#endif /* (CY_DSP_H) */

/* [] END OF FILE */
