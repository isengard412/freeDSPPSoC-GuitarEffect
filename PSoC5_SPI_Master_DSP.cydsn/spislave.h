/*******************************************************************************
* File Name: spimaster.h
*
* Version: 1.2
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via SPI as Master
*   Can send arrays
*
*******************************************************************************/

#if !defined(CY_SPISLAVE_H)
#define CY_SPISLAVE_H

#include <project.h>
#include "stdio.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif


#define S_RD_BUFFER_LEN           (64u)
#define S_WR_BUFFER_LEN           (64u)

/* ASCII value of decimal zero is 48 */
#define S_ASCII_DECIMAL_ZERO      (48u)

/* Any value above 0x07 is an illegal input for mux channel selection */
#define S_ERROR_MASK              (0xF8u)

uint8 S_wrBuffer[S_WR_BUFFER_LEN];
uint8 S_temp;

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
void SPISinit();

/*******************************************************************************
* Function Name: SPIsendNumber
********************************************************************************
*
* Summary:
*  Sending a Number via SPI as Master
*
* Parameters:
*  uint8 number
*
* Return:
*  None.
*
*******************************************************************************/
void SPISsendNumber(uint8 number);

/*******************************************************************************
* Function Name: SPIsendArray
********************************************************************************
*
* Summary:
*  Sending an Array via SPI as Master
*
* Parameters:
*  uint32 numbers[]
*
* Return:
*  None.
*
*******************************************************************************/
void SPISsendArray(uint8* numbers,uint16 numberOfbytes);

/*******************************************************************************
* Function Name: SPIreadNumber
********************************************************************************
*
* Summary:
*  Receiving a Number via SPI as Master
*
* Parameters:
*  None
*
* Return:
*  uint8 received
*
*******************************************************************************/
uint8 SPISreadNumber();

/*******************************************************************************
* Function Name: SPIreadFinished
********************************************************************************
*
* Summary:
*  Returning the RX buffersize
*
* Parameters:
*  None
*
* Return:
*  uint8 buffer
*
*******************************************************************************/
uint8 SPISreadFinished();

#endif /* (CY_SPISLAVE_H) */

/* [] END OF FILE */
