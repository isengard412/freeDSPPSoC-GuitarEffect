/*******************************************************************************
* File Name: uart.h
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via UART
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

#if !defined(CY_UART_H)
#define CY_UART_H

#include <project.h>
#include "stdio.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow usage of the floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

#define USBFS_DEVICE    (0u)

/* The buffer size is equal to the maximum packet size of the IN and OUT bulk
* endpoints.
*/
#define USBUART_BUFFER_SIZE (64u)
#define LINE_STR_LENGTH     (20u)


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
void UARTinit();

/*******************************************************************************
* Function Name: UARTsendString
********************************************************************************
*
* Summary:
*  Sending a string via UART
*
* Parameters:
*  char string[]
*
* Return:
*  None.
*
*******************************************************************************/
void UARTsendString(char[]);

/*******************************************************************************
* Function Name: UARTsendNumber
********************************************************************************
*
* Summary:
*  Sending a number via UART
*
* Parameters:
*  char string[]
*
* Return:
*  None.
*
*******************************************************************************/
void UARTsendNumber(uint32 number);

#endif /* (CY_UART_H) */

/* [] END OF FILE */
