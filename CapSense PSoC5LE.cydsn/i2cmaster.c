/* ========================================
* File Name: capsense.h
*
* Version: 0
* Author: Lukas Creutzburg
*
*  Description:
*  CapSense module
*
* ===========================================================================================================
*/
#include "i2cmaster.h"

/* Variables */

//_________________________________

/*******************************************************************************
* Function Name:  UARTInit
********************************************************************************
*
* Summary:
*   Initializes CapSense  
*
* Parameters:  
*  None
*
* Return: 
*  None 
*  
*******************************************************************************/
void I2CInit(void)
{
    I2CM_Start();
}
//_________________________________________________________________


/*******************************************************************************
* Function Name: I2CWriteCommandPacket
********************************************************************************
*
* Summary:
*  Sends command via I2C
*
* Parameters:  
*   uint8: command to send
* Return: 
*   uint32: current state
*   Returns status of the transfer. There are two statuses
*   - TRANSFER_CMPLT: transfer completed successfully.
*   - TRANSFER_ERROR: the error occurred while transfer.
*
*******************************************************************************/
uint32 I2CWriteCommandPacket(uint8 cmd)
{
    uint8  buffer[BUFFER_SIZE];
    uint32 status = TRANSFER_ERROR;

    /* Initialize buffer with packet */
    buffer[PACKET_SOP_POS] = PACKET_SOP;
    buffer[PACKET_CMD_POS] = cmd;
    buffer[PACKET_EOP_POS] = PACKET_EOP;

    (void) I2CM_MasterWriteBuf(I2C_SLAVE_ADDR, buffer, PACKET_SIZE, \
                                  I2CM_MODE_COMPLETE_XFER);

    /* Waits until master completes write transfer */
    while (0u == (I2CM_MasterStatus() & I2CM_MSTAT_WR_CMPLT))
    {
    }

    /* Displays transfer status */
    if (0u == (I2CM_MSTAT_ERR_XFER & I2CM_MasterStatus()))
    {
        /* Check if all bytes was written */
        if (I2CM_MasterGetWriteBufSize() == BUFFER_SIZE)
        {
            //RGB_LED_ON_GREEN;
            status = TRANSFER_CMPLT;
        }
    }
    else
    {
        //RGB_LED_ON_RED;
    }

    (void) I2CM_MasterClearStatus();

    return (status);
}
//_________________________________________________________________


/*******************************************************************************
* Function Name: I2CReadStatusPacket
********************************************************************************
* Summary:
*  Read command from slave
*
* Parameters:
*  None
*
* Return:
*  Returns status of the transfer. There are two statuses
*  - TRANSFER_CMPLT: transfer completed successfully.
*  - TRANSFER_ERROR: the error occurred while transfer.
*
*******************************************************************************/
uint32 I2CReadStatusPacket(void)
{
    uint8  buffer[BUFFER_SIZE];
    uint32 status = TRANSFER_ERROR;

    (void) I2CM_MasterReadBuf(I2C_SLAVE_ADDR, buffer, PACKET_SIZE, \
                                 I2CM_MODE_COMPLETE_XFER);

    /* Waits until master complete read transfer */
    while (0u == (I2CM_MasterStatus() & I2CM_MSTAT_RD_CMPLT))
    {
    }

    /* Displays transfer status */
    if (0u == (I2CM_MSTAT_ERR_XFER & I2CM_MasterStatus()))
    {
        /* Check packet structure */
        if ((I2CM_MasterGetReadBufSize() == BUFFER_SIZE) &&
            (PACKET_SOP == buffer[PACKET_SOP_POS]) &&
            (PACKET_EOP == buffer[PACKET_EOP_POS]))
        {
            /* Check packet status */
            if (STS_CMD_DONE == buffer[PACKET_STS_POS])
            {
                //RGB_LED_ON_GREEN;
                status = TRANSFER_CMPLT;
            }
        }
    }
    else
    {
        //RGB_LED_ON_RED;
        status = TRANSFER_ERROR;
    }

    (void) I2CM_MasterClearStatus();

    return (status);
}
//___________________________________________________________


//[] END OF FILE
