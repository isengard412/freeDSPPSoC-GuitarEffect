/*
* funk.c 
* Author: Lukas Creutzburg
* Based on:
* ----------------------------------------------------------------------------
* THE COFFEEWARE LICENSE (Revision 1):
* <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a coffee in return.
* -----------------------------------------------------------------------------
*
* Version: 0.1
*/

#include "funk.h"


/* ------------------------------------------------------------------------- */
uint8 temp;
uint8 q = 0;
uint8 data_array[4];
uint8 tx_address[5] = {0xE7,0xE7,0xE7,0xE7,0xE7};
uint8 rx_address[5] = {0xD7,0xD7,0xD7,0xD7,0xD7};
/* ------------------------------------------------------------------------- */
int funkTxTest()
{
    UARTsendString("TX init");
    
    /* init hardware pins */
    nrf24_init();
    
    /* Channel #2 , payload length: 4 */
    nrf24_config(2,4);

    /* Set the device addresses */
    nrf24_tx_address(tx_address);
    nrf24_rx_address(rx_address);    

    while(1)
    {                
        /* Fill the data buffer */
        data_array[0] = 0x00;
        data_array[1] = 0xAA;
        data_array[2] = 0x55;
        data_array[3] = q++;                                    

        /* Automatically goes to TX mode */
        nrf24_send(data_array);        
        
        /* Wait for transmission to end */
        while(nrf24_isSending());

        /* Make analysis on last tranmission attempt */
        temp = nrf24_lastMessageStatus();

        if(temp == NRF24_TRANSMISSON_OK)
        {                    
            UARTsendString("> Tranmission went OK\r\n");
            LED_Write(!LED_Read());
        }
        else if(temp == NRF24_MESSAGE_LOST)
        {                    
            UARTsendString("> Message is lost ...\r\n");    
        }
        
		/* Retranmission count indicates the tranmission quality */
		temp = nrf24_retransmissionCount();
		UARTsendString("> Retranmission count: ");
        UARTsendNumber(temp);

		/* Optionally, go back to RX mode ... */
		nrf24_powerUpRx();

		/* Or you might want to power down after TX */
		// nrf24_powerDown();            

		/* Wait a little ... */
		CyDelay(10);
    }
}

int funkRxTest()
{
    UARTsendString("RX init...");
    /* init hardware pins */
    nrf24_init();
    
    /* Channel #2 , payload length: 4 */
    nrf24_config(2,4);
 
    /* Set the device addresses */
    nrf24_tx_address(tx_address);
    nrf24_rx_address(rx_address);

    while(1)
    {    
        if(nrf24_dataReady())
        {
            nrf24_getData(data_array);        
            UARTsendString("> ");
            UARTsendNumber(data_array[0]);
            UARTsendNumber(data_array[1]);
            UARTsendNumber(data_array[2]);
            UARTsendNumber(data_array[3]);
        }
    }
}

/* ------------------------------------------------------------------------- */
