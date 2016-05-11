/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#if !defined(CY_MAIN_H)
#define CY_MAIN_H

#include <project.h>
#include "stdio.h"

/***************************************
*         Function Prototypes
****************************************/

uint8 ExecuteCommand(uint32 cmd);


/***************************************
*            Constants
****************************************/

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

/* Commands set */
#define CMD_SET_OFF     (0u)
#define CMD_SET_ERROR   (1u)
#define CMD_SET_MODE1   (2u)
#define CMD_SET_MODE2   (3u)
#define CMD_SET_MODE3   (4u)
#define CMD_SET_MODE4   (5u)
#define CMD_SET_MODE5   (6u)

#endif /* (CY_MAIN_H) */

/* [] END OF FILE */
