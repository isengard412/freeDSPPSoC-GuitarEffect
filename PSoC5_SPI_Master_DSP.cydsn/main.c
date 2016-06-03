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
    //UARTsendString("DSP init......\r");
    DSPinit();
    //UARTsendString("done\n\r");
    //UARTsendString("DSP......\r");
    //if(DSPisReady()==1) UARTsendString("connected\n\r");
    //else UARTsendString("NOT connected\n\r");
    
    I2Sinit();
    NRF24L01init();
    
    DSPi2sInput(0);
    uint16 out;
    //uint32 pitch=0x00000000;
    
    for(;;)
    {
//        pitch=0x00155555;
//        DSPpitch(pitch);
//        CyDelay(500);
//        pitch=0xFFEAAAAB;
//        DSPpitch(pitch);
//        CyDelay(500);
        out = NRF24L01readReg(0x00);
        UARTsendNumber(out);
        CyDelay(500);
        


    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
