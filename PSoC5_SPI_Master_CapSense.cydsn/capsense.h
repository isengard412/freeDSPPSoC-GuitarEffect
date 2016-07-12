/* ========================================
* File Name: capsense.h
*
* Version: 1.0
* Author: Lukas Creutzburg
*
*  Description:
*  CapSense module
*
* Copyright:
* Released under Creative Commons Attribution Share-Alike 4.0 license.This 
* allows for both personal and commercial derivative works, as long as they 
* credit freeDSP and release their designs under the same license. The freeDSP 
* brand and freeDSP logo are protected by copyright and cannot be used without 
* formal permission. Please contact Sebastian Merchel for further information.
* https://creativecommons.org/licenses/by-sa/4.0/legalcode
*
* ===========================================================================================================
*/
#ifndef __capsense_H
#define __capsense_H
	
#include <project.h>
#include "uart.h"
#include "spimaster.h"


/*******************************************************************************
* Function Name:  CapSenseInit
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
void CapSenseInit(void);


/*******************************************************************************
* Function Name: CapSense_DisplayState
********************************************************************************
*
* Summary:
*  Get current CapSense State
*
* Parameters:  
*   None
* Return: 
*   uint32: Position on slider
*
*******************************************************************************/
int16 CapSense_DisplayState(void);


/*******************************************************************************
* Function Name: CapSense_Refresh
********************************************************************************
*
* Summary:
*  Refresh CapSense
*
* Parameters:  
*   None
* Return: 
*   uint32: Position on slider
*
*******************************************************************************/
int32 CapSense_Refresh(void);

/*******************************************************************************
* Function Name: CapSense_ButtonX
********************************************************************************
*
* Summary:
*  Interaktion if ButtonX pressed
*
* Parameters:  
*   None
* Return: 
*   None
*
*******************************************************************************/
void CapSense_Button0(void);
void CapSense_Button1(void);
void CapSense_Button2(void);

#endif

//[] END OF FILE