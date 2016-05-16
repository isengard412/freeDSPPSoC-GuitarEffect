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
        int volume;
        for(volume=50;volume<100;volume++)
        {
            //TODO Setzen des Volume Wertes im DSP
            
            sprintf((char *)wrBuffer, "Volume: %i\n\r", volume);
            UARTsendString((char8 *)wrBuffer);
            CyDelay(250);
        }
        
        
        
        

    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
