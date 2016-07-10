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

#if !defined(CY_USBFS_USBFS_1_pvt_H)
#define CY_USBFS_USBFS_1_pvt_H

#include "USBFS_1.h"
   
#ifdef USBFS_1_ENABLE_AUDIO_CLASS
    #include "USBFS_1_audio.h"
#endif /* USBFS_1_ENABLE_AUDIO_CLASS */

#ifdef USBFS_1_ENABLE_CDC_CLASS
    #include "USBFS_1_cdc.h"
#endif /* USBFS_1_ENABLE_CDC_CLASS */

#if (USBFS_1_ENABLE_MIDI_CLASS)
    #include "USBFS_1_midi.h"
#endif /* (USBFS_1_ENABLE_MIDI_CLASS) */

#if (USBFS_1_ENABLE_MSC_CLASS)
    #include "USBFS_1_msc.h"
#endif /* (USBFS_1_ENABLE_MSC_CLASS) */

#if (USBFS_1_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        #include <CyDMA.h>
    #else
        #include <CyDmac.h>
        #if ((USBFS_1_EP_MANAGEMENT_DMA_AUTO) && (USBFS_1_EP_DMA_AUTO_OPT == 0u))
            #include "USBFS_1_EP_DMA_Done_isr.h"
            #include "USBFS_1_EP8_DMA_Done_SR.h"
            #include "USBFS_1_EP17_DMA_Done_SR.h"
        #endif /* ((USBFS_1_EP_MANAGEMENT_DMA_AUTO) && (USBFS_1_EP_DMA_AUTO_OPT == 0u)) */
    #endif /* (CY_PSOC4) */
#endif /* (USBFS_1_EP_MANAGEMENT_DMA) */

#if (USBFS_1_DMA1_ACTIVE)
    #include "USBFS_1_ep1_dma.h"
    #define USBFS_1_EP1_DMA_CH     (USBFS_1_ep1_dma_CHANNEL)
#endif /* (USBFS_1_DMA1_ACTIVE) */

#if (USBFS_1_DMA2_ACTIVE)
    #include "USBFS_1_ep2_dma.h"
    #define USBFS_1_EP2_DMA_CH     (USBFS_1_ep2_dma_CHANNEL)
#endif /* (USBFS_1_DMA2_ACTIVE) */

#if (USBFS_1_DMA3_ACTIVE)
    #include "USBFS_1_ep3_dma.h"
    #define USBFS_1_EP3_DMA_CH     (USBFS_1_ep3_dma_CHANNEL)
#endif /* (USBFS_1_DMA3_ACTIVE) */

#if (USBFS_1_DMA4_ACTIVE)
    #include "USBFS_1_ep4_dma.h"
    #define USBFS_1_EP4_DMA_CH     (USBFS_1_ep4_dma_CHANNEL)
#endif /* (USBFS_1_DMA4_ACTIVE) */

#if (USBFS_1_DMA5_ACTIVE)
    #include "USBFS_1_ep5_dma.h"
    #define USBFS_1_EP5_DMA_CH     (USBFS_1_ep5_dma_CHANNEL)
#endif /* (USBFS_1_DMA5_ACTIVE) */

#if (USBFS_1_DMA6_ACTIVE)
    #include "USBFS_1_ep6_dma.h"
    #define USBFS_1_EP6_DMA_CH     (USBFS_1_ep6_dma_CHANNEL)
#endif /* (USBFS_1_DMA6_ACTIVE) */

#if (USBFS_1_DMA7_ACTIVE)
    #include "USBFS_1_ep7_dma.h"
    #define USBFS_1_EP7_DMA_CH     (USBFS_1_ep7_dma_CHANNEL)
#endif /* (USBFS_1_DMA7_ACTIVE) */

#if (USBFS_1_DMA8_ACTIVE)
    #include "USBFS_1_ep8_dma.h"
    #define USBFS_1_EP8_DMA_CH     (USBFS_1_ep8_dma_CHANNEL)
#endif /* (USBFS_1_DMA8_ACTIVE) */


/***************************************
*     Private Variables
***************************************/

/* Generated external references for descriptors. */
extern const uint8 CYCODE USBFS_1_DEVICE0_DESCR[18u];
extern const uint8 CYCODE USBFS_1_DEVICE0_CONFIGURATION0_DESCR[123u];
extern const T_USBFS_1_EP_SETTINGS_BLOCK CYCODE USBFS_1_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[2u];
extern const uint8 CYCODE USBFS_1_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[2u];
extern const T_USBFS_1_LUT CYCODE USBFS_1_DEVICE0_CONFIGURATION0_TABLE[5u];
extern const T_USBFS_1_LUT CYCODE USBFS_1_DEVICE0_TABLE[3u];
extern const T_USBFS_1_LUT CYCODE USBFS_1_TABLE[1u];
extern const uint8 CYCODE USBFS_1_STRING_DESCRIPTORS[161u];


extern const uint8 CYCODE USBFS_1_MSOS_DESCRIPTOR[USBFS_1_MSOS_DESCRIPTOR_LENGTH];
extern const uint8 CYCODE USBFS_1_MSOS_CONFIGURATION_DESCR[USBFS_1_MSOS_CONF_DESCR_LENGTH];
#if defined(USBFS_1_ENABLE_IDSN_STRING)
    extern uint8 USBFS_1_idSerialNumberStringDescriptor[USBFS_1_IDSN_DESCR_LENGTH];
#endif /* (USBFS_1_ENABLE_IDSN_STRING) */

extern volatile uint8 USBFS_1_interfaceNumber;
extern volatile uint8 USBFS_1_interfaceSetting[USBFS_1_MAX_INTERFACES_NUMBER];
extern volatile uint8 USBFS_1_interfaceSettingLast[USBFS_1_MAX_INTERFACES_NUMBER];
extern volatile uint8 USBFS_1_deviceAddress;
extern volatile uint8 USBFS_1_interfaceStatus[USBFS_1_MAX_INTERFACES_NUMBER];
extern const uint8 CYCODE *USBFS_1_interfaceClass;

extern volatile T_USBFS_1_EP_CTL_BLOCK USBFS_1_EP[USBFS_1_MAX_EP];
extern volatile T_USBFS_1_TD USBFS_1_currentTD;

#if (USBFS_1_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        extern const uint8 USBFS_1_DmaChan[USBFS_1_MAX_EP];
    #else
        extern uint8 USBFS_1_DmaChan[USBFS_1_MAX_EP];
        extern uint8 USBFS_1_DmaTd  [USBFS_1_MAX_EP];
    #endif /* (CY_PSOC4) */
#endif /* (USBFS_1_EP_MANAGEMENT_DMA) */

#if (USBFS_1_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    extern uint8  USBFS_1_DmaEpBurstCnt   [USBFS_1_MAX_EP];
    extern uint8  USBFS_1_DmaEpLastBurstEl[USBFS_1_MAX_EP];

    extern uint8  USBFS_1_DmaEpBurstCntBackup  [USBFS_1_MAX_EP];
    extern uint32 USBFS_1_DmaEpBufferAddrBackup[USBFS_1_MAX_EP];
    
    extern const uint8 USBFS_1_DmaReqOut     [USBFS_1_MAX_EP];    
    extern const uint8 USBFS_1_DmaBurstEndOut[USBFS_1_MAX_EP];
#else
    #if (USBFS_1_EP_DMA_AUTO_OPT == 0u)
        extern uint8 USBFS_1_DmaNextTd[USBFS_1_MAX_EP];
        extern volatile uint16 USBFS_1_inLength [USBFS_1_MAX_EP];
        extern volatile uint8  USBFS_1_inBufFull[USBFS_1_MAX_EP];
        extern const uint8 USBFS_1_epX_TD_TERMOUT_EN[USBFS_1_MAX_EP];
        extern const uint8 *USBFS_1_inDataPointer[USBFS_1_MAX_EP];
    #endif /* (USBFS_1_EP_DMA_AUTO_OPT == 0u) */
#endif /* CY_PSOC4 */
#endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO) */

extern volatile uint8 USBFS_1_ep0Toggle;
extern volatile uint8 USBFS_1_lastPacketSize;
extern volatile uint8 USBFS_1_ep0Mode;
extern volatile uint8 USBFS_1_ep0Count;
extern volatile uint16 USBFS_1_transferByteCount;


/***************************************
*     Private Function Prototypes
***************************************/
void  USBFS_1_ReInitComponent(void)            ;
void  USBFS_1_HandleSetup(void)                ;
void  USBFS_1_HandleIN(void)                   ;
void  USBFS_1_HandleOUT(void)                  ;
void  USBFS_1_LoadEP0(void)                    ;
uint8 USBFS_1_InitControlRead(void)            ;
uint8 USBFS_1_InitControlWrite(void)           ;
void  USBFS_1_ControlReadDataStage(void)       ;
void  USBFS_1_ControlReadStatusStage(void)     ;
void  USBFS_1_ControlReadPrematureStatus(void) ;
uint8 USBFS_1_InitControlWrite(void)           ;
uint8 USBFS_1_InitZeroLengthControlTransfer(void) ;
void  USBFS_1_ControlWriteDataStage(void)      ;
void  USBFS_1_ControlWriteStatusStage(void)    ;
void  USBFS_1_ControlWritePrematureStatus(void);
uint8 USBFS_1_InitNoDataControlTransfer(void)  ;
void  USBFS_1_NoDataControlStatusStage(void)   ;
void  USBFS_1_InitializeStatusBlock(void)      ;
void  USBFS_1_UpdateStatusBlock(uint8 completionCode) ;
uint8 USBFS_1_DispatchClassRqst(void)          ;

void USBFS_1_Config(uint8 clearAltSetting) ;
void USBFS_1_ConfigAltChanged(void)        ;
void USBFS_1_ConfigReg(void)               ;
void USBFS_1_EpStateInit(void)             ;


const T_USBFS_1_LUT CYCODE *USBFS_1_GetConfigTablePtr(uint8 confIndex);
const T_USBFS_1_LUT CYCODE *USBFS_1_GetDeviceTablePtr(void)           ;
#if (USBFS_1_BOS_ENABLE)
    const T_USBFS_1_LUT CYCODE *USBFS_1_GetBOSPtr(void)               ;
#endif /* (USBFS_1_BOS_ENABLE) */
const uint8 CYCODE *USBFS_1_GetInterfaceClassTablePtr(void)                    ;uint8 USBFS_1_ClearEndpointHalt(void)                                          ;
uint8 USBFS_1_SetEndpointHalt(void)                                            ;
uint8 USBFS_1_ValidateAlternateSetting(void)                                   ;

void USBFS_1_SaveConfig(void)      ;
void USBFS_1_RestoreConfig(void)   ;

#if (CY_PSOC3 || CY_PSOC5LP)
    #if (USBFS_1_EP_MANAGEMENT_DMA_AUTO && (USBFS_1_EP_DMA_AUTO_OPT == 0u))
        void USBFS_1_LoadNextInEP(uint8 epNumber, uint8 mode)  ;
    #endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO && (USBFS_1_EP_DMA_AUTO_OPT == 0u)) */
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

#if defined(USBFS_1_ENABLE_IDSN_STRING)
    void USBFS_1_ReadDieID(uint8 descr[])  ;
#endif /* USBFS_1_ENABLE_IDSN_STRING */

#if defined(USBFS_1_ENABLE_HID_CLASS)
    uint8 USBFS_1_DispatchHIDClassRqst(void) ;
#endif /* (USBFS_1_ENABLE_HID_CLASS) */

#if defined(USBFS_1_ENABLE_AUDIO_CLASS)
    uint8 USBFS_1_DispatchAUDIOClassRqst(void) ;
#endif /* (USBFS_1_ENABLE_AUDIO_CLASS) */

#if defined(USBFS_1_ENABLE_CDC_CLASS)
    uint8 USBFS_1_DispatchCDCClassRqst(void) ;
#endif /* (USBFS_1_ENABLE_CDC_CLASS) */

#if (USBFS_1_ENABLE_MSC_CLASS)
    #if (USBFS_1_HANDLE_MSC_REQUESTS)
        uint8 USBFS_1_DispatchMSCClassRqst(void) ;
    #endif /* (USBFS_1_HANDLE_MSC_REQUESTS) */
#endif /* (USBFS_1_ENABLE_MSC_CLASS */

CY_ISR_PROTO(USBFS_1_EP_0_ISR);
CY_ISR_PROTO(USBFS_1_BUS_RESET_ISR);

#if (USBFS_1_SOF_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_SOF_ISR);
#endif /* (USBFS_1_SOF_ISR_ACTIVE) */

#if (USBFS_1_EP1_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_EP_1_ISR);
#endif /* (USBFS_1_EP1_ISR_ACTIVE) */

#if (USBFS_1_EP2_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_EP_2_ISR);
#endif /* (USBFS_1_EP2_ISR_ACTIVE) */

#if (USBFS_1_EP3_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_EP_3_ISR);
#endif /* (USBFS_1_EP3_ISR_ACTIVE) */

#if (USBFS_1_EP4_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_EP_4_ISR);
#endif /* (USBFS_1_EP4_ISR_ACTIVE) */

#if (USBFS_1_EP5_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_EP_5_ISR);
#endif /* (USBFS_1_EP5_ISR_ACTIVE) */

#if (USBFS_1_EP6_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_EP_6_ISR);
#endif /* (USBFS_1_EP6_ISR_ACTIVE) */

#if (USBFS_1_EP7_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_EP_7_ISR);
#endif /* (USBFS_1_EP7_ISR_ACTIVE) */

#if (USBFS_1_EP8_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_EP_8_ISR);
#endif /* (USBFS_1_EP8_ISR_ACTIVE) */

#if (USBFS_1_EP_MANAGEMENT_DMA)
    CY_ISR_PROTO(USBFS_1_ARB_ISR);
#endif /* (USBFS_1_EP_MANAGEMENT_DMA) */

#if (USBFS_1_DP_ISR_ACTIVE)
    CY_ISR_PROTO(USBFS_1_DP_ISR);
#endif /* (USBFS_1_DP_ISR_ACTIVE) */

#if (CY_PSOC4)
    CY_ISR_PROTO(USBFS_1_INTR_HI_ISR);
    CY_ISR_PROTO(USBFS_1_INTR_MED_ISR);
    CY_ISR_PROTO(USBFS_1_INTR_LO_ISR);
    #if (USBFS_1_LPM_ACTIVE)
        CY_ISR_PROTO(USBFS_1_LPM_ISR);
    #endif /* (USBFS_1_LPM_ACTIVE) */
#endif /* (CY_PSOC4) */

#if (USBFS_1_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    #if (USBFS_1_DMA1_ACTIVE)
        void USBFS_1_EP1_DMA_DONE_ISR(void);
    #endif /* (USBFS_1_DMA1_ACTIVE) */

    #if (USBFS_1_DMA2_ACTIVE)
        void USBFS_1_EP2_DMA_DONE_ISR(void);
    #endif /* (USBFS_1_DMA2_ACTIVE) */

    #if (USBFS_1_DMA3_ACTIVE)
        void USBFS_1_EP3_DMA_DONE_ISR(void);
    #endif /* (USBFS_1_DMA3_ACTIVE) */

    #if (USBFS_1_DMA4_ACTIVE)
        void USBFS_1_EP4_DMA_DONE_ISR(void);
    #endif /* (USBFS_1_DMA4_ACTIVE) */

    #if (USBFS_1_DMA5_ACTIVE)
        void USBFS_1_EP5_DMA_DONE_ISR(void);
    #endif /* (USBFS_1_DMA5_ACTIVE) */

    #if (USBFS_1_DMA6_ACTIVE)
        void USBFS_1_EP6_DMA_DONE_ISR(void);
    #endif /* (USBFS_1_DMA6_ACTIVE) */

    #if (USBFS_1_DMA7_ACTIVE)
        void USBFS_1_EP7_DMA_DONE_ISR(void);
    #endif /* (USBFS_1_DMA7_ACTIVE) */

    #if (USBFS_1_DMA8_ACTIVE)
        void USBFS_1_EP8_DMA_DONE_ISR(void);
    #endif /* (USBFS_1_DMA8_ACTIVE) */

#else
    #if (USBFS_1_EP_DMA_AUTO_OPT == 0u)
        CY_ISR_PROTO(USBFS_1_EP_DMA_DONE_ISR);
    #endif /* (USBFS_1_EP_DMA_AUTO_OPT == 0u) */
#endif /* (CY_PSOC4) */
#endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO) */


/***************************************
*         Request Handlers
***************************************/

uint8 USBFS_1_HandleStandardRqst(void) ;
uint8 USBFS_1_DispatchClassRqst(void)  ;
uint8 USBFS_1_HandleVendorRqst(void)   ;


/***************************************
*    HID Internal references
***************************************/

#if defined(USBFS_1_ENABLE_HID_CLASS)
    void USBFS_1_FindReport(void)            ;
    void USBFS_1_FindReportDescriptor(void)  ;
    void USBFS_1_FindHidClassDecriptor(void) ;
#endif /* USBFS_1_ENABLE_HID_CLASS */


/***************************************
*    MIDI Internal references
***************************************/

#if defined(USBFS_1_ENABLE_MIDI_STREAMING)
    void USBFS_1_MIDI_IN_EP_Service(void)  ;
#endif /* (USBFS_1_ENABLE_MIDI_STREAMING) */


/***************************************
*    CDC Internal references
***************************************/

#if defined(USBFS_1_ENABLE_CDC_CLASS)

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
    } t_USBFS_1_cdc_notification;

    uint8 USBFS_1_GetInterfaceComPort(uint8 interface) ;
    uint8 USBFS_1_Cdc_EpInit( const T_USBFS_1_EP_SETTINGS_BLOCK CYCODE *pEP, uint8 epNum, uint8 cdcComNums) ;

    extern volatile uint8  USBFS_1_cdc_dataInEpList[USBFS_1_MAX_MULTI_COM_NUM];
    extern volatile uint8  USBFS_1_cdc_dataOutEpList[USBFS_1_MAX_MULTI_COM_NUM];
    extern volatile uint8  USBFS_1_cdc_commInEpList[USBFS_1_MAX_MULTI_COM_NUM];
#endif /* (USBFS_1_ENABLE_CDC_CLASS) */


#endif /* CY_USBFS_USBFS_1_pvt_H */


/* [] END OF FILE */
