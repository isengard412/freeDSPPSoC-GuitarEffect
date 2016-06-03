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
    UARTsendString("done\n\r");
    UARTsendString("DSP......\r");
    
    NRF24L01init();
    

    
    for(;;)
    {
        UARTsendNumber(NRF24L01GetReg(STATUS));
        CyDelay(500);
        


    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
