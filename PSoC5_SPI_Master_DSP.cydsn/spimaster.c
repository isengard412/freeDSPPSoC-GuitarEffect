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
*   
*
*******************************************************************************/

#include "spimaster.h"

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
void SPIinit()
{
    SPIM_Start();
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
void SPIsendNumber(uint8 number)
{

    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_ReadTxStatus() & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)));
    /* Senden eines Wortes */
    SPIM_WriteTxData(number);
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


/* [] END OF FILE */
