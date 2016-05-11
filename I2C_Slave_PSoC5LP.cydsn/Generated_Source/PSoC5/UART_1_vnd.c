/***************************************************************************//**
* \file UART_1_vnd.c
* \version 3.0
*
* \brief
*  This file contains the  USB vendor request handler.
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

#if(UART_1_EXTERN_VND == UART_1_FALSE)

/***************************************
* Vendor Specific Declarations
***************************************/

/* `#START VENDOR_SPECIFIC_DECLARATIONS` Place your declaration here */

/* `#END` */


/*******************************************************************************
* Function Name: UART_1_HandleVendorRqst
****************************************************************************//**
*
*  This routine provide users with a method to implement vendor specific
*  requests.
*
*  To implement vendor specific requests, add your code in this function to
*  decode and disposition the request.  If the request is handled, your code
*  must set the variable "requestHandled" to TRUE, indicating that the
*  request has been handled.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 UART_1_HandleVendorRqst(void) 
{
    uint8 requestHandled = UART_1_FALSE;

    /* Check request direction: D2H or H2D. */
    if (0u != (UART_1_bmRequestTypeReg & UART_1_RQST_DIR_D2H))
    {
        /* Handle direction from device to host. */
        
        switch (UART_1_bRequestReg)
        {
            case UART_1_GET_EXTENDED_CONFIG_DESCRIPTOR:
            #if defined(UART_1_ENABLE_MSOS_STRING)
                UART_1_currentTD.pData = (volatile uint8 *) &UART_1_MSOS_CONFIGURATION_DESCR[0u];
                UART_1_currentTD.count = UART_1_MSOS_CONFIGURATION_DESCR[0u];
                requestHandled  = UART_1_InitControlRead();
            #endif /* (UART_1_ENABLE_MSOS_STRING) */
                break;
            
            default:
                break;
        }
    }

    /* `#START VENDOR_SPECIFIC_CODE` Place your vendor specific request here */

    /* `#END` */

#ifdef UART_1_HANDLE_VENDOR_RQST_CALLBACK
    if (UART_1_FALSE == requestHandled)
    {
        requestHandled = UART_1_HandleVendorRqst_Callback();
    }
#endif /* (UART_1_HANDLE_VENDOR_RQST_CALLBACK) */

    return (requestHandled);
}


/*******************************************************************************
* Additional user functions supporting Vendor Specific Requests
********************************************************************************/

/* `#START VENDOR_SPECIFIC_FUNCTIONS` Place any additional functions here */

/* `#END` */


#endif /* UART_1_EXTERN_VND */


/* [] END OF FILE */
