/*******************************************************************************
* File Name: dsp.c
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via SPI as Master
*   Can send arrays
*
*******************************************************************************/

#include "dsp.h"

/* RAM values from SIgma Studio */
uint8 program_ram[PROGRAM_RAM_SIZE] = {};
uint8 dm0_ram[DM0_RAM_SIZE] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                              ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                              ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                              ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                              ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00
                              ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                              ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00
                              ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF
                              ,0x00,0x11,0x99,0x9A,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00
                              ,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x04,0xE7,0x00,0x00,0x20,0x8A
                              ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8 dm1_ram[DM1_RAM_SIZE] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                              ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*******************************************************************************
* Function Name: DSPinit
********************************************************************************
*
* Summary:
*  Initialize communication
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DSPinit()
{
    /* SPI intialisieren */
    SPIinit();
    /* Hard reset after full PSoC start */
    DSP_reset_Write(1u);
    CyDelay(5);
    DSP_reset_Write(0u);
    
    /* DSP Initialisierungssequenz nach Datenblatt */
    /* Umschalten des DSP von I2C auf SPI (3 mal dummy senden) */
    DSPwriteWord(0x0000,0x0000);
    DSPwriteWord(0x0000,0x0000);
    DSPwriteWord(0x0000,0x0000);
    /* Enter SOFT_RESET*/
    DSPwriteWord(SOFT_RESET,0x0000);  
    /* Exit SOFT_RESET*/
    DSPwriteWord(SOFT_RESET,0x0001);
    /* Set feedback divider to 96 */
    DSPwriteWord(PLL_CTRL_0,0x0060);
    /* Set PLL input clock divider to 4 */
    DSPwriteWord(PLL_CTRL_1,0x0002);
    /* Set clock source to PLL clock */
    DSPwriteWord(PLL_CLK_SRC,0x0001);
    /* Enable MCLK output (12.288 MHz) */
    DSPwriteWord(MCLK_OUT,0x0005);
    /* Enable PLL */
    DSPwriteWord(PLL_ENABLE,0x0001);
    /* Wait for PLL lock */
    CyDelay(11);
    /* Enable Power for all major systems except clock generator 3 */
    DSPwriteWord(POWER_ENABLE0,0x4FFF);
    /* Disable Power for subsystems like PDM microphones, S/PDIF, ADC */
    DSPwriteWord(POWER_ENABLE1,0x0000);
    
    /* Sigma Studio Program Data goes HERE! */
    DSPwrite(PROGRAM_RAM_DATA,&program_ram[0],PROGRAM_RAM_SIZE);
    DSPwrite(DM0_RAM_DATA,&dm0_ram[0],DM0_RAM_SIZE);
    DSPwrite(DM1_RAM_DATA,&dm1_ram[0],DM1_RAM_SIZE);
    
    /* Set program start address as defined by the Sigma Studio compiler */
    DSPwriteWord(START_ADDRESS,0x0000);
    /* Set DSP core start pulse to internally gernerated pulse */
    DSPwriteWord(START_PULSE,0x0002);
    
    /* Configuration of other registers we use goes here */
    uint8 data[2]={};
    DSPread(POWER_ENABLE0,&data[0],2);
    
    
    /* Stop the core */
    DSPwriteWord(START_CORE,0x0000);
    /* Start the core */
    DSPwriteWord(START_CORE,0x0001);
    /* Wait for initialization program to execute */
    CyDelayUs(50);
    
    /* Initialisation completed */

}

/*******************************************************************************
* Function Name: DSPisReady
********************************************************************************
*
* Summary:
*  Sending data to DSP
*
* Parameters:
*  None.
*
* Return:
*  uint8 ready
*
*******************************************************************************/
uint8 DSPisReady()
{
    uint8 connected=0;
    
    //TODO Lesen eines Registers, dass testet, ob der DSP angelaufen ist
    
    return connected;
}

/*******************************************************************************
* Function Name: DSPwrite
********************************************************************************
*
* Summary:
*  Sending data to DSP
*
* Parameters:
*  uint16 address
*  uint8* pointer to data array
*  uint16 datasize
*
* Return:
*  None.
*
*******************************************************************************/
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

/*******************************************************************************
* Function Name: DSPwriteWord
********************************************************************************
*
* Summary:
*  Sending word of data to DSP
*
* Parameters:
*  uint16 address
*  uint16 word of data
*
* Return:
*  None.
*
*******************************************************************************/
void DSPwriteWord(uint16 address,uint16 data)
{
    uint8 toSend[5];
    toSend[0] = (uint8)((CHIPADDRESS << 1) | (WRITE_DSP));
    toSend[1] = (uint8)(address >> 8);
    toSend[2] = (uint8)(address);
    toSend[3] = (uint8)(data >> 8);
    toSend[4] = (uint8)(data);
    
    SPIsendArray(&toSend[0],5);

}

/*******************************************************************************
* Function Name: DSPread
********************************************************************************
*
* Summary:
*  Reading data from DSP
*
* Parameters:
*  uint16 address
*  uint8* datatarget
*  uint16 datasize
*
* Return:
*  uint8* array
*
*******************************************************************************/
void DSPread(uint16 address, uint8* datatarget, uint16 datasize)
{
    /* Senden des Lesebefehls */
    uint8 toSend[5];
    toSend[0] = (uint8)((CHIPADDRESS << 1) | (READ_DSP));
    toSend[1] = (uint8)(address >> 8);
    toSend[2] = (uint8)(address);
    toSend[3] = 0u;
    toSend[4] = 0u;
    SPIM_ClearRxBuffer();
    SPIsendArray(&toSend[0],5);
    
    /* Lesen */
    uint16 i=0;
    while(i<datasize)
    {
        datatarget[i] = SPIreadNumber();
        i++;
    }
    
}


/* [] END OF FILE */
