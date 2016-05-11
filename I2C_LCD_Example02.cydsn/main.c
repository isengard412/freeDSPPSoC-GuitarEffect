/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is source code for the datasheet example of the I2C LCD component.
*   
* Related Document:
*  PCF2119x LCD controllers/drivers
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>


#define NUM_CUSTOM_CHARS       (8u)
#define LCD_MODULE_ADDRESS     (0x74u)

#define NORMAL_STATE           (0u)
#define FLIPPED_STATE          (1u)

#define ROW_ZERO               (0u)
#define ROW_ONE                (1u)
#define COLUMN_ZERO            (0u)

CY_ISR_PROTO(FlipLcdIsr);


/**********************************************************************  
* Array with IDs of custom characters. The constants are defined by the 
* I2C LCD component.
**********************************************************************/
char8 string[] = {I2C_LCD_CUSTOM_0, I2C_LCD_CUSTOM_1, I2C_LCD_CUSTOM_2, I2C_LCD_CUSTOM_3, 
                  I2C_LCD_CUSTOM_4, I2C_LCD_CUSTOM_5, I2C_LCD_CUSTOM_6, I2C_LCD_CUSTOM_7};

/* Stores state of display */
volatile uint8 lcdState = NORMAL_STATE;

/*******************************************************************************
* Function Name: WakeupIsr
********************************************************************************
* Summary:
*  Changes the state of the display.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(FlipLcdIsr)
{
    /***********************************************************************
    * Analyze the display state and change the variable value to opposite
    * the actual flipping will occur in main loop.
    ***********************************************************************/
    if(NORMAL_STATE == lcdState)
    {
        lcdState = FLIPPED_STATE;
    }
    else
    {
        lcdState = NORMAL_STATE;
    }
    
    /* Some delay to avoid "multiple" button press at one time */
    CyDelay(200u);
    
    /* Clear interrupt flag for this port */
    Button_ClearInterrupt();
}


/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  Demonstrate some of the functionality of I2C LCD.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
int main(void)
{
    uint8 i;
    
    /********************************************************************** 
    * Interrupts should be enabled as the I2C Master uses interrupt to
    * transfer data.
    **********************************************************************/
    CyGlobalIntEnable;
    
    /* ISR initialization */
    Button_Isr_StartEx(FlipLcdIsr);
    
    /* Required 1 ms reset pulse for LCD Module */
    LCD_RST_Write(1u);
    CyDelay(1u);
    LCD_RST_Write(0u);
    
    /*********************************************************************** 
    * I2C LCD component doesn't start the I2C master but it should be
    * enabled for I2C LCD operation.
    ***********************************************************************/
    I2C_M_Start();
    
    /***********************************************************************
    * Start the component. It also loads the custom font which is specified 
    * in the customizer.
    ***********************************************************************/
    I2C_LCD_Start();
    
    /* Delay prior of printing custom characters */
    CyDelay(1000u);
    
    /***********************************************************************
    * Following code will print the eight custom characters in the first row 
    * of the LCD. The data is displayed using I2C_LCD_WriteData().
    ***********************************************************************/
    /* Set position to the start of the first row of the LCD module */
    I2C_LCD_Position(ROW_ZERO, COLUMN_ZERO);
    
    for(i = 0u; i < NUM_CUSTOM_CHARS; i++)
    {
        /* Display custom character specified by 'i' */
        I2C_LCD_WriteData(string[i]);
    }
    
    /***********************************************************************
    * Following code will print the eight custom characters in the second 
    * row of the LCD. The data is displayed using I2C_LCD_PrintString().
    * This is more efficient way of displaying data as the data is sent with 
    * one transaction comparing to eight transaction done with 
    * I2C_LCD_WriteData().
    ***********************************************************************/
    /* Set position to start of second row of LCD module */
    I2C_LCD_Position(ROW_ONE, COLUMN_ZERO);
    
    /* Display entire string of custom characters */
    I2C_LCD_PrintString("Cypress!");
    
    /***********************************************************************
    * Select Basic + Extended instruction(functions). This allows using
    * extended functionality like display flipping. 
    * 
    * Each function in I2C LCD component has an address macro and 
    * the I2C_LCD_AddrSelectExtendedFuncs() is an example of address macro 
    * usage.
    ***********************************************************************/
    I2C_LCD_AddrSelectExtendedFuncs(LCD_MODULE_ADDRESS);
    
    while(1u)
    {
        /* Analyze LCD state variable and set state appropriately */
        if(NORMAL_STATE == lcdState)
        {
            I2C_LCD_SetTopToBottom();
        }
        else
        {
            I2C_LCD_SetBottomToTop();
        }
    }
}

/* [] END OF FILE */

