/***************************************************************************//**
* \file UART_1_std.c
* \version 3.0
*
* \brief
*  This file contains the USB Standard request handler.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_1_pvt.h"

/***************************************
*   Static data allocation
***************************************/

#if defined(UART_1_ENABLE_FWSN_STRING)
    static volatile uint8* UART_1_fwSerialNumberStringDescriptor;
    static volatile uint8  UART_1_snStringConfirm = UART_1_FALSE;
#endif  /* (UART_1_ENABLE_FWSN_STRING) */

#if defined(UART_1_ENABLE_FWSN_STRING)
    /***************************************************************************
    * Function Name: UART_1_SerialNumString
    ************************************************************************//**
    *
    *  This function is available only when the User Call Back option in the 
    *  Serial Number String descriptor properties is selected. Application 
    *  firmware can provide the source of the USB device serial number string 
    *  descriptor during run time. The default string is used if the application 
    *  firmware does not use this function or sets the wrong string descriptor.
    *
    *  \param snString:  Pointer to the user-defined string descriptor. The 
    *  string descriptor should meet the Universal Serial Bus Specification 
    *  revision 2.0 chapter 9.6.7
    *  Offset|Size|Value|Description
    *  ------|----|------|---------------------------------
    *  0     |1   |N     |Size of this descriptor in bytes
    *  1     |1   |0x03  |STRING Descriptor Type
    *  2     |N-2 |Number|UNICODE encoded string
    *  
    * *For example:* uint8 snString[16]={0x0E,0x03,'F',0,'W',0,'S',0,'N',0,'0',0,'1',0};
    *
    * \reentrant
    *  No.
    *
    ***************************************************************************/
    void  UART_1_SerialNumString(uint8 snString[]) 
    {
        UART_1_snStringConfirm = UART_1_FALSE;
        
        if (snString != NULL)
        {
            /* Check descriptor validation */
            if ((snString[0u] > 1u) && (snString[1u] == UART_1_DESCR_STRING))
            {
                UART_1_fwSerialNumberStringDescriptor = snString;
                UART_1_snStringConfirm = UART_1_TRUE;
            }
        }
    }
#endif  /* UART_1_ENABLE_FWSN_STRING */


/*******************************************************************************
* Function Name: UART_1_HandleStandardRqst
****************************************************************************//**
*
*  This Routine dispatches standard requests
*
*
* \return
*  TRUE if request handled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 UART_1_HandleStandardRqst(void) 
{
    uint8 requestHandled = UART_1_FALSE;
    uint8 interfaceNumber;
    uint8 configurationN;
    uint8 bmRequestType = UART_1_bmRequestTypeReg;

#if defined(UART_1_ENABLE_STRINGS)
    volatile uint8 *pStr = 0u;
    #if defined(UART_1_ENABLE_DESCRIPTOR_STRINGS)
        uint8 nStr;
        uint8 descrLength;
    #endif /* (UART_1_ENABLE_DESCRIPTOR_STRINGS) */
#endif /* (UART_1_ENABLE_STRINGS) */
    
    static volatile uint8 UART_1_tBuffer[UART_1_STATUS_LENGTH_MAX];
    const T_UART_1_LUT CYCODE *pTmp;

    UART_1_currentTD.count = 0u;

    if (UART_1_RQST_DIR_D2H == (bmRequestType & UART_1_RQST_DIR_MASK))
    {
        /* Control Read */
        switch (UART_1_bRequestReg)
        {
            case UART_1_GET_DESCRIPTOR:
                if (UART_1_DESCR_DEVICE ==UART_1_wValueHiReg)
                {
                    pTmp = UART_1_GetDeviceTablePtr();
                    UART_1_currentTD.pData = (volatile uint8 *)pTmp->p_list;
                    UART_1_currentTD.count = UART_1_DEVICE_DESCR_LENGTH;
                    
                    requestHandled  = UART_1_InitControlRead();
                }
                else if (UART_1_DESCR_CONFIG == UART_1_wValueHiReg)
                {
                    pTmp = UART_1_GetConfigTablePtr((uint8) UART_1_wValueLoReg);
                    
                    /* Verify that requested descriptor exists */
                    if (pTmp != NULL)
                    {
                        UART_1_currentTD.pData = (volatile uint8 *)pTmp->p_list;
                        UART_1_currentTD.count = (uint16)((uint16)(UART_1_currentTD.pData)[UART_1_CONFIG_DESCR_TOTAL_LENGTH_HI] << 8u) | \
                                                                            (UART_1_currentTD.pData)[UART_1_CONFIG_DESCR_TOTAL_LENGTH_LOW];
                        requestHandled  = UART_1_InitControlRead();
                    }
                }
                
            #if(UART_1_BOS_ENABLE)
                else if (UART_1_DESCR_BOS == UART_1_wValueHiReg)
                {
                    pTmp = UART_1_GetBOSPtr();
                    
                    /* Verify that requested descriptor exists */
                    if (pTmp != NULL)
                    {
                        UART_1_currentTD.pData = (volatile uint8 *)pTmp;
                        UART_1_currentTD.count = ((uint16)((uint16)(UART_1_currentTD.pData)[UART_1_BOS_DESCR_TOTAL_LENGTH_HI] << 8u)) | \
                                                                             (UART_1_currentTD.pData)[UART_1_BOS_DESCR_TOTAL_LENGTH_LOW];
                        requestHandled  = UART_1_InitControlRead();
                    }
                }
            #endif /*(UART_1_BOS_ENABLE)*/
            
            #if defined(UART_1_ENABLE_STRINGS)
                else if (UART_1_DESCR_STRING == UART_1_wValueHiReg)
                {
                /* Descriptor Strings */
                #if defined(UART_1_ENABLE_DESCRIPTOR_STRINGS)
                    nStr = 0u;
                    pStr = (volatile uint8 *) &UART_1_STRING_DESCRIPTORS[0u];
                    
                    while ((UART_1_wValueLoReg > nStr) && (*pStr != 0u))
                    {
                        /* Read descriptor length from 1st byte */
                        descrLength = *pStr;
                        /* Move to next string descriptor */
                        pStr = &pStr[descrLength];
                        nStr++;
                    }
                #endif /* (UART_1_ENABLE_DESCRIPTOR_STRINGS) */
                
                /* Microsoft OS String */
                #if defined(UART_1_ENABLE_MSOS_STRING)
                    if (UART_1_STRING_MSOS == UART_1_wValueLoReg)
                    {
                        pStr = (volatile uint8 *)& UART_1_MSOS_DESCRIPTOR[0u];
                    }
                #endif /* (UART_1_ENABLE_MSOS_STRING) */
                
                /* SN string */
                #if defined(UART_1_ENABLE_SN_STRING)
                    if ((UART_1_wValueLoReg != 0u) && 
                        (UART_1_wValueLoReg == UART_1_DEVICE0_DESCR[UART_1_DEVICE_DESCR_SN_SHIFT]))
                    {
                    #if defined(UART_1_ENABLE_IDSN_STRING)
                        /* Read DIE ID and generate string descriptor in RAM */
                        UART_1_ReadDieID(UART_1_idSerialNumberStringDescriptor);
                        pStr = UART_1_idSerialNumberStringDescriptor;
                    #elif defined(UART_1_ENABLE_FWSN_STRING)
                        
                        if(UART_1_snStringConfirm != UART_1_FALSE)
                        {
                            pStr = UART_1_fwSerialNumberStringDescriptor;
                        }
                        else
                        {
                            pStr = (volatile uint8 *)&UART_1_SN_STRING_DESCRIPTOR[0u];
                        }
                    #else
                        pStr = (volatile uint8 *)&UART_1_SN_STRING_DESCRIPTOR[0u];
                    #endif  /* (UART_1_ENABLE_IDSN_STRING) */
                    }
                #endif /* (UART_1_ENABLE_SN_STRING) */
                
                    if (*pStr != 0u)
                    {
                        UART_1_currentTD.count = *pStr;
                        UART_1_currentTD.pData = pStr;
                        requestHandled  = UART_1_InitControlRead();
                    }
                }
            #endif /*  UART_1_ENABLE_STRINGS */
                else
                {
                    requestHandled = UART_1_DispatchClassRqst();
                }
                break;
                
            case UART_1_GET_STATUS:
                switch (bmRequestType & UART_1_RQST_RCPT_MASK)
                {
                    case UART_1_RQST_RCPT_EP:
                        UART_1_currentTD.count = UART_1_EP_STATUS_LENGTH;
                        UART_1_tBuffer[0u]     = UART_1_EP[UART_1_wIndexLoReg & UART_1_DIR_UNUSED].hwEpState;
                        UART_1_tBuffer[1u]     = 0u;
                        UART_1_currentTD.pData = &UART_1_tBuffer[0u];
                        
                        requestHandled  = UART_1_InitControlRead();
                        break;
                    case UART_1_RQST_RCPT_DEV:
                        UART_1_currentTD.count = UART_1_DEVICE_STATUS_LENGTH;
                        UART_1_tBuffer[0u]     = UART_1_deviceStatus;
                        UART_1_tBuffer[1u]     = 0u;
                        UART_1_currentTD.pData = &UART_1_tBuffer[0u];
                        
                        requestHandled  = UART_1_InitControlRead();
                        break;
                    default:    /* requestHandled is initialized as FALSE by default */
                        break;
                }
                break;
                
            case UART_1_GET_CONFIGURATION:
                UART_1_currentTD.count = 1u;
                UART_1_currentTD.pData = (volatile uint8 *) &UART_1_configuration;
                requestHandled  = UART_1_InitControlRead();
                break;
                
            case UART_1_GET_INTERFACE:
                UART_1_currentTD.count = 1u;
                UART_1_currentTD.pData = (volatile uint8 *) &UART_1_interfaceSetting[UART_1_wIndexLoReg];
                requestHandled  = UART_1_InitControlRead();
                break;
                
            default: /* requestHandled is initialized as FALSE by default */
                break;
        }
    }
    else
    {
        /* Control Write */
        switch (UART_1_bRequestReg)
        {
            case UART_1_SET_ADDRESS:
                /* Store address to be set in UART_1_NoDataControlStatusStage(). */
                UART_1_deviceAddress = (uint8) UART_1_wValueLoReg;
                requestHandled = UART_1_InitNoDataControlTransfer();
                break;
                
            case UART_1_SET_CONFIGURATION:
                configurationN = UART_1_wValueLoReg;
                
                /* Verify that configuration descriptor exists */
                if(configurationN > 0u)
                {
                    pTmp = UART_1_GetConfigTablePtr((uint8) configurationN - 1u);
                }
                
                /* Responds with a Request Error when configuration number is invalid */
                if (((configurationN > 0u) && (pTmp != NULL)) || (configurationN == 0u))
                {
                    /* Set new configuration if it has been changed */
                    if(configurationN != UART_1_configuration)
                    {
                        UART_1_configuration = (uint8) configurationN;
                        UART_1_configurationChanged = UART_1_TRUE;
                        UART_1_Config(UART_1_TRUE);
                    }
                    requestHandled = UART_1_InitNoDataControlTransfer();
                }
                break;
                
            case UART_1_SET_INTERFACE:
                if (0u != UART_1_ValidateAlternateSetting())
                {
                    /* Get interface number from the request. */
                    interfaceNumber = UART_1_wIndexLoReg;
                    UART_1_interfaceNumber = (uint8) UART_1_wIndexLoReg;
                     
                    /* Check if alternate settings is changed for interface. */
                    if (UART_1_interfaceSettingLast[interfaceNumber] != UART_1_interfaceSetting[interfaceNumber])
                    {
                        UART_1_configurationChanged = UART_1_TRUE;
                    
                        /* Change alternate setting for the endpoints. */
                    #if (UART_1_EP_MANAGEMENT_MANUAL && UART_1_EP_ALLOC_DYNAMIC)
                        UART_1_Config(UART_1_FALSE);
                    #else
                        UART_1_ConfigAltChanged();
                    #endif /* (UART_1_EP_MANAGEMENT_MANUAL && UART_1_EP_ALLOC_DYNAMIC) */
                    }
                    
                    requestHandled = UART_1_InitNoDataControlTransfer();
                }
                break;
                
            case UART_1_CLEAR_FEATURE:
                switch (bmRequestType & UART_1_RQST_RCPT_MASK)
                {
                    case UART_1_RQST_RCPT_EP:
                        if (UART_1_wValueLoReg == UART_1_ENDPOINT_HALT)
                        {
                            requestHandled = UART_1_ClearEndpointHalt();
                        }
                        break;
                    case UART_1_RQST_RCPT_DEV:
                        /* Clear device REMOTE_WAKEUP */
                        if (UART_1_wValueLoReg == UART_1_DEVICE_REMOTE_WAKEUP)
                        {
                            UART_1_deviceStatus &= (uint8)~UART_1_DEVICE_STATUS_REMOTE_WAKEUP;
                            requestHandled = UART_1_InitNoDataControlTransfer();
                        }
                        break;
                    case UART_1_RQST_RCPT_IFC:
                        /* Validate interfaceNumber */
                        if (UART_1_wIndexLoReg < UART_1_MAX_INTERFACES_NUMBER)
                        {
                            UART_1_interfaceStatus[UART_1_wIndexLoReg] &= (uint8) ~UART_1_wValueLoReg;
                            requestHandled = UART_1_InitNoDataControlTransfer();
                        }
                        break;
                    default:    /* requestHandled is initialized as FALSE by default */
                        break;
                }
                break;
                
            case UART_1_SET_FEATURE:
                switch (bmRequestType & UART_1_RQST_RCPT_MASK)
                {
                    case UART_1_RQST_RCPT_EP:
                        if (UART_1_wValueLoReg == UART_1_ENDPOINT_HALT)
                        {
                            requestHandled = UART_1_SetEndpointHalt();
                        }
                        break;
                        
                    case UART_1_RQST_RCPT_DEV:
                        /* Set device REMOTE_WAKEUP */
                        if (UART_1_wValueLoReg == UART_1_DEVICE_REMOTE_WAKEUP)
                        {
                            UART_1_deviceStatus |= UART_1_DEVICE_STATUS_REMOTE_WAKEUP;
                            requestHandled = UART_1_InitNoDataControlTransfer();
                        }
                        break;
                        
                    case UART_1_RQST_RCPT_IFC:
                        /* Validate interfaceNumber */
                        if (UART_1_wIndexLoReg < UART_1_MAX_INTERFACES_NUMBER)
                        {
                            UART_1_interfaceStatus[UART_1_wIndexLoReg] &= (uint8) ~UART_1_wValueLoReg;
                            requestHandled = UART_1_InitNoDataControlTransfer();
                        }
                        break;
                    
                    default:    /* requestHandled is initialized as FALSE by default */
                        break;
                }
                break;
                
            default:    /* requestHandled is initialized as FALSE by default */
                break;
        }
    }
    
    return (requestHandled);
}


#if defined(UART_1_ENABLE_IDSN_STRING)
    /***************************************************************************
    * Function Name: UART_1_ReadDieID
    ************************************************************************//**
    *
    *  This routine read Die ID and generate Serial Number string descriptor.
    *
    *  \param descr:  pointer on string descriptor. This string size has to be equal or
    *          greater than UART_1_IDSN_DESCR_LENGTH.
    *
    *
    * \reentrant
    *  No.
    *
    ***************************************************************************/
    void UART_1_ReadDieID(uint8 descr[]) 
    {
        const char8 CYCODE hex[] = "0123456789ABCDEF";
        uint8 i;
        uint8 j = 0u;
        uint8 uniqueId[8u];

        if (NULL != descr)
        {
            /* Initialize descriptor header. */
            descr[0u] = UART_1_IDSN_DESCR_LENGTH;
            descr[1u] = UART_1_DESCR_STRING;
            
            /* Unique ID size is 8 bytes. */
            CyGetUniqueId((uint32 *) uniqueId);

            /* Fill descriptor with unique device ID. */
            for (i = 2u; i < UART_1_IDSN_DESCR_LENGTH; i += 4u)
            {
                descr[i]      = (uint8) hex[(uniqueId[j] >> 4u)];
                descr[i + 1u] = 0u;
                descr[i + 2u] = (uint8) hex[(uniqueId[j] & 0x0Fu)];
                descr[i + 3u] = 0u;
                ++j;
            }
        }
    }
#endif /* (UART_1_ENABLE_IDSN_STRING) */


/*******************************************************************************
* Function Name: UART_1_ConfigReg
****************************************************************************//**
*
*  This routine configures hardware registers from the variables.
*  It is called from UART_1_Config() function and from RestoreConfig
*  after Wakeup.
*
*******************************************************************************/
void UART_1_ConfigReg(void) 
{
    uint8 ep;

#if (UART_1_EP_MANAGEMENT_DMA_AUTO)
    uint8 epType = 0u;
#endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */

    /* Go thought all endpoints and set hardware configuration */
    for (ep = UART_1_EP1; ep < UART_1_MAX_EP; ++ep)
    {
        UART_1_ARB_EP_BASE.arbEp[ep].epCfg = UART_1_ARB_EPX_CFG_DEFAULT;
        
    #if (UART_1_EP_MANAGEMENT_DMA)
        /* Enable arbiter endpoint interrupt sources */
        UART_1_ARB_EP_BASE.arbEp[ep].epIntEn = UART_1_ARB_EPX_INT_MASK;
    #endif /* (UART_1_EP_MANAGEMENT_DMA) */
    
        if (UART_1_EP[ep].epMode != UART_1_MODE_DISABLE)
        {
            if (0u != (UART_1_EP[ep].addr & UART_1_DIR_IN))
            {
                UART_1_SIE_EP_BASE.sieEp[ep].epCr0 = UART_1_MODE_NAK_IN;
                
            #if (UART_1_EP_MANAGEMENT_DMA_AUTO && CY_PSOC4)
                /* Clear DMA_TERMIN for IN endpoint. */
                UART_1_ARB_EP_BASE.arbEp[ep].epIntEn &= (uint32) ~UART_1_ARB_EPX_INT_DMA_TERMIN;
            #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO && CY_PSOC4) */
            }
            else
            {
                UART_1_SIE_EP_BASE.sieEp[ep].epCr0 = UART_1_MODE_NAK_OUT;

            #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
                /* (CY_PSOC4): DMA_TERMIN for OUT endpoint is set above. */
                
                /* Prepare endpoint type mask. */
                epType |= (uint8) (0x01u << (ep - UART_1_EP1));
            #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
            }
        }
        else
        {
            UART_1_SIE_EP_BASE.sieEp[ep].epCr0 = UART_1_MODE_STALL_DATA_EP;
        }
        
    #if (!UART_1_EP_MANAGEMENT_DMA_AUTO)
        #if (CY_PSOC4)
            UART_1_ARB_EP16_BASE.arbEp[ep].rwRa16  = (uint32) UART_1_EP[ep].buffOffset;
            UART_1_ARB_EP16_BASE.arbEp[ep].rwWa16  = (uint32) UART_1_EP[ep].buffOffset;
        #else
            UART_1_ARB_EP_BASE.arbEp[ep].rwRa    = LO8(UART_1_EP[ep].buffOffset);
            UART_1_ARB_EP_BASE.arbEp[ep].rwRaMsb = HI8(UART_1_EP[ep].buffOffset);
            UART_1_ARB_EP_BASE.arbEp[ep].rwWa    = LO8(UART_1_EP[ep].buffOffset);
            UART_1_ARB_EP_BASE.arbEp[ep].rwWaMsb = HI8(UART_1_EP[ep].buffOffset);
        #endif /* (CY_PSOC4) */
    #endif /* (!UART_1_EP_MANAGEMENT_DMA_AUTO) */
    }

#if (UART_1_EP_MANAGEMENT_DMA_AUTO)
     /* BUF_SIZE depend on DMA_THRESS value:0x55-32 bytes  0x44-16 bytes 0x33-8 bytes 0x22-4 bytes 0x11-2 bytes */
    UART_1_BUF_SIZE_REG = UART_1_DMA_BUF_SIZE;

    /* Configure DMA burst threshold */
#if (CY_PSOC4)
    UART_1_DMA_THRES16_REG   = UART_1_DMA_BYTES_PER_BURST;
#else
    UART_1_DMA_THRES_REG     = UART_1_DMA_BYTES_PER_BURST;
    UART_1_DMA_THRES_MSB_REG = 0u;
#endif /* (CY_PSOC4) */
    UART_1_EP_ACTIVE_REG = UART_1_DEFAULT_ARB_INT_EN;
    UART_1_EP_TYPE_REG   = epType;
    
    /* Cfg_cmp bit set to 1 once configuration is complete. */
    /* Lock arbiter configtuation */
    UART_1_ARB_CFG_REG |= (uint8)  UART_1_ARB_CFG_CFG_CMP;
    /* Cfg_cmp bit set to 0 during configuration of PFSUSB Registers. */
    UART_1_ARB_CFG_REG &= (uint8) ~UART_1_ARB_CFG_CFG_CMP;

#endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */

    /* Enable interrupt SIE interurpt source from EP0-EP1 */
    UART_1_SIE_EP_INT_EN_REG = (uint8) UART_1_DEFAULT_SIE_EP_INT_EN;
}


/*******************************************************************************
* Function Name: UART_1_EpStateInit
****************************************************************************//**
*
*  This routine initialize state of Data end points based of its type: 
*   IN  - UART_1_IN_BUFFER_EMPTY (UART_1_EVENT_PENDING)
*   OUT - UART_1_OUT_BUFFER_EMPTY (UART_1_NO_EVENT_PENDING)
*
*******************************************************************************/
void UART_1_EpStateInit(void) 
{
    uint8 i;

    for (i = UART_1_EP1; i < UART_1_MAX_EP; i++)
    { 
        if (0u != (UART_1_EP[i].addr & UART_1_DIR_IN))
        {
            /* IN Endpoint */
            UART_1_EP[i].apiEpState = UART_1_EVENT_PENDING;
        }
        else
        {
            /* OUT Endpoint */
            UART_1_EP[i].apiEpState = UART_1_NO_EVENT_PENDING;
        }
    }
                    
}


/*******************************************************************************
* Function Name: UART_1_Config
****************************************************************************//**
*
*  This routine configures endpoints for the entire configuration by scanning
*  the configuration descriptor.
*
*  \param clearAltSetting: It configures the bAlternateSetting 0 for each interface.
*
* UART_1_interfaceClass - Initialized class array for each interface.
*   It is used for handling Class specific requests depend on interface class.
*   Different classes in multiple Alternate settings does not supported.
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_Config(uint8 clearAltSetting) 
{
    uint8 ep;
    uint8 curEp;
    uint8 i;
    uint8 epType;
    const uint8 *pDescr;
    
    #if (!UART_1_EP_MANAGEMENT_DMA_AUTO)
        uint16 buffCount = 0u;
    #endif /* (!UART_1_EP_MANAGEMENT_DMA_AUTO) */

    const T_UART_1_LUT CYCODE *pTmp;
    const T_UART_1_EP_SETTINGS_BLOCK CYCODE *pEP;

    /* Clear endpoints settings */
    for (ep = 0u; ep < UART_1_MAX_EP; ++ep)
    {
        UART_1_EP[ep].attrib     = 0u;
        UART_1_EP[ep].hwEpState  = 0u;
        UART_1_EP[ep].epToggle   = 0u;
        UART_1_EP[ep].bufferSize = 0u;
        UART_1_EP[ep].interface  = 0u;
        UART_1_EP[ep].apiEpState = UART_1_NO_EVENT_PENDING;
        UART_1_EP[ep].epMode     = UART_1_MODE_DISABLE;   
    }

    /* Clear Alternate settings for all interfaces. */
    if (0u != clearAltSetting)
    {
        for (i = 0u; i < UART_1_MAX_INTERFACES_NUMBER; ++i)
        {
            UART_1_interfaceSetting[i]     = 0u;
            UART_1_interfaceSettingLast[i] = 0u;
        }
    }

    /* Init Endpoints and Device Status if configured */
    if (UART_1_configuration > 0u)
    {
        #if defined(UART_1_ENABLE_CDC_CLASS)
            uint8 cdcComNums = 0u;
        #endif  /* (UART_1_ENABLE_CDC_CLASS) */  

        pTmp = UART_1_GetConfigTablePtr(UART_1_configuration - 1u);
        
        /* Set Power status for current configuration */
        pDescr = (const uint8 *)pTmp->p_list;
        if ((pDescr[UART_1_CONFIG_DESCR_ATTRIB] & UART_1_CONFIG_DESCR_ATTRIB_SELF_POWERED) != 0u)
        {
            UART_1_deviceStatus |= (uint8)  UART_1_DEVICE_STATUS_SELF_POWERED;
        }
        else
        {
            UART_1_deviceStatus &= (uint8) ~UART_1_DEVICE_STATUS_SELF_POWERED;
        }
        
        /* Move to next element */
        pTmp = &pTmp[1u];
        ep = pTmp->c;  /* For this table, c is the number of endpoints configurations  */

        #if (UART_1_EP_MANAGEMENT_MANUAL && UART_1_EP_ALLOC_DYNAMIC)
            /* Configure for dynamic EP memory allocation */
            /* p_list points the endpoint setting table. */
            pEP = (T_UART_1_EP_SETTINGS_BLOCK *) pTmp->p_list;
            
            for (i = 0u; i < ep; i++)
            {     
                /* Compare current Alternate setting with EP Alt */
                if (UART_1_interfaceSetting[pEP->interface] == pEP->altSetting)
                {                                                          
                    curEp  = pEP->addr & UART_1_DIR_UNUSED;
                    epType = pEP->attributes & UART_1_EP_TYPE_MASK;
                    
                    UART_1_EP[curEp].addr       = pEP->addr;
                    UART_1_EP[curEp].attrib     = pEP->attributes;
                    UART_1_EP[curEp].bufferSize = pEP->bufferSize;

                    if (0u != (pEP->addr & UART_1_DIR_IN))
                    {
                        /* IN Endpoint */
                        UART_1_EP[curEp].epMode     = UART_1_GET_ACTIVE_IN_EP_CR0_MODE(epType);
                        UART_1_EP[curEp].apiEpState = UART_1_EVENT_PENDING;
                    
                    #if (defined(UART_1_ENABLE_MIDI_STREAMING) && (UART_1_MIDI_IN_BUFF_SIZE > 0))
                        if ((pEP->bMisc == UART_1_CLASS_AUDIO) && (epType == UART_1_EP_TYPE_BULK))
                        {
                            UART_1_midi_in_ep = curEp;
                        }
                    #endif  /* (UART_1_ENABLE_MIDI_STREAMING) */
                    }
                    else
                    {
                        /* OUT Endpoint */
                        UART_1_EP[curEp].epMode     = UART_1_GET_ACTIVE_OUT_EP_CR0_MODE(epType);
                        UART_1_EP[curEp].apiEpState = UART_1_NO_EVENT_PENDING;
                        
                    #if (defined(UART_1_ENABLE_MIDI_STREAMING) && (UART_1_MIDI_OUT_BUFF_SIZE > 0))
                        if ((pEP->bMisc == UART_1_CLASS_AUDIO) && (epType == UART_1_EP_TYPE_BULK))
                        {
                            UART_1_midi_out_ep = curEp;
                        }
                    #endif  /* (UART_1_ENABLE_MIDI_STREAMING) */
                    }

                #if(defined (UART_1_ENABLE_CDC_CLASS))
                    if((pEP->bMisc == UART_1_CLASS_CDC_DATA) ||(pEP->bMisc == UART_1_CLASS_CDC))
                    {
                        cdcComNums = UART_1_Cdc_EpInit(pEP, curEp, cdcComNums);
                    }
                #endif  /* (UART_1_ENABLE_CDC_CLASS) */
                }
                
                pEP = &pEP[1u];
            }
            
        #else
            for (i = UART_1_EP1; i < UART_1_MAX_EP; ++i)
            {
                /* p_list points the endpoint setting table. */
                pEP = (const T_UART_1_EP_SETTINGS_BLOCK CYCODE *) pTmp->p_list;
                /* Find max length for each EP and select it (length could be different in different Alt settings) */
                /* but other settings should be correct with regards to Interface alt Setting */
                
                for (curEp = 0u; curEp < ep; ++curEp)
                {
                    if (i == (pEP->addr & UART_1_DIR_UNUSED))
                    {
                        /* Compare endpoint buffers size with current size to find greater. */
                        if (UART_1_EP[i].bufferSize < pEP->bufferSize)
                        {
                            UART_1_EP[i].bufferSize = pEP->bufferSize;
                        }
                        
                        /* Compare current Alternate setting with EP Alt */
                        if (UART_1_interfaceSetting[pEP->interface] == pEP->altSetting)
                        {                            
                            UART_1_EP[i].addr = pEP->addr;
                            UART_1_EP[i].attrib = pEP->attributes;
                            
                            epType = pEP->attributes & UART_1_EP_TYPE_MASK;
                            
                            if (0u != (pEP->addr & UART_1_DIR_IN))
                            {
                                /* IN Endpoint */
                                UART_1_EP[i].epMode     = UART_1_GET_ACTIVE_IN_EP_CR0_MODE(epType);
                                UART_1_EP[i].apiEpState = UART_1_EVENT_PENDING;
                                
                            #if (defined(UART_1_ENABLE_MIDI_STREAMING) && (UART_1_MIDI_IN_BUFF_SIZE > 0))
                                if ((pEP->bMisc == UART_1_CLASS_AUDIO) && (epType == UART_1_EP_TYPE_BULK))
                                {
                                    UART_1_midi_in_ep = i;
                                }
                            #endif  /* (UART_1_ENABLE_MIDI_STREAMING) */
                            }
                            else
                            {
                                /* OUT Endpoint */
                                UART_1_EP[i].epMode     = UART_1_GET_ACTIVE_OUT_EP_CR0_MODE(epType);
                                UART_1_EP[i].apiEpState = UART_1_NO_EVENT_PENDING;
                                
                            #if (defined(UART_1_ENABLE_MIDI_STREAMING) && (UART_1_MIDI_OUT_BUFF_SIZE > 0))
                                if ((pEP->bMisc == UART_1_CLASS_AUDIO) && (epType == UART_1_EP_TYPE_BULK))
                                {
                                    UART_1_midi_out_ep = i;
                                }
                            #endif  /* (UART_1_ENABLE_MIDI_STREAMING) */
                            }

                        #if (defined(UART_1_ENABLE_CDC_CLASS))
                            if((pEP->bMisc == UART_1_CLASS_CDC_DATA) ||(pEP->bMisc == UART_1_CLASS_CDC))
                            {
                                cdcComNums = UART_1_Cdc_EpInit(pEP, i, cdcComNums);
                            }
                        #endif  /* (UART_1_ENABLE_CDC_CLASS) */

                            #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
                                break;  /* Use first EP setting in Auto memory management */
                            #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
                        }
                    }
                    
                    pEP = &pEP[1u];
                }
            }
        #endif /*  (UART_1_EP_MANAGEMENT_MANUAL && UART_1_EP_ALLOC_DYNAMIC) */

        /* Init class array for each interface and interface number for each EP.
        *  It is used for handling Class specific requests directed to either an
        *  interface or the endpoint.
        */
        /* p_list points the endpoint setting table. */
        pEP = (const T_UART_1_EP_SETTINGS_BLOCK CYCODE *) pTmp->p_list;
        for (i = 0u; i < ep; i++)
        {
            /* Configure interface number for each EP */
            UART_1_EP[pEP->addr & UART_1_DIR_UNUSED].interface = pEP->interface;
            pEP = &pEP[1u];
        }
        
        /* Init pointer on interface class table */
        UART_1_interfaceClass = UART_1_GetInterfaceClassTablePtr();
        
    /* Set the endpoint buffer addresses */
    #if (!UART_1_EP_MANAGEMENT_DMA_AUTO)
        buffCount = 0u;
        for (ep = UART_1_EP1; ep < UART_1_MAX_EP; ++ep)
        {
            UART_1_EP[ep].buffOffset = buffCount;        
            buffCount += UART_1_EP[ep].bufferSize;
            
        #if (UART_1_GEN_16BITS_EP_ACCESS)
            /* Align EP buffers to be event size to access 16-bits DR register. */
            buffCount += (0u != (buffCount & 0x01u)) ? 1u : 0u;
        #endif /* (UART_1_GEN_16BITS_EP_ACCESS) */            
        }
    #endif /* (!UART_1_EP_MANAGEMENT_DMA_AUTO) */

        /* Configure hardware registers */
        UART_1_ConfigReg();
    }
}


/*******************************************************************************
* Function Name: UART_1_ConfigAltChanged
****************************************************************************//**
*
*  This routine update configuration for the required endpoints only.
*  It is called after SET_INTERFACE request when Static memory allocation used.
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_ConfigAltChanged(void) 
{
    uint8 ep;
    uint8 curEp;
    uint8 epType;
    uint8 i;
    uint8 interfaceNum;

    const T_UART_1_LUT CYCODE *pTmp;
    const T_UART_1_EP_SETTINGS_BLOCK CYCODE *pEP;

    /* Init Endpoints and Device Status if configured */
    if (UART_1_configuration > 0u)
    {
        /* Get number of endpoints configurations (ep). */
        pTmp = UART_1_GetConfigTablePtr(UART_1_configuration - 1u);
        pTmp = &pTmp[1u];
        ep = pTmp->c;

        /* Get pointer to endpoints setting table (pEP). */
        pEP = (const T_UART_1_EP_SETTINGS_BLOCK CYCODE *) pTmp->p_list;
        
        /* Look through all possible endpoint configurations. Find endpoints 
        * which belong to current interface and alternate settings for 
        * re-configuration.
        */
        interfaceNum = UART_1_interfaceNumber;
        for (i = 0u; i < ep; i++)
        {
            /* Find endpoints which belong to current interface and alternate settings. */
            if ((interfaceNum == pEP->interface) && 
                (UART_1_interfaceSetting[interfaceNum] == pEP->altSetting))
            {
                curEp  = ((uint8) pEP->addr & UART_1_DIR_UNUSED);
                epType = ((uint8) pEP->attributes & UART_1_EP_TYPE_MASK);
                
                /* Change the SIE mode for the selected EP to NAK ALL */
                UART_1_EP[curEp].epToggle   = 0u;
                UART_1_EP[curEp].addr       = pEP->addr;
                UART_1_EP[curEp].attrib     = pEP->attributes;
                UART_1_EP[curEp].bufferSize = pEP->bufferSize;

                if (0u != (pEP->addr & UART_1_DIR_IN))
                {
                    /* IN Endpoint */
                    UART_1_EP[curEp].epMode     = UART_1_GET_ACTIVE_IN_EP_CR0_MODE(epType);
                    UART_1_EP[curEp].apiEpState = UART_1_EVENT_PENDING;
                }
                else
                {
                    /* OUT Endpoint */
                    UART_1_EP[curEp].epMode     = UART_1_GET_ACTIVE_OUT_EP_CR0_MODE(epType);
                    UART_1_EP[curEp].apiEpState = UART_1_NO_EVENT_PENDING;
                }
                
                /* Make SIE to NAK any endpoint requests */
                UART_1_SIE_EP_BASE.sieEp[curEp].epCr0 = UART_1_MODE_NAK_IN_OUT;

            #if (UART_1_EP_MANAGEMENT_DMA_AUTO)
                /* Clear IN data ready. */
                UART_1_ARB_EP_BASE.arbEp[curEp].epCfg &= (uint8) ~UART_1_ARB_EPX_CFG_IN_DATA_RDY;

                /* Select endpoint number of reconfiguration */
                UART_1_DYN_RECONFIG_REG = (uint8) ((curEp - 1u) << UART_1_DYN_RECONFIG_EP_SHIFT);
                
                /* Request for dynamic re-configuration of endpoint. */
                UART_1_DYN_RECONFIG_REG |= UART_1_DYN_RECONFIG_ENABLE;
                
                /* Wait until block is ready for re-configuration */
                while (0u == (UART_1_DYN_RECONFIG_REG & UART_1_DYN_RECONFIG_RDY_STS))
                {
                }
                
                /* Once DYN_RECONFIG_RDY_STS bit is set, FW can change the EP configuration. */
                /* Change EP Type with new direction */
                if (0u != (pEP->addr & UART_1_DIR_IN))
                {
                    /* Set endpoint type: 0 - IN and 1 - OUT. */
                    UART_1_EP_TYPE_REG &= (uint8) ~(uint8)((uint8) 0x01u << (curEp - 1u));
                    
                #if (CY_PSOC4)
                    /* Clear DMA_TERMIN for IN endpoint */
                    UART_1_ARB_EP_BASE.arbEp[curEp].epIntEn &= (uint32) ~UART_1_ARB_EPX_INT_DMA_TERMIN;
                #endif /* (CY_PSOC4) */
                }
                else
                {
                    /* Set endpoint type: 0 - IN and 1- OUT. */
                    UART_1_EP_TYPE_REG |= (uint8) ((uint8) 0x01u << (curEp - 1u));
                    
                #if (CY_PSOC4)
                    /* Set DMA_TERMIN for OUT endpoint */
                    UART_1_ARB_EP_BASE.arbEp[curEp].epIntEn |= (uint32) UART_1_ARB_EPX_INT_DMA_TERMIN;
                #endif /* (CY_PSOC4) */
                }
                
                /* Complete dynamic re-configuration: all endpoint related status and signals 
                * are set into the default state.
                */
                UART_1_DYN_RECONFIG_REG &= (uint8) ~UART_1_DYN_RECONFIG_ENABLE;

            #else
                UART_1_SIE_EP_BASE.sieEp[curEp].epCnt0 = HI8(UART_1_EP[curEp].bufferSize);
                UART_1_SIE_EP_BASE.sieEp[curEp].epCnt1 = LO8(UART_1_EP[curEp].bufferSize);
                
                #if (CY_PSOC4)
                    UART_1_ARB_EP16_BASE.arbEp[curEp].rwRa16  = (uint32) UART_1_EP[curEp].buffOffset;
                    UART_1_ARB_EP16_BASE.arbEp[curEp].rwWa16  = (uint32) UART_1_EP[curEp].buffOffset;
                #else
                    UART_1_ARB_EP_BASE.arbEp[curEp].rwRa    = LO8(UART_1_EP[curEp].buffOffset);
                    UART_1_ARB_EP_BASE.arbEp[curEp].rwRaMsb = HI8(UART_1_EP[curEp].buffOffset);
                    UART_1_ARB_EP_BASE.arbEp[curEp].rwWa    = LO8(UART_1_EP[curEp].buffOffset);
                    UART_1_ARB_EP_BASE.arbEp[curEp].rwWaMsb = HI8(UART_1_EP[curEp].buffOffset);
                #endif /* (CY_PSOC4) */                
            #endif /* (UART_1_EP_MANAGEMENT_DMA_AUTO) */
            }
            
            pEP = &pEP[1u]; /* Get next EP element */
        }
        
        /* The main loop has to re-enable DMA and OUT endpoint */
    }
}


/*******************************************************************************
* Function Name: UART_1_GetConfigTablePtr
****************************************************************************//**
*
*  This routine returns a pointer a configuration table entry
*
*  \param confIndex:  Configuration Index
*
* \return
*  Device Descriptor pointer or NULL when descriptor does not exist.
*
*******************************************************************************/
const T_UART_1_LUT CYCODE *UART_1_GetConfigTablePtr(uint8 confIndex)
                                                        
{
    /* Device Table */
    const T_UART_1_LUT CYCODE *pTmp;

    pTmp = (const T_UART_1_LUT CYCODE *) UART_1_TABLE[UART_1_device].p_list;

    /* The first entry points to the Device Descriptor,
    *  the second entry point to the BOS Descriptor
    *  the rest configuration entries.
    *  Set pointer to the first Configuration Descriptor
    */
    pTmp = &pTmp[2u];
    /* For this table, c is the number of configuration descriptors  */
    if(confIndex >= pTmp->c)   /* Verify that required configuration descriptor exists */
    {
        pTmp = (const T_UART_1_LUT CYCODE *) NULL;
    }
    else
    {
        pTmp = (const T_UART_1_LUT CYCODE *) pTmp[confIndex].p_list;
    }

    return (pTmp);
}


#if (UART_1_BOS_ENABLE)
    /*******************************************************************************
    * Function Name: UART_1_GetBOSPtr
    ****************************************************************************//**
    *
    *  This routine returns a pointer a BOS table entry
    *
    *  
    *
    * \return
    *  BOS Descriptor pointer or NULL when descriptor does not exist.
    *
    *******************************************************************************/
    const T_UART_1_LUT CYCODE *UART_1_GetBOSPtr(void)
                                                            
    {
        /* Device Table */
        const T_UART_1_LUT CYCODE *pTmp;

        pTmp = (const T_UART_1_LUT CYCODE *) UART_1_TABLE[UART_1_device].p_list;

        /* The first entry points to the Device Descriptor,
        *  the second entry points to the BOS Descriptor
        */
        pTmp = &pTmp[1u];
        pTmp = (const T_UART_1_LUT CYCODE *) pTmp->p_list;
        return (pTmp);
    }
#endif /* (UART_1_BOS_ENABLE) */


/*******************************************************************************
* Function Name: UART_1_GetDeviceTablePtr
****************************************************************************//**
*
*  This routine returns a pointer to the Device table
*
* \return
*  Device Table pointer
*
*******************************************************************************/
const T_UART_1_LUT CYCODE *UART_1_GetDeviceTablePtr(void)
                                                            
{
    /* Device Table */
    return( (const T_UART_1_LUT CYCODE *) UART_1_TABLE[UART_1_device].p_list );
}


/*******************************************************************************
* Function Name: USB_GetInterfaceClassTablePtr
****************************************************************************//**
*
*  This routine returns Interface Class table pointer, which contains
*  the relation between interface number and interface class.
*
* \return
*  Interface Class table pointer.
*
*******************************************************************************/
const uint8 CYCODE *UART_1_GetInterfaceClassTablePtr(void)
                                                        
{
    const T_UART_1_LUT CYCODE *pTmp;
    const uint8 CYCODE *pInterfaceClass;
    uint8 currentInterfacesNum;

    pTmp = UART_1_GetConfigTablePtr(UART_1_configuration - 1u);
    if (pTmp != NULL)
    {
        currentInterfacesNum  = ((const uint8 *) pTmp->p_list)[UART_1_CONFIG_DESCR_NUM_INTERFACES];
        /* Third entry in the LUT starts the Interface Table pointers */
        /* The INTERFACE_CLASS table is located after all interfaces */
        pTmp = &pTmp[currentInterfacesNum + 2u];
        pInterfaceClass = (const uint8 CYCODE *) pTmp->p_list;
    }
    else
    {
        pInterfaceClass = (const uint8 CYCODE *) NULL;
    }

    return (pInterfaceClass);
}


/*******************************************************************************
* Function Name: UART_1_TerminateEP
****************************************************************************//**
*
*  This function terminates the specified USBFS endpoint.
*  This function should be used before endpoint reconfiguration.
*
*  \param ep Contains the data endpoint number.
*
*  \reentrant
*  No.
*
* \sideeffect
* 
* The device responds with a NAK for any transactions on the selected endpoint.
*   
*******************************************************************************/
void UART_1_TerminateEP(uint8 epNumber) 
{
    /* Get endpoint number */
    epNumber &= UART_1_DIR_UNUSED;

    if ((epNumber > UART_1_EP0) && (epNumber < UART_1_MAX_EP))
    {
        /* Set the endpoint Halt */
        UART_1_EP[epNumber].hwEpState |= UART_1_ENDPOINT_STATUS_HALT;

        /* Clear the data toggle */
        UART_1_EP[epNumber].epToggle = 0u;
        UART_1_EP[epNumber].apiEpState = UART_1_NO_EVENT_ALLOWED;

        if ((UART_1_EP[epNumber].addr & UART_1_DIR_IN) != 0u)
        {   
            /* IN Endpoint */
            UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_MODE_NAK_IN;
        }
        else
        {
            /* OUT Endpoint */
            UART_1_SIE_EP_BASE.sieEp[epNumber].epCr0 = UART_1_MODE_NAK_OUT;
        }
    }
}


/*******************************************************************************
* Function Name: UART_1_SetEndpointHalt
****************************************************************************//**
*
*  This routine handles set endpoint halt.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 UART_1_SetEndpointHalt(void) 
{
    uint8 requestHandled = UART_1_FALSE;
    uint8 ep;
    
    /* Set endpoint halt */
    ep = UART_1_wIndexLoReg & UART_1_DIR_UNUSED;

    if ((ep > UART_1_EP0) && (ep < UART_1_MAX_EP))
    {
        /* Set the endpoint Halt */
        UART_1_EP[ep].hwEpState |= (UART_1_ENDPOINT_STATUS_HALT);

        /* Clear the data toggle */
        UART_1_EP[ep].epToggle = 0u;
        UART_1_EP[ep].apiEpState |= UART_1_NO_EVENT_ALLOWED;

        if ((UART_1_EP[ep].addr & UART_1_DIR_IN) != 0u)
        {
            /* IN Endpoint */
            UART_1_SIE_EP_BASE.sieEp[ep].epCr0 = (UART_1_MODE_STALL_DATA_EP | 
                                                            UART_1_MODE_ACK_IN);
        }
        else
        {
            /* OUT Endpoint */
            UART_1_SIE_EP_BASE.sieEp[ep].epCr0 = (UART_1_MODE_STALL_DATA_EP | 
                                                            UART_1_MODE_ACK_OUT);
        }
        requestHandled = UART_1_InitNoDataControlTransfer();
    }

    return (requestHandled);
}


/*******************************************************************************
* Function Name: UART_1_ClearEndpointHalt
****************************************************************************//**
*
*  This routine handles clear endpoint halt.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 UART_1_ClearEndpointHalt(void) 
{
    uint8 requestHandled = UART_1_FALSE;
    uint8 ep;

    /* Clear endpoint halt */
    ep = UART_1_wIndexLoReg & UART_1_DIR_UNUSED;

    if ((ep > UART_1_EP0) && (ep < UART_1_MAX_EP))
    {
        /* Clear the endpoint Halt */
        UART_1_EP[ep].hwEpState &= (uint8) ~UART_1_ENDPOINT_STATUS_HALT;

        /* Clear the data toggle */
        UART_1_EP[ep].epToggle = 0u;
        
        /* Clear toggle bit for already armed packet */
        UART_1_SIE_EP_BASE.sieEp[ep].epCnt0 = (uint8) ~(uint8)UART_1_EPX_CNT_DATA_TOGGLE;
        
        /* Return API State as it was defined before */
        UART_1_EP[ep].apiEpState &= (uint8) ~UART_1_NO_EVENT_ALLOWED;

        if ((UART_1_EP[ep].addr & UART_1_DIR_IN) != 0u)
        {
            /* IN Endpoint */
            if(UART_1_EP[ep].apiEpState == UART_1_IN_BUFFER_EMPTY)
            {       
                /* Wait for next packet from application */
                UART_1_SIE_EP_BASE.sieEp[ep].epCr0 = UART_1_MODE_NAK_IN;
            }
            else    /* Continue armed transfer */
            {
                UART_1_SIE_EP_BASE.sieEp[ep].epCr0 = UART_1_MODE_ACK_IN;
            }
        }
        else
        {
            /* OUT Endpoint */
            if (UART_1_EP[ep].apiEpState == UART_1_OUT_BUFFER_FULL)
            {       
                /* Allow application to read full buffer */
                UART_1_SIE_EP_BASE.sieEp[ep].epCr0 = UART_1_MODE_NAK_OUT;
            }
            else    /* Mark endpoint as empty, so it will be reloaded */
            {
                UART_1_SIE_EP_BASE.sieEp[ep].epCr0 = UART_1_MODE_ACK_OUT;
            }
        }
        
        requestHandled = UART_1_InitNoDataControlTransfer();
    }

    return(requestHandled);
}


/*******************************************************************************
* Function Name: UART_1_ValidateAlternateSetting
****************************************************************************//**
*
*  Validates (and records) a SET INTERFACE request.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 UART_1_ValidateAlternateSetting(void) 
{
    uint8 requestHandled = UART_1_FALSE;
    
    uint8 interfaceNum;
    uint8 curInterfacesNum;
    const T_UART_1_LUT CYCODE *pTmp;
    
    /* Get interface number from the request. */
    interfaceNum = (uint8) UART_1_wIndexLoReg;
    
    /* Get number of interfaces for current configuration. */
    pTmp = UART_1_GetConfigTablePtr(UART_1_configuration - 1u);
    curInterfacesNum  = ((const uint8 *) pTmp->p_list)[UART_1_CONFIG_DESCR_NUM_INTERFACES];

    /* Validate that interface number is within range. */
    if ((interfaceNum <= curInterfacesNum) || (interfaceNum <= UART_1_MAX_INTERFACES_NUMBER))
    {
        /* Save current and new alternate settings (come with request) to make 
        * desicion about following endpoint re-configuration.
        */
        UART_1_interfaceSettingLast[interfaceNum] = UART_1_interfaceSetting[interfaceNum];
        UART_1_interfaceSetting[interfaceNum]     = (uint8) UART_1_wValueLoReg;
        
        requestHandled = UART_1_TRUE;
    }

    return (requestHandled);
}


/* [] END OF FILE */
