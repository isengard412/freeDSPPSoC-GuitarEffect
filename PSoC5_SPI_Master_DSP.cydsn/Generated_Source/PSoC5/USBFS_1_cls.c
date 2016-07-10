/***************************************************************************//**
* \file USBFS_1_cls.c
* \version 3.0
*
* \brief
*  This file contains the USB Class request handler.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBFS_1_pvt.h"
#include "cyapicallbacks.h"

#if(USBFS_1_EXTERN_CLS == USBFS_1_FALSE)

/***************************************
* User Implemented Class Driver Declarations.
***************************************/
/* `#START USER_DEFINED_CLASS_DECLARATIONS` Place your declaration here */

/* `#END` */


/*******************************************************************************
* Function Name: USBFS_1_DispatchClassRqst
****************************************************************************//**
*  This routine dispatches class specific requests depend on interface class.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 USBFS_1_DispatchClassRqst(void) 
{
    uint8 requestHandled;
    uint8 interfaceNumber;

    /* Get interface to which request is intended. */
    switch (USBFS_1_bmRequestTypeReg & USBFS_1_RQST_RCPT_MASK)
    {
        case USBFS_1_RQST_RCPT_IFC:
            /* Class-specific request directed to interface: wIndexLoReg 
            * contains interface number.
            */
            interfaceNumber = (uint8) USBFS_1_wIndexLoReg;
            break;
        
        case USBFS_1_RQST_RCPT_EP:
            /* Class-specific request directed to endpoint: wIndexLoReg contains 
            * endpoint number. Find interface related to endpoint, 
            */
            interfaceNumber = USBFS_1_EP[USBFS_1_wIndexLoReg & USBFS_1_DIR_UNUSED].interface;
            break;
            
        default:
            /* Default interface is zero. */
            interfaceNumber = 0u;
            break;
    }

#if (defined(USBFS_1_ENABLE_HID_CLASS) ||\
            defined(USBFS_1_ENABLE_AUDIO_CLASS) ||\
            defined(USBFS_1_ENABLE_CDC_CLASS) ||\
            USBFS_1_ENABLE_MSC_CLASS)

    /* Handle class request depends on interface type. */
    switch (USBFS_1_interfaceClass[interfaceNumber])
    {
    #if defined(USBFS_1_ENABLE_HID_CLASS)
        case USBFS_1_CLASS_HID:
            requestHandled = USBFS_1_DispatchHIDClassRqst();
            break;
    #endif /* (USBFS_1_ENABLE_HID_CLASS) */
            
    #if defined(USBFS_1_ENABLE_AUDIO_CLASS)
        case USBFS_1_CLASS_AUDIO:
            requestHandled = USBFS_1_DispatchAUDIOClassRqst();
            break;
    #endif /* (USBFS_1_CLASS_AUDIO) */
            
    #if defined(USBFS_1_ENABLE_CDC_CLASS)
        case USBFS_1_CLASS_CDC:
            requestHandled = USBFS_1_DispatchCDCClassRqst();
            break;
    #endif /* (USBFS_1_ENABLE_CDC_CLASS) */
        
    #if (USBFS_1_ENABLE_MSC_CLASS)
        case USBFS_1_CLASS_MSD:
        #if (USBFS_1_HANDLE_MSC_REQUESTS)
            /* MSC requests are handled by the component. */
            requestHandled = USBFS_1_DispatchMSCClassRqst();
        #elif defined(USBFS_1_DISPATCH_MSC_CLASS_RQST_CALLBACK)
            /* MSC requests are handled by user defined callbcak. */
            requestHandled = USBFS_1_DispatchMSCClassRqst_Callback();
        #else
            /* MSC requests are not handled. */
            requestHandled = USBFS_1_FALSE;
        #endif /* (USBFS_1_HANDLE_MSC_REQUESTS) */
            break;
    #endif /* (USBFS_1_ENABLE_MSC_CLASS) */
        
        default:
            /* Request is not handled: unknown class request type. */
            requestHandled = USBFS_1_FALSE;
            break;
    }
#else /*No class is defined*/
    if (0u != interfaceNumber)
    {
        /* Suppress warning message */
    }
    requestHandled = USBFS_1_FALSE;
#endif /*HID or AUDIO or MSC or CDC class enabled*/

    /* `#START USER_DEFINED_CLASS_CODE` Place your Class request here */

    /* `#END` */

#ifdef USBFS_1_DISPATCH_CLASS_RQST_CALLBACK
    if (USBFS_1_FALSE == requestHandled)
    {
        requestHandled = USBFS_1_DispatchClassRqst_Callback(interfaceNumber);
    }
#endif /* (USBFS_1_DISPATCH_CLASS_RQST_CALLBACK) */

    return (requestHandled);
}


/*******************************************************************************
* Additional user functions supporting Class Specific Requests
********************************************************************************/

/* `#START CLASS_SPECIFIC_FUNCTIONS` Place any additional functions here */

/* `#END` */

#endif /* USBFS_1_EXTERN_CLS */


/* [] END OF FILE */
