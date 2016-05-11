/*******************************************************************************
* File Name: main.c
*
* Version: 1
* Author: Lukas Creutzburg
*
* Description:
*  Guitar PSoC Code
*
*******************************************************************************/

#include "project.h"
#include "i2cmaster.h"

// DSP Libraries
#include "i2clib/EEPROM24.h"
#include "i2clib/I2CMASTER.h"
#include "i2clib/SoftI2C_mod.h"
#include "i2clib/ADAU1701.h"

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  Main function performs following functions:
*   1. Enable global interrupts.
*   2. Initialize CapSense, UART (Debug), I2C Interaction
*   3. Process scanning results and sending them
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
int main()
{
    // Initialise DSP Libraries
    SoftI2C     mI2C    (DSP_SDA, DSP_SCL);
    EEPROM24    mEprom  (mI2C, EEPROM_24LC256);
    ADAU1701    mDSP    (mI2C, DSP_ADDRESS);
    
    
    /* Enable global interrupts */
    CyGlobalIntEnable;
    
    uint8 command = CMD_SET_OFF;
    //int32 pos = 30000;
    uint8 i = 0; 
    uint8 direction =1; 
    
    I2CInit();

    while(1u)
    {
        
        // Beispiel Volume Control, i wechselt kontinuierlich zwischen 0 und 100

        /* Send packet with command to the slave */
        if (0u == I2CWriteCommandPacket(command))
        {
            /* Read response packet from the slave */
            if (0u == I2CReadStatusPacket())
            {
                 if (i == 100)
                { 
                    direction = 0;
                }
                else if (i == 0)
                {
                    direction = 1;
                }
                if (direction == 1)
                {
                    i=i+1;
                }
                else 
                {
                    i = i-1;
                }
                
                command = i;
                
                /* Next command to be written */
        /*        pos = CapSense_Refresh();
                if(pos!=-1){
                    UART_SendNumber((uint8)(((uint32)pos) >> 8));
                    command = (uint8)(((uint32)pos) >> 8);*/
            }
                
        }
            
    }

        LED_1_Write(!LED_1_Read());
        //CyDelay(CMD_TO_CMD_DELAY); /* Delay between commands */

}



/* [] END OF FILE */
