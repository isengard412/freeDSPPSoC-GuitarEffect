/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*  Interaction with DSP
*
* Copyright:
* Released under Creative Commons Attribution Share-Alike 4.0 license.This 
* allows for both personal and commercial derivative works, as long as they 
* credit freeDSP and release their designs under the same license. The freeDSP 
* brand and freeDSP logo are protected by copyright and cannot be used without 
* formal permission. Please contact Sebastian Merchel for further information.
* https://creativecommons.org/licenses/by-sa/4.0/legalcode
*
*******************************************************************************/

#include "main.h"

int32 pitch = 0;
int32 pitch_target = 0;
int32 cache = 0x4;

CY_ISR_PROTO(spi_rx_interrupt);


CY_ISR(SPI_Rx)
{
    
    cache = (int32)SPISreadNumber(0u);
    
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
        if(cache>0x3) 
        {
            pitch_target=cache;
            /* Wert zwischen +-34953 */
            pitch_target = (pitch_target-113)*200;
        }
        else
        {
            DSPInput((uint32)cache);
            cache = 130;
        }
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
