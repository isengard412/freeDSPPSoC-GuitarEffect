/********************************************************************************
* File Name: main.c
*
* Version : 1.00
*
* Description: 
*  This is a source code for example project of 16 bit Timer UDB Block.
*
* Test Result:
*  Watch capture output on P0_0, tc output on P0_1, and Period, Compare and 
*  Count value on LCD.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/
#include <device.h>

uint8 InterruptCnt;


/*******************************************************************************
* Define Interrupt service routine and allocate an vector to the Interrupt
********************************************************************************/
CY_ISR(InterruptHandler)
{
	/* Read Status register in order to clear the sticky Terminal Count (TC) bit 
	 * in the status register. Note that the function is not called, but rather 
	 * the status is read directly.
	 */
   	Timer_1_STATUS;
    
	/* Increment the Counter to indicate the keep track of the number of 
     * interrupts received */
    InterruptCnt++;    
}


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
* Main function performs following functions:
* 1: Enables the clock
* 2: Start the Timer
* 3: Initializes the LCD
* 4: Print Period, capture, counter value on LCD
* 
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{   
    /* Enable the global interrupt */
    CyGlobalIntEnable;
    
    /* Enable the Interrupt component connected to Timer interrupt */
    TimerISR_StartEx(InterruptHandler);

	/* Start the components */
    Timer_1_Start();

    /* Display TMR-16 on LCD */
    LCD_Start();
    LCD_Position(0u, 0u);
    LCD_PrintString("TMR-16"); 

    for(;;)
    {
        /* To display Period on LCD */
        LCD_Position(0u, 7u);
        LCD_PrintInt16(Timer_1_ReadPeriod());

        /* To display Capture value on LCD */
        LCD_Position(0u, 12u);
        LCD_PrintInt16(Timer_1_ReadCapture());

        /* To display count on LCD */
        LCD_Position(1u, 0u);
        LCD_PrintInt16(Timer_1_ReadCounter());

        /* To display Interrupt count on LCD */
        LCD_Position(1u, 5u);
        LCD_PrintString("IntCnt:");
        LCD_PrintInt16(InterruptCnt);
		
		CyDelay(100u);
    }
}


/* [] END OF FILE */
