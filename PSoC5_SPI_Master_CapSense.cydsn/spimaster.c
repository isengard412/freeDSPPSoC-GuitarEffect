/*******************************************************************************
* File Name: spimaster.c
*
* Version: 1.2
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via SPI as Master
*   Can send arrays
*
* Changes:
*   -Can now receive
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

#include "spimaster.h"

void SPIinit()
{
    SPIM_Start();
}

void SPIsendNumber(uint8 number)
{

    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_ReadTxStatus() & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)));
    /* Senden eines Wortes */
    SPIM_WriteTxData(number);
    CyDelayUs(5);
}

void SPIsendArray(uint8* numbers, uint16 numberOfbytes)
{
    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_ReadTxStatus() & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)))
    {
        CyDelayUs(5);
    }

    uint16 transmitted=0;
    while(transmitted<numberOfbytes)
    {
        /* Weniger als 255 Werte zu übertragen */
        if((numberOfbytes-transmitted)<255) 
        {
            SPIM_PutArray(&numbers[transmitted],numberOfbytes-transmitted);
            transmitted = numberOfbytes;
        }
        /* Noch mehr als 255 Restwerte */
        else 
        {
            SPIM_PutArray(&numbers[transmitted],255);
            transmitted += 255;
        }
    }

}

uint8 SPIreadNumber()
{

    /* Warten auf Byte */
    while(SPIM_GetRxBufferSize() == 0)
    {
        CyDelayUs(5);    
    }
    /* Senden eines Wortes */
    uint8 received = SPIM_ReadRxData();
    return received;
}

uint8 SPIreadFinished()
{
    return SPIM_GetRxBufferSize();
}


/* [] END OF FILE */
