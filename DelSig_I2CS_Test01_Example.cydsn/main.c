/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is the test project for the 8-ch DelSig ADC and I2C Slave Example 
*  project.
*  
* Parameters used:
*  I2C Master
*   Implementation		Fixed function
*   Data rate			100kbps
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
#define RD_BUFFER_SIZE		(2u)
/* The I2C Slave address by default in a PSoC device is 8 */
#define I2C_SLAVE_ADDRESS	(8u)

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Main function performs following functions:
*   1. Starts used components.
*   2. Reads slave data buffer.
*   3. Displays this data on Character LCD.
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
	/* Allocate 2 bytes to store data read from I2C slave */
	uint8 rdBuf[RD_BUFFER_SIZE];
	
	/* Temporary variable */
	uint8 temp = 0u;

	/* Start I2C Master and Character LCD */
	I2CM_Start();
	LCD_Char_Start();

	/* Enable Global Interrupts - needed for I2C operation */
	CyGlobalIntEnable;

	for(;;)
    {
		/* Attempt to initiate communication with the slave until the function 
		 * completes without error. 
		 */
		do
		{
			/* The syntax below automatically reads a buffer of data from a 
		     * slave device from start to stop. 
		 	 */
			temp = I2CM_MasterReadBuf(I2C_SLAVE_ADDRESS, rdBuf, 
										RD_BUFFER_SIZE, I2CM_MODE_COMPLETE_XFER);
		}
		while (temp != I2CM_MSTR_NO_ERROR);
		
		/* Wait for the data transfer to complete */
		while(I2CM_MasterStatus() & I2CM_MSTAT_XFER_INP);

		temp = I2CM_MasterGetReadBufSize();
		
		LCD_Char_ClearDisplay();

		if(temp == RD_BUFFER_SIZE)
		{
			LCD_Char_PrintString("0x");
			LCD_Char_PrintInt8(rdBuf[0]);
			LCD_Char_PrintInt8(rdBuf[1]);
		}
		else /* Indicate the Error and place your error handling code here */
		{
			LCD_Char_PrintString("I2C Error!");
			I2CM_MasterClearStatus();
		}

		/* This delay is present to facilitate easy reading of the Character LCD */
		CyDelay(2000u/*ms*/);	
		
	} /* End forever loop */
} /* End main */


/* [] END OF FILE */
