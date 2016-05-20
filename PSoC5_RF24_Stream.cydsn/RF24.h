/*******************************************************************************
* File Name: RF24.h
*
* Version: 0.0
* Author: Lukas Creutzburg
*
* Description:
*   Component controls RF24 transceiver
*
*******************************************************************************/

#if !defined(CY_RF24_H)
#define CY_RF24_H

#include <project.h>
#include "stdio.h"
#include "spimaster.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif


/*******************************************************************************
* Function Name: RF24init
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
void RF24init();

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
//void SPIsendNumber(uint8 number);

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
//void SPIsendArray(uint8* numbers,uint16 numberOfbytes);

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
//uint8 SPIreadNumber();

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
//uint8 SPIreadFinished();

#endif /* (CY_RF24_H) */

/* [] END OF FILE */
