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
    
    CE_Funk_Write(0);
    
    /* Dummy Read for Test */
    NRF24L01GetReg(STATUS);
}

uint8 NRF24L01GetReg(uint8 number)
{
    SPIM_Funk_ClearRxBuffer();
    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_Funk_ReadTxStatus() & (SPIM_Funk_STS_SPI_DONE | SPIM_Funk_STS_SPI_IDLE)));
    /* Senden eines Wortes */
    SPIM_Funk_WriteTxData(R_REGISTER + number);
    CyDelayUs(10);
    SPIM_Funk_WriteTxData(NOP);
    CyDelayUs(10);
    uint8 received=SPIM_Funk_ReadRxData();
    CyDelayUs(10);
    return received;
}


/* [] END OF FILE */
