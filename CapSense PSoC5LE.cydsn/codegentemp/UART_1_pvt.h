/***************************************************************************//**
* \file .h
* \version 3.0
*
* \brief
*  This file provides private function prototypes and constants for the 
*  USBFS component. It is not intended to be used in the user project.
*
********************************************************************************
* \copyright
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_UART_1_pvt_H)
#define CY_USBFS_UART_1_pvt_H

#include "UART_1.h"
   
#ifdef UART_1_ENABLE_AUDIO_CLASS
    #include "UART_1_audio.h"
#endif /* UART_1_ENABLE_AUDIO_CLASS */

#ifdef UART_1_ENABLE_CDC_CLASS
    #include "UART_1_cdc.h"
#endif /* UART_1_ENABLE_CDC_CLASS */

#if (UART_1_ENABLE_MIDI_CLASS)
    #include "UART_1_midi.h"
#endif /* (UART_1_ENABLE_MIDI_CLASS) */

#if (UART_1_ENABLE_MSC_CLASS)
    #include "UART_1_msc.h"
#endif /* (UART_1_ENABLE_MSC_CLASS) */

#if (UART_1_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        #include <CyDMA.h>
    #else
        #include <CyDmac.h>
        #if ((UART_1_EP_MANAGEMENT_DMA_AUTO) && (UART_1_EP_DMA_AUTO_OPT == 0u))
            #include "UART_1_EP_DMA_Done_isr.h"
            #include "UART_1_EP8_DMA_Done_SR.h"
            #include "UART_1_EP17_DMA_Done_SR.h"
        #endif /* ((UART_1_EP_MANAGEMENT_DMA_AUTO) && (UART_1_EP_DMA_AUTO_OPT == 0u)) */
    #endif /* (CY_PSOC4) */
#endif /* (UART_1_EP_MANAGEMENT_DMA) */

#if (UART_1_DMA1_ACTIVE)
    #include "UART_1_ep1_dma.h"
    #define UART_1_EP1_DMA_CH     (UART_1_ep1_dma_CHANNEL)
#endif /* (UART_1_DMA1_ACTIVE) */

#if (UART_1_DMA2_ACTIVE)
    #include "UART_1_ep2_dma.h"
    #define UART_1_EP2_DMA_CH     (UART_1_ep2_dma_CHANNEL)
#endif /* (UART_1_DMA2_ACTIVE) */

#if (UART_1_DMA3_ACTIVE)
    #include "UART_1_ep3_dma.h"
    #define UART_1_EP3_DMA_CH     (UART_1_ep3_dma_CHANNEL)
#endif /* (UART_1_DMA3_ACTIVE) */

#if (UART_1_DMA4_ACTIVE)
    #include "UART_1_ep4_dma.h"
    #define UART_1_EP4_DMA_CH     (UART_1_ep4_dma_CHANNEL)
#endif /* (UART_1_DMA4_ACTIVE) */

#if (UART_1_DMA5_ACTIVE)
    #include "UART_1_ep5_dma.h"
    #define UART_1_EP5_DMA_CH     (UART_1_ep5_dma_CHANNEL)
#endif /* (UART_1_DMA5_ACTIVE) */

#if (UART_1_DMA6_ACTIVE)
    #include "UART_1_ep6_dma.h"
    #define UART_1_EP6_DMA_CH     (UART_1_ep6_dma_CHANNEL)
#endif /* (UART_1_DMA6_ACTIVE) */

#if (UART_1_DMA7_ACTIVE)
    #include "UART_1_ep7_dma.h"
    #define UART_1_EP7_DMA_CH     (UART_1_ep7_dma_CHANNEL)
#endif /* (UART_1_DMA7_ACTIVE) */

#if (UART_1_DMA8_ACTIVE)
    #include "UART_1_ep8_dma.h"
    #define UART_1_EP8_DMA_CH     (UART_1_ep8_dma_CHANNEL)
#endif /* (UART_1_DMA8_ACTIVE) */


/***************************************
*     Private Variables
***************************************/

/* Generated external references for descriptors. */
extern const uint8 CYCODE UART_1_DEVICE0_DESCR[18u];
extern const uint8 CYCODE UART_1_DEVICE0_CONFIGURATION0_DESCR[67u];
extern const T_UART_1_EP_SETTINGS_BLOCK CYCODE UART_1_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[3u];
extern const uint8 CYCODE UART_1_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[2u];
extern const T_UART_1_LUT CYCODE UART_1_DEVICE0_CONFIGURATION0_TABLE[5u];
extern const T_UART_1_LUT CYCODE UART_1_DEVICE0_TABLE[3u];
extern const T_UART_1_LUT CYCODE UART_1_TABLE[1u];
extern const uint8 CYCODE UART_1_SN_STRING_DESCRIPTOR[2];
extern const uint8 CYCODE UART_1_STRING_DESCRIPTORS[159u];


extern const uint8 CYCODE UART_1_MSOS_DESCRIPTOR[UART_1_MSOS_DESCRIPTOR_LENGTH];
extern const uint8 CYCODE UART_1_MSOS_CONFIGURATION_DESCR[UART_1_MSOS_CONF_DESCR_LENGTH];
#if defined(UART_1_ENABLE_IDSN_STRING)
    extern uint8 UART_1_idSerialNumberStringDescriptor[UART_1_IDSN_DESCR_LENGTH];
#endif /* (UART_1_ENABLE_IDSN_STRING) */

extern volatile uint8 UART_1_interfaceNumber;
extern volatile uint8 UART_1_interfaceSetting[UART_1_MAX_INTERFACES_NUMBER];
extern volatile uint8 UART_1_interfaceSettingLast[UART_1_MAX_INTERFACES_NUMBER];
extern volatile uint8 UART_1_deviceAddress;
extern volatile uint8 UART_1_interfaceStatus[UART_1_MAX_INTERFACES_NUMBER];
extern const uint8 CYCODE *UART_1_interfaceClass;

extern volatile T_UART_1_EP_CTL_BLOCK UART_1_EP[UART_1_MAX_EP];
extern volatile T_UART_1_TD UART_1_currentTD;

#if (UART_1_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        extern const uint8 UART_1_DmaChan[UART_1_MAX_EP];
    #else
        extern uint8 UART_1_DmaChan[UART_1_MAX_EP];
        extern uint8 UART_1_DmaTd  [UART_1_MAX_EP];
    #endif /* (CY_PSOC4) */
#endif /* (UART_1_EP_MANAGEMENT_DMA) */

#if (UART_1_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    extern uint8  UART_1_DmaEpBurstCnt   [UART_1_MAX_EP];
    extern uint8  UART_1_DmaEpLastBurstEl[UART_1_MAX_EP];

    extern uint8  UART_1_DmaEpBurstCntBackup  [UART_1_MAX_EP];
    extern uint32 UART_1_DmaEpBufferAddrBackup[UART_1_MAX_EP];
    
    extern const uint8 UART_1_DmaReqOut     [UART_1_MAX_EP];    
    extern const uint8 UART_1_DmaBurstEndOut[UART_1_MAX_EP];
#else
    #if (UART_1_EP_DMA_AUTO_OPT == 0u)
        extern uint8 UART_1_DmaNextTd[UART_1_MAX_EP];
        extern volatile uint16 UART_1_inLength [UART_1_MAX_EP];
        extern volatile uint8  UART_1_inBufFull[UART_1_MAX_EP];
        extern const uint8 UART_1_epX_TD_TERMOUT_EN[UART_1_MAX_EP];
        extern const uint8 *UART_1_inDataPointer[UART_1_MAX_EP];
    #endif /* (UART_1_EP_DMA_AUTO_OPT == 0u) */
#endif /* CY_PSOC4 */
#endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */

extern volatile uint8 UART_1_ep0Toggle;
extern volatile uint8 UART_1_lastPacketSize;
extern volatile uint8 UART_1_ep0Mode;
extern volatile uint8 UART_1_ep0Count;
extern volatile uint16 UART_1_transferByteCount;


/***************************************
*     Private Function Prototypes
***************************************/
void  UART_1_ReInitComponent(void)            ;
void  UART_1_HandleSetup(void)                ;
void  UART_1_HandleIN(void)                   ;
void  UART_1_HandleOUT(void)                  ;
void  UART_1_LoadEP0(void)                    ;
uint8 UART_1_InitControlRead(void)            ;
uint8 UART_1_InitControlWrite(void)           ;
void  UART_1_ControlReadDataStage(void)       ;
void  UART_1_ControlReadStatusStage(void)     ;
void  UART_1_ControlReadPrematureStatus(void) ;
uint8 UART_1_InitControlWrite(void)           ;
uint8 UART_1_InitZeroLengthControlTransfer(void) ;
void  UART_1_ControlWriteDataStage(void)      ;
void  UART_1_ControlWriteStatusStage(void)    ;
void  UART_1_ControlWritePrematureStatus(void);
uint8 UART_1_InitNoDataControlTransfer(void)  ;
void  UART_1_NoDataControlStatusStage(void)   ;
void  UART_1_InitializeStatusBlock(void)      ;
void  UART_1_UpdateStatusBlock(uint8 completionCode) ;
uint8 UART_1_DispatchClassRqst(void)          ;

void UART_1_Config(uint8 clearAltSetting) ;
void UART_1_ConfigAltChanged(void)        ;
void UART_1_ConfigReg(void)               ;
void UART_1_EpStateInit(void)             ;


const T_UART_1_LUT CYCODE *UART_1_GetConfigTablePtr(uint8 confIndex);
const T_UART_1_LUT CYCODE *UART_1_GetDeviceTablePtr(void)           ;
#if (UART_1_BOS_ENABLE)
    const T_UART_1_LUT CYCODE *UART_1_GetBOSPtr(void)               ;
#endif /* (UART_1_BOS_ENABLE) */
const uint8 CYCODE *UART_1_GetInterfaceClassTablePtr(void)                    ;uint8 UART_1_ClearEndpointHalt(void)                                          ;
uint8 UART_1_SetEndpointHalt(void)                                            ;
uint8 UART_1_ValidateAlternateSetting(void)                                   ;

void UART_1_SaveConfig(void)      ;
void UART_1_RestoreConfig(void)   ;

#if (CY_PSOC3 || CY_PSOC5LP)
    #if (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u))
        void UART_1_LoadNextInEP(uint8 epNumber, uint8 mode)  ;
    #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u)) */
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

#if defined(UART_1_ENABLE_IDSN_STRING)
    void UART_1_ReadDieID(uint8 descr[])  ;
#endif /* UART_1_ENABLE_IDSN_STRING */

#if defined(UART_1_ENABLE_HID_CLASS)
    uint8 UART_1_DispatchHIDClassRqst(void) ;
#endif /* (UART_1_ENABLE_HID_CLASS) */

#if defined(UART_1_ENABLE_AUDIO_CLASS)
    uint8 UART_1_DispatchAUDIOClassRqst(void) ;
#endif /* (UART_1_ENABLE_AUDIO_CLASS) */

#if defined(UART_1_ENABLE_CDC_CLASS)
    uint8 UART_1_DispatchCDCClassRqst(void) ;
#endif /* (UART_1_ENABLE_CDC_CLASS) */

#if (UART_1_ENABLE_MSC_CLASS)
    #if (UART_1_HANDLE_MSC_REQUESTS)
        uint8 UART_1_DispatchMSCClassRqst(void) ;
    #endif /* (UART_1_HANDLE_MSC_REQUESTS) */
#endif /* (UART_1_ENABLE_MSC_CLASS */

CY_ISR_PROTO(UART_1_EP_0_ISR);
CY_ISR_PROTO(UART_1_BUS_RESET_ISR);

#if (UART_1_SOF_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_SOF_ISR);
#endif /* (UART_1_SOF_ISR_ACTIVE) */

#if (UART_1_EP1_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_EP_1_ISR);
#endif /* (UART_1_EP1_ISR_ACTIVE) */

#if (UART_1_EP2_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_EP_2_ISR);
#endif /* (UART_1_EP2_ISR_ACTIVE) */

#if (UART_1_EP3_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_EP_3_ISR);
#endif /* (UART_1_EP3_ISR_ACTIVE) */

#if (UART_1_EP4_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_EP_4_ISR);
#endif /* (UART_1_EP4_ISR_ACTIVE) */

#if (UART_1_EP5_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_EP_5_ISR);
#endif /* (UART_1_EP5_ISR_ACTIVE) */

#if (UART_1_EP6_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_EP_6_ISR);
#endif /* (UART_1_EP6_ISR_ACTIVE) */

#if (UART_1_EP7_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_EP_7_ISR);
#endif /* (UART_1_EP7_ISR_ACTIVE) */

#if (UART_1_EP8_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_EP_8_ISR);
#endif /* (UART_1_EP8_ISR_ACTIVE) */

#if (UART_1_EP_MANAGEMENT_DMA)
    CY_ISR_PROTO(UART_1_ARB_ISR);
#endif /* (UART_1_EP_MANAGEMENT_DMA) */

#if (UART_1_DP_ISR_ACTIVE)
    CY_ISR_PROTO(UART_1_DP_ISR);
#endif /* (UART_1_DP_ISR_ACTIVE) */

#if (CY_PSOC4)
    CY_ISR_PROTO(UART_1_INTR_HI_ISR);
    CY_ISR_PROTO(UART_1_INTR_MED_ISR);
    CY_ISR_PROTO(UART_1_INTR_LO_ISR);
    #if (UART_1_LPM_ACTIVE)
        CY_ISR_PROTO(UART_1_LPM_ISR);
    #endif /* (UART_1_LPM_ACTIVE) */
#endif /* (CY_PSOC4) */

#if (UART_1_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    #if (UART_1_DMA1_ACTIVE)
        void UART_1_EP1_DMA_DONE_ISR(void);
    #endif /* (UART_1_DMA1_ACTIVE) */

    #if (UART_1_DMA2_ACTIVE)
        void UART_1_EP2_DMA_DONE_ISR(void);
    #endif /* (UART_1_DMA2_ACTIVE) */

    #if (UART_1_DMA3_ACTIVE)
        void UART_1_EP3_DMA_DONE_ISR(void);
    #endif /* (UART_1_DMA3_ACTIVE) */

    #if (UART_1_DMA4_ACTIVE)
        void UART_1_EP4_DMA_DONE_ISR(void);
    #endif /* (UART_1_DMA4_ACTIVE) */

    #if (UART_1_DMA5_ACTIVE)
        void UART_1_EP5_DMA_DONE_ISR(void);
    #endif /* (UART_1_DMA5_ACTIVE) */

    #if (UART_1_DMA6_ACTIVE)
        void UART_1_EP6_DMA_DONE_ISR(void);
    #endif /* (UART_1_DMA6_ACTIVE) */

    #if (UART_1_DMA7_ACTIVE)
        void UART_1_EP7_DMA_DONE_ISR(void);
    #endif /* (UART_1_DMA7_ACTIVE) */

    #if (UART_1_DMA8_ACTIVE)
        void UART_1_EP8_DMA_DONE_ISR(void);
    #endif /* (UART_1_DMA8_ACTIVE) */

#else
    #if (UART_1_EP_DMA_AUTO_OPT == 0u)
        CY_ISR_PROTO(UART_1_EP_DMA_DONE_ISR);
    #endif /* (UART_1_EP_DMA_AUTO_OPT == 0u) */
#endif /* (CY_PSOC4) */
#endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */


/***************************************
*         Request Handlers
***************************************/

uint8 UART_1_HandleStandardRqst(void) ;
uint8 UART_1_DispatchClassRqst(void)  ;
uint8 UART_1_HandleVendorRqst(void)   ;


/***************************************
*    HID Internal references
***************************************/

#if defined(UART_1_ENABLE_HID_CLASS)
    void UART_1_FindReport(void)            ;
    void UART_1_FindReportDescriptor(void)  ;
    void UART_1_FindHidClassDecriptor(void) ;
#endif /* UART_1_ENABLE_HID_CLASS */


/***************************************
*    MIDI Internal references
***************************************/

#if defined(UART_1_ENABLE_MIDI_STREAMING)
    void UART_1_MIDI_IN_EP_Service(void)  ;
#endif /* (UART_1_ENABLE_MIDI_STREAMING) */


/***************************************
*    CDC Internal references
***************************************/

#if defined(UART_1_ENABLE_CDC_CLASS)

    typedef struct
    {
        uint8  bRequestType;
        uint8  bNotification;
        uint8  wValue;
        uint8  wValueMSB;
        uint8  wIndex;
        uint8  wIndexMSB;
        uint8  wLength;
        uint8  wLengthMSB;
        uint8  wSerialState;
        uint8  wSerialStateMSB;
    } t_UART_1_cdc_notification;

    uint8 UART_1_GetInterfaceComPort(uint8 interface) ;
    uint8 UART_1_Cdc_EpInit( const T_UART_1_EP_SETTINGS_BLOCK CYCODE *pEP, uint8 epNum, uint8 cdcComNums) ;

    extern volatile uint8  UART_1_cdc_dataInEpList[UART_1_MAX_MULTI_COM_NUM];
    extern volatile uint8  UART_1_cdc_dataOutEpList[UART_1_MAX_MULTI_COM_NUM];
    extern volatile uint8  UART_1_cdc_commInEpList[UART_1_MAX_MULTI_COM_NUM];
#endif /* (UART_1_ENABLE_CDC_CLASS) */


#endif /* CY_USBFS_UART_1_pvt_H */


/* [] END OF FILE */
