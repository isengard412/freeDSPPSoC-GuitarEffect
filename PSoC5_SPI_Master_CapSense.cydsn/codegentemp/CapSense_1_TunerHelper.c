/*******************************************************************************
* File Name: CapSense_1_TunerHelper.c
* Version 3.40
*
* Description:
*  This file provides the source code of Tuner helper APIs for the CapSense CSD 
*  component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_1_TunerHelper.h"

#if (CapSense_1_TUNER_API_GENERATE)
    volatile CapSense_1_MAILBOXES CapSense_1_mailboxesComm;
#endif  /* (CapSense_1_TUNER_API_GENERATE) */


/*******************************************************************************
* Function Name: CapSense_1_TunerStart
********************************************************************************
*
* Summary:
*  Initializes CapSense CSD component and EzI2C communication componenet to use
*  mailbox data structure for communication with Tuner GUI.
*  Start the scanning, after initialization complete.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
* Note:
*  All widgets are enabled by default except proximity widgets. Proximity widgets 
*  must be manually enabled as their long scan time is incompatible 
*  with the fast response required of other widget types. 
*
*******************************************************************************/
void CapSense_1_TunerStart(void) 
{
    #if (CapSense_1_TUNER_API_GENERATE)
        
        /* Init mbx and quick check */
        CapSense_1_InitMailbox(&CapSense_1_mailboxesComm.csdMailbox);
        CapSense_1_mailboxesComm.numMailBoxes = CapSense_1_DEFAULT_MAILBOXES_NUMBER;
        
        /* Start CapSense and baselines */
        CapSense_1_Start();
        
        /* Initialize baselines */ 
        CapSense_1_InitializeAllBaselines();
        CapSense_1_InitializeAllBaselines();
        
        /* Start EzI2C, clears buf pointers */
        EZI2C_Start();
        
        /* Setup EzI2C buffers */
        EZI2C_SetBuffer1(sizeof(CapSense_1_mailboxesComm), sizeof(CapSense_1_mailboxesComm),
                                        (void *) &CapSense_1_mailboxesComm);
        
        /* Starts scan all enabled sensors */
        CapSense_1_ScanEnabledWidgets();
    
    #endif  /* (CapSense_1_TUNER_API_GENERATE) */
}


/*******************************************************************************
* Function Name: CapSense_1_TunerComm
********************************************************************************
*
* Summary:
*  This function is blocking. It waits till scaning loop is completed and apply
*  new parameters from Tuner GUI if available (manual tuning mode only). Updates
*  enabled baselines and state of widgets. Waits while Tuner GUI reports that 
*  content of mailbox could be modified. Then loads the report data into outbox 
*  and sets the busy flag. Starts new scanning loop.
*  
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_TunerComm(void) 
{
    #if (CapSense_1_TUNER_API_GENERATE)
        if (0u == CapSense_1_IsBusy())
        {   
            /* Apply new settings */
            #if (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING)
                CapSense_1_ReadMessage(&CapSense_1_mailboxesComm.csdMailbox);
            #endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */

            /* Update all baselines and process all widgets */
            CapSense_1_UpdateEnabledBaselines();
            CapSense_1_ProcessAllWidgets(&CapSense_1_mailboxesComm.csdMailbox.outbox);
            CapSense_1_PostMessage(&CapSense_1_mailboxesComm.csdMailbox);

            /* Enable EZI2C interrupts, after scan complete */
            EZI2C_EnableInt();

            while((CapSense_1_mailboxesComm.csdMailbox.type != CapSense_1_TYPE_ID) || \
                  ((EZI2C_GetActivity() & EZI2C_STATUS_BUSY) != 0u)){}
            
            /* Disable EZI2C interrupts, while scanning */
            EZI2C_DisableInt();
            
            /* Start scan all sensors */
            CapSense_1_ScanEnabledWidgets();
        }
    #endif /* (CapSense_1_TUNER_API_GENERATE) */
}


#if (CapSense_1_TUNER_API_GENERATE)
    /*******************************************************************************
    * Function Name: CapSense_1_ProcessAllWidgets
    ********************************************************************************
    *
    * Summary:
    *  Call required functions to update all widgets state:
    *   - CapSense_1_GetCentroidPos() - calls only if linear sliders 
    *     available.
    *   - CapSense_1_GetRadialCentroidPos() - calls only if radial slider 
    *     available.
    *   - CapSense_1_GetTouchCentroidPos() - calls only if touch pad slider 
    *     available.
    *   - CapSense_1_CheckIsAnyWidgetActive();
    *  The results of opeartions are copied to OUTBOX.
    *   
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Global Variables:
    *  CapSense_1_OUTBOX outbox - structure which is used as ouput 
    *  buffer for report data to Tuner GUI.
    *  Update fields:
    *    - position[];
    *    - OnMask[];
    *
    * Reentrant:
    *  No
    *
    *******************************************************************************/
    void CapSense_1_ProcessAllWidgets(volatile CapSense_1_OUTBOX *outbox)
	                                        
    {
        uint8 i = 0u;
		#if (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT)
        	volatile uint8 *mbPositionAddr;
		#endif /* (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT) */

        #if (CapSense_1_TOTAL_TOUCH_PADS_COUNT)
            uint16 pos[2];
        #endif  /* (CapSense_1_TOTAL_TOUCH_PADS_COUNT) */
        
        #if ( (CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT) || (CapSense_1_TOTAL_TOUCH_PADS_COUNT) || \
              (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT) )
            uint8 widgetCnt;
        #endif  /* ((CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT) || (CapSense_1_TOTAL_TOUCH_PADS_COUNT)) || 
                *   (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT)
                */
        
        /* Calculate widget with centroids */
        #if (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT)
            for(; i < CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT; i++)
            {
                outbox->position[i] = CapSense_1_SWAP_ENDIAN16(CapSense_1_GetCentroidPos(i));
            }
        #endif /* (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT) */
        
        #if (CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT)
            widgetCnt = i;
            for(; i < (widgetCnt + CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT); i++)
            {
                outbox->position[i] = CapSense_1_SWAP_ENDIAN16(CapSense_1_GetRadialCentroidPos(i));
            }
        #endif /* (CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT) */
        
        #if (CapSense_1_TOTAL_TOUCH_PADS_COUNT)
            widgetCnt = i;
            for(; i < (widgetCnt + (CapSense_1_TOTAL_TOUCH_PADS_COUNT * 2u)); i = (i+2u))
            {
                if(CapSense_1_GetTouchCentroidPos(i, pos) == 0u)
                {
                    outbox->position[i] = 0xFFFFu;
                    outbox->position[i+1u] = 0xFFFFu;
                }
                else
                {
                    outbox->position[i] = CapSense_1_SWAP_ENDIAN16( (uint16) pos[0u]);
                    outbox->position[i+1u] = CapSense_1_SWAP_ENDIAN16( (uint16) pos[1u]);
                }
            }
        #endif /* (CapSense_1_TOTAL_TOUCH_PADS_COUNT) */

        #if (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT)
            i += CapSense_1_TOTAL_BUTTONS_COUNT;
            widgetCnt = 0u;
            for(; widgetCnt < (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT * 2u); widgetCnt += 2u)
            {
                mbPositionAddr = &outbox->mbPosition[widgetCnt];
                if(CapSense_1_GetMatrixButtonPos(i, ((uint8*) mbPositionAddr)) == 0u)
                {
                    outbox->mbPosition[widgetCnt] = 0xFFu;
                    outbox->mbPosition[widgetCnt+1u] = 0xFFu;
                }
                i += 2u;
            }
        #endif /* (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT) */

        /* Update On/Off State */
        (void)CapSense_1_CheckIsAnyWidgetActive();

        /* Copy OnMask */
        for(i = 0u; i < CapSense_1_TOTAL_SENSOR_MASK_COUNT; i++)
        {
            outbox->onMask[i]  = CapSense_1_sensorOnMask[i];
        }
    }
#endif /* (CapSense_1_TUNER_API_GENERATE) */


/* [] END OF FILE */
