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


void NRF24L01initRX()
{
    SPIM_Funk_Start();
    
    CE_Funk_Write(0);
    /* CONFIG Register 
     * 0(default)0(RX interrupt)1(TX interrupt)1(MAX_RT interrupt)1(CRC_Enable)0(CRC 1 byte)0(PWR_DOWN)1(RX)
     */
    NRF24L01writeReg(0x00,0b00111001);
    /* EN_RXADDR Register
     * 00(default)000011(Enable RX pipes)
     */
    NRF24L01writeReg(0x01,0b00000011);
    /* EN_AA Register
     * 00(default)000011(Enable auto ACK)
     */
    NRF24L01writeReg(0x02,0b00000011);
    /* RX_PW_Px Register
     * 00(default)XXXXXX(pipe length)
     */
    NRF24L01writeReg(0x11,0b00100000);
    NRF24L01writeReg(0x12,0b00100000);
    
    CE_Funk_Write(1);
    CyDelayUs(150);
}

void NRF24L01initTX()
{
    SPIM_Funk_Start();
    
    CE_Funk_Write(0);
    /* CONFIG Register 
     * 0(default)0(RX interrupt)1(TX interrupt)1(MAX_RT interrupt)1(CRC_Enable)0(CRC 1 byte)0(PWR_DOWN)1(RX)
     */
    NRF24L01writeReg(0x00,0b01011000);
    /* EN_RXADDR Register
     * 00(default)000011(Enable RX pipes)
     */
    NRF24L01writeReg(0x01,0b00000011);
    /* EN_AA Register
     * 00(default)000011(Enable auto ACK)
     */
    NRF24L01writeReg(0x02,0b00000011);
    /* RX_PW_Px Register
     * 00(default)XXXXXX(pipe length)
     */
    NRF24L01writeReg(0x11,0b00100000);
    NRF24L01writeReg(0x12,0b00100000);
    
    CE_Funk_Write(1);
    CyDelayUs(15);
    
}

void NRF24L01writeReg(uint8 address, uint8 data)
{
    while(!(SPIM_Funk_ReadTxStatus() & (SPIM_Funk_STS_SPI_DONE | SPIM_Funk_STS_SPI_IDLE)));
    /* Senden eines Wortes */
    SPIM_Funk_WriteTxData((1 << 5) & address);
    CyDelayUs(10);
    SPIM_Funk_WriteTxData(data);
    CyDelayUs(10);
}

uint16 NRF24L01readReg(uint8 addressfivebit)
{
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
    return received;
}

void NRF24L01readRXpayload(uint8 numberOfbytes, uint8* target)
{
    SPIM_Funk_ClearRxBuffer();
    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_Funk_ReadTxStatus() & (SPIM_Funk_STS_SPI_DONE | SPIM_Funk_STS_SPI_IDLE)))
    {
        CyDelayUs(5);
    }

    SPIM_Funk_WriteTxData(0b01100001);
    uint16 transmitted=0;
    while(transmitted<numberOfbytes)
    {
        SPIM_Funk_WriteTxData(0b11111111);
    }
    SPIM_Funk_ReadRxData();
    int i;
    for(i=0;i<numberOfbytes;i++)
    {
        target[i]=SPIM_Funk_ReadRxData();
    }
}

void NRF24L01writeTXpayload(uint8 numberOfbytes, uint8* data)
{
    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_Funk_ReadTxStatus() & (SPIM_Funk_STS_SPI_DONE | SPIM_Funk_STS_SPI_IDLE)))
    {
        CyDelayUs(5);
    }

    SPIM_Funk_WriteTxData(0b10100000);
    uint16 transmitted=0;
    while(transmitted<numberOfbytes)
    {
        /* Weniger als 255 Werte zu übertragen */
        if((numberOfbytes-transmitted)<255) 
        {
            SPIM_Funk_PutArray(&data[transmitted],numberOfbytes-transmitted);
            transmitted = numberOfbytes;
        }
        /* Noch mehr als 255 Restwerte */
        else 
        {
            SPIM_Funk_PutArray(&data[transmitted],255);
            transmitted += 255;
        }
    }
}


/* [] END OF FILE */
