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
CY_ISR_PROTO(timeout_interrupt);


CY_ISR(SPI_Rx)
{
    
    cache = (int32)SPISreadNumber(0u);
    Timeout_timer_Start();
    Timeout_timer_WriteCounter(255);
    LED_Write(!LED_Read());
}
CY_ISR(Timeout_inter)
{
    Timeout_timer_STATUS;
    Timeout_timer_Stop();
    cache=130;
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
    /* Activatind Timeout Timer */
    //Timeout_timer_Start();
    timeout_interrupt_StartEx(Timeout_inter);
    timeout_interrupt_SetPriority(1u);
    
    
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
            pitch_target = (pitch_target-113)*100;
        }
        else
        {
            if(cache==0) DSPInput(2);
            else DSPInput((uint32)cache);
            cache = 130;
        }
        if(pitch_target>pitch+5000) pitch+=4000;
        else
        { 
            if(pitch_target<pitch-0x2000) pitch-=1500;
            else pitch=pitch_target;
        }
        DSPpitch(pitch);

    }  /* End of forever loop */
}  /* End of main */



/* [] END OF FILE */
