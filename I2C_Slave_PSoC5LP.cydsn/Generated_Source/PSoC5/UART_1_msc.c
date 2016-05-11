/***************************************************************************//**
* \file UART_1_cdc.c
* \version 3.0
*
* \brief
*  This file contains the USB MSC Class request handler and global API for MSC 
*  class.
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

#include "UART_1_msc.h"
#include "UART_1_pvt.h"
#include "cyapicallbacks.h"

#if (UART_1_HANDLE_MSC_REQUESTS)

/***************************************
*          Internal variables
***************************************/

static uint8 UART_1_lunCount = UART_1_MSC_LUN_NUMBER;


/*******************************************************************************
* Function Name: UART_1_DispatchMSCClassRqst
****************************************************************************//**
*   
*  \internal 
*  This routine dispatches MSC class requests.
*
* \return
*  Status of request processing: handled or not handled.
*
* \globalvars
*  UART_1_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 UART_1_DispatchMSCClassRqst(void) 
{
    uint8 requestHandled = UART_1_FALSE;
    
    /* Get request data. */
    uint16 value  = UART_1_GET_UINT16(UART_1_wValueHiReg,  UART_1_wValueLoReg);
    uint16 dataLength = UART_1_GET_UINT16(UART_1_wLengthHiReg, UART_1_wLengthLoReg);
       
    /* Check request direction: D2H or H2D. */
    if (0u != (UART_1_bmRequestTypeReg & UART_1_RQST_DIR_D2H))
    {
        /* Handle direction from device to host. */
        
        if (UART_1_MSC_GET_MAX_LUN == UART_1_bRequestReg)
        {
            /* Check request fields. */
            if ((value  == UART_1_MSC_GET_MAX_LUN_WVALUE) &&
                (dataLength == UART_1_MSC_GET_MAX_LUN_WLENGTH))
            {
                /* Reply to Get Max LUN request: setup control read. */
                UART_1_currentTD.pData = &UART_1_lunCount;
                UART_1_currentTD.count =  UART_1_MSC_GET_MAX_LUN_WLENGTH;
                
                requestHandled  = UART_1_InitControlRead();
            }
        }
    }
    else
    {
        /* Handle direction from host to device. */
        
        if (UART_1_MSC_RESET == UART_1_bRequestReg)
        {
            /* Check request fields. */
            if ((value  == UART_1_MSC_RESET_WVALUE) &&
                (dataLength == UART_1_MSC_RESET_WLENGTH))
            {
                /* Handle to Bulk-Only Reset request: no data control transfer. */
                UART_1_currentTD.count = UART_1_MSC_RESET_WLENGTH;
                
            #ifdef UART_1_DISPATCH_MSC_CLASS_MSC_RESET_RQST_CALLBACK
                UART_1_DispatchMSCClass_MSC_RESET_RQST_Callback();
            #endif /* (UART_1_DISPATCH_MSC_CLASS_MSC_RESET_RQST_CALLBACK) */
                
                requestHandled = UART_1_InitNoDataControlTransfer();
            }
        }
    }
    
    return (requestHandled);
}


/*******************************************************************************
* Function Name: UART_1_MSC_SetLunCount
****************************************************************************//**
*
*  This function sets the number of logical units supported in the application. 
*  The default number of logical units is set in the component customizer.
*
*  \param lunCount: Count of the logical units. Valid range is between 1 and 16.
*
*
* \globalvars
*  UART_1_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
void UART_1_MSC_SetLunCount(uint8 lunCount) 
{
    UART_1_lunCount = (lunCount - 1u);
}


/*******************************************************************************
* Function Name: UART_1_MSC_GetLunCount
****************************************************************************//**
*
*  This function returns the number of logical units.
*
* \return
*   Number of the logical units.
*
* \globalvars
*  UART_1_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 UART_1_MSC_GetLunCount(void) 
{
    return (UART_1_lunCount + 1u);
}   

#endif /* (UART_1_HANDLE_MSC_REQUESTS) */


/* [] END OF FILE */
