/*******************************************************************************
* File Name: nrf24l01.c
*
* Version: 0.0 
* Author: Lukas Creutzburg
*
* Description:
*   Funk Modul Interaktion
*
*
*******************************************************************************/

#include "nrf24l01.h"


void NRF24L01init()
{
    SPIM_Funk_Start();
    
    CE_Funk_Write(1);
    
}

void NRF24L01writeReg(uint8 fivebit)
{
    CE_Funk_Write(0);
    while(!(SPIM_Funk_ReadTxStatus() & (SPIM_Funk_STS_SPI_DONE | SPIM_Funk_STS_SPI_IDLE)));
    /* Senden eines Wortes */
    SPIM_Funk_WriteTxData((1 << 5) & fivebit);
    CyDelayUs(10);
    CE_Funk_Write(1);
}

uint16 NRF24L01readReg(uint8 addressfivebit)
{
    CE_Funk_Write(0);
    SPIM_Funk_ClearRxBuffer();
    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_Funk_ReadTxStatus() & (SPIM_Funk_STS_SPI_DONE | SPIM_Funk_STS_SPI_IDLE)));
    /* Senden eines Wortes */
    SPIM_Funk_WriteTxData(0x00 + addressfivebit);
    CyDelayUs(10);
    SPIM_Funk_WriteTxData(0xFF);
    CyDelayUs(10);
    while(SPIM_Funk_GetRxBufferSize()==0){CyDelayUs(50);}
    uint16 received=SPIM_Funk_ReadRxData();
    received=SPIM_Funk_ReadRxData();
    CyDelayUs(10);
    CE_Funk_Write(1);
    return received;
}


/* [] END OF FILE */
