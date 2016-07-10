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
* Changes:
*   
*
*******************************************************************************/

#include "spislave.h"

/*******************************************************************************
* Function Name: SPIinit
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
void SPISinit()
{
    SPIS_Start();
}

/*******************************************************************************
* Function Name: SPIsendNumber
********************************************************************************
*
* Summary:
*  Sending a Number via SPI as Master
*
* Parameters:
*  uint8 number
*
* Return:
*  None.
*
*******************************************************************************/
void SPISsendNumber(uint8 number)
{

    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIS_ReadTxStatus() & SPIS_STS_SPI_DONE));
    /* Senden eines Wortes */
    SPIS_WriteTxData(number);
    CyDelayUs(5);
}


/*******************************************************************************
* Function Name: SPIsendArray
********************************************************************************
*
* Summary:
*  Sending an Array via SPI as Master
*
* Parameters:
*  uint8 numbers[]
*
* Return:
*  None.
*
*******************************************************************************/
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

/*******************************************************************************
* Function Name: SPIreadNumber
********************************************************************************
*
* Summary:
*  Receiving a Number via SPI as Master
*
* Parameters:
*  None
*
* Return:
*  uint8 received
*
*******************************************************************************/
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

/*******************************************************************************
* Function Name: SPIreadFinished
********************************************************************************
*
* Summary:
*  Returning the RX buffersize
*
* Parameters:
*  None
*
* Return:
*  uint8 buffer
*
*******************************************************************************/
uint8 SPISreadFinished()
{
    return SPIS_GetRxBufferSize();
}


/* [] END OF FILE */
