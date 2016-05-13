/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*  Interaction with DSP
*
*******************************************************************************/

#include "main.h"



/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main() sends things via SPI and UART simmultaniously
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
    uint16 value[2];
    value[0] = 0xAABB;
    value[1] = 0xCCDD;


    /* Enable Global interrupts - used for USB communication */
    CyGlobalIntEnable;

    DSPinit();
    UARTinit();

    for(;;)
    {
        //PrintToUSBUART("Please choose the channel (0-7) \n\r");
        UARTsendString("Now sending via SPI\n\r");

        SPIsendArray(value);
        
        sprintf((char *)wrBuffer, "The value is: 0x%4x und 0x%4x \n\r\n\r", value[0], value[1]);
        UARTsendString((char8 *)wrBuffer);
        CyDelay(500);
        
        

    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
