/*******************************************************************************
* File Name: CapSense_1_MBX.c
* Version 3.40
*
* Description:
*  This file provides the source code of Tuner communication APIs for the 
*  CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_1_MBX.h"

#if (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING)
    
CapSense_1_NO_STRICT_VOLATILE static void CapSense_1_InitParams(volatile const CapSense_1_INBOX *inbox)
                                        ;
    
                                        
    /*******************************************************************************
    * Function Name: CapSense_1_InitParams
    ********************************************************************************
    *
    * Summary:
    *  Configures component parameters to match the parameters in the inbox.
    *  Used only in manual tuning mode to apply new scanning parameters from Tuner 
    *  GUI.
    *
    * Parameters:
    *  inbox:  Pointer to Inbox structure in RAM.
    *
    * Return:
    *  None. Contents of the structure are not modified.
    * 
    * Side Effects: 
    *  Resets baseline values.
    *
    * Global Variables:
    *  CapSense_1_idacSettings[] - used to store idac value for all sensors.
    *  CapSense_1_fingerThreshold[] - used to store finger threshold for all 
    *  widgets.
    *  CapSense_1_noiseThreshold[] - used to sotre noise threshold for all 
    *  widgets.
    *  CapSense_1_hysteresis[] - used to store finger threshold for all 
    *  widgets.
    *  CapSense_1_debounce[] - used to store finger threshold for all 
    *  widgets.
    *  CapSense_1_INBOX inbox - structure which is used as input buffer
    *  for parameters from Tuner GUI. Only used in manual tuning mode.
    *
    * Reentrant:
    *  No
    *
    *******************************************************************************/
    static void CapSense_1_InitParams(volatile const CapSense_1_INBOX *inbox)
	                                        
    {
        /* Define widget sensor belongs to */
        uint8 sensor = inbox->sensorIndex;
        uint8 widget = CapSense_1_widgetNumber[sensor];
        uint16 tmpValue;
        
        /* Scanning parameters */
        #if (CapSense_1_CURRENT_SOURCE)
            CapSense_1_idacSettings[sensor] = inbox->idacSettings;
        #endif /* CapSense_1_CURRENT_SOURCE */   
        CapSense_1_widgetResolution[widget] = inbox->resolution;
    
        #if (CapSense_1_TOTAL_GENERICS_COUNT)
            /* Exclude generic wiget */
            if(widget < CapSense_1_END_OF_WIDGETS_INDEX)
            {
        #endif  /* CapSense_1_TOTAL_GENERICS_COUNT */
        
            /* High level parameters */
            tmpValue = inbox->fingerThreshold;
            CapSense_1_fingerThreshold[widget] = CapSense_1_SWAP_ENDIAN16(tmpValue);
            tmpValue = inbox->noiseThreshold;
            CapSense_1_noiseThreshold[widget]  = CapSense_1_SWAP_ENDIAN16(tmpValue);
            
            tmpValue = inbox->hysteresis;
            CapSense_1_hysteresis[widget] = CapSense_1_SWAP_ENDIAN16(tmpValue);
            CapSense_1_debounce[widget]   = inbox->debounce;
        
        #if (CapSense_1_TOTAL_GENERICS_COUNT)
            /* Exclude generic wiget */
            }
        #endif  /* CapSense_1_TOTAL_GENERICS_COUNT */

        #if ( CapSense_1_MULTIPLE_PRESCALER_ENABLED )
            #if (CapSense_1_DESIGN_TYPE == CapSense_1_TWO_CHANNELS_DESIGN)
                if( sensor > CapSense_1_TOTAL_SENSOR_COUNT__CH0 && \
                    sensor < CapSense_1_TOTAL_SENSOR_COUNT__CH1 )
                {
                    sensor = sensor - CapSense_1_TOTAL_SENSOR_COUNT__CH0;
                }
            #endif /* (CapSense_1_DESIGN_TYPE == CapSense_1_TWO_CHANNELS_DESIGN) */
            CapSense_1_analogSwitchDivider[sensor] = inbox->analogSwitchDivider;
        #else
            CapSense_1_analogSwitchDivider = inbox->analogSwitchDivider;
        #endif /* ( CapSense_1_MULTIPLE_PRESCALER_ENABLED ) */

        /* Re-Init baselines */
        CapSense_1_InitializeAllBaselines();
    }
#endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */


/*******************************************************************************
* Function Name: CapSense_1_InitMailbox
********************************************************************************
*
* Summary:
*  Initialize parameters  of mailbox structure.
*  Sets type and size of mailbox structure. 
*  Sets check sum to check by Tuner GUI and noReadMsg flag to indicate that this 
*  is the first communication packet.
*
* Parameters:
*  mbx:  Pointer to Mailbox structure in RAM.
*
* Return:
*  None. Modifies the contents of mbx and mbx->outbox.
*
* Global Variables:
*  CapSense_1_MAILBOXES - structure which incorporates two fields: 
*    - numMailBoxes (number of mailboxes);
*    - CapSense_1_MAILBOX csdMailbox;
*  CapSense_1_MAILBOX - structure which incorporates status output and
*  input buffer fields and CapSense_1_OUTBOX and CapSense_1_INBOX.
*    - type (used as outbox read status of Tuner GUI);
*    - size (used as inbox apply status of component);
*    - CapSense_1_OUTBOX outbox - structure which is used as ouput 
*      buffer for report data to Tuner GUI.
*    - CapSense_1_INBOX inbox - structure which is used as input buffer
*      for paramters from Tuner GUI. Only used in manual tuning mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_InitMailbox(volatile CapSense_1_MAILBOX *mbx)
                                  
{
    /* Restore TYPE_ID (clear busy flag) to indicate "action complete" */
    mbx->type = CapSense_1_TYPE_ID;
    /* Restore default value - clear "have_msg" */
    mbx->size = CapSense_1_SWAP_ENDIAN16(sizeof(CapSense_1_MAILBOX));
    
    /* Addtional fields for async and reset handling */
    #if(CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING)
        mbx->outbox.noReadMsg = 1u;
    #endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */
    
    mbx->outbox.checkSum = CapSense_1_SWAP_ENDIAN16(CapSense_1_CHECK_SUM);
}


/*******************************************************************************
* Function Name:  CapSense_1_PostMessage
********************************************************************************
*
* Summary:
*  This blocking function waits while Tuner GUI reports that content of mailbox 
*  could be modified (clears CapSense_1_BUSY_FLAG). Then loads the report 
*  data to outbox and sets the busy flag.
*  In manual tuning mode the report data:
*    - raw data, baseline, signal;
*  In auto tuning mode to report added data:
*    - fingerThreshold;
*    - noiseThreshold;
*    - scanResolution;
*    - idacValue;
*    - prescaler.
*
* Parameters:
*  mbx:  Pointer to Mailbox structure in RAM.
*
* Return:
*  None. Modifies the contents of mbx->outbox.
*
* Global Variables:
*  CapSense_1_MAILBOXES - structure which incorporates two fields: 
*    - numMailBoxes (number of mailboxes);
*    - CapSense_1_MAILBOX csdMailbox;
*  CapSense_1_MAILBOX - structure which incorporates status output and
*  input buffer fields and CapSense_1_OUTBOX and CapSense_1_INBOX.
*    - type (used as outbox read status of Tuner GUI);
*    - size (used as inbox apply status of component);
*    - CapSense_1_OUTBOX outbox - structure which is used as ouput 
*      buffer for report data to Tuner GUI.
*    - CapSense_1_INBOX inbox - structure which is used as input buffer
*      for parameters from Tuner GUI. Only used in manual tuning mode.
*  CapSense_1_lowLevelTuningDone - used to notify the Tuner GUI that 
*  tuning of scanning parameters are done. The scanning parameters in mailbox
*  will not be updated after clear it.
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_PostMessage(volatile CapSense_1_MAILBOX *mbx)
                                  
{
    uint8 i;

    /* Check busy flag */
    while (mbx->type != CapSense_1_TYPE_ID)
    {
        /* Wait while busy flag is set */
    }
    
    /* Copy all data - Raw, Base, Signal, OnMask */
    for(i = 0u; i < CapSense_1_TOTAL_SENSOR_COUNT; i++)
    {
        mbx->outbox.rawData[i]  = CapSense_1_SWAP_ENDIAN16(CapSense_1_sensorRaw[i]);
        mbx->outbox.baseLine[i] = CapSense_1_SWAP_ENDIAN16(CapSense_1_sensorBaseline[i]);
        #if (CapSense_1_SIGNAL_SIZE == CapSense_1_SIGNAL_SIZE_UINT8)
            mbx->outbox.signal[i]   = CapSense_1_sensorSignal[i];
        #else
            mbx->outbox.signal[i]   = CapSense_1_SWAP_ENDIAN16(CapSense_1_sensorSignal[i]);
        #endif  /* (CapSense_1_SIGNAL_SIZE == CapSense_1_SIGNAL_SIZE_UINT8) */
    }
        
    /* AutoTuning - need to copy all High Level parameters */
    #if (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING)
        
        /* Parameters are changed in run time */
        for(i = 0u; i < CapSense_1_WIDGET_CSHL_PARAMETERS_COUNT; i++)
        {
            #if (CapSense_1_SIGNAL_SIZE == CapSense_1_SIGNAL_SIZE_UINT8)
                mbx->outbox.fingerThreshold[i] = CapSense_1_fingerThreshold[i];
                mbx->outbox.noiseThreshold[i]  = CapSense_1_noiseThreshold[i];
            #else
                mbx->outbox.fingerThreshold[i] = $INSTANCE_NAME`_SWAP_ENDIAN16(CapSense_1_fingerThreshold[i]);
                mbx->outbox.noiseThreshold[i]  = $INSTANCE_NAME`_SWAP_ENDIAN16(CapSense_1_noiseThreshold[i]); 
            #endif /* (CapSense_1_SIGNAL_SIZE == CapSense_1_SIGNAL_SIZE_UINT8) */
        }
        
        /* Widget resolution, take to account TP and MB */
        for(i=0u; i < CapSense_1_WIDGET_RESOLUTION_PARAMETERS_COUNT; i++)
        {
            mbx->outbox.scanResolution[i]  = CapSense_1_widgetResolution[i];
        }

        /* Copy tuned idac values */
        for(i=0u; i < CapSense_1_TOTAL_SENSOR_COUNT; i++)
        {
            mbx->outbox.idacValue[i] = CapSense_1_idacSettings[i];
        }
            
        /* Pass parameters only once */
        CapSense_1_lowLevelTuningDone = 0u;
    #endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */

    /* Copy scan parameters */
    #if ( CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING )
        for(i = 0u; i < CapSense_1_TOTAL_SCANSLOT_COUNT; i++)
        {
            mbx->outbox.analogSwitchDivider[i] = CapSense_1_analogSwitchDivider[i];
        }
    #endif /* (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING) */

    /* Set busy flag */
    mbx->type = CapSense_1_BUSY_FLAG;
}


#if (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING)
    /*******************************************************************************
    * Function Name: CapSense_1_ReadMessage
    ********************************************************************************
    *
    * Summary:
    *  If CapSense_1_HAVE_MSG is found in the mailbox, initialize component 
    *  with parameters found in the inbox. Signal DONE by overwriting the
    *  value in size field in mailbox.
    *  Only available when manual tuning mode.
    *
    * Parameters:
    *  mbx:  Pointer to Mailbox structure in RAM.
    *
    * Return:
    *  None. Modifies the contents of mbx.
    *
    * Side Effects: 
    *  Initializes component parameters if CapSense_1_HAVE_MSG is received.
    *
    * Global Variables:
    *  CapSense_1_MAILBOXES - structure which incorporates two fields: 
    *    - numMailBoxes (number of mailboxes);
    *    - CapSense_1_MAILBOX csdMailbox;
    *  CapSense_1_MAILBOX - structure which incorporates status output and
    *  input buffer fields and CapSense_1_OUTBOX and CapSense_1_INBOX.
    *    - type (used as outbox read status of Tuner GUI);
    *    - size (used as inbox apply status of component);
    *    - CapSense_1_OUTBOX outbox - structure which is used as ouput 
    *      buffer for report data to Tuner GUI.
    *    - CapSense_1_INBOX inbox - structure which is used as input buffer
    *      for parameters from Tuner GUI. Only used in manual tuning mode.
    *
    * Reentrant:
    *  No
    *
    *******************************************************************************/
    void CapSense_1_ReadMessage(volatile CapSense_1_MAILBOX *mbx)
	                                  
    {
        volatile CapSense_1_INBOX *tmpInbox;
        uint16 tmpValue;
        
        tmpValue = mbx->size;
       
        /* Do we have a message waiting? */
        if (CapSense_1_SWAP_ENDIAN16(tmpValue) == CapSense_1_HAVE_MSG)
        {
            tmpInbox = &(mbx->inbox);
            
            CapSense_1_InitParams(tmpInbox);
    
            /* Notify host/tuner that we have consumed the message */
            mbx->size = CapSense_1_SWAP_ENDIAN16(sizeof(CapSense_1_MAILBOX));
            
            /* Defualt settings where changed */
            mbx->outbox.noReadMsg = 0u;
        }       
    }
#endif  /* (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */


/* [] END OF FILE */
