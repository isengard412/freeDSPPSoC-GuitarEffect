/* ========================================
* File Name: uart.h
*
* Version: 0
* Author: Lukas Creutzburg
*
*  Description:
*  UART interaction
*
* ===========================================================================================================
*/
#ifndef __uart_H
#define __uart_H
	
#include "project.h"
#include <stdio.h>


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
void UARTInit(void);


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
void UART_SendNumber(uint32 number);


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
void UART_SendString(char[]);

#endif

//[] END OF FILE