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

uint8 TX_textpayload[32] = {0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11};

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
    /* Activating RX transciver */
    NRF24L01initTX();
    Funk_RX_interrupt_Start();
    
    VDAC8_1_Start();
    CapSenseInit();
    /***** Initialization completed *****/
    
    int32 pos = 30000;
    
    for(;;)
    {

        CyDelay(50);
        NRF24L01writeTXpayload(32,&TX_textpayload[0]);
        LED_Write(!LED_Read());
        /* Next command to be written */
        pos = CapSense_Refresh();
        if(pos!=-1){
            UARTsendNumber((uint8)(((uint32)pos) >> 0));
        }
        
        


    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
