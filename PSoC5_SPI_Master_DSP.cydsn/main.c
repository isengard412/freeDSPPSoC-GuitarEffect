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

int32 pitch = 0;
int32 pitch_target = 0;

CY_ISR_PROTO(spi_rx_interrupt);


CY_ISR(SPI_Rx)
{
    /* Wert zwischen +-34953 */
    pitch_target = (int32)SPISreadNumber(0u);
    pitch_target = (pitch_target-130)*200;
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
    /* Enable Global interrupts */
    CyGlobalIntEnable;
    /* SPI Slave interrupt */
    spi_rx_interrupt_StartEx(SPI_Rx);
    spi_rx_interrupt_SetPriority(3u);
    /* Start DMA completion interrupt. */
    DmaDone_StartEx(&TxDmaDone);
    /* Initializing DSP */
    DSPinit();
    /* Activating I2S Communication */
    I2Sinit();
    /* Activatind PSoC Communication */
    SPISinit();
    /* Start USBFS Operation with 5V operation. */
    //USBFS_Start(USBFS_AUDIO_DEVICE, USBFS_5V_OPERATION);
    
    /***** Initialization completed *****/
    
    //generated input
    DSPInput(1);
    CyDelay(500);
    //i2s input
    //DSPInput(0);
    //analog input
    DSPInput(2);
    //set to no pitching
    DSPpitch(0u);

    
    for(;;)
    {
        //USBrefresh();
        if(pitch_target>pitch+0xF) pitch+=0x1;
        else
        { 
            if(pitch_target<pitch-0xF) pitch-=0x1;
            else pitch=pitch_target;
        }
        LED_Write(!LED_Read());
        DSPpitch(pitch_target);

    }  /* End of forever loop */
}  /* End of main */



/* [] END OF FILE */
