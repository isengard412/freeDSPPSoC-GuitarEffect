/*******************************************************************************
* File Name: main.h
*
* Version: 1.20
*
* Description:
*  This file provides function prototypes, constants and macros for the example
*  project.
*
********************************************************************************
* Copyright 2014-2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#if !defined(CY_MAIN_H)
#define CY_MAIN_H

#include <project.h>
    


/***************************************
*         Function Prototypes
****************************************/

/* Function prototypes */
uint32 CheckSwitchState(void);
uint32 WriteCommandPacket(uint8 cmd);
uint32 ReadStatusPacket(void);


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
#define CMD_SET_ERROR   (1u)
#define CMD_SET_MODE1   (2u)
#define CMD_SET_MODE2   (3u)
#define CMD_SET_MODE3   (4u)
#define CMD_SET_MODE4   (5u)
#define CMD_SET_MODE5   (6u)

/* Delay between commands in milliseconds */
#define CMD_TO_CMD_DELAY  (5u)

// DSP Constants

#define DSP_SDA         9
#define DSP_SCL         10
#define DSP_WP          11
#define DSP_RES         12
#define DSP_ADDRESS     0

#define VOLUME0_ADDR    0x0027

//Defines for serial communication

#define COM_BAUD        9600
#define COM_BUFFSIZE    25



/***************************************
*               Macros
****************************************/

/* Set LED RED color */
#define RGB_LED_ON_RED  \
                do{     \
                    LED_RED_Write  (0u); \
                    LED_GREEN_Write(1u); \
                }while(0)

#endif /* (CY_MAIN_H) */


/* [] END OF FILE */
