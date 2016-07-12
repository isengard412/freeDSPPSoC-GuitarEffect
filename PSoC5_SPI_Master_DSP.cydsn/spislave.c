/*******************************************************************************
* File Name: spislave.c
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via SPI as Slave (Problems with this!)
*   Can send arrays (Problems with this!)
*   Receives from Master
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

#include "spislave.h"

void SPISinit()
{
    SPIS_Start();
}

void SPISsendNumber(uint8 number)
{

    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIS_ReadTxStatus() & SPIS_STS_SPI_DONE));
    /* Senden eines Wortes */
    SPIS_WriteTxData(number);
    CyDelayUs(5);
}

void SPISsendArray(uint8* numbers, uint16 numberOfbytes)
{
    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIS_ReadTxStatus() & SPIS_STS_SPI_DONE))
    {
        CyDelayUs(5);
    }

    uint16 transmitted=0;
    while(transmitted<numberOfbytes)
    {
        /* Weniger als 255 Werte zu übertragen */
        if((numberOfbytes-transmitted)<255) 
        {
            SPIS_PutArray(&numbers[transmitted],numberOfbytes-transmitted);
            transmitted = numberOfbytes;
        }
        /* Noch mehr als 255 Restwerte */
        else 
        {
            SPIS_PutArray(&numbers[transmitted],255);
            transmitted += 255;
        }
    }

}

uint8 SPISreadNumber(uint8 waiting)
{

    /* Warten auf Byte */
    if(waiting)
    {
        while(SPIS_GetRxBufferSize() == 0)
        {
            CyDelayUs(5);    
        }
    }
    /* Senden eines Wortes */
    uint8 received = SPIS_ReadRxData();
    return received;
}

uint8 SPISreadFinished()
{
    return SPIS_GetRxBufferSize();
}


/* [] END OF FILE */
