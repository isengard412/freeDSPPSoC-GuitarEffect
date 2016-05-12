/*******************************************************************************
* File Name: uart.h
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via UART
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
