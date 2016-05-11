/***************************************************************************//**
* \file UART_1_cdc.h
* \version 3.0
*
* \brief
*  This file provides function prototypes and constants for the USBFS component 
*  CDC class.
*
* Related Document:
*  Universal Serial Bus Class Definitions for Communication Devices Version 1.1
*
********************************************************************************
* \copyright
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_UART_1_cdc_H)
#define CY_USBFS_UART_1_cdc_H

#include "UART_1.h"


/*******************************************************************************
* Prototypes of the UART_1_cdc API.
*******************************************************************************/
/**
* \addtogroup group_cdc
* @{
*/
#if (UART_1_ENABLE_CDC_CLASS_API != 0u)
    uint8 UART_1_CDC_Init(void)            ;
    void UART_1_PutData(const uint8* pData, uint16 length) ;
    void UART_1_PutString(const char8 string[])            ;
    void UART_1_PutChar(char8 txDataByte) ;
    void UART_1_PutCRLF(void)             ;
    uint16 UART_1_GetCount(void)          ;
    uint8  UART_1_CDCIsReady(void)        ;
    uint8  UART_1_DataIsReady(void)       ;
    uint16 UART_1_GetData(uint8* pData, uint16 length)     ;
    uint16 UART_1_GetAll(uint8* pData)    ;
    uint8  UART_1_GetChar(void)           ;
    uint8  UART_1_IsLineChanged(void)     ;
    uint32 UART_1_GetDTERate(void)        ;
    uint8  UART_1_GetCharFormat(void)     ;
    uint8  UART_1_GetParityType(void)     ;
    uint8  UART_1_GetDataBits(void)       ;
    uint16 UART_1_GetLineControl(void)    ;
    void UART_1_SendSerialState (uint16 serialState) ;
    uint16 UART_1_GetSerialState (void)   ;
    void UART_1_SetComPort (uint8 comNumber) ;
    uint8 UART_1_GetComPort (void)        ;
    uint8 UART_1_NotificationIsReady(void) ;

#endif  /* (UART_1_ENABLE_CDC_CLASS_API) */
/** @} cdc */

/*******************************************************************************
*  Constants for UART_1_cdc API.
*******************************************************************************/

/* CDC Class-Specific Request Codes (CDC ver 1.2 Table 19) */
#define UART_1_CDC_SET_LINE_CODING        (0x20u)
#define UART_1_CDC_GET_LINE_CODING        (0x21u)
#define UART_1_CDC_SET_CONTROL_LINE_STATE (0x22u)

/*PSTN Subclass Specific Notifications (CDC ver 1.2 Table 30)*/
#define UART_1_SERIAL_STATE               (0x20u)

#define UART_1_LINE_CODING_CHANGED        (0x01u)
#define UART_1_LINE_CONTROL_CHANGED       (0x02u)

#define UART_1_1_STOPBIT                  (0x00u)
#define UART_1_1_5_STOPBITS               (0x01u)
#define UART_1_2_STOPBITS                 (0x02u)

#define UART_1_PARITY_NONE                (0x00u)
#define UART_1_PARITY_ODD                 (0x01u)
#define UART_1_PARITY_EVEN                (0x02u)
#define UART_1_PARITY_MARK                (0x03u)
#define UART_1_PARITY_SPACE               (0x04u)

#define UART_1_LINE_CODING_SIZE           (0x07u)
#define UART_1_LINE_CODING_RATE           (0x00u)
#define UART_1_LINE_CODING_STOP_BITS      (0x04u)
#define UART_1_LINE_CODING_PARITY         (0x05u)
#define UART_1_LINE_CODING_DATA_BITS      (0x06u)

#define UART_1_LINE_CONTROL_DTR           (0x01u)
#define UART_1_LINE_CONTROL_RTS           (0x02u)

#define UART_1_MAX_MULTI_COM_NUM          (2u) 

#define UART_1_COM_PORT1                  (0u) 
#define UART_1_COM_PORT2                  (1u) 

#define UART_1_SUCCESS                    (0u)
#define UART_1_FAILURE                    (1u)

#define UART_1_SERIAL_STATE_SIZE          (10u)

/* SerialState constants*/
#define UART_1_SERIAL_STATE_REQUEST_TYPE  (0xA1u)
#define UART_1_SERIAL_STATE_LENGTH        (0x2u)

/*******************************************************************************
* External data references
*******************************************************************************/
/**
* \addtogroup group_cdc
* @{
*/
extern volatile uint8  UART_1_linesCoding[UART_1_MAX_MULTI_COM_NUM][UART_1_LINE_CODING_SIZE];
extern volatile uint8  UART_1_linesChanged[UART_1_MAX_MULTI_COM_NUM];
extern volatile uint16 UART_1_linesControlBitmap[UART_1_MAX_MULTI_COM_NUM];
extern volatile uint16 UART_1_serialStateBitmap[UART_1_MAX_MULTI_COM_NUM];
extern volatile uint8  UART_1_cdcDataInEp[UART_1_MAX_MULTI_COM_NUM];
extern volatile uint8  UART_1_cdcDataOutEp[UART_1_MAX_MULTI_COM_NUM];
extern volatile uint8  UART_1_cdcCommInInterruptEp[UART_1_MAX_MULTI_COM_NUM];
/** @} cdc */

/*******************************************************************************
* The following code is DEPRECATED and
* must not be used.
*******************************************************************************/


#define UART_1_lineCoding             UART_1_linesCoding[0]
#define UART_1_lineChanged            UART_1_linesChanged[0]
#define UART_1_lineControlBitmap      UART_1_linesControlBitmap[0]
#define UART_1_cdc_data_in_ep         UART_1_cdcDataInEp[0]
#define UART_1_cdc_data_out_ep        UART_1_cdcDataOutEp[0]

#endif /* (CY_USBFS_UART_1_cdc_H) */


/* [] END OF FILE */
