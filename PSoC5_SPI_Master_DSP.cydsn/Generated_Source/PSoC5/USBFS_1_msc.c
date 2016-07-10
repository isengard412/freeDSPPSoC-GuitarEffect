/***************************************************************************//**
* \file USBFS_1_cdc.c
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

#include "USBFS_1_msc.h"
#include "USBFS_1_pvt.h"
#include "cyapicallbacks.h"

#if (USBFS_1_HANDLE_MSC_REQUESTS)

/***************************************
*          Internal variables
***************************************/

static uint8 USBFS_1_lunCount = USBFS_1_MSC_LUN_NUMBER;


/*******************************************************************************
* Function Name: USBFS_1_DispatchMSCClassRqst
****************************************************************************//**
*   
*  \internal 
*  This routine dispatches MSC class requests.
*
* \return
*  Status of request processing: handled or not handled.
*
* \globalvars
*  USBFS_1_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 USBFS_1_DispatchMSCClassRqst(void) 
{
    uint8 requestHandled = USBFS_1_FALSE;
    
    /* Get request data. */
    uint16 value  = USBFS_1_GET_UINT16(USBFS_1_wValueHiReg,  USBFS_1_wValueLoReg);
    uint16 dataLength = USBFS_1_GET_UINT16(USBFS_1_wLengthHiReg, USBFS_1_wLengthLoReg);
       
    /* Check request direction: D2H or H2D. */
    if (0u != (USBFS_1_bmRequestTypeReg & USBFS_1_RQST_DIR_D2H))
    {
        /* Handle direction from device to host. */
        
        if (USBFS_1_MSC_GET_MAX_LUN == USBFS_1_bRequestReg)
        {
            /* Check request fields. */
            if ((value  == USBFS_1_MSC_GET_MAX_LUN_WVALUE) &&
                (dataLength == USBFS_1_MSC_GET_MAX_LUN_WLENGTH))
            {
                /* Reply to Get Max LUN request: setup control read. */
                USBFS_1_currentTD.pData = &USBFS_1_lunCount;
                USBFS_1_currentTD.count =  USBFS_1_MSC_GET_MAX_LUN_WLENGTH;
                
                requestHandled  = USBFS_1_InitControlRead();
            }
        }
    }
    else
    {
        /* Handle direction from host to device. */
        
        if (USBFS_1_MSC_RESET == USBFS_1_bRequestReg)
        {
            /* Check request fields. */
            if ((value  == USBFS_1_MSC_RESET_WVALUE) &&
                (dataLength == USBFS_1_MSC_RESET_WLENGTH))
            {
                /* Handle to Bulk-Only Reset request: no data control transfer. */
                USBFS_1_currentTD.count = USBFS_1_MSC_RESET_WLENGTH;
                
            #ifdef USBFS_1_DISPATCH_MSC_CLASS_MSC_RESET_RQST_CALLBACK
                USBFS_1_DispatchMSCClass_MSC_RESET_RQST_Callback();
            #endif /* (USBFS_1_DISPATCH_MSC_CLASS_MSC_RESET_RQST_CALLBACK) */
                
                requestHandled = USBFS_1_InitNoDataControlTransfer();
            }
        }
    }
    
    return (requestHandled);
}


/*******************************************************************************
* Function Name: USBFS_1_MSC_SetLunCount
****************************************************************************//**
*
*  This function sets the number of logical units supported in the application. 
*  The default number of logical units is set in the component customizer.
*
*  \param lunCount: Count of the logical units. Valid range is between 1 and 16.
*
*
* \globalvars
*  USBFS_1_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
void USBFS_1_MSC_SetLunCount(uint8 lunCount) 
{
    USBFS_1_lunCount = (lunCount - 1u);
}


/*******************************************************************************
* Function Name: USBFS_1_MSC_GetLunCount
****************************************************************************//**
*
*  This function returns the number of logical units.
*
* \return
*   Number of the logical units.
*
* \globalvars
*  USBFS_1_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 USBFS_1_MSC_GetLunCount(void) 
{
    return (USBFS_1_lunCount + 1u);
}   

#endif /* (USBFS_1_HANDLE_MSC_REQUESTS) */


/* [] END OF FILE */
