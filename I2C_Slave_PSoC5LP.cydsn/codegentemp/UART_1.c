/***************************************************************************//**
* \file UART_1.c
* \version 3.0
*
* \brief
*  This file contains the global USBFS API functions.
*
* Note:
*  Many of the functions use an endpoint number. SRAM arrays are sized with 9
*  elements, so they are indexed directly by epNumber.  The SIE and ARB
*  registers are indexed by variations of epNumber - 1.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_1_pvt.h"
#include "UART_1_cydmac.h"
#include "UART_1_hid.h"


/***************************************
* Global data allocation
***************************************/

/** Indicates whether the USBFS has been initialized. The variable is
* initialized to 0 after device reset and set to 1 the first time USBFS_Start()
* is called. This allows the Component to restart without reinitialization after
* the first call to the USBFS_Start() routine.
* If re-initialization of the Component is required, the variable should be set
* to 0 before the USBFS_Start() routine is called. Alternatively, the USBFS can
* be reinitialized by calling both USBFS_Init() and USBFS_InitComponent()
* functions.
*/
uint8 UART_1_initVar = 0u;

#if (UART_1_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        static void UART_1_InitEpDma(void);

        /* DMA chanels assigend for endpoints. */
        const uint8 UART_1_DmaChan[UART_1_MAX_EP] =
        {
            0u,
            0u,
            0u,
            0u,
            0u,
            0u,
            0u,
            0u,
            0u,
        };        
    #else
        /* DMA chanels assigend for endpoints. */
        uint8 UART_1_DmaChan[UART_1_MAX_EP];
        
        /* DMA TDs require for PSoC 3/5LP operation. */
        uint8 UART_1_DmaTd[UART_1_MAX_EP];
    #endif /* (CY_PSOC4) */
#endif /* (UART_1_EP_MANAGEMENT_DMA) */

#if (UART_1_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    /* Number of DMA bursts. */
    uint8  UART_1_DmaEpBurstCnt   [UART_1_MAX_EP];
    
    /* Number of bytes to transfer in last DMA burst. */
    uint8  UART_1_DmaEpLastBurstEl[UART_1_MAX_EP];

    /* Storage for arrays above. */
    uint8  UART_1_DmaEpBurstCntBackup  [UART_1_MAX_EP];
    uint32 UART_1_DmaEpBufferAddrBackup[UART_1_MAX_EP];
     
    /* DMA trigger mux output for usb.dma_req[0-7]. */
    const uint8 UART_1_DmaReqOut[UART_1_MAX_EP] =
    {
        0u,
        UART_1_ep1_dma__TR_OUTPUT,
        UART_1_ep2_dma__TR_OUTPUT,
        UART_1_ep3_dma__TR_OUTPUT,
        0u,
        0u,
        0u,
        0u,
        0u,
    };

    /* DMA trigger mux output for usb.dma_burstend[0-7]. */
    const uint8 UART_1_DmaBurstEndOut[UART_1_MAX_EP] =
    {
        0u,
        UART_1_BURSTEND_0_TR_OUTPUT,
        UART_1_BURSTEND_1_TR_OUTPUT,
        UART_1_BURSTEND_2_TR_OUTPUT,
        UART_1_BURSTEND_3_TR_OUTPUT,
        UART_1_BURSTEND_4_TR_OUTPUT,
        UART_1_BURSTEND_5_TR_OUTPUT,
        UART_1_BURSTEND_6_TR_OUTPUT,
        UART_1_BURSTEND_7_TR_OUTPUT
    };
    
#else
    #if (UART_1_EP_DMA_AUTO_OPT == 0u)
        static uint8 clearInDataRdyStatus = UART_1_ARB_EPX_CFG_DEFAULT;
        uint8 UART_1_DmaNextTd[UART_1_MAX_EP];
        const uint8 UART_1_epX_TD_TERMOUT_EN[UART_1_MAX_EP] =
        {
            0u,
            0u,
            0u,
            0u,
            0u,
            0u,
            0u,
            0u,
            0u,
        };

        volatile uint16 UART_1_inLength[UART_1_MAX_EP];
        const uint8 *UART_1_inDataPointer[UART_1_MAX_EP];
        volatile uint8 UART_1_inBufFull[UART_1_MAX_EP];
    #endif /* (UART_1_EP_DMA_AUTO_OPT == 0u) */
#endif /* (CY_PSOC4) */
#endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */


/*******************************************************************************
* Function Name: UART_1_Start
****************************************************************************//**
*
*   This function performs all required initialization for the USBFS component.
*   After this function call, the USB device initiates communication with the
*   host by pull-up D+ line. This is the preferred method to begin component
*   operation.
*
*   Note that global interrupts have to be enabled because interrupts are
*   required for USBFS component operation.
*
*   PSoC 4200L devices: when USBFS component configured to DMA with Automatic
*   Buffer Management, the DMA interrupt priority is changed to the highest
*   (priority 0) inside this function.
*
*   PSoC 3/PSoC 5LP devices: when USBFS component configured to DMA with
*   Automatic Buffer Management, the Arbiter interrupt priority is changed to
*   the highest (priority 0) inside this function.
*
*  \param device
*          Contains the device number of the desired device descriptor.
*          The device number can be found in the Device Descriptor Tab of
*          "Configure" dialog, under the settings of desired Device Descriptor,
*          in the "Device Number" field.
*  \param mode:
*   The operating voltage. This determines whether the voltage regulator
*   is enabled for 5V operation or if pass through mode is used for 3.3V
*   operation. Symbolic names and their associated values are given in the
*   following list.
*
*       *UART_1_3V_OPERATION* - Disable voltage regulator and pass-
*                                      through Vcc for pull-up
*
*       *UART_1_5V_OPERATION* - Enable voltage regulator and use
*                                      regulator for pull-up
*
*       *UART_1_DWR_POWER_OPERATION* - Enable or disable the voltage
*                                      regulator depending on the power supply
*                                      voltage configuration in the DWR tab.
*                                      For PSoC 3/5LP devices, the VDDD supply
*                                      voltage is considered and for PSoC 4A-L,
*                                      the VBUS supply voltage is considered.*
* \globalvars
*  \ref UART_1_initVar
*
* \sideeffect
*   This function will reset all communication states to default.
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_Start(uint8 device, uint8 mode) 
{
    if (0u == UART_1_initVar)
    {
        UART_1_Init();
        UART_1_initVar = 1u;
    }

    UART_1_InitComponent(device, mode);
}


/*******************************************************************************
* Function Name: UART_1_Init
****************************************************************************//**
*
* This function initializes or restores the component according to the
* customizer Configure dialog settings. It is not necessary to call
* UART_1_Init() because the UART_1_Start() routine calls
* this function and is the preferred method to begin component operation.
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_Init(void) 
{
#if (CY_PSOC4)
    /* Enable clock to USB IP. */
    UART_1_USB_CLK_EN_REG = UART_1_USB_CLK_CSR_CLK_EN;

    /* The internal regulator (CR1.REG_ENABLE) is enabled in
    * UART_1_InitComponent() if it is required.
    */

    /* Enable USBIO control on drive mode of D+ and D- pins. */
    UART_1_USBIO_CR1_REG &= ~ (uint32) UART_1_USBIO_CR1_IOMODE;

    /* Set number of LF CLK to detect UBS bus reset. */
    UART_1_BUS_RST_CNT_REG = UART_1_DEFUALT_BUS_RST_CNT;

    /* Select VBUS detection source and clear PHY isolate. The application level
    * must ensure that VBUS is valid. There is no need to wait 2us before VBUS is valid.
    */
    UART_1_POWER_CTRL_REG = UART_1_DEFAULT_POWER_CTRL_VBUS;

    /* Enable PHY detector and single-ended and differential receivers. */
    UART_1_POWER_CTRL_REG |= UART_1_DEFAULT_POWER_CTRL_PHY;

    /* Suspend clear sequence. */
    UART_1_POWER_CTRL_REG &= (uint32) ~UART_1_POWER_CTRL_SUSPEND;
    CyDelayUs(UART_1_WAIT_SUSPEND_DEL_DISABLE);
    UART_1_POWER_CTRL_REG &= (uint32) ~UART_1_POWER_CTRL_SUSPEND_DEL;

    /* Sets IMO lock options and clear all other bits. */
    UART_1_CR1_REG = UART_1_DEFUALT_CR1;

    /* Configure level (hi, lo, med) for each interrupt source. */
    UART_1_INTR_LVL_SEL_REG = UART_1_DEFAULT_INTR_LVL_SEL;

    /* Configure interrupt sources from: SOF, Bus Reset and EP0. */
    UART_1_INTR_SIE_MASK_REG = UART_1_DEFAULT_INTR_SIE_MASK;

#else
    uint8 enableInterrupts = CyEnterCriticalSection();

#if (UART_1_EP_MANAGEMENT_DMA)
    uint16 i;
#endif /* (UART_1_EP_MANAGEMENT_DMA) */

    /* Enable USB block. */
    UART_1_PM_ACT_CFG_REG |= UART_1_PM_ACT_EN_FSUSB;
    /* Enable USB block for Standby Power Mode. */
    UART_1_PM_STBY_CFG_REG |= UART_1_PM_STBY_EN_FSUSB;

    /* Enable core clock. */
    UART_1_USB_CLK_EN_REG = UART_1_USB_CLK_ENABLE;

    UART_1_CR1_REG = UART_1_CR1_ENABLE_LOCK;

    /* ENABLING USBIO PADS IN USB MODE FROM I/O MODE. */
    /* Ensure USB transmit enable is low (USB_USBIO_CR0.ten). - Manual Transmission - Disabled. */
    UART_1_USBIO_CR0_REG &= (uint8) ~UART_1_USBIO_CR0_TEN;
    CyDelayUs(UART_1_WAIT_REG_STABILITY_50NS);  /* ~50ns delay. */
    /* Disable USBIO by asserting PM.USB_CR0.fsusbio_pd_n(Inverted.
    *  high. These bits will be set low by the power manager out-of-reset.
    *  Also confirm USBIO pull-up is disabled.
    */
    UART_1_PM_USB_CR0_REG &= (uint8) ~(UART_1_PM_USB_CR0_PD_N |
                                                 UART_1_PM_USB_CR0_PD_PULLUP_N);

    /* Select IOMODE to USB mode. */
    UART_1_USBIO_CR1_REG &= (uint8) ~UART_1_USBIO_CR1_IOMODE;

    /* Enable USBIO reference by setting PM.USB_CR0.fsusbio_ref_en. */
    UART_1_PM_USB_CR0_REG |= UART_1_PM_USB_CR0_REF_EN;
    /* Reference is available for 1us after regulator is enabled. */
    CyDelayUs(UART_1_WAIT_REG_STABILITY_1US);
    /* OR 40us after power is restored. */
    CyDelayUs(UART_1_WAIT_VREF_RESTORE);
    /* Ensure single-ended disable bits are low (PRT15.INP_DIS[7:6])(input receiver enabled). */
    UART_1_DM_INP_DIS_REG &= (uint8) ~UART_1_DM_MASK;
    UART_1_DP_INP_DIS_REG &= (uint8) ~UART_1_DP_MASK;

    /* Enable USBIO. */
    UART_1_PM_USB_CR0_REG |= UART_1_PM_USB_CR0_PD_N;
    CyDelayUs(UART_1_WAIT_PD_PULLUP_N_ENABLE);
    /* Set USBIO pull-up enable. */
    UART_1_PM_USB_CR0_REG |= UART_1_PM_USB_CR0_PD_PULLUP_N;

    /* Reset Arbiter Write Address register for endpoint 1. */
    CY_SET_REG8(UART_1_ARB_RW1_WA_PTR,     0u);
    CY_SET_REG8(UART_1_ARB_RW1_WA_MSB_PTR, 0u);

#if (UART_1_EP_MANAGEMENT_DMA)
    /* Initialize transfer descriptor. This will be used to detect DMA state - initialized or not. */
    for (i = 0u; i < UART_1_MAX_EP; ++i)
    {
        UART_1_DmaTd[i] = DMA_INVALID_TD;

    #if (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u))
        UART_1_DmaNextTd[i] = DMA_INVALID_TD;
    #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u)) */
    }
#endif /* (UART_1_EP_MANAGEMENT_DMA) */

    CyExitCriticalSection(enableInterrupts);
#endif /* (CY_PSOC4) */

    /* Configure interrupts from USB block. */
#if (CY_PSOC4)
    /* Configure hi_int: set handler and priority. */
    CyIntSetPriority     (UART_1_INTR_HI_VECT_NUM,  UART_1_INTR_HI_PRIORITY);
    (void) CyIntSetVector(UART_1_INTR_HI_VECT_NUM, &UART_1_INTR_HI_ISR);

    /* Configure lo_int: set handler and priority. */
    CyIntSetPriority     (UART_1_INTR_LO_VECT_NUM,  UART_1_INTR_LO_PRIORITY);
    (void) CyIntSetVector(UART_1_INTR_LO_VECT_NUM, &UART_1_INTR_LO_ISR);

    /* Configure med_int: set handler and priority (routed through DSI). */
    CyIntSetPriority     (UART_1_INTR_MED_VECT_NUM,  UART_1_INTR_MED_PRIORITY);
    (void) CyIntSetVector(UART_1_INTR_MED_VECT_NUM, &UART_1_INTR_MED_ISR);

#else
    /* Set bus reset interrupt. */
    CyIntSetPriority(UART_1_BUS_RESET_VECT_NUM, UART_1_BUS_RESET_PRIOR);
    (void) CyIntSetVector(UART_1_BUS_RESET_VECT_NUM,   &UART_1_BUS_RESET_ISR);

    /* Set Control Endpoint Interrupt. */
    CyIntSetPriority(UART_1_EP_0_VECT_NUM, UART_1_EP_0_PRIOR);
    (void) CyIntSetVector(UART_1_EP_0_VECT_NUM,   &UART_1_EP_0_ISR);

    /* Set SOF interrupt. */
    #if (UART_1_SOF_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_SOF_VECT_NUM,  UART_1_SOF_PRIOR);
        (void) CyIntSetVector(UART_1_SOF_VECT_NUM, &UART_1_SOF_ISR);
    #endif /* (UART_1_SOF_ISR_ACTIVE) */

    /* Set Data Endpoint 1 Interrupt. */
    #if (UART_1_EP1_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_EP_1_VECT_NUM,  UART_1_EP_1_PRIOR);
        (void) CyIntSetVector(UART_1_EP_1_VECT_NUM,  &UART_1_EP_1_ISR);
    #endif /* (UART_1_EP1_ISR_ACTIVE) */

    /* Set Data Endpoint 2 Interrupt. */
    #if (UART_1_EP2_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_EP_2_VECT_NUM,  UART_1_EP_2_PRIOR);
        (void) CyIntSetVector(UART_1_EP_2_VECT_NUM, &UART_1_EP_2_ISR);
    #endif /* (UART_1_EP2_ISR_ACTIVE) */

    /* Set Data Endpoint 3 Interrupt. */
    #if (UART_1_EP3_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_EP_3_VECT_NUM,  UART_1_EP_3_PRIOR);
        (void) CyIntSetVector(UART_1_EP_3_VECT_NUM, &UART_1_EP_3_ISR);
    #endif /* (UART_1_EP3_ISR_ACTIVE) */

    /* Set Data Endpoint 4 Interrupt. */
    #if (UART_1_EP4_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_EP_4_VECT_NUM,  UART_1_EP_4_PRIOR);
        (void) CyIntSetVector(UART_1_EP_4_VECT_NUM, &UART_1_EP_4_ISR);
    #endif /* (UART_1_EP4_ISR_ACTIVE) */

    /* Set Data Endpoint 5 Interrupt. */
    #if (UART_1_EP5_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_EP_5_VECT_NUM,  UART_1_EP_5_PRIOR);
        (void) CyIntSetVector(UART_1_EP_5_VECT_NUM, &UART_1_EP_5_ISR);
    #endif /* (UART_1_EP5_ISR_ACTIVE) */

    /* Set Data Endpoint 6 Interrupt. */
    #if (UART_1_EP6_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_EP_6_VECT_NUM,  UART_1_EP_6_PRIOR);
        (void) CyIntSetVector(UART_1_EP_6_VECT_NUM, &UART_1_EP_6_ISR);
    #endif /* (UART_1_EP6_ISR_ACTIVE) */

     /* Set Data Endpoint 7 Interrupt. */
    #if (UART_1_EP7_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_EP_7_VECT_NUM,  UART_1_EP_7_PRIOR);
        (void) CyIntSetVector(UART_1_EP_7_VECT_NUM, &UART_1_EP_7_ISR);
    #endif /* (UART_1_EP7_ISR_ACTIVE) */

    /* Set Data Endpoint 8 Interrupt. */
    #if (UART_1_EP8_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_EP_8_VECT_NUM,  UART_1_EP_8_PRIOR);
        (void) CyIntSetVector(UART_1_EP_8_VECT_NUM, &UART_1_EP_8_ISR);
    #endif /* (UART_1_EP8_ISR_ACTIVE) */

    /* Set ARB Interrupt. */
    #if (UART_1_EP_MANAGEMENT_DMA && UART_1_ARB_ISR_ACTIVE)
        CyIntSetPriority     (UART_1_ARB_VECT_NUM,  UART_1_ARB_PRIOR);
        (void) CyIntSetVector(UART_1_ARB_VECT_NUM, &UART_1_ARB_ISR);
    #endif /* (UART_1_EP_MANAGEMENT_DMA && UART_1_ARB_ISR_ACTIVE) */
#endif /* (CY_PSOC4) */

    /* Common: Configure GPIO interrupt for wakeup. */
#if (UART_1_DP_ISR_ACTIVE)
    CyIntSetPriority     (UART_1_DP_INTC_VECT_NUM,  UART_1_DP_INTC_PRIORITY);
    (void) CyIntSetVector(UART_1_DP_INTC_VECT_NUM, &UART_1_DP_ISR);
#endif /* (UART_1_DP_ISR_ACTIVE) */

#if (UART_1_EP_MANAGEMENT_DMA && CY_PSOC4)
    /* Initialize DMA channels. */
    UART_1_InitEpDma();
#endif /* (UART_1_EP_MANAGEMENT_DMA && CY_PSOC4) */
}


/*******************************************************************************
* Function Name: UART_1_InitComponent
****************************************************************************//**
*
*   This function initializes the component’s global variables and initiates
*   communication with the host by pull-up D+ line.
*
* \param device:
*   Contains the device number of the desired device descriptor. The device
*   number can be found in the Device Descriptor Tab of "Configure" dialog,
*   under the settings of desired Device Descriptor, in the *Device Number*
*   field.
*  \param mode:
*   The operating voltage. This determines whether the voltage regulator
*   is enabled for 5V operation or if pass through mode is used for 3.3V
*   operation. Symbolic names and their associated values are given in the
*   following list.
*
*       *UART_1_3V_OPERATION* - Disable voltage regulator and pass-
*                                      through Vcc for pull-up
*
*       *UART_1_5V_OPERATION* - Enable voltage regulator and use
*                                      regulator for pull-up
*
*       *UART_1_DWR_POWER_OPERATION* - Enable or disable the voltage
*                                      regulator depending on the power supply
*                                      voltage configuration in the DWR tab.
*                                      For PSoC 3/5LP devices, the VDDD supply
*                                      voltage is considered and for PSoC 4A-L,
*                                      the VBUS supply voltage is considered.
*
* \globalvars
*   \ref UART_1_device
*   \ref UART_1_transferState
*   \ref UART_1_configuration
*   \ref UART_1_deviceStatus
*
*   \ref UART_1_deviceAddress - Contains the current device address. This
*       variable is initialized to zero in this API. The Host starts to communicate
*      to the device with address 0 and then sets it to a whatever value using a
*      SET_ADDRESS request.
*
*   \ref UART_1_lastPacketSize - Initialized to 0;
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_InitComponent(uint8 device, uint8 mode) 
{
    /* Initialize _hidProtocol variable to comply with
    *  HID 7.2.6 Set_Protocol Request:
    *  "When initialized, all devices default to report protocol."
    */
#if defined(UART_1_ENABLE_HID_CLASS)
    uint8 i;

    for (i = 0u; i < UART_1_MAX_INTERFACES_NUMBER; i++)
    {
        UART_1_hidProtocol[i] = UART_1_PROTOCOL_REPORT;
    }
#endif /* UART_1_ENABLE_HID_CLASS */

    /* Store device number to access descriptor. */
    UART_1_device = device;

    /* Reset component internal variables. */
    UART_1_transferState   = UART_1_TRANS_STATE_IDLE;
    UART_1_configurationChanged = 0u;
    UART_1_configuration   = 0u;
    UART_1_interfaceNumber = 0u;
    UART_1_deviceAddress   = 0u;
    UART_1_deviceStatus    = 0u;
    UART_1_lastPacketSize  = 0u;

    /* Enable component interrupts. */
#if (CY_PSOC4)
    CyIntEnable(UART_1_INTR_HI_VECT_NUM);
    CyIntEnable(UART_1_INTR_MED_VECT_NUM);
    CyIntEnable(UART_1_INTR_LO_VECT_NUM);
#else
    CyIntEnable(UART_1_BUS_RESET_VECT_NUM);
    CyIntEnable(UART_1_EP_0_VECT_NUM);

    #if (UART_1_SOF_ISR_ACTIVE)
        CyIntEnable(UART_1_SOF_VECT_NUM);
    #endif /* (UART_1_SOF_ISR_ACTIVE) */

    #if (UART_1_EP1_ISR_ACTIVE)
        CyIntEnable(UART_1_EP_1_VECT_NUM);
    #endif /* (UART_1_EP1_ISR_ACTIVE) */

    #if (UART_1_EP2_ISR_ACTIVE)
        CyIntEnable(UART_1_EP_2_VECT_NUM);
    #endif /* (UART_1_EP5_ISR_ACTIVE) */

    #if (UART_1_EP3_ISR_ACTIVE)
        CyIntEnable(UART_1_EP_3_VECT_NUM);
    #endif /* (UART_1_EP5_ISR_ACTIVE) */

    #if (UART_1_EP4_ISR_ACTIVE)
        CyIntEnable(UART_1_EP_4_VECT_NUM);
    #endif /* (UART_1_EP5_ISR_ACTIVE) */

    #if (UART_1_EP5_ISR_ACTIVE)
        CyIntEnable(UART_1_EP_5_VECT_NUM);
    #endif /* (UART_1_EP5_ISR_ACTIVE) */

    #if (UART_1_EP6_ISR_ACTIVE)
        CyIntEnable(UART_1_EP_6_VECT_NUM);
    #endif /* UART_1_EP6_ISR_REMOVE */

    #if (UART_1_EP7_ISR_ACTIVE)
        CyIntEnable(UART_1_EP_7_VECT_NUM);
    #endif /* (UART_1_EP7_ISR_ACTIVE) */

    #if (UART_1_EP8_ISR_ACTIVE)
        CyIntEnable(UART_1_EP_8_VECT_NUM);
    #endif /* (UART_1_EP8_ISR_ACTIVE) */
#endif /* (CY_PSOC4) */

#if (UART_1_EP_MANAGEMENT_DMA && UART_1_ARB_ISR_ACTIVE)
    /* Enable ARB EP interrupt sources. */
    UART_1_ARB_INT_EN_REG = UART_1_DEFAULT_ARB_INT_EN;

    #if (CY_PSOC3 || CY_PSOC5)
        CyIntEnable(UART_1_ARB_VECT_NUM);
    #endif /* (CY_PSOC3 || CY_PSOC5) */
#endif   /* (UART_1_EP_MANAGEMENT_DMA && UART_1_ARB_ISR_ACTIVE) */

/* Arbiter configuration for DMA transfers. */
#if (UART_1_EP_MANAGEMENT_DMA)
    /* Configure Arbiter for Manual or Auto DMA operation and clear configuration completion. */
    UART_1_ARB_CFG_REG = UART_1_DEFAULT_ARB_CFG;

    #if (CY_PSOC4)
        /* Enable DMA operation. */
        CyDmaEnable();

        #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
            /* Change DMA priority to be highest. */
             CyIntSetPriority(CYDMA_INTR_NUMBER, UART_1_DMA_AUTO_INTR_PRIO);
        #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
    #endif /* (CY_PSOC4) */

    #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
        #if (CY_PSOC4)
            /* Enable DMA interrupt to handle DMA management. */
            CyIntEnable(CYDMA_INTR_NUMBER);
        #else
            #if (UART_1_EP_DMA_AUTO_OPT == 0u)
                /* Initialize interrupts which handle verification of successful DMA transaction. */
                UART_1_EP_DMA_Done_isr_StartEx(&UART_1_EP_DMA_DONE_ISR);
                UART_1_EP17_DMA_Done_SR_InterruptEnable();
                UART_1_EP8_DMA_Done_SR_InterruptEnable();
            #endif /* (UART_1_EP_DMA_AUTO_OPT == 0u) */
        #endif /* (CY_PSOC4) */
    #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
#endif /* (UART_1_EP_MANAGEMENT_DMA) */

    /* Enable USB regulator depends on operation voltage. IMO Locking is enabled in Init(). */
    switch(mode)
    {
    case UART_1_3V_OPERATION:
        /* Disable regulator for 3V operation. */
        UART_1_CR1_REG &= (uint8) ~UART_1_CR1_REG_ENABLE;
        break;

    case UART_1_5V_OPERATION:
        /* Enable regulator for 5V operation. */
        UART_1_CR1_REG |= (uint8)  UART_1_CR1_REG_ENABLE;
        break;

    default: /* Check DWR settings of USB power supply. */
    #if (UART_1_VDDD_MV < UART_1_3500MV)
        /* Disable regulator for 3V operation. */
        UART_1_CR1_REG &= (uint8) ~UART_1_CR1_REG_ENABLE;
    #else
        /* Enable regulator for 5V operation. */
        UART_1_CR1_REG |= (uint8)  UART_1_CR1_REG_ENABLE;
    #endif /* (UART_1_VDDD_MV < UART_1_3500MV) */
        break;
    }

#if (CY_PSOC4)
    /* Clear bus activity. */
    UART_1_CR1_REG &= (uint32) ~UART_1_CR1_BUS_ACTIVITY;

    /* Clear EP0 count register. */
    UART_1_EP0_CNT_REG = UART_1_CLEAR_REG;

    /* Set EP0.CR: ACK Setup, NAK IN/OUT. */
    UART_1_EP0_CR_REG = UART_1_MODE_NAK_IN_OUT;

    #if (UART_1_LPM_ACTIVE)
        if (NULL != UART_1_GetBOSPtr())
        {
            /* Enable LPM and acknowledge LPM packets for active device.
            * Reset NYET_EN and SUB_RESP bits in the LPM_CTRL register.
            */
            UART_1_LPM_CTRL_REG = (UART_1_LPM_CTRL_LPM_EN | \
                                             UART_1_LPM_CTRL_LPM_ACK_RESP);
        }
        else
        {
            /* Disable LPM for active device. */
            UART_1_LPM_CTRL_REG &= (uint32) ~UART_1_LPM_CTRL_LPM_EN;
        }
    #endif /* (UART_1_LPM_ACTIVE) */

    /* Enable device to responds to USB traffic with address 0. */
    UART_1_CR0_REG = UART_1_DEFUALT_CR0;

#else
    /* Set EP0.CR: ACK Setup, STALL IN/OUT. */
    UART_1_EP0_CR_REG = UART_1_MODE_STALL_IN_OUT;

    /* Enable device to respond to USB traffic with address 0. */
    UART_1_CR0_REG = UART_1_DEFUALT_CR0;
    CyDelayCycles(UART_1_WAIT_CR0_REG_STABILITY);
#endif /* (CY_PSOC4) */

    /* Enable D+ pull-up and keep USB control on IO. */
    UART_1_USBIO_CR1_REG = UART_1_USBIO_CR1_USBPUEN;
}


/*******************************************************************************
* Function Name: UART_1_ReInitComponent
****************************************************************************//**
*
*  This function reinitialize the component configuration and is
*  intend to be called from the Reset interrupt.
*
* \globalvars
*   UART_1_device - Contains the device number of the desired Device
*        Descriptor. The device number can be found in the Device Descriptor tab
*       of the Configure dialog, under the settings of the desired Device Descriptor,
*       in the Device Number field.
*   UART_1_transferState - This variable is used by the communication
*       functions to handle the current transfer state. Initialized to
*       TRANS_STATE_IDLE in this API.
*   UART_1_configuration - Contains the current configuration number
*       set by the Host using a SET_CONFIGURATION request.
*       Initialized to zero in this API.
*   UART_1_deviceAddress - Contains the current device address. This
*       variable is initialized to zero in this API. The Host starts to communicate
*      to the device with address 0 and then sets it to a whatever value using
*      a SET_ADDRESS request.
*   UART_1_deviceStatus - Initialized to 0.
*       This is a two-bit variable which contains the power status in the first bit
*       (DEVICE_STATUS_BUS_POWERED or DEVICE_STATUS_SELF_POWERED) and the remote
*       wakeup status (DEVICE_STATUS_REMOTE_WAKEUP) in the second bit.
*   UART_1_lastPacketSize - Initialized to 0;
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_ReInitComponent(void) 
{
    /* Initialize _hidProtocol variable to comply with HID 7.2.6 Set_Protocol
    *  Request: "When initialized, all devices default to report protocol."
    */
#if defined(UART_1_ENABLE_HID_CLASS)
    uint8 i;

    for (i = 0u; i < UART_1_MAX_INTERFACES_NUMBER; i++)
    {
        UART_1_hidProtocol[i] = UART_1_PROTOCOL_REPORT;
    }
#endif /* UART_1_ENABLE_HID_CLASS */

    /* Reset component internal variables. */
    UART_1_transferState   = UART_1_TRANS_STATE_IDLE;
    UART_1_configurationChanged = 0u;
    UART_1_configuration   = 0u;
    UART_1_interfaceNumber = 0u;
    UART_1_deviceAddress   = 0u;
    UART_1_deviceStatus    = 0u;
    UART_1_lastPacketSize  = 0u;

#if (CY_PSOC4)
    /* Set EP0.CR: ACK Setup, NAK IN/OUT. */
    UART_1_EP0_CR_REG = UART_1_MODE_NAK_IN_OUT;
#else
    /* Set EP0.CR: ACK Setup, STALL IN/OUT. */
    UART_1_EP0_CR_REG = UART_1_MODE_STALL_IN_OUT;
#endif /* (CY_PSOC4) */

    /* Enable device to respond to USB traffic with address 0. */
    UART_1_CR0_REG = UART_1_DEFUALT_CR0;
}


/*******************************************************************************
* Function Name: UART_1_Stop
****************************************************************************//**
*
*  This function shuts down the USB function including to release
*  the D+ pull-up and disabling the SIE.
*
* \globalvars
*   \ref UART_1_configuration
*
*   UART_1_deviceAddress - Contains the current device address. This
*       variable is initialized to zero in this API. The Host starts to communicate
*      to the device with address 0 and then sets it to a whatever value using
*      a SET_ADDRESS request.
*
*   \ref UART_1_deviceStatus
*
*   \ref UART_1_configurationChanged
*
*   UART_1_intiVar -  This variable is set to zero
*
*******************************************************************************/
void UART_1_Stop(void) 
{
    uint8 enableInterrupts;

#if (UART_1_EP_MANAGEMENT_DMA)
    /* Stop all DMA channels. */
    UART_1_Stop_DMA(UART_1_MAX_EP);
#endif /* (UART_1_EP_MANAGEMENT_DMA) */

    enableInterrupts = CyEnterCriticalSection();

    /* Disable USB IP to respond to USB traffic. */
    UART_1_CR0_REG &= (uint8) ~UART_1_CR0_ENABLE;

    /* Disable D+ pull-up. */
    UART_1_USBIO_CR1_REG &= (uint8) ~ UART_1_USBIO_CR1_USBPUEN;

#if (CY_PSOC4)
    /* Disable USBFS block. */
    UART_1_POWER_CTRL_REG &= (uint32) ~UART_1_POWER_CTRL_ENABLE;
#else
    /* Clear power active and standby mode templates. */
    UART_1_PM_ACT_CFG_REG  &= (uint8) ~UART_1_PM_ACT_EN_FSUSB;
    UART_1_PM_STBY_CFG_REG &= (uint8) ~UART_1_PM_STBY_EN_FSUSB;
#endif /* (CY_PSOC4) */

    CyExitCriticalSection(enableInterrupts);

    /* Disable component interrupts. */
#if (CY_PSOC4)
    CyIntDisable(UART_1_INTR_HI_VECT_NUM);
    CyIntDisable(UART_1_INTR_LO_VECT_NUM);
    CyIntDisable(UART_1_INTR_MED_VECT_NUM);
#else

    CyIntDisable(UART_1_BUS_RESET_VECT_NUM);
    CyIntDisable(UART_1_EP_0_VECT_NUM);

    #if (UART_1_SOF_ISR_ACTIVE)
        CyIntDisable(UART_1_SOF_VECT_NUM);
    #endif /* (UART_1_SOF_ISR_ACTIVE) */

    #if (UART_1_EP1_ISR_ACTIVE)
        CyIntDisable(UART_1_EP_1_VECT_NUM);
    #endif /* (UART_1_EP1_ISR_ACTIVE) */

    #if (UART_1_EP2_ISR_ACTIVE)
        CyIntDisable(UART_1_EP_2_VECT_NUM);
    #endif /* (UART_1_EP2_ISR_ACTIVE) */

    #if (UART_1_EP3_ISR_ACTIVE)
        CyIntDisable(UART_1_EP_3_VECT_NUM);
    #endif /* (UART_1_EP3_ISR_ACTIVE) */

    #if (UART_1_EP4_ISR_ACTIVE)
        CyIntDisable(UART_1_EP_4_VECT_NUM);
    #endif /* (UART_1_EP4_ISR_ACTIVE) */

    #if (UART_1_EP5_ISR_ACTIVE)
        CyIntDisable(UART_1_EP_5_VECT_NUM);
    #endif /* (UART_1_EP5_ISR_ACTIVE) */

    #if (UART_1_EP6_ISR_ACTIVE)
        CyIntDisable(UART_1_EP_6_VECT_NUM);
    #endif /* UART_1_EP6_ISR_REMOVE */

    #if (UART_1_EP7_ISR_ACTIVE)
        CyIntDisable(UART_1_EP_7_VECT_NUM);
    #endif /* (UART_1_EP7_ISR_ACTIVE) */

    #if (UART_1_EP8_ISR_ACTIVE)
        CyIntDisable(UART_1_EP_8_VECT_NUM);
    #endif /* (UART_1_EP8_ISR_ACTIVE) */
#endif /* (CY_PSOC4) */

    /* Reset component internal variables. */
    UART_1_configurationChanged = 0u;
    UART_1_configuration   = 0u;
    UART_1_interfaceNumber = 0u;
    UART_1_deviceAddress   = 0u;
    UART_1_deviceStatus    = 0u;

    /* It is mandatory for correct device startup. */
    UART_1_initVar = 0u;
}


/*******************************************************************************
* Function Name: UART_1_CheckActivity
****************************************************************************//**
*
*  This function returns the activity status of the bus. It clears the hardware
*  status to provide updated status on the next call of this function. It
*  provides a way to determine whether any USB bus activity occurred. The
*  application should use this function to determine if the USB suspend
*  conditions are met.
*
*
* \return
*  cystatus: Status of the bus since the last call of the function.
*  Return Value |   Description
*  -------------|---------------------------------------------------------------
*  1            |Bus activity was detected since the last call to this function
*  0            |Bus activity was not detected since the last call to this function
*
*
*******************************************************************************/
uint8 UART_1_CheckActivity(void) 
{
    uint8 cr1Reg = UART_1_CR1_REG;

    /* Clear bus activity. */
    UART_1_CR1_REG = (cr1Reg & (uint8) ~UART_1_CR1_BUS_ACTIVITY);

    /* Get bus activity. */
    return ((0u != (cr1Reg & UART_1_CR1_BUS_ACTIVITY)) ? (1u) : (0u));
}


/*******************************************************************************
* Function Name: UART_1_GetConfiguration
****************************************************************************//**
*
*  This function gets the current configuration of the USB device.
*
* \return
*  Returns the currently assigned configuration. Returns 0 if the device
*  is not configured
*
*******************************************************************************/
uint8 UART_1_GetConfiguration(void) 
{
    return (UART_1_configuration);
}


/*******************************************************************************
* Function Name: UART_1_IsConfigurationChanged
****************************************************************************//**
*
*  This function returns the clear-on-read configuration state.  It is useful
*  when the host sends double SET_CONFIGURATION request with the same 
*  configuration number or changes alternate settings of the interface. 
*  After configuration has been changed the OUT endpoints must be enabled and IN 
*  endpoint must be loaded with data to start communication with the host.
*
* \return
*  None-zero value when new configuration has been changed, otherwise zero is
*  returned.
*
* \globalvars
*
*  \ref UART_1_configurationChanged - This variable is set to 1 after
*   a SET_CONFIGURATION request and cleared in this function.
*
*******************************************************************************/
uint8 UART_1_IsConfigurationChanged(void) 
{
    uint8 res = 0u;

    if (UART_1_configurationChanged != 0u)
    {
        res = UART_1_configurationChanged;
        UART_1_configurationChanged = 0u;
    }

    return (res);
}


/*******************************************************************************
* Function Name: UART_1_GetInterfaceSetting
****************************************************************************//**
*
*  This function gets the current alternate setting for the specified interface.
*  It is useful to identify which alternate settings are active in the specified 
*  interface.
*
*  \param
*  interfaceNumber interface number
*
* \return
*  Returns the current alternate setting for the specified interface.
*
*******************************************************************************/
uint8  UART_1_GetInterfaceSetting(uint8 interfaceNumber)
                                                    
{
    return (UART_1_interfaceSetting[interfaceNumber]);
}


/*******************************************************************************
* Function Name: UART_1_GetEPState
****************************************************************************//**
*
*  This function returns the state of the requested endpoint.
*
* \param epNumber Data endpoint number
*
* \return
*  Returns the current state of the specified USBFS endpoint. Symbolic names and
*  their associated values are given in the following table. Use these constants
*  whenever you write code to change the state of the endpoints, such as ISR
*  code, to handle data sent or received.
*
*  Return Value           | Description
*  -----------------------|-----------------------------------------------------
*  USBFS_NO_EVENT_PENDING |The endpoint is awaiting SIE action
*  USBFS_EVENT_PENDING    |The endpoint is awaiting CPU action
*  USBFS_NO_EVENT_ALLOWED |The endpoint is locked from access
*  USBFS_IN_BUFFER_FULL   |The IN endpoint is loaded and the mode is set to ACK IN
*  USBFS_IN_BUFFER_EMPTY  |An IN transaction occurred and more data can be loaded
*  USBFS_OUT_BUFFER_EMPTY |The OUT endpoint is set to ACK OUT and is waiting for data
*  USBFS_OUT_BUFFER_FULL  |An OUT transaction has occurred and data can be read
*
*******************************************************************************/
uint8 UART_1_GetEPState(uint8 epNumber) 
{
    return (UART_1_EP[epNumber].apiEpState);
}


/*******************************************************************************
* Function Name: UART_1_GetEPCount
****************************************************************************//**
*
*  This function supports Data Endpoints only(EP1-EP8).
*  Returns the transfer count for the requested endpoint.  The value from
*  the count registers includes 2 counts for the two byte checksum of the
*  packet.  This function subtracts the two counts.
*
*  \param epNumber Data Endpoint Number.
*                   Valid values are between 1 and 8.
*
* \return
*  Returns the current byte count from the specified endpoint or 0 for an
*  invalid endpoint.
*
*******************************************************************************/
uint16 UART_1_GetEPCount(uint8 epNumber) 
{
    uint16 cntr = 0u;

    if ((epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
    {
        /* Get 11-bits EP counter where epCnt0 - 3 bits MSB and epCnt1 - 8 bits LSB. */
        cntr  = ((uint16) UART_1_SIE_EP_BASE.sieEp[epNumber].epCnt0) & UART_1_EPX_CNT0_MASK;
        cntr  = ((uint16) (cntr << 8u)) | ((uint16) UART_1_SIE_EP_BASE.sieEp[epNumber].epCnt1);
        cntr -= UART_1_EPX_CNTX_CRC_COUNT;
    }

    return (cntr);
}


#if (UART_1_EP_MANAGEMENT_DMA)
#if (CY_PSOC4)
    /*******************************************************************************
    * Function Name: UART_1_InitEpDma
    ****************************************************************************//**
    *
    *  This function configures priority for all DMA channels utilized by the
    *  component. Also sets callbacks for DMA auto mode.
    *
    *******************************************************************************/
    static void UART_1_InitEpDma(void)
    {
    #if (UART_1_DMA1_ACTIVE)
        CYDMA_CH_CTL_BASE.ctl[UART_1_ep1_dma_CHANNEL] = UART_1_ep1_dma_CHANNEL_CFG;
    #endif /* (UART_1_DMA1_ACTIVE) */

    #if (UART_1_DMA2_ACTIVE)
        CYDMA_CH_CTL_BASE.ctl[UART_1_ep2_dma_CHANNEL] = UART_1_ep2_dma_CHANNEL_CFG;
    #endif /* (UART_1_DMA2_ACTIVE) */

    #if (UART_1_DMA3_ACTIVE)
        CYDMA_CH_CTL_BASE.ctl[UART_1_ep3_dma_CHANNEL] = UART_1_ep3_dma_CHANNEL_CFG;
    #endif /* (UART_1_DMA3_ACTIVE) */

    #if (UART_1_DMA4_ACTIVE)
        CYDMA_CH_CTL_BASE.ctl[UART_1_ep4_dma_CHANNEL] = UART_1_ep4_dma_CHANNEL_CFG;
    #endif /* (UART_1_DMA4_ACTIVE) */

    #if (UART_1_DMA5_ACTIVE)
        CYDMA_CH_CTL_BASE.ctl[UART_1_ep5_dma_CHANNEL] = UART_1_ep5_dma_CHANNEL_CFG;
    #endif /* (UART_1_DMA5_ACTIVE) */

    #if (UART_1_DMA6_ACTIVE)
        CYDMA_CH_CTL_BASE.ctl[UART_1_ep6_dma_CHANNEL] = UART_1_ep6_dma_CHANNEL_CFG;
    #endif /* (UART_1_DMA6_ACTIVE) */

    #if (UART_1_DMA7_ACTIVE)
        CYDMA_CH_CTL_BASE.ctl[UART_1_ep7_dma_CHANNEL] = UART_1_ep7_dma_CHANNEL_CFG;
    #endif /* (UART_1_DMA7_ACTIVE) */

    #if (UART_1_DMA8_ACTIVE)
        CYDMA_CH_CTL_BASE.ctl[UART_1_ep8_dma_CHANNEL] = UART_1_ep8_dma_CHANNEL_CFG;
    #endif /* (UART_1_DMA8_ACTIVE) */

    #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
        /* Initialize DMA channel callbacks. */
        #if (UART_1_DMA1_ACTIVE)
            (void) UART_1_ep1_dma_SetInterruptCallback(&UART_1_EP1_DMA_DONE_ISR);
        #endif /* (UART_1_DMA1_ACTIVE) */

        #if (UART_1_DMA2_ACTIVE)
            (void) UART_1_ep2_dma_SetInterruptCallback(&UART_1_EP2_DMA_DONE_ISR);
        #endif /* (UART_1_DMA2_ACTIVE) */

        #if (UART_1_DMA3_ACTIVE)
            (void) UART_1_ep3_dma_SetInterruptCallback(&UART_1_EP3_DMA_DONE_ISR);
        #endif /* (UART_1_DMA3_ACTIVE) */

        #if (UART_1_DMA4_ACTIVE)
            (void) UART_1_ep4_dma_SetInterruptCallback(&UART_1_EP4_DMA_DONE_ISR);
        #endif /* (UART_1_DMA4_ACTIVE) */

        #if (UART_1_DMA5_ACTIVE)
            (void) UART_1_ep5_dma_SetInterruptCallback(&UART_1_EP5_DMA_DONE_ISR);
        #endif /* (UART_1_DMA5_ACTIVE) */

        #if (UART_1_DMA6_ACTIVE)
            (void) UART_1_ep6_dma_SetInterruptCallback(&UART_1_EP6_DMA_DONE_ISR);
        #endif /* (UART_1_DMA6_ACTIVE) */

        #if (UART_1_DMA7_ACTIVE)
            (void) UART_1_ep7_dma_SetInterruptCallback(&UART_1_EP7_DMA_DONE_ISR);
        #endif /* (UART_1_DMA7_ACTIVE) */

        #if (UART_1_DMA8_ACTIVE)
            (void) UART_1_ep8_dma_SetInterruptCallback(&UART_1_EP8_DMA_DONE_ISR);
        #endif /* (UART_1_DMA8_ACTIVE) */
    #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
    }
#else


    /***************************************************************************
    * Function Name: UART_1_InitEP_DMA
    ************************************************************************//**
    *
    *  This function allocates and initializes a DMA channel to be used by the
    *  UART_1_LoadInEP() or UART_1_ReadOutEP() APIs for data
    *  transfer. It is available when the Endpoint Memory Management parameter
    *  is set to DMA.
    *
    *  This function is automatically called from the USBFS_LoadInEP() and USBFS_ReadOutEP() APIs.
    *
    *  \param epNumber Contains the data endpoint number.
    *            Valid values are between 1 and 8.
    *  \param *pData Pointer to a data array that is related to the EP transfers.
    *
    * \reentrant No.
    *
    ***************************************************************************/
    void UART_1_InitEP_DMA(uint8 epNumber, const uint8 *pData)
                                                                    
    {
        uint16 src;
        uint16 dst;

    #if (CY_PSOC3)
        src = HI16(CYDEV_SRAM_BASE);
        dst = HI16(CYDEV_PERIPH_BASE);
        pData = pData;
    #else
        if ((UART_1_EP[epNumber].addr & UART_1_DIR_IN) != 0u)
        {
            /* IN endpoint: source is memory buffer. */
            src = HI16(pData);
            dst = HI16(CYDEV_PERIPH_BASE);
        }
        else
        {
            /* OUT endpoint: source is USB IP memory buffer. */
            src = HI16(CYDEV_PERIPH_BASE);
            dst = HI16(pData);
        }
    #endif  /* (CY_PSOC3) */

        switch(epNumber)
        {
    #if (UART_1_DMA1_ACTIVE)
        case UART_1_EP1:
            UART_1_DmaChan[epNumber] = UART_1_ep1_DmaInitialize(UART_1_DMA_BYTES_PER_BURST,
                                                                                    UART_1_DMA_REQUEST_PER_BURST, src, dst);
            break;
    #endif /* (UART_1_DMA1_ACTIVE) */

    #if (UART_1_DMA2_ACTIVE)
        case UART_1_EP2:
            UART_1_DmaChan[epNumber] = UART_1_ep2_DmaInitialize(UART_1_DMA_BYTES_PER_BURST,
                                                                                    UART_1_DMA_REQUEST_PER_BURST, src, dst);
            break;
    #endif /* (UART_1_DMA2_ACTIVE) */

    #if (UART_1_DMA3_ACTIVE)
            case UART_1_EP3:
                UART_1_DmaChan[epNumber] = UART_1_ep3_DmaInitialize(UART_1_DMA_BYTES_PER_BURST,
                                                                                        UART_1_DMA_REQUEST_PER_BURST, src, dst);
            break;
    #endif /* (UART_1_DMA3_ACTIVE) */

    #if (UART_1_DMA4_ACTIVE)
            case UART_1_EP4:
                UART_1_DmaChan[epNumber] = UART_1_ep4_DmaInitialize(UART_1_DMA_BYTES_PER_BURST,
                                                                                        UART_1_DMA_REQUEST_PER_BURST, src, dst);
            break;
    #endif /* (UART_1_DMA4_ACTIVE) */

    #if (UART_1_DMA5_ACTIVE)
            case UART_1_EP5:
                UART_1_DmaChan[epNumber] = UART_1_ep5_DmaInitialize(UART_1_DMA_BYTES_PER_BURST,
                                                                                        UART_1_DMA_REQUEST_PER_BURST, src, dst);
            break;
    #endif /* (UART_1_DMA5_ACTIVE) */

    #if (UART_1_DMA6_ACTIVE)
        case UART_1_EP6:
            UART_1_DmaChan[epNumber] = UART_1_ep6_DmaInitialize(UART_1_DMA_BYTES_PER_BURST,
                                                                                    UART_1_DMA_REQUEST_PER_BURST, src, dst);
            break;
    #endif /* (UART_1_DMA6_ACTIVE) */

    #if (UART_1_DMA7_ACTIVE)
        case UART_1_EP7:
                UART_1_DmaChan[epNumber] = UART_1_ep7_DmaInitialize(UART_1_DMA_BYTES_PER_BURST,
                                                                                        UART_1_DMA_REQUEST_PER_BURST, src, dst);
            break;
    #endif /* (UART_1_DMA7_ACTIVE) */

    #if (UART_1_DMA8_ACTIVE)
        case UART_1_EP8:
                UART_1_DmaChan[epNumber] = UART_1_ep8_DmaInitialize(UART_1_DMA_BYTES_PER_BURST,
                                                                                        UART_1_DMA_REQUEST_PER_BURST, src, dst);
            break;
    #endif /* (UART_1_DMA8_ACTIVE) */

        default:
            /* Do nothing for endpoints other than 1-8. */
            break;
        }

        if ((epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
        {
            UART_1_DmaTd[epNumber] = CyDmaTdAllocate();

        #if (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u))
            UART_1_DmaNextTd[epNumber] = CyDmaTdAllocate();
        #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u)) */
        }
    }
#endif /* (CY_PSOC4) */

    /***************************************************************************
    * Function Name: UART_1_Stop_DMA
    ************************************************************************//**
    *  
    *  This function stops DMA channel associated with endpoint. It is available 
    *  when the Endpoint Buffer Management parameter is set to DMA. Call this 
    *  function when endpoint direction is changed from IN to OUT or vice versa 
    *  to trigger DMA re-configuration when UART_1_LoadInEP() or 
    *  UART_1_ReadOutEP() functions are called the first time. 
    *  
    *  \param epNumber: The data endpoint number for which associated DMA 
    *  channel is stopped. The range of valid values is between 1 and 8. To stop 
    *  all DMAs associated with endpoints call this function with 
    *  UART_1_MAX_EP argument.
    *
    * \reentrant
    *  No.
    *
    ***************************************************************************/
    void UART_1_Stop_DMA(uint8 epNumber) 
    {
        uint8 i;

        i = (epNumber < UART_1_MAX_EP) ? epNumber : UART_1_EP1;

        do
        {
        #if (CY_PSOC4)
            if (0u != UART_1_DmaChan[i])
            {
                UART_1_CyDmaChDisable(UART_1_DmaChan[i]);
            }
        #else
            if(UART_1_DmaTd[i] != DMA_INVALID_TD)
            {
                (void) CyDmaChDisable(UART_1_DmaChan[i]);
                CyDmaTdFree(UART_1_DmaTd[i]);
                UART_1_DmaTd[i] = DMA_INVALID_TD;
            }

            #if (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u))
                if(UART_1_DmaNextTd[i] != DMA_INVALID_TD)
                {
                    CyDmaTdFree(UART_1_DmaNextTd[i]);
                    UART_1_DmaNextTd[i] = DMA_INVALID_TD;
                }
            #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u)) */

        #endif /* (CY_PSOC4) */
            i++;
        }
        while ((i < UART_1_MAX_EP) && (epNumber == UART_1_MAX_EP));
    }
#endif /* (UART_1_EP_MANAGEMENT_DMA) */


#if (CY_PSOC3 || CY_PSOC5)
#if (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u))
    /***************************************************************************
    * Function Name: UART_1_LoadNextInEP
    ************************************************************************//**
    *
    * Summary:
    *  This internal function is used for IN endpoint DMA reconfiguration in
    *  Auto DMA mode.
    *
    * Parameters:
    *  epNumber: Contains the data endpoint number.
    *  mode:   0 - Configure DMA to send the the rest of data.
    *          1 - Configure DMA to repeat 2 last bytes of the first burst.
    *
    ***************************************************************************/
    void UART_1_LoadNextInEP(uint8 epNumber, uint8 mode) 
    {
        reg16 *convert;

        if (mode == 0u)
        {
            /* Configure DMA to send rest of data. */
            /* CyDmaTdSetConfiguration API is optimized to change transfer length only and configure TD. */
            convert = (reg16 *) &CY_DMA_TDMEM_STRUCT_PTR[UART_1_DmaTd[epNumber]].TD0[0u];
            /* Set transfer length. */
            CY_SET_REG16(convert, UART_1_inLength[epNumber] - UART_1_DMA_BYTES_PER_BURST);
            /* CyDmaTdSetAddress API is optimized to change source address only. */
            convert = (reg16 *) &CY_DMA_TDMEM_STRUCT_PTR[UART_1_DmaTd[epNumber]].TD1[0u];
            CY_SET_REG16(convert, LO16((uint32)UART_1_inDataPointer[epNumber] +
                                            UART_1_DMA_BYTES_PER_BURST));
            UART_1_inBufFull[epNumber] = 1u;
        }
        else
        {
            /* Configure DMA to repeat 2 last bytes of the first burst. */
            /* CyDmaTdSetConfiguration API is optimized to change transfer length only and configure TD. */
            convert = (reg16 *) &CY_DMA_TDMEM_STRUCT_PTR[UART_1_DmaTd[epNumber]].TD0[0u];
            /* Set transfer length. */
            CY_SET_REG16(convert, UART_1_DMA_BYTES_REPEAT);
            /* CyDmaTdSetAddress API is optimized to change source address only. */
            convert = (reg16 *) &CY_DMA_TDMEM_STRUCT_PTR[UART_1_DmaTd[epNumber]].TD1[0u];
            CY_SET_REG16(convert,  LO16((uint32)UART_1_inDataPointer[epNumber] +
                                   (UART_1_DMA_BYTES_PER_BURST - UART_1_DMA_BYTES_REPEAT)));
        }

        /* CyDmaChSetInitialTd API is optimized to initialize TD. */
        CY_DMA_CH_STRUCT_PTR[UART_1_DmaChan[epNumber]].basic_status[1u] = UART_1_DmaTd[epNumber];
    }
#endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO && (UART_1_EP_DMA_AUTO_OPT == 0u)) */
#endif /* (CY_PSOC3 || CY_PSOC5) */


/*******************************************************************************
* Function Name: UART_1_LoadInEP
****************************************************************************//**
*
*  This function performs different functionality depending on the Component’s
*  configured Endpoint Buffer Management. This parameter is defined in
*  the Descriptor Root in Component Configure window.
*
*  *Manual (Static/Dynamic Allocation):*
*  This function loads and enables the specified USB data endpoint for an IN
*  data transfer.
*
*  *DMA with Manual Buffer Management:*
*  Configures DMA for a data transfer from system RAM to endpoint buffer.
*  Generates request for a transfer.
*
*  *DMA with Automatic Buffer Management:*
*  Configures DMA. This is required only once, so it is done only when parameter
*  pData is not NULL. When the pData pointer is NULL, the function skips this
*  task. Sets Data ready status: This generates the first DMA transfer and
*  prepares data in endpoint buffer.
*
*  \param epNumber Contains the data endpoint number.
*            Valid values are between 1 and 8.
*  \param *pData A pointer to a data array from which the data for the endpoint space
*          is loaded.
*  \param length The number of bytes to transfer from the array and then send as
*          a result of an IN request. Valid values are between 0 and 512
*          (1023 for DMA with Automatic Buffer Management mode). The value 512
*          is applicable if only one endpoint is used.
*
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_LoadInEP(uint8 epNumber, const uint8 pData[], uint16 length)
                                                                        
{
    if ((epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
    {
    #if (!UART_1_EP_MANAGEMENT_DMA_AUTO)
        /* Limit length to available buffer USB IP buffer size.*/
        if (length > (UART_1_EPX_DATA_BUF_MAX - UART_1_EP[epNumber].buffOffset))
        {
            length = UART_1_EPX_DATA_BUF_MAX - UART_1_EP[epNumber].buffOffset;
        }
    #endif /* (!UART_1_EP_MANAGEMENT_DMA_AUTO) */

        /* Set count and data toggle. */
        UART_1_SIE_EP_BASE.sieEp[epNumber].epCnt0 = (uint8) HI8(length) | UART_1_EP[epNumber].epToggle;
        UART_1_SIE_EP_BASE.sieEp[epNumber].epCnt1 = (uint8) LO8(length);

    #if (UART_1_EP_MANAGEMENT_MANUAL)
        if (NULL != pData)
        {
			/* Copy data using arbiter data register. */
            uint16 i;
            for (i = 0u; i < length; ++i)
            {
                UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr = pData[i];
            }
        }

        /* IN endpoint buffer is full - read to be read. */
        UART_1_EP[epNumber].apiEpState = UART_1_NO_EVENT_PENDING;

        /* Arm IN endpoint. */
        UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_EP[epNumber].epMode;

    #else

        #if (CY_PSOC3 || CY_PSOC5LP)
            /* Initialize DMA if it was not initialized. */
            if (DMA_INVALID_TD == UART_1_DmaTd[epNumber])
            {
                UART_1_InitEP_DMA(epNumber, pData);
            }
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */

        #if (UART_1_EP_MANAGEMENT_DMA_MANUAL)
            /* IN endpoint buffer will be fully loaded by DMA shortly. */
            UART_1_EP[epNumber].apiEpState = UART_1_NO_EVENT_PENDING;

            if ((pData != NULL) && (length > 0u))
            {
            #if (CY_PSOC4)
                uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];

                /* Disable DMA channel: start configuration. */
                UART_1_CyDmaChDisable(channelNum);

                /* Configure source and destination. */
                UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR0, (void*) pData);
                UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR0, (void*) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr);

                /* Configure DMA descriptor. */
                --length;
                UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR0, UART_1_DMA_COMMON_CFG | length |
                                                        CYDMA_BYTE | CYDMA_ELEMENT_WORD | CYDMA_INC_SRC_ADDR | CYDMA_INVALIDATE | CYDMA_PREEMPTABLE);

                /* Validate descriptor to execute on following DMA request. */
                UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR0);

                /* Enable DMA channel: configuration complete. */
                UART_1_CyDmaChEnable(channelNum);
            #else
                /* Configure DMA to transfer data. */
                (void) CyDmaChDisable(UART_1_DmaChan[epNumber]);
                (void) CyDmaTdSetConfiguration(UART_1_DmaTd[epNumber], length, CY_DMA_DISABLE_TD, TD_TERMIN_EN | TD_INC_SRC_ADR);
                (void) CyDmaTdSetAddress(UART_1_DmaTd[epNumber], LO16((uint32) pData), LO16((uint32) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr));

                /* Enable DMA channel. */
                (void) CyDmaChSetInitialTd(UART_1_DmaChan[epNumber], UART_1_DmaTd[epNumber]);
                (void) CyDmaChEnable(UART_1_DmaChan[epNumber], 1u);
            #endif /* (CY_PSOC4) */

                /* Generate DMA request. */
                UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg |=  (uint8)  UART_1_ARB_EPX_CFG_DMA_REQ;
                UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg &=  (uint8) ~UART_1_ARB_EPX_CFG_DMA_REQ;

                /* IN endpoint will be armed in ARB_ISR(source: IN_BUF_FULL) after first DMA transfer has been completed. */
            }
            else
            {
                /* When zero-length packet: arm IN endpoint directly. */
                UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_EP[epNumber].epMode;
            }
        #endif /* (UART_1_EP_MANAGEMENT_DMA_MANUAL) */

        #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
            if (pData != NULL)
            {
            #if (CY_PSOC4)
                uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];

                /* Store address of buffer. */
                UART_1_DmaEpBufferAddrBackup[epNumber] = (uint32) pData;

                /* Disable DMA channel: start configuration. */
                UART_1_CyDmaChDisable(channelNum);

                /* Set destination address. */
                UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR0, (void*) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr);
                UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR1, (void*) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr);

                /* Configure DMA descriptor. */
                UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR0, UART_1_DMA_COMMON_CFG  |
                                                        CYDMA_BYTE | CYDMA_ELEMENT_WORD | CYDMA_INC_SRC_ADDR | CYDMA_INVALIDATE | CYDMA_CHAIN);

                /* Configure DMA descriptor. */
                UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR1, UART_1_DMA_COMMON_CFG  |
                                                        CYDMA_BYTE | CYDMA_ELEMENT_WORD | CYDMA_INC_SRC_ADDR | CYDMA_CHAIN);

                /* Enable interrupt from DMA channel. */
                UART_1_CyDmaSetInterruptMask(channelNum);

                /* Validate descriptor 1. It will not be invalided during operation. */
                UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR1);

                /* Enable DMA channel: configuration complete. */
                UART_1_CyDmaChEnable(channelNum);

            #else
                (void) CyDmaChDisable(UART_1_DmaChan[epNumber]);

                #if (UART_1_EP_DMA_AUTO_OPT == 0u)
                    UART_1_inLength[epNumber] = length;
                    UART_1_inDataPointer[epNumber] = pData;

                    /* Configure DMA to send data only for first burst */
                    (void) CyDmaTdSetConfiguration(UART_1_DmaTd[epNumber],
                        (length > UART_1_DMA_BYTES_PER_BURST) ? UART_1_DMA_BYTES_PER_BURST : length,
                        UART_1_DmaNextTd[epNumber], TD_TERMIN_EN | TD_INC_SRC_ADR);
                    (void) CyDmaTdSetAddress(UART_1_DmaTd[epNumber], LO16((uint32) pData),
                                                                               LO16((uint32) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr));

                    /* The second TD will be executed only when the first one fails.
                    *  The intention of this TD is to generate NRQ interrupt
                    *  and repeat 2 last bytes of the first burst.
                    */
                    (void) CyDmaTdSetConfiguration(UART_1_DmaNextTd[epNumber], 1u,
                                                   UART_1_DmaNextTd[epNumber],
                                                   UART_1_epX_TD_TERMOUT_EN[epNumber]);

                    /* Configure DmaNextTd to clear Data Ready status. */
                    (void) CyDmaTdSetAddress(UART_1_DmaNextTd[epNumber], LO16((uint32) &clearInDataRdyStatus),
                                                                                   LO16((uint32) &UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg));
                #else
                    /* Configure DMA to send all data. */
                    (void) CyDmaTdSetConfiguration(UART_1_DmaTd[epNumber], length,
                                                   UART_1_DmaTd[epNumber], TD_TERMIN_EN | TD_INC_SRC_ADR);
                    (void) CyDmaTdSetAddress(UART_1_DmaTd[epNumber], LO16((uint32) pData),
                                                                               LO16((uint32) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr));
                #endif /* (UART_1_EP_DMA_AUTO_OPT == 0u) */

                /* Clear any potential pending DMA requests before starting DMA channel to transfer data. */
                (void) CyDmaClearPendingDrq(UART_1_DmaChan[epNumber]);
                /* Enable DMA. */
                (void) CyDmaChSetInitialTd(UART_1_DmaChan[epNumber], UART_1_DmaTd[epNumber]);
                (void) CyDmaChEnable(UART_1_DmaChan[epNumber], 1u);
            #endif /* (CY_PSOC4) */
            }
            else
            {
                /* IN endpoint buffer (32 bytes) will shortly be preloaded by DMA. */
                UART_1_EP[epNumber].apiEpState = UART_1_NO_EVENT_PENDING;

                if (length > 0u)
                {
                #if (CY_PSOC4)
                    uint32 lengthDescr0, lengthDescr1;
                    uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];

                    /* Get number of full bursts. */
                    UART_1_DmaEpBurstCnt[epNumber] = (uint8) (length / UART_1_DMA_BYTES_PER_BURST);

                    /* Get number of elements in the last burst. */
                    UART_1_DmaEpLastBurstEl[epNumber] = (uint8) (length % UART_1_DMA_BYTES_PER_BURST);

                    /* Get total number of bursts. */
                    UART_1_DmaEpBurstCnt[epNumber] += (0u != UART_1_DmaEpLastBurstEl[epNumber]) ? 1u : 0u;

                    /* Adjust number of data elements transferred in last burst. */
                    UART_1_DmaEpLastBurstEl[epNumber] = (0u != UART_1_DmaEpLastBurstEl[epNumber]) ?
                                                                          (UART_1_DmaEpLastBurstEl[epNumber] - 1u) :
                                                                          (UART_1_DMA_BYTES_PER_BURST - 1u);

                    /* Get number of data elements to transfer for descriptor 0 and 1. */
                    lengthDescr0 = (1u == UART_1_DmaEpBurstCnt[epNumber]) ? UART_1_DmaEpLastBurstEl[epNumber] : (UART_1_DMA_BYTES_PER_BURST - 1u);
                    lengthDescr1 = (2u == UART_1_DmaEpBurstCnt[epNumber]) ? UART_1_DmaEpLastBurstEl[epNumber] : (UART_1_DMA_BYTES_PER_BURST - 1u);


                    /* Mark which descriptor is last one to execute. */
                    UART_1_DmaEpLastBurstEl[epNumber] |= (0u != (UART_1_DmaEpBurstCnt[epNumber] & 0x1u)) ?
                                                                            UART_1_DMA_DESCR0_MASK : UART_1_DMA_DESCR1_MASK;

                    /* Adjust burst counter taking to account: 2 valid descriptors and interrupt trigger after valid descriptor were executed. */
                    UART_1_DmaEpBurstCnt[epNumber] = UART_1_DMA_GET_BURST_CNT(UART_1_DmaEpBurstCnt[epNumber]);

                    /* Restore DMA settings for current transfer. */
                    UART_1_CyDmaChDisable(channelNum);

                    /* Restore destination address for input endpoint. */
                    UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR0, (void*) ((uint32) UART_1_DmaEpBufferAddrBackup[epNumber]));
                    UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR1, (void*) ((uint32) UART_1_DmaEpBufferAddrBackup[epNumber] +
                                                                                                                   UART_1_DMA_BYTES_PER_BURST));

                    /* Set number of elements to transfer. */
                    UART_1_CyDmaSetNumDataElements(channelNum, UART_1_DMA_DESCR0, lengthDescr0);
                    UART_1_CyDmaSetNumDataElements(channelNum, UART_1_DMA_DESCR1, lengthDescr1);

                    /* Validate descriptor 0 and command to start with it. */
                    UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR0);
                    UART_1_CyDmaSetDescriptor0Next(channelNum);

                    /* Enable DMA channel: configuration complete. */
                    UART_1_CyDmaChEnable(channelNum);

                #elif (UART_1_EP_DMA_AUTO_OPT == 0u)
                    UART_1_inLength[epNumber]  = length;
                    UART_1_inBufFull[epNumber] = 0u;

                    (void) CyDmaChDisable(UART_1_DmaChan[epNumber]);
                    /* Configure DMA to send data only for first burst. */
                    (void) CyDmaTdSetConfiguration(
                        UART_1_DmaTd[epNumber], (length > UART_1_DMA_BYTES_PER_BURST) ?
                        UART_1_DMA_BYTES_PER_BURST : length,
                        UART_1_DmaNextTd[epNumber], TD_TERMIN_EN | TD_INC_SRC_ADR );
                    (void) CyDmaTdSetAddress(UART_1_DmaTd[epNumber], LO16((uint32)  UART_1_inDataPointer[epNumber]),
                                                                               LO16((uint32) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr));
                    /* Clear Any potential pending DMA requests before starting DMA channel to transfer data. */
                    (void) CyDmaClearPendingDrq(UART_1_DmaChan[epNumber]);
                    /* Enable DMA. */
                    (void) CyDmaChSetInitialTd(UART_1_DmaChan[epNumber], UART_1_DmaTd[epNumber]);
                    (void) CyDmaChEnable(UART_1_DmaChan[epNumber], 1u);
                #endif /* (CY_PSOC4) */

                #if !defined (UART_1_MANUAL_IN_EP_ARM)
                    /* Set IN data ready to generate DMA request to load data into endpoint buffer. */
                    UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg |= UART_1_ARB_EPX_CFG_IN_DATA_RDY;
                #endif  /* (UART_1_MANUAL_IN_EP_ARM) */

                    /* IN endpoint will be armed in ARB_ISR(source: IN_BUF_FULL) after first DMA transfer has been completed. */
                }
                else
                {
                    /* When zero-length packet: arm IN endpoint directly. */
                    UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_EP[epNumber].epMode;
                }
            }
        #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
    #endif /* (UART_1_EP_MANAGEMENT_MANUAL) */
    }
}


/*******************************************************************************
* Function Name: UART_1_ReadOutEP
****************************************************************************//**
*
*   This function performs different functionality depending on the Component’s
*   configured Endpoint Buffer Management. This parameter is defined in the
*   Descriptor Root in Component Configure window.
*
*   *Manual (Static/Dynamic Allocation):*
*   This function moves the specified number of bytes from endpoint buffer to
*   system RAM. The number of bytes actually transferred from endpoint buffer to
*   system RAM is the lesser of the actual number of bytes sent by the host or
*   the number of bytes requested by the length parameter.
*
*   *DMA with Manual Buffer Management:*
*   Configure DMA to transfer data from endpoint buffer to system RAM. Generate
*   a DMA request. The firmware must wait until the DMA completes the data
*   transfer after calling the UART_1_ReadOutEP() API. For example,
*   by checking EPstate:
*
*   \snippet /USBFS_sut_02.cydsn/main.c checking EPstatey
*
*   The USBFS_EnableOutEP() has to be called to allow host to write data into
*   the endpoint buffer after DMA has completed transfer data from OUT endpoint
*   buffer to SRAM.
*
*   *DMA with Automatic Buffer Management:*
*   Configure DMA. This is required only once and automatically generates DMA
*   requests as data arrives
*
*  \param epNumber: Contains the data endpoint number.
*            Valid values are between 1 and 8.
*  \param pData: A pointer to a data array from which the data for the endpoint
*         space is loaded.
*  \param length: The number of bytes to transfer from the USB Out endpoint and
*          loads it into data array. Valid values are between 0 and 1023. The
*          function moves fewer than the requested number of bytes if the host
*          sends fewer bytes than requested.
*
* \return
*  Number of bytes received, 0 for an invalid endpoint.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint16 UART_1_ReadOutEP(uint8 epNumber, uint8 pData[], uint16 length)
                                                                        
{
    if ((pData != NULL) && (epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
    {
    #if (!UART_1_EP_MANAGEMENT_DMA_AUTO)
        /* Adjust requested length to available data. */
        length = (length > UART_1_GetEPCount(epNumber)) ? UART_1_GetEPCount(epNumber) : length;
    #endif /* (!UART_1_EP_MANAGEMENT_DMA_AUTO) */

    #if (UART_1_EP_MANAGEMENT_MANUAL)
        {
            /* Copy data using arbiter data register. */
            uint16 i;
            for (i = 0u; i < length; ++i)
            {
                pData[i] = (uint8) UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr;
            }
        }

        /* Arm OUT endpoint after data has been copied from endpoint buffer. */
        UART_1_EnableOutEP(epNumber);
    #else

        #if (CY_PSOC3 || CY_PSOC5LP)
            /* Initialize DMA if it was not initialized. */
            if (DMA_INVALID_TD == UART_1_DmaTd[epNumber])
            {
                UART_1_InitEP_DMA(epNumber, pData);
            }
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */

        #if (UART_1_EP_MANAGEMENT_DMA_MANUAL)
        #if (CY_PSOC4)
        {
            uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];

            /* Disable DMA channel: start configuration. */
            UART_1_CyDmaChDisable(channelNum);

            /* Configure source and destination. */
            UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR0, (void*) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr);
            UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR0, (void*) pData);

            /* Configure DMA descriptor. */
            UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR0, UART_1_DMA_COMMON_CFG | (uint16)(length - 1u) |
                                                    CYDMA_BYTE | CYDMA_WORD_ELEMENT | CYDMA_INC_DST_ADDR | CYDMA_INVALIDATE | CYDMA_PREEMPTABLE);

            /* Validate descriptor to execute on following DMA request. */
            UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR0);

            /* Enable DMA channel: configuration complete. */
            UART_1_CyDmaChEnable(channelNum);
        }
        #else
            /* Configure DMA to transfer data. */
            (void) CyDmaChDisable(UART_1_DmaChan[epNumber]);
            (void) CyDmaTdSetConfiguration(UART_1_DmaTd[epNumber], length, CY_DMA_DISABLE_TD, TD_TERMIN_EN | TD_INC_DST_ADR);
            (void) CyDmaTdSetAddress(UART_1_DmaTd[epNumber], LO16((uint32) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr), LO16((uint32)pData));

            /* Enable DMA channel. */
            (void) CyDmaChSetInitialTd(UART_1_DmaChan[epNumber], UART_1_DmaTd[epNumber]);
            (void) CyDmaChEnable(UART_1_DmaChan[epNumber], 1u);
        #endif /* (CY_PSOC4) */

            /* Generate DMA request. */
            UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg |=  (uint8)  UART_1_ARB_EPX_CFG_DMA_REQ;
            UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg &=  (uint8) ~UART_1_ARB_EPX_CFG_DMA_REQ;

            /* OUT endpoint has to be armed again by user when DMA transfers have been completed.
            * NO_EVENT_PENDING: notifies that data has been copied from endpoint buffer.
            */

        #endif /* (UART_1_EP_MANAGEMENT_DMA_MANUAL) */

        #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
        #if (CY_PSOC4)
        {
            uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];
            uint32 lengthDescr0, lengthDescr1;

            /* Get number of full bursts. */
            UART_1_DmaEpBurstCnt[epNumber] = (uint8) (length / UART_1_DMA_BYTES_PER_BURST);

            /* Get number of elements in the last burst. */
            UART_1_DmaEpLastBurstEl[epNumber] = (uint8) (length % UART_1_DMA_BYTES_PER_BURST);

            /* Get total number of bursts. */
            UART_1_DmaEpBurstCnt[epNumber] += (0u != UART_1_DmaEpLastBurstEl[epNumber]) ? 1u : 0u;

            /* Adjust number of the data elements transfered in last burst. */
            UART_1_DmaEpLastBurstEl[epNumber] = (0u != UART_1_DmaEpLastBurstEl[epNumber]) ?
                                                                  (UART_1_DmaEpLastBurstEl[epNumber] - 1u) :
                                                                  (UART_1_DMA_BYTES_PER_BURST - 1u);

            /* Get number of data elements to transfer for descriptor 0 and 1. */
            lengthDescr0 = (1u == UART_1_DmaEpBurstCnt[epNumber]) ? UART_1_DmaEpLastBurstEl[epNumber] : (UART_1_DMA_BYTES_PER_BURST - 1u);
            lengthDescr1 = (2u == UART_1_DmaEpBurstCnt[epNumber]) ? UART_1_DmaEpLastBurstEl[epNumber] : (UART_1_DMA_BYTES_PER_BURST - 1u);

            /* Mark if revert number of data elements in descriptor after transfer completion. */
            UART_1_DmaEpLastBurstEl[epNumber] |= (UART_1_DmaEpBurstCnt[epNumber] > 2u) ? UART_1_DMA_DESCR_REVERT : 0u;

            /* Mark last descriptor to be executed. */
            UART_1_DmaEpLastBurstEl[epNumber] |= (0u != (UART_1_DmaEpBurstCnt[epNumber] & 0x1u)) ?
                                                                    UART_1_DMA_DESCR0_MASK : UART_1_DMA_DESCR1_MASK;

            /* Adjust burst counter taking to account: 2 valid descriptors and interrupt trigger after valid descriptor were executed. */
            UART_1_DmaEpBurstCnt[epNumber] = UART_1_DMA_GET_BURST_CNT(UART_1_DmaEpBurstCnt[epNumber]);

            /* Store address of buffer and burst counter for endpoint. */
            UART_1_DmaEpBufferAddrBackup[epNumber] = (uint32) pData;
            UART_1_DmaEpBurstCntBackup[epNumber]   = UART_1_DmaEpBurstCnt[epNumber];

            /* Disable DMA channel: start configuration. */
            UART_1_CyDmaChDisable(channelNum);

            /* Set destination address. */
            UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR0, (void*) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr);
            UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR1, (void*) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr);

            UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR0, (void*) ((uint32) pData));
            UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR1, (void*) ((uint32) pData + UART_1_DMA_BYTES_PER_BURST));

            /* Configure DMA descriptor. */
            UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR0, UART_1_DMA_COMMON_CFG  | lengthDescr0 |
                                                    CYDMA_BYTE | CYDMA_WORD_ELEMENT | CYDMA_INC_DST_ADDR | CYDMA_INVALIDATE | CYDMA_CHAIN);

            /* Configure DMA descriptor. */
            UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR1, UART_1_DMA_COMMON_CFG  | lengthDescr1 |
                                                    CYDMA_BYTE | CYDMA_WORD_ELEMENT | CYDMA_INC_DST_ADDR | CYDMA_CHAIN);

            /* Enable interrupt from DMA channel. */
            UART_1_CyDmaSetInterruptMask(channelNum);

            /* Validate DMA descriptor 0 and 1. */
            UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR0);
            UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR1);

            /* Enable DMA channel: configuration complete. */
            UART_1_CyDmaChEnable(channelNum);
        }
        #else
            (void) CyDmaChDisable(UART_1_DmaChan[epNumber]);
            (void) CyDmaTdSetConfiguration(UART_1_DmaTd[epNumber], length,  UART_1_DmaTd[epNumber], TD_TERMIN_EN | TD_INC_DST_ADR);
            (void) CyDmaTdSetAddress(UART_1_DmaTd[epNumber], LO16((uint32) &UART_1_ARB_EP_BASE.arbEp[epNumber].rwDr), LO16((uint32) pData));

            /* Clear Any potential pending DMA requests before starting DMA channel to transfer data. */
            (void) CyDmaClearPendingDrq(UART_1_DmaChan[epNumber]);

            /* Enable DMA channel. */
            (void) CyDmaChSetInitialTd(UART_1_DmaChan[epNumber], UART_1_DmaTd[epNumber]);
            (void) CyDmaChEnable(UART_1_DmaChan[epNumber], 1u);
        #endif /* (CY_PSOC4) */

            /* OUT endpoint has to be armed again by user when DMA transfers have been completed.
            * NO_EVENT_PENDING: notifies that data has been copied from endpoint buffer.
            */

        #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
    #endif /* (UART_1_EP_MANAGEMENT_MANUAL) */
    }
    else
    {
        length = 0u;
    }

    return (length);
}


#if (UART_1_16BITS_EP_ACCESS_ENABLE)
/*******************************************************************************
* Function Name: UART_1_LoadInEP16
****************************************************************************//**
*
*  This function performs different functionality depending on the Component’s
*  configured Endpoint Buffer Management. This parameter is defined in
*  the Descriptor Root in Component Configure window.
*
*  *Manual (Static/Dynamic Allocation):*
*  This function loads and enables the specified USB data endpoint for an IN
*  data transfer.
*
*  *DMA with Manual Buffer Management:*
*  Configures DMA for a data transfer from system RAM to endpoint buffer.
*  Generates request for a transfer.
*
*  *DMA with Automatic Buffer Management:*
*  Configures DMA. This is required only once, so it is done only when parameter
*  pData is not NULL. When the pData pointer is NULL, the function skips this
*  task. Sets Data ready status: This generates the first DMA transfer and
*  prepares data in endpoint buffer.
*
*  \param epNumber Contains the data endpoint number.
*        Valid values are between 1 and 8.
*  \param *pData A pointer to a data array from which the data for the endpoint
*        space is loaded. It shall be ensured that this pointer address is even
*        to ensure the 16-bit transfer is aligned to even address. Else, a hard
*        fault condition can occur.
*  \param length The number of bytes to transfer from the array and then send as
*        a result of an IN request. Valid values are between 0 and 512 (1023 for
*        DMA with Automatic Buffer Management mode). The value 512 is applicable
*        if only one endpoint is used.
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_LoadInEP16(uint8 epNumber, const uint8 pData[], uint16 length)
{
    /* Check array alignment on half-word boundary. */
    CYASSERT(0u == (((uint32) pData) & 0x01u));

    if ((epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
    {
    #if (!UART_1_EP_MANAGEMENT_DMA_AUTO)
        /* Limit length to available buffer USB IP buffer size. */
        if (length > (UART_1_EPX_DATA_BUF_MAX - UART_1_EP[epNumber].buffOffset))
        {
            length = UART_1_EPX_DATA_BUF_MAX - UART_1_EP[epNumber].buffOffset;
        }
    #endif /* (!UART_1_EP_MANAGEMENT_DMA_AUTO) */

        /* Set count and data toggle. */
        UART_1_SIE_EP_BASE.sieEp[epNumber].epCnt0 = (uint32) HI8(length) | UART_1_EP[epNumber].epToggle;
        UART_1_SIE_EP_BASE.sieEp[epNumber].epCnt1 = (uint32) LO8(length);

        /* Adjust requested length: 2 bytes are handled at one data register access. */
        length += (length & 0x01u);

    #if (UART_1_EP_MANAGEMENT_MANUAL)
        if (NULL != pData)
        {
            /* Convert uint8 array to uint16. */
            const uint16 *dataBuf = (uint16 *) pData;

            /* Copy data using 16-bits arbiter data register. */
            uint16 i;
            for (i = 0u; i < (length >> 1u); ++i)
            {
                UART_1_ARB_EP16_BASE.arbEp[epNumber].rwDr16 = dataBuf[i];
            }
        }

        /* IN endpoint buffer is full - read to be read. */
        UART_1_EP[epNumber].apiEpState = UART_1_NO_EVENT_PENDING;

        /* Arm IN endpoint. */
        UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_EP[epNumber].epMode;

    #else

        #if (UART_1_EP_MANAGEMENT_DMA_MANUAL)
            /* IN endpoint buffer will be fully loaded by DMA shortly. */
            UART_1_EP[epNumber].apiEpState = UART_1_NO_EVENT_PENDING;

            if ((pData != NULL) && (length > 0u))
            {
                uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];

                /* Disable DMA channel: start configuration. */
                UART_1_CyDmaChDisable(channelNum);

                /* Configure source and destination. */
                UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR0, (void*) pData);
                UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR0, (void*) &UART_1_ARB_EP16_BASE.arbEp[epNumber].rwDr16);

                /* Configure DMA descriptor. */
                length = (length >> 1u) - 1u;
                UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR0, UART_1_DMA_COMMON_CFG | length |
                                                        CYDMA_HALFWORD | CYDMA_ELEMENT_WORD | CYDMA_INC_SRC_ADDR | CYDMA_INVALIDATE | CYDMA_PREEMPTABLE);

                /* Validate descriptor to execute on following DMA request. */
                UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR0);

                /* Enable DMA channel: configuration complete. */
                UART_1_CyDmaChEnable(channelNum);

                /* Generate DMA request. */
                UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg |=  (uint32)  UART_1_ARB_EPX_CFG_DMA_REQ;
                UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg &=  (uint32) ~UART_1_ARB_EPX_CFG_DMA_REQ;

                /* IN endpoint will be armed in ARB_ISR(source: IN_BUF_FULL) after first DMA transfer has been completed. */
            }
            else
            {
                /* When zero-length packet: arm IN endpoint directly. */
                UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_EP[epNumber].epMode;
            }
        #endif /* (UART_1_EP_MANAGEMENT_DMA_MANUAL) */

        #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
            if (pData != NULL)
            {
                uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];

                /* Store address of buffer. */
                UART_1_DmaEpBufferAddrBackup[epNumber] = (uint32) pData;

                /* Disable DMA channel: start configuration. */
                UART_1_CyDmaChDisable(channelNum);

                /* Set destination address. */
                UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR0, (void*) &UART_1_ARB_EP16_BASE.arbEp[epNumber].rwDr16);
                UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR1, (void*) &UART_1_ARB_EP16_BASE.arbEp[epNumber].rwDr16);

                /* Configure DMA descriptor. */
                UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR0, UART_1_DMA_COMMON_CFG  |
                                                        CYDMA_HALFWORD | CYDMA_ELEMENT_WORD | CYDMA_INC_SRC_ADDR | CYDMA_INVALIDATE | CYDMA_CHAIN);

                /* Configure DMA descriptor. */
                UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR1, UART_1_DMA_COMMON_CFG  |
                                                        CYDMA_HALFWORD | CYDMA_ELEMENT_WORD | CYDMA_INC_SRC_ADDR | CYDMA_CHAIN);

                /* Enable interrupt from DMA channel. */
                UART_1_CyDmaSetInterruptMask(channelNum);

                /* Validate descriptor 1. It will not be invalided during operation. */
                UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR1);

                /* Enable DMA channel: configuration complete. */
                UART_1_CyDmaChEnable(channelNum);
            }
            else
            {
                /* IN endpoint buffer (32 bytes) will shortly be preloaded by DMA. */
                UART_1_EP[epNumber].apiEpState = UART_1_NO_EVENT_PENDING;

                if (length > 0u)
                {
                    uint32 lengthDescr0, lengthDescr1;
                    uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];

                    /* Get number of full bursts. */
                    UART_1_DmaEpBurstCnt[epNumber] = (uint8) (length / UART_1_DMA_BYTES_PER_BURST);

                    /* Get number of elements in the last burst. */
                    UART_1_DmaEpLastBurstEl[epNumber] = (uint8) (length % UART_1_DMA_BYTES_PER_BURST);

                    /* Get total number of bursts. */
                    UART_1_DmaEpBurstCnt[epNumber] += (0u != UART_1_DmaEpLastBurstEl[epNumber]) ? 1u : 0u;

                    /* Adjust number of data elements transferred in last burst. */
                    UART_1_DmaEpLastBurstEl[epNumber] = (0u != UART_1_DmaEpLastBurstEl[epNumber]) ?
                                                                          ((UART_1_DmaEpLastBurstEl[epNumber] >> 1u) - 1u) :
                                                                           (UART_1_DMA_HALFWORDS_PER_BURST - 1u);

                    /* Get number of data elements to transfer for descriptor 0 and 1. */
                    lengthDescr0 = (1u == UART_1_DmaEpBurstCnt[epNumber]) ? UART_1_DmaEpLastBurstEl[epNumber] : (UART_1_DMA_HALFWORDS_PER_BURST - 1u);
                    lengthDescr1 = (2u == UART_1_DmaEpBurstCnt[epNumber]) ? UART_1_DmaEpLastBurstEl[epNumber] : (UART_1_DMA_HALFWORDS_PER_BURST - 1u);

                    /* Mark which descriptor is last one to execute. */
                    UART_1_DmaEpLastBurstEl[epNumber] |= (0u != (UART_1_DmaEpBurstCnt[epNumber] & 0x1u)) ?
                                                                            UART_1_DMA_DESCR0_MASK : UART_1_DMA_DESCR1_MASK;

                    /* Adjust burst counter taking to account: 2 valid descriptors and interrupt trigger after valid descriptor were executed. */
                    UART_1_DmaEpBurstCnt[epNumber] = UART_1_DMA_GET_BURST_CNT(UART_1_DmaEpBurstCnt[epNumber]);

                    /* Restore DMA settings for current transfer. */
                    UART_1_CyDmaChDisable(channelNum);

                    /* Restore destination address for input endpoint. */
                    UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR0, (void*) ((uint32) UART_1_DmaEpBufferAddrBackup[epNumber]));
                    UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR1, (void*) ((uint32) UART_1_DmaEpBufferAddrBackup[epNumber] +
                                                                                                                   UART_1_DMA_BYTES_PER_BURST));

                    /* Set number of elements to transfer. */
                    UART_1_CyDmaSetNumDataElements(channelNum, UART_1_DMA_DESCR0, lengthDescr0);
                    UART_1_CyDmaSetNumDataElements(channelNum, UART_1_DMA_DESCR1, lengthDescr1);

                    /* Validate descriptor 0 and command to start with it. */
                    UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR0);
                    UART_1_CyDmaSetDescriptor0Next(channelNum);

                    /* Enable DMA channel: configuration complete. */
                    UART_1_CyDmaChEnable(channelNum);

                #if !defined (UART_1_MANUAL_IN_EP_ARM)
                    /* Set IN data ready to generate DMA request to load data into endpoint buffer. */
                    UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg |= UART_1_ARB_EPX_CFG_IN_DATA_RDY;
                #endif  /* (UART_1_MANUAL_IN_EP_ARM) */

                    /* IN endpoint will be armed in ARB_ISR(source: IN_BUF_FULL) after first DMA transfer has been completed. */
                }
                else
                {
                    /* When zero-length packet: arm IN endpoint directly. */
                    UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_EP[epNumber].epMode;
                }
            }
        #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
    #endif /* (UART_1_EP_MANAGEMENT_MANUAL) */
    }
}


/*******************************************************************************
* Function Name: UART_1_ReadOutEP16
****************************************************************************//**
*
*   This function performs different functionality depending on the Component’s
*   configured Endpoint Buffer Management. This parameter is defined in the
*   Descriptor Root in Component Configure window.
*
*   *Manual (Static/Dynamic Allocation):*
*   This function moves the specified number of bytes from endpoint buffer to
*   system RAM. The number of bytes actually transferred from endpoint buffer to
*   system RAM is the lesser of the actual number of bytes sent by the host or
*   the number of bytes requested by the length parameter.
*
*   *DMA with Manual Buffer Management:*
*   Configure DMA to transfer data from endpoint buffer to system RAM. Generate
*   a DMA request. The firmware must wait until the DMA completes the data
*   transfer after calling the UART_1_ReadOutEP() API. For example,
*   by checking EPstate:
*
*   \snippet /USBFS_sut_02.cydsn/main.c checking EPstatey
*
*   The USBFS_EnableOutEP() has to be called to allow host to write data into
*   the endpoint buffer after DMA has completed transfer data from OUT endpoint
*   buffer to SRAM.
*
*   *DMA with Automatic Buffer Management:*
*   Configure DMA. This is required only once and automatically generates DMA
*   requests as data arrives
*
*  \param epNumber: Contains the data endpoint number.
*         Valid values are between 1 and 8.
*  \param pData: A pointer to a data array into which the data for the endpoint
*         space is copied. It shall be ensured that this pointer address is
*         even to ensure the 16-bit transfer is aligned to even address. Else,
*         a hard fault condition can occur.
*  \param length: The number of bytes to transfer from the USB Out endpoint and
*         loads it into data array. Valid values are between 0 and 1023. The
*         function moves fewer than the requested number of bytes if the host
*         sends fewer bytes than requested.
*
* \return
*  Number of bytes received, 0 for an invalid endpoint.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint16 UART_1_ReadOutEP16(uint8 epNumber, uint8 pData[], uint16 length)
{
    uint32 adjLength;

    /* Check array alignment on half-word boundary */
    CYASSERT(0u == (((uint32) pData) & 0x01u));

    if ((pData != NULL) && (epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
    {
    #if (!UART_1_EP_MANAGEMENT_DMA_AUTO)
        /* Adjust requested length to available data. */
        length = (length > UART_1_GetEPCount(epNumber)) ? UART_1_GetEPCount(epNumber) : length;
    #endif /* (!UART_1_EP_MANAGEMENT_DMA_AUTO) */

    /* Adjust requested length: 2 bytes are handled at one data register access. */
    adjLength =  length + ((uint32)length & 1u);

    #if (UART_1_EP_MANAGEMENT_MANUAL)
        {
            /* Convert uint8 array to uint16. */
            uint16 *dataBuf = (uint16 *) pData;

            /* Copy data using 16-bits arbiter data register. */
            uint16 i;
            for (i = 0u; i < (adjLength >> 1u); ++i)
            {
                dataBuf[i] = (uint16) UART_1_ARB_EP16_BASE.arbEp[epNumber].rwDr16;
            }
        }

        /* Arm OUT endpoint after data has been read from endpoint buffer. */
        UART_1_EnableOutEP(epNumber);
    #else

        #if (UART_1_EP_MANAGEMENT_DMA_MANUAL)
        {
            uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];

            /* Disable DMA channel: start configuration. */
            UART_1_CyDmaChDisable(channelNum);

            /* Configure source and destination. */
            UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR0, (void*) &UART_1_ARB_EP16_BASE.arbEp[epNumber].rwDr16);
            UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR0, (void*) pData);

            /* Configure DMA descriptor. */
            UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR0, UART_1_DMA_COMMON_CFG | (uint16)((adjLength >> 1u) - 1u) |
                                                    CYDMA_HALFWORD | CYDMA_WORD_ELEMENT | CYDMA_INC_DST_ADDR | CYDMA_INVALIDATE | CYDMA_PREEMPTABLE);

            /* Validate descriptor to execute on following DMA request. */
            UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR0);

            /* Enable DMA channel: configuration complete. */
            UART_1_CyDmaChEnable(channelNum);

            /* Generate DMA request. */
            UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg |=  (uint32)  UART_1_ARB_EPX_CFG_DMA_REQ;
            UART_1_ARB_EP_BASE.arbEp[epNumber].epCfg &=  (uint32) ~UART_1_ARB_EPX_CFG_DMA_REQ;

            /* OUT endpoint has to be armed again by user when DMA transfers have been completed.
            * NO_EVENT_PENDING: notifies that data has been copied from endpoint buffer.
            */
        }
        #endif /* (UART_1_EP_MANAGEMENT_DMA_MANUAL) */

        #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
        {
            uint32 lengthDescr0, lengthDescr1;
            uint32 channelNum = (uint32) UART_1_DmaChan[epNumber];

            /* Get number of full bursts. */
            UART_1_DmaEpBurstCnt[epNumber] = (uint8) (adjLength / UART_1_DMA_BYTES_PER_BURST);

            /* Get number of elements in last burst. */
            UART_1_DmaEpLastBurstEl[epNumber] = (uint8) (adjLength % UART_1_DMA_BYTES_PER_BURST);

            /* Get total number of bursts. */
            UART_1_DmaEpBurstCnt[epNumber] += (0u != UART_1_DmaEpLastBurstEl[epNumber]) ? 1u : 0u;

            /* Adjust number of data elements transferred in last burst. */
            UART_1_DmaEpLastBurstEl[epNumber] = (0u != UART_1_DmaEpLastBurstEl[epNumber]) ?
                                                                  ((UART_1_DmaEpLastBurstEl[epNumber] >> 1u) - 1u) :
                                                                   (UART_1_DMA_HALFWORDS_PER_BURST - 1u);

            /* Get number of data elements to transfer for descriptor 0 and 1. */
            lengthDescr0 = (1u == UART_1_DmaEpBurstCnt[epNumber]) ? UART_1_DmaEpLastBurstEl[epNumber] : (UART_1_DMA_HALFWORDS_PER_BURST - 1u);
            lengthDescr1 = (2u == UART_1_DmaEpBurstCnt[epNumber]) ? UART_1_DmaEpLastBurstEl[epNumber] : (UART_1_DMA_HALFWORDS_PER_BURST - 1u);

            /* Mark last descriptor to be executed. */
            UART_1_DmaEpLastBurstEl[epNumber] |= (0u != (UART_1_DmaEpBurstCnt[epNumber] & 0x1u)) ?
                                                                    UART_1_DMA_DESCR0_MASK : UART_1_DMA_DESCR1_MASK;

            /* Mark if revert number of data elements in descriptor after transfer completion. */
            UART_1_DmaEpLastBurstEl[epNumber] |= (UART_1_DmaEpBurstCnt[epNumber] > 2u) ? UART_1_DMA_DESCR_REVERT : 0u;

            /* Mark that 16-bits access to data register is performed. */
            UART_1_DmaEpLastBurstEl[epNumber] |= UART_1_DMA_DESCR_16BITS;

            /* Adjust burst counter taking to account: 2 valid descriptors and interrupt trigger after valid descriptor were executed. */
            UART_1_DmaEpBurstCnt[epNumber] = UART_1_DMA_GET_BURST_CNT(UART_1_DmaEpBurstCnt[epNumber]);

            /* Store address of buffer and burst counter for endpoint. */
            UART_1_DmaEpBufferAddrBackup[epNumber] = (uint32) pData;
            UART_1_DmaEpBurstCntBackup[epNumber]   = UART_1_DmaEpBurstCnt[epNumber];

            /* Disable DMA channel: start configuration. */
            UART_1_CyDmaChDisable(channelNum);

            /* Set destination address. */
            UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR0, (void*) &UART_1_ARB_EP16_BASE.arbEp[epNumber].rwDr16);
            UART_1_CyDmaSetSrcAddress(channelNum, UART_1_DMA_DESCR1, (void*) &UART_1_ARB_EP16_BASE.arbEp[epNumber].rwDr16);

            UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR0, (void*) ((uint32) pData));
            UART_1_CyDmaSetDstAddress(channelNum, UART_1_DMA_DESCR1, (void*) ((uint32) pData + UART_1_DMA_BYTES_PER_BURST));

            /* Configure DMA descriptor 0. */
            UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR0, UART_1_DMA_COMMON_CFG  | lengthDescr0 |
                                                    CYDMA_HALFWORD | CYDMA_WORD_ELEMENT | CYDMA_INC_DST_ADDR | CYDMA_INVALIDATE | CYDMA_CHAIN);

            /* Configure DMA descriptor 1. */
            UART_1_CyDmaSetConfiguration(channelNum, UART_1_DMA_DESCR1, UART_1_DMA_COMMON_CFG  | lengthDescr1 |
                                                    CYDMA_HALFWORD | CYDMA_WORD_ELEMENT | CYDMA_INC_DST_ADDR | CYDMA_CHAIN);

            /* Enable interrupt from DMA channel. */
            UART_1_CyDmaSetInterruptMask(channelNum);

            /* Validate DMA descriptor 0 and 1. */
            UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR0);
            UART_1_CyDmaValidateDescriptor(channelNum, UART_1_DMA_DESCR1);

            /* Enable DMA channel: configuration complete. */
            UART_1_CyDmaChEnable(channelNum);

            /* OUT endpoint has to be armed again by user when DMA transfers have been completed.
            * NO_EVENT_PENDING: notifies that data has been copied from endpoint buffer.
            */
        }
        #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
    #endif /* (UART_1_EP_MANAGEMENT_MANUAL) */
    }
    else
    {
        length = 0u;
    }

    return (length);
}
#endif /* (UART_1_16BITS_EP_ACCESS_ENABLE) */


/*******************************************************************************
* Function Name: UART_1_EnableOutEP
****************************************************************************//**
*
*  This function enables the specified endpoint for OUT transfers. Do not call
*  this function for IN endpoints.
*
*  \param epNumber: Contains the data endpoint number. Valid values are between
*  1 and 8.
*
* \globalvars
*
*  \ref UART_1_EP[epNumber].apiEpState - set to NO_EVENT_PENDING
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_EnableOutEP(uint8 epNumber) 
{
    if ((epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
    {
        UART_1_EP[epNumber].apiEpState = UART_1_NO_EVENT_PENDING;

        /* Enable OUT endpoint to be written by Host. */
        UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_EP[epNumber].epMode;
        
    }
}


/*******************************************************************************
* Function Name: UART_1_DisableOutEP
****************************************************************************//**
*
*  This function disables the specified USBFS OUT endpoint. Do not call this
*  function for IN endpoints.
*
*  \param epNumber: Contains the data endpoint number.
*            Valid values are between 1 and 8.
*
*******************************************************************************/
void UART_1_DisableOutEP(uint8 epNumber) 
{
    if ((epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
    {
        /* Set NAK response for OUT endpoint. */
        UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_MODE_NAK_OUT;
    }
}


/*******************************************************************************
* Function Name: UART_1_Force
****************************************************************************//**
*
*  This function forces a USB J, K, or SE0 state on the D+/D– lines. It provides
*  the necessary mechanism for a USB device application to perform a USB Remote
*  Wakeup. For more information, see the USB 2.0 Specification for details on
*  Suspend and Resume.
*
*  \param state A byte indicating which of the four bus states to enable.
*        Symbolic names  and their associated values are listed here:
*    State                      |Description
*    ---------------------------|----------------------------------------------
*    UART_1_FORCE_J   | Force a J State onto the D+/D– lines
*    UART_1_FORCE_K   | Force a K State onto the D+/D– lines
*    UART_1_FORCE_SE0 | Force a Single Ended 0 onto the D+/D– lines
*    UART_1_FORCE_NONE| Return bus to SIE control
*
*
*******************************************************************************/
void UART_1_Force(uint8 bState) 
{
    /* This registers is used only for manual control of SIE (no masking is
    * needed before write into it).
    */
    UART_1_USBIO_CR0_REG = bState;
}


/*******************************************************************************
* Function Name: UART_1_GetEPAckState
****************************************************************************//**
*
*  This function determines whether an ACK transaction occurred on this endpoint
*  by reading the ACK bit in the control register of the endpoint. It does not
*  clear the ACK bit.
*
*  \param epNumber Contains the data endpoint number.
*            Valid values are between 1 and 8.
*
*  \return
*  If an ACKed transaction occurred, this function returns a non-zero value.
*  Otherwise, it returns zero.
*
*******************************************************************************/
uint8 UART_1_GetEPAckState(uint8 epNumber) 
{
    uint8 cr = 0u;

    if ((epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
    {
        cr = UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 & UART_1_MODE_ACKD;
    }

    return ((uint8) cr);
}


/*******************************************************************************
* Function Name: UART_1_SetPowerStatus
****************************************************************************//**
*
*  This function sets the current power status. The device replies to USB
*  GET_STATUS requests based on this value. This allows the device to properly
*  report its status for USB Chapter 9 compliance. Devices can change their
*  power source from self powered to bus powered at any time and report their
*  current power source as part of the device status. You should call this
*  function any time your device changes from self powered to bus powered or
*  vice versa, and set the status appropriately.
*
*  \param powerStatus: Contains the desired power status, one for self powered
*        or zero for bus powered. Symbolic names and their associated values are
*        given here:
*  Power Status                                |Description
*  --------------------------------------------|---------------------------
*  UART_1_DEVICE_STATUS_BUS_POWERED  | Set the device to bus powered
*  UART_1_DEVICE_STATUS_SELF_POWERED | Set the device to self powered
*
* \globalvars
*
*  \ref UART_1_deviceStatus - set power status
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_SetPowerStatus(uint8 powerStatus) 
{
    if (powerStatus != UART_1_DEVICE_STATUS_BUS_POWERED)
    {
        UART_1_deviceStatus |= (uint8)  UART_1_DEVICE_STATUS_SELF_POWERED;
    }
    else
    {
        UART_1_deviceStatus &= (uint8) ~UART_1_DEVICE_STATUS_SELF_POWERED;
    }
}


#if (UART_1_VBUS_MONITORING_ENABLE)
    /***************************************************************************
    * Function Name: UART_1_VBusPresent
    ************************************************************************//**
    *
    *  Determines VBUS presence for self-powered devices. This function is
    *  available when the VBUS Monitoring option is enabled in the Advanced tab.
    *
    * \return
    *  The return value can be the following:
    *  Return Value | Description
    *  -------------|-----------------
    *  1            | VBUS is present
    *  0            | VBUS is absent
    *
    *
    ***************************************************************************/
    uint8 UART_1_VBusPresent(void) 
    {
        return ((0u != (UART_1_VBUS_STATUS_REG & UART_1_VBUS_VALID)) ? (uint8) 1u : (uint8) 0u);
    }
#endif /* (UART_1_VBUS_MONITORING_ENABLE) */


/*******************************************************************************
* Function Name: UART_1_RWUEnabled
****************************************************************************//**
*
*  This function returns the current remote wakeup status.
*  If the device supports remote wakeup, the application should use this
*  function to determine if remote wakeup was enabled by the host. When the
*  device is suspended and it determines the conditions to initiate a remote
*  wakeup are met, the application should use the USBFS_Force() function to
*  force the appropriate J and K states onto the USB bus, signaling a remote
*  wakeup.
*
*
* \return
*  Returns non-zero value if remote wakeup is enabled and zero otherwise.
*
* \globalvars
*  UART_1_deviceStatus - checked to determine remote status
*
*******************************************************************************/
uint8 UART_1_RWUEnabled(void) 
{
    uint8 result = UART_1_FALSE;

    if (0u != (UART_1_deviceStatus & UART_1_DEVICE_STATUS_REMOTE_WAKEUP))
    {
        result = UART_1_TRUE;
    }

    return (result);
}


/*******************************************************************************
* Function Name: UART_1_GetDeviceAddress
****************************************************************************//**
*
*  This function returns the currently assigned address for the USB device.
*
* \return
*  Returns the currently assigned address.
*  Returns 0 if the device has not yet been assigned an address.
*
*******************************************************************************/
uint8 UART_1_GetDeviceAddress(void) 
{
    return (uint8)(UART_1_CR0_REG & UART_1_CR0_DEVICE_ADDRESS_MASK);
}


/*******************************************************************************
* Function Name: UART_1_EnableSofInt
****************************************************************************//**
*
*  This function enables interrupt generation when a Start-of-Frame (SOF)
*  packet is received from the host.
*
*******************************************************************************/
void UART_1_EnableSofInt(void) 
{
#if (CY_PSOC4)
    /* Enable SOF interrupt interrupt source. */
    UART_1_INTR_SIE_MASK_REG |= (uint32) UART_1_INTR_SIE_SOF_INTR;
#else
    /* Enable SOF interrupt if it is present. */
    #if (UART_1_SOF_ISR_ACTIVE)
        CyIntEnable(UART_1_SOF_VECT_NUM);
    #endif /* (UART_1_SOF_ISR_ACTIVE) */
#endif /* (CY_PSOC4) */
}


/*******************************************************************************
* Function Name: UART_1_DisableSofInt
****************************************************************************//**
*
*  This function disables interrupt generation when a Start-of-Frame (SOF)
*  packet is received from the host.
*
*******************************************************************************/
void UART_1_DisableSofInt(void) 
{
#if (CY_PSOC4)
    /* Disable SOF interrupt interrupt source. */
    UART_1_INTR_SIE_MASK_REG &= (uint32) ~UART_1_INTR_SIE_SOF_INTR;
#else
    /* Disable SOF interrupt if it is present. */
    #if (UART_1_SOF_ISR_ACTIVE)
        CyIntDisable(UART_1_SOF_VECT_NUM);
    #endif /* (UART_1_SOF_ISR_ACTIVE) */
#endif /* (CY_PSOC4) */
}


#if (UART_1_BATT_CHARG_DET_ENABLE)
    /***************************************************************************
    * Function Name: UART_1_DetectPortType
    ************************************************************************//**
    *
    *   This function implements the USB  Battery Charger Detection (BCD)
    *   algorithm to determine the type of USB host downstream port. This API
    *   is available only for PSoC 4 devices, and should be called when the VBUS
    *   voltage transition (OFF to ON) is detected on the bus. If the USB device
    *   functionality is enabled, this API first calls USBFS_Stop() API
    *   internally to disable the USB device functionality, and then proceeds to
    *   implement the BCD algorithm to detect the USB host port type.
    *   The USBFS_Start() API should be called after this API if the USB
    *   communication needs to be initiated with the host.
    *   *Note* This API is generated only if the “Enable Battery Charging 
    *   Detection” option is enabled in the “Advanced” tab of the component GUI.
    *   *Note* API implements the steps 2-4 of the BCD algorithm which are 
    *   - Data Contact Detect
    *   - Primary Detection 
    *   - Secondary Detection 
    * 
    *   The first step of BCD algorithm, namely, VBUS detection shall be handled 
    *   at the application firmware level.
    *
    * \return
    *   The return value can be the following:
    *   Return Value                      |Description
    *   ----------------------------------|-------------------------------------
    *   UART_1_BCD_PORT_SDP     | Standard downstream port detected
    *   UART_1_BCD_PORT_CDP     | Charging downstream port detected
    *   UART_1_BCD_PORT_DCP     | Dedicated charging port detected
    *   UART_1_BCD_PORT_UNKNOWN | Unable to detect charging port type (proprietary charger type)
    *   UART_1_BCD_PORT_ERR     | Error condition in detection process
    *
    *
    * \sideeffects
    *
    *  USB device functionality is disabled by this API if not already disabled.
    *
    ***************************************************************************/
    uint8 UART_1_Bcd_DetectPortType(void)
    {
        uint32 bkPwrCtrl;
        uint32 cr1RegVal;
        uint32 secondaryDetection = 0u;
        uint8 result = UART_1_BCD_PORT_UNKNOWN;

        /*Check USB Started and Stop it*/
        if(0u != UART_1_initVar)
        {
            UART_1_Stop();
        }
        /*Initialize USBFS IP for Charger detection*/

        /*Enable clock to USB IP. */
        UART_1_USB_CLK_EN_REG = UART_1_USB_CLK_CSR_CLK_EN;

        /* Enable USBIO control on drive mode of D+ and D- pins. */
        UART_1_USBIO_CR1_REG &= ~ (uint32) UART_1_USBIO_CR1_IOMODE;

        /* Select VBUS detection source and clear PHY isolate. The application
        *  level must ensure that VBUS is valid. There is no need to wait 2us
        *  before VBUS is valid.
        */
        bkPwrCtrl = UART_1_POWER_CTRL_REG;
        UART_1_POWER_CTRL_REG = UART_1_DEFAULT_POWER_CTRL_VBUS\
                            & (~UART_1_POWER_CTRL_ENABLE_VBUS_PULLDOWN)\
                            & (~UART_1_POWER_CTRL_ENABLE_DM_PULLDOWN);


        /* Enable PHY detector and single-ended and differential receivers.
         * Enable charger detection.  */
        UART_1_POWER_CTRL_REG |= UART_1_DEFAULT_POWER_CTRL_PHY\
                                         | UART_1_POWER_CTRL_ENABLE_CHGDET;

        /* Suspend clear sequence. */
        UART_1_POWER_CTRL_REG &= (uint32) ~UART_1_POWER_CTRL_SUSPEND;
        CyDelayUs(UART_1_WAIT_SUSPEND_DEL_DISABLE);
        UART_1_POWER_CTRL_REG &= (uint32) ~UART_1_POWER_CTRL_SUSPEND_DEL;

        /* Data connection detection
        * Realization with delay as Hard IP does not support DCD 300 ms.
        */
        #if defined (UART_1_NO_DCD)
        CyDelay(UART_1_BCD_TIMEOUT);
        #else
        /* DCD implementation:*/

        {
            uint16 timeout = UART_1_BCD_TIMEOUT;
            uint8 connectionApproved = 0u;
            uint8 connected = 0u;

            /*   BCD spec 1.2: Turns on Idp_src and D- pull-down resistor */
            UART_1_POWER_CTRL_REG |= UART_1_POWER_CTRL_ENABLE_DM_PULLDOWN;
            UART_1_CHGDET_CTRL_REG |= UART_1_CHGDET_CTRL_DCD_SRC_EN;

            /* BCD spec 1.2: Waits for D+ to be low for a time of Tdcd_dbnc*/
            while ((0u != timeout) && (0u == connectionApproved))
            {
                if (0u == (UART_1_USBIO_CR1_REG & UART_1_USBIO_CR1_DP0))
                {
                    connected++;
                }
                else
                {
                    connected = 0u;
                }
                connectionApproved = (UART_1_BCD_TDCD_DBNC < connected) ? 1u:0u;
                CyDelay(1u);
                timeout--;
            }

            /*   BCD spec 1.2: Turns off Idp_src. */
            UART_1_CHGDET_CTRL_REG &= ~UART_1_CHGDET_CTRL_DCD_SRC_EN;
        }
        #endif /*(UART_1_NO_DCD)*/

        /* Primary detection: enable VDP_SRC on D+ and IDM_SINK on D-. */
        UART_1_CHGDET_CTRL_REG = UART_1_CHGDET_CTRL_PRIMARY;
        CyDelay(UART_1_BCD_PRIMARY_WAIT);
        cr1RegVal = UART_1_USBIO_CR1_REG;

        /* Check is it SDP or DCP/CDP, read comparator 2 output. */
        if (0u == (UART_1_CHGDET_CTRL_REG & UART_1_CHGDET_CTRL_COMP_OUT))
        {
            /* Check status of D- line. */
            if (0u == (cr1RegVal & UART_1_USBIO_CR1_DM0))
            {
                result = UART_1_BCD_PORT_SDP;
            }
            else
            {
                /* ERROR: such combination is impossible. Abort charger
                 * detection.
                */
                result = UART_1_BCD_PORT_ERR;
            }
        }
        else
        {
                /* Need Secondary detection. Charging port: DCP or proprietary*/
                secondaryDetection = 1u;
        }

        /* Secondary detection: Set CHGDET_CTRL register to enable VDM_SRC on D- and IDP_SINK on D+. */

        if (0u != secondaryDetection)
        {
            UART_1_CHGDET_CTRL_REG = UART_1_CHGDET_CTRL_DEFAULT \
                                                | UART_1_CHGDET_CTRL_SECONDARY;
            CyDelay(UART_1_BCD_SECONDARY_WAIT);
            cr1RegVal = UART_1_USBIO_CR1_REG;

            /* Check is it SDP or DCP/CDP, read comparator 1 output. */
            if (0u == (UART_1_CHGDET_CTRL_REG & UART_1_CHGDET_CTRL_COMP_OUT))
            {
                /* Check status of D+ line. */
                if (0u == (cr1RegVal & UART_1_USBIO_CR1_DP0))
                {
                    result = UART_1_BCD_PORT_CDP;
                }
                else
                {
                    /* ERROR: such combination is impossible. Abort charger
                     * detection.
                    */
                    result = UART_1_BCD_PORT_ERR;
                }
            }
            else
            {
                /* Check status of D+ line. */
                if (0u == (cr1RegVal & UART_1_USBIO_CR1_DP0))
                {
                    result = UART_1_BCD_PORT_DCP;
                }
                else
                {
                    /* It is may be proprietary charger. Proprietary charge is
                     * not supported byHardware IP block.
                    */
                    result = UART_1_BCD_PORT_UNKNOWN;
                }
            }
        }

        /* Restore CHGDET_CTRL. */
        UART_1_CHGDET_CTRL_REG = 0u;

        /*Revert registers back*/
        UART_1_POWER_CTRL_REG = bkPwrCtrl;
        UART_1_USBIO_CR1_REG |= (uint32) UART_1_USBIO_CR1_IOMODE;
        UART_1_USB_CLK_EN_REG = ~UART_1_USB_CLK_CSR_CLK_EN;

        return (result);
    }
#endif  /* (UART_1_BATT_CHARG_DET_ENABLE) */


#if (UART_1_LPM_ACTIVE)
    /***************************************************************************
    * Function Name: UART_1_Lpm_GetBeslValue
    ************************************************************************//**
    *
    *  This function returns the Best Effort Service Latency (BESL) value
    *  sent by the host as part of the LPM token transaction.
    *
    * \return
    *  4-bit BESL value received in the LPM token packet from the host
    *
    *
    ***************************************************************************/
    uint32 UART_1_Lpm_GetBeslValue(void)
    {
        return (uint32) (UART_1_LPM_STAT_REG & UART_1_LPM_STAT_LPM_BESL_MASK);
    }


    /***************************************************************************
    * Function Name: UART_1_Lpm_RemoteWakeUpAllowed
    ************************************************************************//**
    *
    *  This function returns the remote wakeup permission set for the device by
    *  the host as part of the LPM token transaction.
    *
    * \return
    *   0 - remote wakeup not allowed, 1 - remote wakeup allowed
    *
    *
    ***************************************************************************/
    uint32 UART_1_Lpm_RemoteWakeUpAllowed(void)
    {
        return (uint32) (UART_1_LPM_STAT_REG & UART_1_LPM_STAT_LPM_REMOTE_WAKE);
    }


    /***************************************************************************
    * Function Name: UART_1_Lpm_SetResponse
    ************************************************************************//**
    *
    *  This function configures the response in the handshake packet the device
    *  has to send when an LPM token packet is received.
    *
    * \param response
    *   type of response to return for an LPM token packet
    *   Allowed response values:
    *       - UART_1_LPM_REQ_ACK - next LPM request will be
    *                                           responded with ACK
    *       - UART_1_LPM_REQ_NACK - next LPM request will be
    *                                           responded with NACK
    *       - UART_1_LPM_REQ_NYET - next LPM request will be
    *                                           responded with NYET
    *
    ***************************************************************************/
    void UART_1_Lpm_SetResponse(uint32 response)
    {
        uint32 lpmCtrl = UART_1_LPM_CTRL_REG & (uint32) ~UART_1_LPM_CTRL_ACK_NYET_MASK;

        UART_1_LPM_CTRL_REG = lpmCtrl | ((uint32) response & UART_1_LPM_CTRL_ACK_NYET_MASK);
    }


    /***************************************************************************
    * Function Name: UART_1_Lpm_GetResponse
    ************************************************************************//**
    *
    *  This function returns the currently configured response value that the
    *  device will send as part of the handshake packet when an LPM token
    *  packet is received.
    *
    * \return
    *   type of handshake response that will be returned by the device
    *   for an LPM token packet
    *   Possible response values:
    *       - UART_1_LPM_REQ_ACK - next LPM request will be responded
    *                                        with ACK
    *       - UART_1_LPM_REQ_NACK - next LPM request will be responded
    *                                        with NACK
    *       - UART_1_LPM_REQ_NYET - next LPM request will be responded
    *                                        with NYET
    *
    ***************************************************************************/
    uint32 UART_1_Lpm_GetResponse(void)
    {

        return  ((uint32) UART_1_LPM_CTRL_REG & (uint32)UART_1_LPM_CTRL_ACK_NYET_MASK);
    }


#endif /* (UART_1_LPM_ACTIVE) */


/* [] END OF FILE */
