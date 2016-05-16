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
*   -Extended for 32bit use
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
*  uint16 number
*
* Return:
*  None.
*
*******************************************************************************/
void SPIsendNumber(uint16 number)
{

    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_ReadTxStatus() & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)));
    /* Senden eines Wortes */
    SPIM_WriteTxData(number);
    CyDelayUs(5);
}

/*******************************************************************************
* Function Name: SPIsendNumber32
********************************************************************************
*
* Summary:
*  Sending a Number via SPI as Master
*
* Parameters:
*  uint32 number
*
* Return:
*  None.
*
*******************************************************************************/
void SPIsendNumber32(uint32 number)
{

    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_ReadTxStatus() & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)));

    /* Enable setzen */
    SS_control_Write(0);
    SPIsendNumber((uint16)(number >> 16));
    SPIsendNumber((uint16)(number & 0x0000FFFF));
    /* Warten auf abschließen der TX UEbertragung */
    while(!(SPIM_ReadTxStatus() & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)));
    /* Enable reset */
    SS_control_Write(1);
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
void SPIsendArray(uint16 numbers[])
{
    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_ReadTxStatus() & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)))
    {
        CyDelayUs(5);
    }

    SPIM_PutArray(numbers,2);
}

/*******************************************************************************
* Function Name: SPIsendArray32
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
void SPIsendArray32(uint32 numbers[],int arraysize)
{
    /* Warten auf abschliessen der TX Uebertragung */
    while(!(SPIM_ReadTxStatus() & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)))
    {
        CyDelayUs(5);
    }

    int i;
    for(i=0;i<arraysize;i++)
    {
        SPIsendNumber32(numbers[i]);
    }

}


/* [] END OF FILE */
