/*******************************************************************************
* File Name: spimaster.h
*
* Version: 1.1
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via SPI as Master
*   Can send arrays
*
*******************************************************************************/

#if !defined(CY_SPIMASTER_H)
#define CY_SPIMASTER_H

#include <project.h>
#include "stdio.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif


#define RD_BUFFER_LEN           (64u)
#define WR_BUFFER_LEN           (64u)

/* ASCII value of decimal zero is 48 */
#define ASCII_DECIMAL_ZERO      (48u)

/* Any value above 0x07 is an illegal input for mux channel selection */
#define ERROR_MASK              (0xF8u)

uint8 wrBuffer[WR_BUFFER_LEN];
uint8 temp;

/*******************************************************************************
* Function Name: main
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
void SPIinit();

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
void SPIsendNumber(uint16);

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
void SPIsendArray(uint16[]);

#endif /* (CY_SPIMASTER_H) */

/* [] END OF FILE */
