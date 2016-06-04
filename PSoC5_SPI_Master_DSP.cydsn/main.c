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

/* receive interrupt */
CY_ISR(IRQ_handler)
{
    LED_Write(1);
    uint8 target[32];
    NRF24L01readRXpayload(32,&target[0]);
    CyDelay(500);
    LED_Write(0);
    int i;
    for(i=0;i<32;i++)
    {
        UARTsendNumber(target[i]);
    }
    
}

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
    /* Configuring IRQ RX interrupt */
    Funk_RX_interrupt_StartEx(IRQ_handler);
    Funk_RX_interrupt_SetPriority(3u);
    Funk_RX_interrupt_Stop();
    /* Enable Global interrupts */
    CyGlobalIntEnable;
    /*Activating UART */
    UARTinit();
    /* Initializing DSP */
    DSPinit();
    /* Activating I2S Communication */
    I2Sinit();
    /* Activating RX transciver */
    NRF24L01initRX();
    Funk_RX_interrupt_Start();
    
    
    
    /***** Initialization completed *****/
    
    DSPi2sInput(0);
    //uint16 out;
    //uint32 pitch=0x00000000;
    
    for(;;)
    {
//        pitch=0x00155555;
//        DSPpitch(pitch);
//        CyDelay(500);
//        pitch=0xFFEAAAAB;
//        DSPpitch(pitch);
        CyDelay(500);
        UARTsendString("bla");
        
        


    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
