/* ========================================
* File Name: i2cmaster.h
*
* Version: 0
* Author: Lukas Creutzburg
*
*  Description:
*  i2c interaction between PSoCs. Master module
*
* ===========================================================================================================
*/
#ifndef __i2cmaster_H
#define __i2cmaster_H
	
#include "project.h"

/***************************************
*            Constants
****************************************/
    
/* I2C slave address to communicate with */
#define I2C_SLAVE_ADDR  (0x08u)

/* Buffer and packet size */
#define BUFFER_SIZE     (3u)
#define PACKET_SIZE     (BUFFER_SIZE)

/* Packet positions */
#define PACKET_SOP_POS  (0u)
#define PACKET_CMD_POS  (1u)
#define PACKET_STS_POS  (PACKET_CMD_POS)
#define PACKET_EOP_POS  (2u)

/* Start and end of packet markers */
#define PACKET_SOP      (0x01u)
#define PACKET_EOP      (0x17u)

/* Command valid status */
#define STS_CMD_DONE    (0x00u)
#define STS_CMD_FAIL    (0xFFu)

/* Command valid status */
#define TRANSFER_CMPLT    (0x00u)
#define TRANSFER_ERROR    (0xFFu)
    
/* Commands set */
#define CMD_SET_OFF     (0u)
#define CMD_SET_RED     (1u)
#define CMD_SET_GREEN   (2u)
#define CMD_SET_BLUE    (3u)

/* Delay between commands in milliseconds */
#define CMD_TO_CMD_DELAY  (500u)

/*******************************************************************************
* Function Name:  I2CInit
********************************************************************************
*
* Summary:
*   Initializes I2C  
*
* Parameters:  
*  None
*
* Return: 
*  None 
*  
*******************************************************************************/
void I2CInit(void);


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
uint32 I2CWriteCommandPacket(uint8 cmd);


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
uint32 I2CReadStatusPacket(void);

#endif

//[] END OF FILE