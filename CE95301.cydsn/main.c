/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is the test project for the 8-ch DelSig ADC and I2C master example   
*  project.
*  
* Parameters used:
*  I2C slave
*	Address				8
*   Implementation		Fixed function
*   Data rate			100kbps
*	Address decode		Hardware
*   SDA SCL config     	Open drain, drives low
*   Pull-up resistors	2.67k each 
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

/* Set the write buffer length to be 16 bits or 2 bytes */
#define WR_BUFFER_SIZE		(2u)

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  Main function performs following functions:
*   1. Starts used components.
*   2. Waits for, then receives data sent by I2C master.
*   3. Displays this data on Character LCD.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void main()
{
	uint8 wrBuf[WR_BUFFER_SIZE];
	uint8 byteCount = 0u;

	/* Set up the write buffer for the I2C Slave */
	I2CS_SlaveInitWriteBuf((uint8 *) wrBuf, WR_BUFFER_SIZE);
	
	I2CS_Start();

	/* The LCD will display the values read from ADC in hex */
	LCD_Char_Start();
	
	/* Enable global interrupts - required for I2C */
	CyGlobalIntEnable;
	
    for(;;)
    {
	    /* Check if the write from the master is complete */
		if(I2CS_SlaveStatus() & I2CS_SSTAT_WR_CMPLT)
		{
			byteCount = I2CS_SlaveGetWriteBufSize();
		
			I2CS_SlaveClearWriteStatus();
			I2CS_SlaveClearWriteBuf();
			
			/* If both bytes are received from master, display on LCD */
			if(byteCount == WR_BUFFER_SIZE)
			{
				/* Read and display received data on the LCD and verify this is same as
				 * sent by master. 
				 */
				LCD_Char_ClearDisplay();
				LCD_Char_PrintString("0x");
				LCD_Char_PrintInt8(wrBuf[0]);
				LCD_Char_PrintInt8(wrBuf[1]);
			}
			
			else /* Wrong number of bytes read */
			{
				/*  Indicate a read error and wait for next read */
				LCD_Char_ClearDisplay();
				LCD_Char_PrintString("I2C Error! ");
				/* Place error handling code here */
			}
		}
    } /* End forever loop */
} /* End main */


/* [] END OF FILE */
