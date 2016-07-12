/*******************************************************************************
* File Name: dsp.c
*
* Version: 1.1 
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via SPI as Master
*   Can send arrays
*
* Changes:
*   - Changed Wordsize to 32bit
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

#include "dsp.h"

/* RAM and Control values from Sigma Studio */
uint8 program_ram[PROGRAM_RAM_SIZE] =
{
#include "DSP_program.h"
};
uint8 dm0_ram[DM0_RAM_SIZE] = 
{
#include "DSP_dm0.h"
};
uint8 dm1_ram[DM1_RAM_SIZE] = 
{
#include "DSP_dm1.h"
};

void DSPinit()
{
    DSP_reset_Write(1u);
    /* SPI intialisieren */
    SPIinit();
    /* Hard reset after full PSoC start */
    DSP_reset_Write(0u);
    CyDelay(20);
    DSP_reset_Write(1u);
    
    /* DSP Initialisierungssequenz nach Datenblatt */
    /* Umschalten des DSP von I2C auf SPI (3 mal dummy senden) */
    CyDelay(260);
    DSPwriteWord32(0x4FFF,0x00000000);
    CyDelay(260);
    DSPwriteWord32(0x4FFF,0x00000000);
    CyDelay(260);
    DSPwriteWord32(0x4FFF,0x00000000);
    CyDelay(260);
    /* Enter SOFT_RESET*/
    DSPwriteWord16(SOFT_RESET,0x0000);  
    CyDelay(1);
    /* Exit SOFT_RESET*/
    DSPwriteWord16(SOFT_RESET,0x0001);
    CyDelay(260);
    /* Exit Hypernate*/
    DSPwriteWord16(HYPERNATE,0x0000); 
    CyDelay(1);
    /* Enter Hypernate*/
    DSPwriteWord16(HYPERNATE,0x0001);
    CyDelay(260);
    /* Exit Kill Core*/
    DSPwriteWord16(KILL_CORE,0x0000);
    CyDelay(1);
    /* Kill Core*/
    DSPwriteWord16(KILL_CORE,0x0001);
    CyDelay(1);
    /* Exit Kill Core*/
    DSPwriteWord16(KILL_CORE,0x0000);
    CyDelay(1);
    /* Set PLL input clock divider to 4 */
    DSPwriteWord16(PLL_CTRL_1,0x0002);
    CyDelay(1);
    /* Set clock source to PLL clock */
    DSPwriteWord16(PLL_CLK_SRC,0x0001);
    CyDelay(1);
    /* Enable MCLK output (12.288 MHz) */
    DSPwriteWord16(MCLK_OUT,0x0005);
    CyDelay(1);
    /* Enable PLL */
    DSPwriteWord16(PLL_ENABLE,0x0001);
    /* Wait for PLL lock */
    CyDelay(260);
    /* Enable Power for all major systems except clock generator 3 */
    DSPwriteWord16(POWER_ENABLE0,0x1FFF);
    CyDelay(1);
    /* Disable Power for subsystems like PDM microphones, S/PDIF, ADC */
    DSPwriteWord16(POWER_ENABLE1,0x001F);
    CyDelay(1);
    /* Serial Output Port */
    int i;
    for(i=SERIAL_OUTPUT;i<=SERIAL_OUTPUT_END;i++)
    {
        DSPwriteWord16(i,0x0002);
        CyDelay(1);
    }
    
    /* Serial Port Control */
    DSPwriteWord16(0xF200,0x0102);
    CyDelay(1);
    //0b    001-LRCLK1   001-BCLK1   0-LRCLKMODE   0-LRCLKPOL   0-BCLKPOL   01-WORDLENGTH   00-MSBPOS   000-32bitcycles64bitframes
    DSPwriteWord16(SDATA_IN_1,0b0010010000000000);
    CyDelay(1);
    DSPwriteWord16(0xF208,0x0102);
    CyDelay(1);
    DSPwriteWord16(0xF20C,0x9102);
    CyDelay(1);
    DSPwriteWord16(0xF210,0x9102);
    CyDelay(1);
    DSPwriteWord16(0xF214,0x9103);
    CyDelay(1);
    DSPwriteWord16(0xF218,0x9102);
    CyDelay(1);
    DSPwriteWord16(0xF21C,0x9102);
    CyDelay(1);
    
    /* Sigma Studio Program Data goes HERE! */
    DSPwrite(PROGRAM_RAM_DATA,&program_ram[0],PROGRAM_RAM_SIZE);
    CyDelay(1);
    DSPwrite(DM0_RAM_DATA,&dm0_ram[0],DM0_RAM_SIZE);
    CyDelay(1);
    DSPwrite(DM1_RAM_DATA,&dm1_ram[0],DM1_RAM_SIZE);
    CyDelay(1);
    
    /* Exit Kill Core*/
    DSPwriteWord16(KILL_CORE,0x0000);
    CyDelay(1);
    /* Set program start address as defined by the Sigma Studio compiler */
    DSPwriteWord16(START_ADDRESS,0x0000);
    CyDelay(1);
    /* Set DSP core start pulse to internally gernerated pulse */
    DSPwriteWord16(START_PULSE,0x0002);  
    CyDelay(1);
    /* Stop the core */
    DSPwriteWord16(START_CORE,0x0000);
    CyDelay(1);
    /* Start the core */
    DSPwriteWord16(START_CORE,0x0001);
    CyDelay(3);
    /* Exit Hypernate*/
    DSPwriteWord16(HYPERNATE,0x0000);
    /* Wait for initialization program to execute */
    CyDelay(260);
    
    /* Initialisation completed */
    


}

uint8 DSPisReady()
{
    uint8 connected=0;
    
    //TODO Lesen eines Registers, dass testet, ob der DSP angelaufen ist
    
    return connected;
}

void DSPwrite(uint16 address,uint8* data,uint16 datasize)
{
    uint8 toSend[datasize+3];
    toSend[0] = (uint8)((CHIPADDRESS << 1) | (WRITE_DSP));
    toSend[1] = (uint8)(address >> 8);
    toSend[2] = (uint8)(address);
    uint16 i;
    for(i=0;i<datasize;i++)
    {
        toSend[i+3] = data[i];
    }
    SPIsendArray(&toSend[0],datasize+3);
}

void DSPwriteWord32(uint16 address,uint32 data)
{
    uint8 toSend[7];
    toSend[0] = (uint8)((CHIPADDRESS << 1) | (WRITE_DSP));
    toSend[1] = (uint8)(address >> 8);
    toSend[2] = (uint8)(address);
    toSend[3] = (uint8)(data >> 24);
    toSend[4] = (uint8)(data >> 16);
    toSend[5] = (uint8)(data >> 8);
    toSend[6] = (uint8)(data);
    
    SPIsendArray(&toSend[0],7);

}

void DSPwriteWord16(uint16 address,uint16 data)
{
    uint8 toSend[5];
    toSend[0] = (uint8)((CHIPADDRESS << 1) | (WRITE_DSP));
    toSend[1] = (uint8)(address >> 8);
    toSend[2] = (uint8)(address);
    toSend[3] = (uint8)(data >> 8);
    toSend[4] = (uint8)(data);
    
    SPIsendArray(&toSend[0],5);

}

void DSPsafeLoad(uint16 address,uint32 data)
{
    //Block Write Slew Mode
    DSPwriteWord32(0x0027,0x0000208A);
    CyDelay(26);
    //Safeload
    //Data to Register 0x0014
    DSPwriteWord32(0x0014,data);
    CyDelay(1);
    
    //Register to write into to Register 0x0019
    DSPwriteWord32(0x0019,address);
    CyDelay(1);
    //Safeload trigger / number of words to write to Register 0x001A
    DSPwriteWord32(0x001A,0x00000001);
    CyDelay(60);
}

void DSPread32(uint16 address, uint8* datatarget, uint16 datasize)
{
    /* Senden des Lesebefehls */
    uint8 toSend[7];
    toSend[0] = (uint8)((CHIPADDRESS << 1) | (READ_DSP));
    toSend[1] = (uint8)(address >> 8);
    toSend[2] = (uint8)(address);
    toSend[3] = 0u;
    toSend[4] = 0u;
    toSend[3] = 0u;
    toSend[4] = 0u;
    SPIM_ClearRxBuffer();
    SPIsendArray(&toSend[0],7);
    
    /* Lesen */
    uint16 i=0;
    while(i<datasize)
    {
        datatarget[i] = SPIreadNumber();
        i++;
    }
    
}

void DSPInput(uint32 in)
{
    /* 0-i2s, 1-generated, 2-analog */
    if(in<3) DSPwriteWord32(0x0026,in);
}

void DSPpitch(int32 pitch)
{
    /* Wert zwischen +-34953 */
    DSPsafeLoad(0x002A,(uint32)pitch);
}


/* [] END OF FILE */
