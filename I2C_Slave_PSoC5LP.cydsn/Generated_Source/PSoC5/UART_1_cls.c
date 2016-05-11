/***************************************************************************//**
* \file UART_1_cls.c
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

#include "UART_1_pvt.h"
#include "cyapicallbacks.h"

#if(UART_1_EXTERN_CLS == UART_1_FALSE)

/***************************************
* User Implemented Class Driver Declarations.
***************************************/
/* `#START USER_DEFINED_CLASS_DECLARATIONS` Place your declaration here */

/* `#END` */


/*******************************************************************************
* Function Name: UART_1_DispatchClassRqst
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
uint8 UART_1_DispatchClassRqst(void) 
{
    uint8 requestHandled;
    uint8 interfaceNumber;

    /* Get interface to which request is intended. */
    switch (UART_1_bmRequestTypeReg & UART_1_RQST_RCPT_MASK)
    {
        case UART_1_RQST_RCPT_IFC:
            /* Class-specific request directed to interface: wIndexLoReg 
            * contains interface number.
            */
            interfaceNumber = (uint8) UART_1_wIndexLoReg;
            break;
        
        case UART_1_RQST_RCPT_EP:
            /* Class-specific request directed to endpoint: wIndexLoReg contains 
            * endpoint number. Find interface related to endpoint, 
            */
            interfaceNumber = UART_1_EP[UART_1_wIndexLoReg & UART_1_DIR_UNUSED].interface;
            break;
            
        default:
            /* Default interface is zero. */
            interfaceNumber = 0u;
            break;
    }

#if (defined(UART_1_ENABLE_HID_CLASS) ||\
            defined(UART_1_ENABLE_AUDIO_CLASS) ||\
            defined(UART_1_ENABLE_CDC_CLASS) ||\
            UART_1_ENABLE_MSC_CLASS)

    /* Handle class request depends on interface type. */
    switch (UART_1_interfaceClass[interfaceNumber])
    {
    #if defined(UART_1_ENABLE_HID_CLASS)
        case UART_1_CLASS_HID:
            requestHandled = UART_1_DispatchHIDClassRqst();
            break;
    #endif /* (UART_1_ENABLE_HID_CLASS) */
            
    #if defined(UART_1_ENABLE_AUDIO_CLASS)
        case UART_1_CLASS_AUDIO:
            requestHandled = UART_1_DispatchAUDIOClassRqst();
            break;
    #endif /* (UART_1_CLASS_AUDIO) */
            
    #if defined(UART_1_ENABLE_CDC_CLASS)
        case UART_1_CLASS_CDC:
            requestHandled = UART_1_DispatchCDCClassRqst();
            break;
    #endif /* (UART_1_ENABLE_CDC_CLASS) */
        
    #if (UART_1_ENABLE_MSC_CLASS)
        case UART_1_CLASS_MSD:
        #if (UART_1_HANDLE_MSC_REQUESTS)
            /* MSC requests are handled by the component. */
            requestHandled = UART_1_DispatchMSCClassRqst();
        #elif defined(UART_1_DISPATCH_MSC_CLASS_RQST_CALLBACK)
            /* MSC requests are handled by user defined callbcak. */
            requestHandled = UART_1_DispatchMSCClassRqst_Callback();
        #else
            /* MSC requests are not handled. */
            requestHandled = UART_1_FALSE;
        #endif /* (UART_1_HANDLE_MSC_REQUESTS) */
            break;
    #endif /* (UART_1_ENABLE_MSC_CLASS) */
        
        default:
            /* Request is not handled: unknown class request type. */
            requestHandled = UART_1_FALSE;
            break;
    }
#else /*No class is defined*/
    if (0u != interfaceNumber)
    {
        /* Suppress warning message */
    }
    requestHandled = UART_1_FALSE;
#endif /*HID or AUDIO or MSC or CDC class enabled*/

    /* `#START USER_DEFINED_CLASS_CODE` Place your Class request here */

    /* `#END` */

#ifdef UART_1_DISPATCH_CLASS_RQST_CALLBACK
    if (UART_1_FALSE == requestHandled)
    {
        requestHandled = UART_1_DispatchClassRqst_Callback(interfaceNumber);
    }
#endif /* (UART_1_DISPATCH_CLASS_RQST_CALLBACK) */

    return (requestHandled);
}


/*******************************************************************************
* Additional user functions supporting Class Specific Requests
********************************************************************************/

/* `#START CLASS_SPECIFIC_FUNCTIONS` Place any additional functions here */

/* `#END` */

#endif /* UART_1_EXTERN_CLS */


/* [] END OF FILE */
