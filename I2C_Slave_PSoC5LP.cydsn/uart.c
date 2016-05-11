/* ========================================
* File Name: capsense.h
*
* Version: 0
* Author: Lukas Creutzburg
*
*  Description:
*  CapSense module
*
* ===========================================================================================================
*/
#include "uart.h"

/* Variables */

//_________________________________

/*******************************************************************************
* Function Name:  UARTInit
********************************************************************************
*
* Summary:
*   Initializes CapSense  
*
* Parameters:  
*  None
*
* Return: 
*  None 
*  
*******************************************************************************/
void UARTInit(void)
{
    UART_1_Start();
}
//_________________________________________________________________


/*******************************************************************************
* Function Name: UART_SendNumber
********************************************************************************
*
* Summary:
*  Sends number via UART
*
* Parameters:  
*   uint32: number to send
* Return: 
*   None
*
*******************************************************************************/
void UART_SendNumber(uint32 number)
{
    int bytesWritten; 
    char myString[50]; 
    bytesWritten = sprintf(myString, "%lu", number); 
    myString[bytesWritten]='\r';
    myString[bytesWritten+1]='\n';
    myString[bytesWritten+2]='\0';
    UART_1_PutString(myString);
}
//_________________________________________________________________


/*******************************************************************************
* Function Name: UART_SendString
********************************************************************************
*
* Summary:
*  Sends string via UART
*
* Parameters:  
*   char[]: String
* Return: 
*   None
*
*******************************************************************************/
void UART_SendString(char string[])
{
    UART_1_PutString(string);
}
//_________________________________________________________________

//[] END OF FILE
