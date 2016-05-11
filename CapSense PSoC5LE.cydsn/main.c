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
#include "capsense.h"
#include "uart.h"
#include "i2cmaster.h"


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
    /* Enable global interrupts */
    CyGlobalIntEnable;
    
    uint8 command = CMD_SET_OFF;
    int32 pos = 30000;
    
    UARTInit();
    CapSenseInit();
    I2CInit();

    while(1u)
    {
        
        /* Send packet with command to the slave */
        if (0u == I2CWriteCommandPacket(command))
        {
            /* Read response packet from the slave */
            if (0u == I2CReadStatusPacket())
            {
                /* Next command to be written */
                pos = CapSense_Refresh();
                if(pos!=-1){
                    UART_SendNumber((uint8)(((uint32)pos) >> 8));
                    command = (uint8)(((uint32)pos) >> 8);
                }
                
            }
            
        }

        LED_1_Write(!LED_1_Read());
        //CyDelay(CMD_TO_CMD_DELAY); /* Delay between commands */
    }
}



/* [] END OF FILE */
