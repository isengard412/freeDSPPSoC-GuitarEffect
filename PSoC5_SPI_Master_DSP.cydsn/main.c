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

uint8 slew[4] = {0x00,0x00,0x20,0x8A};
uint8 volumereg[8] = {0x00,0x00,0x00,0x26, 0x00, 0x00, 0x00, 0x01};
uint8 volumetosend[4] = {};


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

    /* Enable Global interrupts - used for USB communication */
    CyGlobalIntEnable;

    UARTinit();
    UARTsendString("DSP init......\r");
    DSPinit();
    UARTsendString("done\n\r");
    UARTsendString("DSP......\r");
    if(DSPisReady()==1) UARTsendString("connected\n\r");
    else UARTsendString("NOT connected\n\r");

    for(;;)
    {
        uint8 volume;
        for(volume=50;volume<0x80;volume++)
        {
            //Block Write Slew Mode
            DSPwrite(0x0027,&slew[0],4);
            //Safeload
            //Data to 0x0014
            volumetosend[0]=(volume>>7);
            volumetosend[1]=(volume<<1);
            volumetosend[2]=0x00;
            volumetosend[3]=0x00;
            DSPwrite(0x0027,&volumetosend[0],4);
            //Register to write into
            DSPwrite(0x0019,&volumereg[0],8);         
            
            sprintf((char *)wrBuffer, "Volume: %i\n\r", volume);
            UARTsendString((char8 *)wrBuffer);
            CyDelay(20);
        }
        
        
        
        

    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
