/*******************************************************************************
* File Name: spimaster.c
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via SPI as Master
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

    /* Clear the transmit buffer before next reading (good practice) */
    SPIM_ClearTxBuffer();

    temp = SPIM_ReadTxStatus();

    /* Ensure that previous SPI read is done, or SPI is idle before sending data */
    if((temp & (SPIM_STS_SPI_DONE | SPIM_STS_SPI_IDLE)))
    {
        SPIM_WriteTxData(number);
    }
}



/* [] END OF FILE */
