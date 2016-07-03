/*******************************************************************************
* File Name: CapSense_1_MBX.h
* Version 3.40
*
* Description:
*  This file provides constants and structure declarations for the tuner 
*  communication the for CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAPSENSE_CSD_MBX_CapSense_1_H)
#define CY_CAPSENSE_CSD_MBX_CapSense_1_H

#include "CapSense_1.h"
#include "CapSense_1_CSHL.h"


/***************************************
*   Condition compilation parameters
***************************************/

/* Check Sum to identify data */
#define CapSense_1_CHECK_SUM      (3994u)

#define CapSense_1_TOTAL_SENSOR_MASK_COUNT     (((CapSense_1_TOTAL_SENSOR_COUNT - 1u) / 8u) + 1u)

/* Do nothing from big endian compilers (__C51__), for ARM compilers need to swap bytes */
#if defined(__C51__) || defined(__CX51__)
    #define CapSense_1_SWAP_ENDIAN16(x) (x)
#else
    #define CapSense_1_SWAP_ENDIAN16(x) ((uint16)(((uint16)(x) << 8) | ((x) >> 8)))
#endif  /* (defined(__C51__)) */

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
    #define CapSense_1_PACKED_STRUCT __attribute__ ((packed))
#elif defined(__ICCARM__)
    #define CapSense_1_PACKED_STRUCT __packed
#else
    #define CapSense_1_PACKED_STRUCT
#endif /* (defined(__GNUC__) || defined(__ARMCC_VERSION)) */

#if defined(__GNUC__)
	#define CapSense_1_NO_STRICT_VOLATILE __attribute__((optimize("-fno-strict-volatile-bitfields")))
#else
	#define CapSense_1_NO_STRICT_VOLATILE	
#endif /* (defined(__GNUC__)) */

/***************************************
*      Type defines for mailboxes
***************************************/

/* Outbox structure definition */
typedef struct
{       
    #if (CapSense_1_TOTAL_CENTROIDS_COUNT)
        uint16   position[CapSense_1_TOTAL_CENTROIDS_COUNT];
    #endif  /* (CapSense_1_TOTAL_CENTROIDS_COUNT) */

    #if (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT)
        uint8   mbPosition[CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT * 2u];
    #endif /* (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT) */

    uint16   rawData[CapSense_1_TOTAL_SENSOR_COUNT];
    uint16   baseLine[CapSense_1_TOTAL_SENSOR_COUNT];
    uint16    signal[CapSense_1_TOTAL_SENSOR_COUNT];
    uint8    onMask[CapSense_1_TOTAL_SENSOR_MASK_COUNT];
    
    #if (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING)
        uint16   fingerThreshold[CapSense_1_WIDGET_CSHL_PARAMETERS_COUNT];
        uint16   noiseThreshold[CapSense_1_WIDGET_CSHL_PARAMETERS_COUNT];
        uint8   scanResolution[CapSense_1_WIDGET_RESOLUTION_PARAMETERS_COUNT];
        uint8   idacValue[CapSense_1_TOTAL_SENSOR_COUNT];
		uint8   analogSwitchDivider[CapSense_1_TOTAL_SCANSLOT_COUNT];
    #endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */

    #if(CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING)
        uint8   noReadMsg;
    #endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */
    uint16  checkSum;
    
} CapSense_1_PACKED_STRUCT CapSense_1_OUTBOX;

/* Inbox structure definition */
#if (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING)
    typedef struct
    {
        uint8   sensorIndex;
        #if (CapSense_1_CURRENT_SOURCE)
            uint8   idacSettings;
        #endif /* CapSense_1_CURRENT_SOURCE */
        uint8   resolution;
        uint16   fingerThreshold;
        uint16   noiseThreshold;
        uint16   hysteresis;
        uint8   debounce;
        uint8   analogSwitchDivider;
    } CapSense_1_PACKED_STRUCT CapSense_1_INBOX;
    
#endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */

/* Mailbox structure definition */
typedef struct
{
    uint8   type;               /* Must be the first byte with values ranging from 0-119 */
    uint16  size;               /* Must be the size of this data structure. Range between 0-127 */
    CapSense_1_OUTBOX  outbox;
    #if (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING)
        CapSense_1_INBOX inbox;
    #endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */
    
} CapSense_1_PACKED_STRUCT CapSense_1_MAILBOX;


/* Mailboxes structure definition */
typedef struct
{
    uint8   numMailBoxes;       /* This must always be the first. Represents # of mailboxes */
    CapSense_1_MAILBOX    csdMailbox;
} CapSense_1_PACKED_STRUCT CapSense_1_MAILBOXES;


/***************************************
*        Function Prototypes
***************************************/

CapSense_1_NO_STRICT_VOLATILE void CapSense_1_InitMailbox(volatile CapSense_1_MAILBOX *mbx) \
                                  ;
CapSense_1_NO_STRICT_VOLATILE void CapSense_1_PostMessage(volatile CapSense_1_MAILBOX *mbx) \
                                  ;
#if (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING)
CapSense_1_NO_STRICT_VOLATILE void CapSense_1_ReadMessage(volatile CapSense_1_MAILBOX *mbx) \
	                                  ;
#endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */


/***************************************
*           API Constants        
***************************************/

/* The selected ID for this version of Tuner */
#define CapSense_1_TYPE_ID        (0x04u)

#define CapSense_1_BUSY_FLAG      (CapSense_1_TYPE_ID | 0x80u)
#define CapSense_1_HAVE_MSG       (sizeof(CapSense_1_MAILBOX) | 0x8000u)


#if (CapSense_1_CURRENT_SOURCE)
    extern uint8 CapSense_1_idacSettings[CapSense_1_TOTAL_SENSOR_COUNT];
#endif /* CapSense_1_CURRENT_SOURCE */

extern uint8 CapSense_1_widgetResolution[CapSense_1_WIDGET_RESOLUTION_PARAMETERS_COUNT];

extern uint16 CapSense_1_fingerThreshold[CapSense_1_WIDGET_CSHL_PARAMETERS_COUNT];
extern uint16 CapSense_1_noiseThreshold[CapSense_1_WIDGET_CSHL_PARAMETERS_COUNT];
extern uint16 CapSense_1_hysteresis[CapSense_1_WIDGET_CSHL_PARAMETERS_COUNT];
extern uint8 CapSense_1_debounce[CapSense_1_WIDGET_CSHL_PARAMETERS_COUNT];
   
#if (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING)
    extern uint8 CapSense_1_lowLevelTuningDone;
    extern uint8 CapSense_1_GetPrescaler(void);
#endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */

#if ( (CapSense_1_MULTIPLE_PRESCALER_ENABLED) || \
      (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING) )
    extern uint8 CapSense_1_analogSwitchDivider[CapSense_1_TOTAL_SCANSLOT_COUNT];
#else
    extern uint8 CapSense_1_analogSwitchDivider;
#endif /* ( (CapSense_1_MULTIPLE_PRESCALER_ENABLED) || \
       *    (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING) )
       */


#endif  /* (CY_CAPSENSE_CSD_MBX_CapSense_1_H) */

/* [] END OF FILE */
