/***************************************************************************//**
* \file USBFS_1_episr.c
* \version 3.0
*
* \brief
*  This file contains the Data endpoint Interrupt Service Routines.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBFS_1_pvt.h"
#include "USBFS_1_cydmac.h"
#include "cyapicallbacks.h"


/***************************************
* Custom Declarations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */


#if (USBFS_1_EP1_ISR_ACTIVE)
    /******************************************************************************
    * Function Name: USBFS_1_EP_1_ISR
    ***************************************************************************//**
    *
    *  Endpoint 1 Interrupt Service Routine
    *
    ******************************************************************************/
    CY_ISR(USBFS_1_EP_1_ISR)
    {

    #ifdef USBFS_1_EP_1_ISR_ENTRY_CALLBACK
        USBFS_1_EP_1_ISR_EntryCallback();
    #endif /* (USBFS_1_EP_1_ISR_ENTRY_CALLBACK) */

        /* `#START EP1_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    
        USBFS_1_ClearSieEpInterruptSource(USBFS_1_SIE_INT_EP1_INTR);
            
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to be read from endpoint buffer. 
        */
    #if (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (USBFS_1_EP[USBFS_1_EP1].addr & USBFS_1_DIR_IN))
    #endif /* (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO) */
        {
            /* Read CR0 register to clear SIE lock. */
            (void) USBFS_1_SIE_EP_BASE.sieEp[USBFS_1_EP1].epCr0;
            
            /* Toggle all endpoint types except ISOC. */
            if (USBFS_1_GET_EP_TYPE(USBFS_1_EP1) != USBFS_1_EP_TYPE_ISOC)
            {
                USBFS_1_EP[USBFS_1_EP1].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            USBFS_1_EP[USBFS_1_EP1].apiEpState = USBFS_1_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
            !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
            if (USBFS_1_midi_out_ep == USBFS_1_EP1)
            {
                USBFS_1_MIDI_OUT_Service();
            }
        #endif /* (USBFS_1_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)) */
    
        /* `#START EP1_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef USBFS_1_EP_1_ISR_EXIT_CALLBACK
        USBFS_1_EP_1_ISR_ExitCallback();
    #endif /* (USBFS_1_EP_1_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    }

#endif /* (USBFS_1_EP1_ISR_ACTIVE) */


#if (USBFS_1_EP2_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: USBFS_1_EP_2_ISR
    ****************************************************************************//**
    *
    *  Endpoint 2 Interrupt Service Routine.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_2_ISR)
    {
    #ifdef USBFS_1_EP_2_ISR_ENTRY_CALLBACK
        USBFS_1_EP_2_ISR_EntryCallback();
    #endif /* (USBFS_1_EP_2_ISR_ENTRY_CALLBACK) */

        /* `#START EP2_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */

        USBFS_1_ClearSieEpInterruptSource(USBFS_1_SIE_INT_EP2_INTR);

        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to be read from endpoint buffer. 
        */
    #if (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (USBFS_1_EP[USBFS_1_EP2].addr & USBFS_1_DIR_IN))
    #endif /* (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO) */
        {            
            /* Read CR0 register to clear SIE lock. */
            (void) USBFS_1_SIE_EP_BASE.sieEp[USBFS_1_EP2].epCr0;
            
            /* Toggle all endpoint types except ISOC. */
            if (USBFS_1_GET_EP_TYPE(USBFS_1_EP2) != USBFS_1_EP_TYPE_ISOC)
            {
                USBFS_1_EP[USBFS_1_EP2].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            USBFS_1_EP[USBFS_1_EP2].apiEpState = USBFS_1_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
            !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
            if (USBFS_1_midi_out_ep == USBFS_1_EP2)
            {
                USBFS_1_MIDI_OUT_Service();
            }
        #endif /* (USBFS_1_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)) */        
    
        /* `#START EP2_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef USBFS_1_EP_2_ISR_EXIT_CALLBACK
        USBFS_1_EP_2_ISR_ExitCallback();
    #endif /* (USBFS_1_EP_2_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (USBFS_1_EP2_ISR_ACTIVE) */


#if (USBFS_1_EP3_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: USBFS_1_EP_3_ISR
    ****************************************************************************//**
    *
    *  Endpoint 3 Interrupt Service Routine.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_3_ISR)
    {
    #ifdef USBFS_1_EP_3_ISR_ENTRY_CALLBACK
        USBFS_1_EP_3_ISR_EntryCallback();
    #endif /* (USBFS_1_EP_3_ISR_ENTRY_CALLBACK) */

        /* `#START EP3_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */

        USBFS_1_ClearSieEpInterruptSource(USBFS_1_SIE_INT_EP3_INTR);    

        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to be read from endpoint buffer. 
        */
    #if (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (USBFS_1_EP[USBFS_1_EP3].addr & USBFS_1_DIR_IN))
    #endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO) */
        {            
            /* Read CR0 register to clear SIE lock. */
            (void) USBFS_1_SIE_EP_BASE.sieEp[USBFS_1_EP3].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (USBFS_1_GET_EP_TYPE(USBFS_1_EP3) != USBFS_1_EP_TYPE_ISOC)
            {
                USBFS_1_EP[USBFS_1_EP3].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            USBFS_1_EP[USBFS_1_EP3].apiEpState = USBFS_1_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
            !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
            if (USBFS_1_midi_out_ep == USBFS_1_EP3)
            {
                USBFS_1_MIDI_OUT_Service();
            }
        #endif /* (USBFS_1_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)) */        

        /* `#START EP3_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef USBFS_1_EP_3_ISR_EXIT_CALLBACK
        USBFS_1_EP_3_ISR_ExitCallback();
    #endif /* (USBFS_1_EP_3_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (USBFS_1_EP3_ISR_ACTIVE) */


#if (USBFS_1_EP4_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: USBFS_1_EP_4_ISR
    ****************************************************************************//**
    *
    *  Endpoint 4 Interrupt Service Routine.
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_4_ISR)
    {
    #ifdef USBFS_1_EP_4_ISR_ENTRY_CALLBACK
        USBFS_1_EP_4_ISR_EntryCallback();
    #endif /* (USBFS_1_EP_4_ISR_ENTRY_CALLBACK) */

        /* `#START EP4_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */

        USBFS_1_ClearSieEpInterruptSource(USBFS_1_SIE_INT_EP4_INTR);
        
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (USBFS_1_EP[USBFS_1_EP4].addr & USBFS_1_DIR_IN))
    #endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO) */
        {
            /* Read CR0 register to clear SIE lock. */
            (void) USBFS_1_SIE_EP_BASE.sieEp[USBFS_1_EP4].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (USBFS_1_GET_EP_TYPE(USBFS_1_EP4) != USBFS_1_EP_TYPE_ISOC)
            {
                USBFS_1_EP[USBFS_1_EP4].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            USBFS_1_EP[USBFS_1_EP4].apiEpState = USBFS_1_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
            !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
            if(USBFS_1_midi_out_ep == USBFS_1_EP4)
            {
                USBFS_1_MIDI_OUT_Service();
            }
        #endif /* (USBFS_1_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)) */        

        /* `#START EP4_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef USBFS_1_EP_4_ISR_EXIT_CALLBACK
        USBFS_1_EP_4_ISR_ExitCallback();
    #endif /* (USBFS_1_EP_4_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (USBFS_1_EP4_ISR_ACTIVE) */


#if (USBFS_1_EP5_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: USBFS_1_EP_5_ISR
    ****************************************************************************//**
    *
    *  Endpoint 5 Interrupt Service Routine
    *
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_5_ISR)
    {
    #ifdef USBFS_1_EP_5_ISR_ENTRY_CALLBACK
        USBFS_1_EP_5_ISR_EntryCallback();
    #endif /* (USBFS_1_EP_5_ISR_ENTRY_CALLBACK) */

        /* `#START EP5_USER_CODE` Place your code here */

        /* `#END` */

    #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && \
                 USBFS_1_ISR_SERVICE_MIDI_OUT && CY_PSOC3)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */

        USBFS_1_ClearSieEpInterruptSource(USBFS_1_SIE_INT_EP5_INTR);
    
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (USBFS_1_EP[USBFS_1_EP5].addr & USBFS_1_DIR_IN))
    #endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO) */
        {            
            /* Read CR0 register to clear SIE lock. */
            (void) USBFS_1_SIE_EP_BASE.sieEp[USBFS_1_EP5].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (USBFS_1_GET_EP_TYPE(USBFS_1_EP5) != USBFS_1_EP_TYPE_ISOC)
            {
                USBFS_1_EP[USBFS_1_EP5].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            USBFS_1_EP[USBFS_1_EP5].apiEpState = USBFS_1_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO))        
        #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
            !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
            if (USBFS_1_midi_out_ep == USBFS_1_EP5)
            {
                USBFS_1_MIDI_OUT_Service();
            }
        #endif /* (USBFS_1_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)) */

        /* `#START EP5_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef USBFS_1_EP_5_ISR_EXIT_CALLBACK
        USBFS_1_EP_5_ISR_ExitCallback();
    #endif /* (USBFS_1_EP_5_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (USBFS_1_EP5_ISR_ACTIVE) */


#if (USBFS_1_EP6_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: USBFS_1_EP_6_ISR
    ****************************************************************************//**
    *
    *  Endpoint 6 Interrupt Service Routine.
    *
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_6_ISR)
    {
    #ifdef USBFS_1_EP_6_ISR_ENTRY_CALLBACK
        USBFS_1_EP_6_ISR_EntryCallback();
    #endif /* (USBFS_1_EP_6_ISR_ENTRY_CALLBACK) */

        /* `#START EP6_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */

        USBFS_1_ClearSieEpInterruptSource(USBFS_1_SIE_INT_EP6_INTR);
        
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (USBFS_1_EP[USBFS_1_EP6].addr & USBFS_1_DIR_IN))
    #endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO) */
        {
            /* Read CR0 register to clear SIE lock. */
            (void) USBFS_1_SIE_EP_BASE.sieEp[USBFS_1_EP6].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (USBFS_1_GET_EP_TYPE(USBFS_1_EP6) != USBFS_1_EP_TYPE_ISOC)
            {
                USBFS_1_EP[USBFS_1_EP6].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
            }
            
            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            USBFS_1_EP[USBFS_1_EP6].apiEpState = USBFS_1_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
            !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
            if (USBFS_1_midi_out_ep == USBFS_1_EP6)
            {
                USBFS_1_MIDI_OUT_Service();
            }
        #endif /* (USBFS_1_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)) */

        /* `#START EP6_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef USBFS_1_EP_6_ISR_EXIT_CALLBACK
        USBFS_1_EP_6_ISR_ExitCallback();
    #endif /* (USBFS_1_EP_6_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (USBFS_1_EP6_ISR_ACTIVE) */


#if (USBFS_1_EP7_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: USBFS_1_EP_7_ISR
    ****************************************************************************//**
    *
    *  Endpoint 7 Interrupt Service Routine.
    *
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_7_ISR)
    {
    #ifdef USBFS_1_EP_7_ISR_ENTRY_CALLBACK
        USBFS_1_EP_7_ISR_EntryCallback();
    #endif /* (USBFS_1_EP_7_ISR_ENTRY_CALLBACK) */

        /* `#START EP7_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    
        USBFS_1_ClearSieEpInterruptSource(USBFS_1_SIE_INT_EP7_INTR);
        
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (USBFS_1_EP[USBFS_1_EP7].addr & USBFS_1_DIR_IN))
    #endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO) */
        {           
            /* Read CR0 register to clear SIE lock. */
            (void) USBFS_1_SIE_EP_BASE.sieEp[USBFS_1_EP7].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (USBFS_1_GET_EP_TYPE(USBFS_1_EP7) != USBFS_1_EP_TYPE_ISOC)
            {
                USBFS_1_EP[USBFS_1_EP7].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
            }
            
            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            USBFS_1_EP[USBFS_1_EP7].apiEpState = USBFS_1_EVENT_PENDING;
        }


    #if (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
            !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
            if(USBFS_1_midi_out_ep == USBFS_1_EP7)
            {
                USBFS_1_MIDI_OUT_Service();
            }
        #endif /* (USBFS_1_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)) */

        /* `#START EP7_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef USBFS_1_EP_7_ISR_EXIT_CALLBACK
        USBFS_1_EP_7_ISR_ExitCallback();
    #endif /* (USBFS_1_EP_7_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (USBFS_1_EP7_ISR_ACTIVE) */


#if (USBFS_1_EP8_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: USBFS_1_EP_8_ISR
    ****************************************************************************//**
    *
    *  Endpoint 8 Interrupt Service Routine
    *
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_EP_8_ISR)
    {
    #ifdef USBFS_1_EP_8_ISR_ENTRY_CALLBACK
        USBFS_1_EP_8_ISR_EntryCallback();
    #endif /* (USBFS_1_EP_8_ISR_ENTRY_CALLBACK) */

        /* `#START EP8_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */

        USBFS_1_ClearSieEpInterruptSource(USBFS_1_SIE_INT_EP8_INTR);
        
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (USBFS_1_EP[USBFS_1_EP8].addr & USBFS_1_DIR_IN))
    #endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO) */
        {
            /* Read CR0 register to clear SIE lock. */
            (void) USBFS_1_SIE_EP_BASE.sieEp[USBFS_1_EP8].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (USBFS_1_GET_EP_TYPE(USBFS_1_EP8) != USBFS_1_EP_TYPE_ISOC)
            {
                USBFS_1_EP[USBFS_1_EP8].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            USBFS_1_EP[USBFS_1_EP8].apiEpState = USBFS_1_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
            !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
            if (USBFS_1_midi_out_ep == USBFS_1_EP8)
            {
                USBFS_1_MIDI_OUT_Service();
            }
        #endif /* (USBFS_1_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)) */

        /* `#START EP8_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef USBFS_1_EP_8_ISR_EXIT_CALLBACK
        USBFS_1_EP_8_ISR_ExitCallback();
    #endif /* (USBFS_1_EP_8_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
        !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && USBFS_1_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (USBFS_1_EP8_ISR_ACTIVE) */


#if (USBFS_1_SOF_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: USBFS_1_SOF_ISR
    ****************************************************************************//**
    *
    *  Start of Frame Interrupt Service Routine.
    *
    *
    *******************************************************************************/
    CY_ISR(USBFS_1_SOF_ISR)
    {
    #ifdef USBFS_1_SOF_ISR_ENTRY_CALLBACK
        USBFS_1_SOF_ISR_EntryCallback();
    #endif /* (USBFS_1_SOF_ISR_ENTRY_CALLBACK) */

        /* `#START SOF_USER_CODE` Place your code here */

        /* `#END` */

        USBFS_1_ClearSieInterruptSource(USBFS_1_INTR_SIE_SOF_INTR);

    #ifdef USBFS_1_SOF_ISR_EXIT_CALLBACK
        USBFS_1_SOF_ISR_ExitCallback();
    #endif /* (USBFS_1_SOF_ISR_EXIT_CALLBACK) */
    }
#endif /* (USBFS_1_SOF_ISR_ACTIVE) */


#if (USBFS_1_BUS_RESET_ISR_ACTIVE)
/*******************************************************************************
* Function Name: USBFS_1_BUS_RESET_ISR
****************************************************************************//**
*
*  USB Bus Reset Interrupt Service Routine.  Calls _Start with the same
*  parameters as the last USER call to _Start
*
*
*******************************************************************************/
CY_ISR(USBFS_1_BUS_RESET_ISR)
{
#ifdef USBFS_1_BUS_RESET_ISR_ENTRY_CALLBACK
    USBFS_1_BUS_RESET_ISR_EntryCallback();
#endif /* (USBFS_1_BUS_RESET_ISR_ENTRY_CALLBACK) */

    /* `#START BUS_RESET_USER_CODE` Place your code here */

    /* `#END` */

    USBFS_1_ClearSieInterruptSource(USBFS_1_INTR_SIE_BUS_RESET_INTR);

    USBFS_1_ReInitComponent();

#ifdef USBFS_1_BUS_RESET_ISR_EXIT_CALLBACK
    USBFS_1_BUS_RESET_ISR_ExitCallback();
#endif /* (USBFS_1_BUS_RESET_ISR_EXIT_CALLBACK) */
}
#endif /* (USBFS_1_BUS_RESET_ISR_ACTIVE) */


#if (USBFS_1_LPM_ACTIVE)
/***************************************************************************
* Function Name: USBFS_1_INTR_LPM_ISR
************************************************************************//**
*
*   Interrupt Service Routine for LPM of the interrupt sources.
*
*
***************************************************************************/
CY_ISR(USBFS_1_LPM_ISR)
{
#ifdef USBFS_1_LPM_ISR_ENTRY_CALLBACK
    USBFS_1_LPM_ISR_EntryCallback();
#endif /* (USBFS_1_LPM_ISR_ENTRY_CALLBACK) */

    /* `#START LPM_BEGIN_USER_CODE` Place your code here */

    /* `#END` */

    USBFS_1_ClearSieInterruptSource(USBFS_1_INTR_SIE_LPM_INTR);

    /* `#START LPM_END_USER_CODE` Place your code here */

    /* `#END` */

#ifdef USBFS_1_LPM_ISR_EXIT_CALLBACK
    USBFS_1_LPM_ISR_ExitCallback();
#endif /* (USBFS_1_LPM_ISR_EXIT_CALLBACK) */
}
#endif /* (USBFS_1_LPM_ACTIVE) */


#if (USBFS_1_EP_MANAGEMENT_DMA && USBFS_1_ARB_ISR_ACTIVE)
    /***************************************************************************
    * Function Name: USBFS_1_ARB_ISR
    ************************************************************************//**
    *
    *  Arbiter Interrupt Service Routine.
    *
    *
    ***************************************************************************/
    CY_ISR(USBFS_1_ARB_ISR)
    {
        uint8 arbIntrStatus;
        uint8 epStatus;
        uint8 ep = USBFS_1_EP1;

    #ifdef USBFS_1_ARB_ISR_ENTRY_CALLBACK
        USBFS_1_ARB_ISR_EntryCallback();
    #endif /* (USBFS_1_ARB_ISR_ENTRY_CALLBACK) */

        /* `#START ARB_BEGIN_USER_CODE` Place your code here */

        /* `#END` */

        /* Get pending ARB interrupt sources. */
        arbIntrStatus = USBFS_1_ARB_INT_SR_REG;

        while (0u != arbIntrStatus)
        {
            /* Check which EP is interrupt source. */
            if (0u != (arbIntrStatus & 0x01u))
            {
                /* Get endpoint enable interrupt sources. */
                epStatus = (USBFS_1_ARB_EP_BASE.arbEp[ep].epSr & USBFS_1_ARB_EP_BASE.arbEp[ep].epIntEn);

                /* Handle IN endpoint buffer full event: happens only once when endpoint buffer is loaded. */
                if (0u != (epStatus & USBFS_1_ARB_EPX_INT_IN_BUF_FULL))
                {
                    if (0u != (USBFS_1_EP[ep].addr & USBFS_1_DIR_IN))
                    {
                        /* Clear data ready status. */
                        USBFS_1_ARB_EP_BASE.arbEp[ep].epCfg &= (uint8) ~USBFS_1_ARB_EPX_CFG_IN_DATA_RDY;

                    #if (CY_PSOC3 || CY_PSOC5LP)
                        #if (USBFS_1_EP_MANAGEMENT_DMA_AUTO && (USBFS_1_EP_DMA_AUTO_OPT == 0u))
                            /* Set up common area DMA with rest of data. */
                            if(USBFS_1_inLength[ep] > USBFS_1_DMA_BYTES_PER_BURST)
                            {
                                USBFS_1_LoadNextInEP(ep, 0u);
                            }
                            else
                            {
                                USBFS_1_inBufFull[ep] = 1u;
                            }
                        #endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO && (USBFS_1_EP_DMA_AUTO_OPT == 0u)) */
                    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

                        /* Arm IN endpoint. */
                        USBFS_1_SIE_EP_BASE.sieEp[ep].epCr0 = USBFS_1_EP[ep].epMode;

                    #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && USBFS_1_ISR_SERVICE_MIDI_IN)
                        if (ep == USBFS_1_midi_in_ep)
                        {
                            /* Clear MIDI input pointer. */
                            USBFS_1_midiInPointer = 0u;
                        }
                    #endif /* (USBFS_1_ENABLE_MIDI_STREAMING) */
                    }
                }

            #if (USBFS_1_EP_MANAGEMENT_DMA_MANUAL)
                /* Handle DMA completion event for OUT endpoints. */
                if (0u != (epStatus & USBFS_1_ARB_EPX_SR_DMA_GNT))
                {
                    if (0u == (USBFS_1_EP[ep].addr & USBFS_1_DIR_IN))
                    {
                        /* Notify user that data has been copied from endpoint buffer. */
                        USBFS_1_EP[ep].apiEpState = USBFS_1_NO_EVENT_PENDING;

                        /* DMA done coping data: OUT endpoint has to be re-armed by user. */
                    }
                }
            #endif /* (USBFS_1_EP_MANAGEMENT_DMA_MANUAL) */

            #if (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO)
                /* Handle DMA completion event for OUT endpoints. */
                if (0u != (epStatus & USBFS_1_ARB_EPX_INT_DMA_TERMIN))
                {
                    uint32 channelNum = USBFS_1_DmaChan[ep];

                    /* Restore burst counter for endpoint. */
                    USBFS_1_DmaEpBurstCnt[ep] = USBFS_1_DmaEpBurstCntBackup[ep];

                    /* Disable DMA channel to restore descriptor configuration. The on-going transfer is aborted. */
                    USBFS_1_CyDmaChDisable(channelNum);

                    /* Generate DMA tr_out signal to notify USB IP that DMA is done. This signal is not generated
                    * when transfer was aborted (it occurs when host writes less bytes than buffer size).
                    */
                    USBFS_1_CyDmaTriggerOut(USBFS_1_DmaBurstEndOut[ep]);

                    /* Restore destination address for output endpoint. */
                    USBFS_1_CyDmaSetDstAddress(channelNum, USBFS_1_DMA_DESCR0, (void*) ((uint32) USBFS_1_DmaEpBufferAddrBackup[ep]));
                    USBFS_1_CyDmaSetDstAddress(channelNum, USBFS_1_DMA_DESCR1, (void*) ((uint32) USBFS_1_DmaEpBufferAddrBackup[ep] +
                                                                                                                   USBFS_1_DMA_BYTES_PER_BURST));

                    /* Restore number of data elements to transfer which was adjusted for last burst. */
                    if (0u != (USBFS_1_DmaEpLastBurstEl[ep] & USBFS_1_DMA_DESCR_REVERT))
                    {
                        USBFS_1_CyDmaSetNumDataElements(channelNum, (USBFS_1_DmaEpLastBurstEl[ep] >> USBFS_1_DMA_DESCR_SHIFT),
                                                                             USBFS_1_DMA_GET_MAX_ELEM_PER_BURST(USBFS_1_DmaEpLastBurstEl[ep]));
                    }

                    /* Validate descriptor 0 and 1 (also reset current state). Command to start with descriptor 0. */
                    USBFS_1_CyDmaValidateDescriptor(channelNum, USBFS_1_DMA_DESCR0);
                    USBFS_1_CyDmaValidateDescriptor(channelNum, USBFS_1_DMA_DESCR1);
                    USBFS_1_CyDmaSetDescriptor0Next(channelNum);

                    /* Enable DMA channel: configuration complete. */
                    USBFS_1_CyDmaChEnable(channelNum);
                    
                    
                    /* Read CR0 register to clear SIE lock. */
                    (void) USBFS_1_SIE_EP_BASE.sieEp[ep].epCr0;
                    
                    /* Toggle all endpoint types except ISOC. */
                    if (USBFS_1_GET_EP_TYPE(ep) != USBFS_1_EP_TYPE_ISOC)
                    {
                        USBFS_1_EP[ep].epToggle ^= USBFS_1_EPX_CNT_DATA_TOGGLE;
                    }
            
                    /* Notify user that data has been copied from endpoint buffer. */
                    USBFS_1_EP[ep].apiEpState = USBFS_1_EVENT_PENDING;
                    
                #if (defined(USBFS_1_ENABLE_MIDI_STREAMING) && \
                    !defined(USBFS_1_MAIN_SERVICE_MIDI_OUT) && USBFS_1_ISR_SERVICE_MIDI_OUT)
                    if (USBFS_1_midi_out_ep == ep)
                    {
                        USBFS_1_MIDI_OUT_Service();
                    }
                #endif /* (USBFS_1_ISR_SERVICE_MIDI_OUT) */
                }
            #endif /* (CY_PSOC4 && USBFS_1_EP_MANAGEMENT_DMA_AUTO) */


                /* `#START ARB_USER_CODE` Place your code here for handle Buffer Underflow/Overflow */

                /* `#END` */

            #ifdef USBFS_1_ARB_ISR_CALLBACK
                USBFS_1_ARB_ISR_Callback(ep, epStatus);
            #endif /* (USBFS_1_ARB_ISR_CALLBACK) */

                /* Clear serviced endpoint interrupt sources. */
                USBFS_1_ARB_EP_BASE.arbEp[ep].epSr = epStatus;
            }

            ++ep;
            arbIntrStatus >>= 1u;
        }

        /* `#START ARB_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef USBFS_1_ARB_ISR_EXIT_CALLBACK
        USBFS_1_ARB_ISR_ExitCallback();
    #endif /* (USBFS_1_ARB_ISR_EXIT_CALLBACK) */
    }

#endif /*  (USBFS_1_ARB_ISR_ACTIVE && USBFS_1_EP_MANAGEMENT_DMA) */


#if (USBFS_1_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    #if (USBFS_1_DMA1_ACTIVE)
        /******************************************************************************
        * Function Name: USBFS_1_EP1_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 1 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void USBFS_1_EP1_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != USBFS_1_DmaEpBurstCnt[USBFS_1_EP1])
            {
                /* Decrement burst counter. */
                --USBFS_1_DmaEpBurstCnt[USBFS_1_EP1];
            }
            else
            {
                /* Adjust length of last burst. */
                USBFS_1_CyDmaSetNumDataElements(USBFS_1_EP1_DMA_CH,
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP1] >> USBFS_1_DMA_DESCR_SHIFT),
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP1] &  USBFS_1_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (USBFS_1_EP[USBFS_1_EP1].addr & USBFS_1_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) USBFS_1_CyDmaGetSrcAddress(USBFS_1_EP1_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP1_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP1_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) USBFS_1_CyDmaGetDstAddress(USBFS_1_EP1_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP1_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP1_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            USBFS_1_CyDmaValidateDescriptor(USBFS_1_EP1_DMA_CH, USBFS_1_DMA_DESCR0);
            USBFS_1_CyDmaChEnable (USBFS_1_EP1_DMA_CH);
            USBFS_1_CyDmaTriggerIn(USBFS_1_DmaReqOut[USBFS_1_EP1]);
        }
    #endif /* (USBFS_1_DMA1_ACTIVE) */


    #if (USBFS_1_DMA2_ACTIVE)
        /******************************************************************************
        * Function Name: USBFS_1_EP2_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 2 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void USBFS_1_EP2_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != USBFS_1_DmaEpBurstCnt[USBFS_1_EP2])
            {
                /* Decrement burst counter. */
                --USBFS_1_DmaEpBurstCnt[USBFS_1_EP2];
            }
            else
            {
                /* Adjust length of last burst. */
                USBFS_1_CyDmaSetNumDataElements(USBFS_1_EP2_DMA_CH,
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP2] >> USBFS_1_DMA_DESCR_SHIFT),
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP2] &  USBFS_1_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (USBFS_1_EP[USBFS_1_EP2].addr & USBFS_1_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) USBFS_1_CyDmaGetSrcAddress(USBFS_1_EP2_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP2_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP2_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) USBFS_1_CyDmaGetDstAddress(USBFS_1_EP2_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP2_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP2_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            USBFS_1_CyDmaValidateDescriptor(USBFS_1_EP2_DMA_CH, USBFS_1_DMA_DESCR0);
            USBFS_1_CyDmaChEnable (USBFS_1_EP2_DMA_CH);
            USBFS_1_CyDmaTriggerIn(USBFS_1_DmaReqOut[USBFS_1_EP2]);
        }
    #endif /* (USBFS_1_DMA2_ACTIVE) */


    #if (USBFS_1_DMA3_ACTIVE)
        /******************************************************************************
        * Function Name: USBFS_1_EP3_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 3 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void USBFS_1_EP3_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != USBFS_1_DmaEpBurstCnt[USBFS_1_EP3])
            {
                /* Decrement burst counter. */
                --USBFS_1_DmaEpBurstCnt[USBFS_1_EP3];
            }
            else
            {
                /* Adjust length of last burst. */
                USBFS_1_CyDmaSetNumDataElements(USBFS_1_EP3_DMA_CH,
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP3] >> USBFS_1_DMA_DESCR_SHIFT),
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP3] &  USBFS_1_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (USBFS_1_EP[USBFS_1_EP3].addr & USBFS_1_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) USBFS_1_CyDmaGetSrcAddress(USBFS_1_EP3_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP3_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP3_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) USBFS_1_CyDmaGetDstAddress(USBFS_1_EP3_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP3_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP3_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            USBFS_1_CyDmaValidateDescriptor(USBFS_1_EP3_DMA_CH, USBFS_1_DMA_DESCR0);
            USBFS_1_CyDmaChEnable (USBFS_1_EP3_DMA_CH);
            USBFS_1_CyDmaTriggerIn(USBFS_1_DmaReqOut[USBFS_1_EP3]);
        }
    #endif /* (USBFS_1_DMA3_ACTIVE) */


    #if (USBFS_1_DMA4_ACTIVE)
        /******************************************************************************
        * Function Name: USBFS_1_EP4_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 4 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void USBFS_1_EP4_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != USBFS_1_DmaEpBurstCnt[USBFS_1_EP4])
            {
                /* Decrement burst counter. */
                --USBFS_1_DmaEpBurstCnt[USBFS_1_EP4];
            }
            else
            {
                /* Adjust length of last burst. */
                USBFS_1_CyDmaSetNumDataElements(USBFS_1_EP4_DMA_CH,
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP4] >> USBFS_1_DMA_DESCR_SHIFT),
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP4] &  USBFS_1_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (USBFS_1_EP[USBFS_1_EP4].addr & USBFS_1_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) USBFS_1_CyDmaGetSrcAddress(USBFS_1_EP4_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP4_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP4_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) USBFS_1_CyDmaGetDstAddress(USBFS_1_EP4_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP4_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP4_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            USBFS_1_CyDmaValidateDescriptor(USBFS_1_EP4_DMA_CH, USBFS_1_DMA_DESCR0);
            USBFS_1_CyDmaChEnable (USBFS_1_EP4_DMA_CH);
            USBFS_1_CyDmaTriggerIn(USBFS_1_DmaReqOut[USBFS_1_EP4]);
        }
    #endif /* (USBFS_1_DMA4_ACTIVE) */


    #if (USBFS_1_DMA5_ACTIVE)
        /******************************************************************************
        * Function Name: USBFS_1_EP5_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 5 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void USBFS_1_EP5_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != USBFS_1_DmaEpBurstCnt[USBFS_1_EP5])
            {
                /* Decrement burst counter. */
                --USBFS_1_DmaEpBurstCnt[USBFS_1_EP5];
            }
            else
            {
                /* Adjust length of last burst. */
                USBFS_1_CyDmaSetNumDataElements(USBFS_1_EP5_DMA_CH,
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP5] >> USBFS_1_DMA_DESCR_SHIFT),
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP5] &  USBFS_1_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (USBFS_1_EP[USBFS_1_EP5].addr & USBFS_1_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) USBFS_1_CyDmaGetSrcAddress(USBFS_1_EP5_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP5_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP5_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) USBFS_1_CyDmaGetDstAddress(USBFS_1_EP5_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP5_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP5_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            USBFS_1_CyDmaValidateDescriptor(USBFS_1_EP5_DMA_CH, USBFS_1_DMA_DESCR0);
            USBFS_1_CyDmaChEnable (USBFS_1_EP5_DMA_CH);
            USBFS_1_CyDmaTriggerIn(USBFS_1_DmaReqOut[USBFS_1_EP5]);
        }
    #endif /* (USBFS_1_DMA5_ACTIVE) */


    #if (USBFS_1_DMA6_ACTIVE)
        /******************************************************************************
        * Function Name: USBFS_1_EP6_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 6 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void USBFS_1_EP6_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != USBFS_1_DmaEpBurstCnt[USBFS_1_EP6])
            {
                /* Decrement burst counter. */
                --USBFS_1_DmaEpBurstCnt[USBFS_1_EP6];
            }
            else
            {
                /* Adjust length of last burst. */
                USBFS_1_CyDmaSetNumDataElements(USBFS_1_EP6_DMA_CH,
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP6] >> USBFS_1_DMA_DESCR_SHIFT),
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP6] &  USBFS_1_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (USBFS_1_EP[USBFS_1_EP6].addr & USBFS_1_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) USBFS_1_CyDmaGetSrcAddress(USBFS_1_EP6_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP6_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP6_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) USBFS_1_CyDmaGetDstAddress(USBFS_1_EP6_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP6_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP6_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable the DMA to execute transfer as it was disabled because there were no valid descriptor. */
            USBFS_1_CyDmaValidateDescriptor(USBFS_1_EP6_DMA_CH, USBFS_1_DMA_DESCR0);
            USBFS_1_CyDmaChEnable (USBFS_1_EP6_DMA_CH);
            USBFS_1_CyDmaTriggerIn(USBFS_1_DmaReqOut[USBFS_1_EP6]);
        }
    #endif /* (USBFS_1_DMA6_ACTIVE) */


    #if (USBFS_1_DMA7_ACTIVE)
        /******************************************************************************
        * Function Name: USBFS_1_EP7_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 7 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void USBFS_1_EP7_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != USBFS_1_DmaEpBurstCnt[USBFS_1_EP7])
            {
                /* Decrement burst counter. */
                --USBFS_1_DmaEpBurstCnt[USBFS_1_EP7];
            }
            else
            {
                /* Adjust length of last burst. */
                USBFS_1_CyDmaSetNumDataElements(USBFS_1_EP7_DMA_CH,
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP7] >> USBFS_1_DMA_DESCR_SHIFT),
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP7] &  USBFS_1_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (USBFS_1_EP[USBFS_1_EP7].addr & USBFS_1_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) USBFS_1_CyDmaGetSrcAddress(USBFS_1_EP7_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP7_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP7_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) USBFS_1_CyDmaGetDstAddress(USBFS_1_EP7_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP7_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP7_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            USBFS_1_CyDmaValidateDescriptor(USBFS_1_EP7_DMA_CH, USBFS_1_DMA_DESCR0);
            USBFS_1_CyDmaChEnable (USBFS_1_EP7_DMA_CH);
            USBFS_1_CyDmaTriggerIn(USBFS_1_DmaReqOut[USBFS_1_EP7]);
        }
    #endif /* (USBFS_1_DMA7_ACTIVE) */


    #if (USBFS_1_DMA8_ACTIVE)
        /******************************************************************************
        * Function Name: USBFS_1_EP8_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 8 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void USBFS_1_EP8_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != USBFS_1_DmaEpBurstCnt[USBFS_1_EP8])
            {
                /* Decrement burst counter. */
                --USBFS_1_DmaEpBurstCnt[USBFS_1_EP8];
            }
            else
            {
                /* Adjust length of last burst. */
                USBFS_1_CyDmaSetNumDataElements(USBFS_1_EP8_DMA_CH,
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP8] >> USBFS_1_DMA_DESCR_SHIFT),
                                                        ((uint32) USBFS_1_DmaEpLastBurstEl[USBFS_1_EP8] &  USBFS_1_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (USBFS_1_EP[USBFS_1_EP8].addr & USBFS_1_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) USBFS_1_CyDmaGetSrcAddress(USBFS_1_EP8_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP8_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetSrcAddress(USBFS_1_EP8_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) USBFS_1_CyDmaGetDstAddress(USBFS_1_EP8_DMA_CH, USBFS_1_DMA_DESCR0);
                nextAddr += (2u * USBFS_1_DMA_BYTES_PER_BURST);
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP8_DMA_CH, USBFS_1_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += USBFS_1_DMA_BYTES_PER_BURST;
                USBFS_1_CyDmaSetDstAddress(USBFS_1_EP8_DMA_CH, USBFS_1_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            USBFS_1_CyDmaValidateDescriptor(USBFS_1_EP8_DMA_CH, USBFS_1_DMA_DESCR0);
            USBFS_1_CyDmaChEnable (USBFS_1_EP8_DMA_CH);
            USBFS_1_CyDmaTriggerIn(USBFS_1_DmaReqOut[USBFS_1_EP8]);
        }
    #endif /* (USBFS_1_DMA8_ACTIVE) */

#else
    #if (USBFS_1_EP_DMA_AUTO_OPT == 0u)
        /******************************************************************************
        * Function Name: USBFS_1_EP_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        CY_ISR(USBFS_1_EP_DMA_DONE_ISR)
        {
            uint8 int8Status;
            uint8 int17Status;
            uint8 ep_status;
            uint8 ep = USBFS_1_EP1;

        #ifdef USBFS_1_EP_DMA_DONE_ISR_ENTRY_CALLBACK
            USBFS_1_EP_DMA_DONE_ISR_EntryCallback();
        #endif /* (USBFS_1_EP_DMA_DONE_ISR_ENTRY_CALLBACK) */

            /* `#START EP_DMA_DONE_BEGIN_USER_CODE` Place your code here */

            /* `#END` */

            /* Read clear on read status register with EP source of interrupt. */
            int17Status = USBFS_1_EP17_DMA_Done_SR_Read() & USBFS_1_EP17_SR_MASK;
            int8Status  = USBFS_1_EP8_DMA_Done_SR_Read()  & USBFS_1_EP8_SR_MASK;

            while (int8Status != 0u)
            {
                while (int17Status != 0u)
                {
                    if ((int17Status & 1u) != 0u)  /* If EpX interrupt present. */
                    {
                        /* Read Endpoint Status Register. */
                        ep_status = USBFS_1_ARB_EP_BASE.arbEp[ep].epSr;

                        if ((0u == (ep_status & USBFS_1_ARB_EPX_SR_IN_BUF_FULL)) &&
                            (0u ==USBFS_1_inBufFull[ep]))
                        {
                            /* `#START EP_DMA_DONE_USER_CODE` Place your code here */

                            /* `#END` */

                        #ifdef USBFS_1_EP_DMA_DONE_ISR_CALLBACK
                            USBFS_1_EP_DMA_DONE_ISR_Callback();
                        #endif /* (USBFS_1_EP_DMA_DONE_ISR_CALLBACK) */

                            /* Transfer again 2 last bytes into pre-fetch endpoint area. */
                            USBFS_1_ARB_EP_BASE.arbEp[ep].rwWaMsb = 0u;
                            USBFS_1_ARB_EP_BASE.arbEp[ep].rwWa = (USBFS_1_DMA_BYTES_PER_BURST * ep) - USBFS_1_DMA_BYTES_REPEAT;
                            USBFS_1_LoadNextInEP(ep, 1u);

                            /* Set Data ready status to generate DMA request. */
                            USBFS_1_ARB_EP_BASE.arbEp[ep].epCfg |= USBFS_1_ARB_EPX_CFG_IN_DATA_RDY;
                        }
                    }

                    ep++;
                    int17Status >>= 1u;
                }

                int8Status >>= 1u;

                if (int8Status != 0u)
                {
                    /* Prepare pointer for EP8. */
                    ep = USBFS_1_EP8;
                    int17Status = int8Status & 0x01u;
                }
            }

            /* `#START EP_DMA_DONE_END_USER_CODE` Place your code here */

            /* `#END` */

    #ifdef USBFS_1_EP_DMA_DONE_ISR_EXIT_CALLBACK
        USBFS_1_EP_DMA_DONE_ISR_ExitCallback();
    #endif /* (USBFS_1_EP_DMA_DONE_ISR_EXIT_CALLBACK) */
        }
    #endif /* (USBFS_1_EP_DMA_AUTO_OPT == 0u) */
#endif /* (CY_PSOC4) */
#endif /* (USBFS_1_EP_MANAGEMENT_DMA_AUTO) */


#if (CY_PSOC4)
    /***************************************************************************
    * Function Name: USBFS_1_IntrHandler
    ************************************************************************//**
    *
    *   Interrupt handler for Hi/Mid/Low ISRs.
    *
    *  regCause - The cause register of interrupt. One of the three variants:
    *       USBFS_1_INTR_CAUSE_LO_REG - Low interrupts.
    *       USBFS_1_INTR_CAUSE_MED_REG - Med interrupts.
    *       USBFS_1_INTR_CAUSE_HI_REG - - High interrupts.
    *
    *
    ***************************************************************************/
    CY_INLINE static void USBFS_1_IntrHandler(uint32 intrCause)
    {
        /* Array of pointers to component interrupt handlers. */
        static const cyisraddress USBFS_1_isrCallbacks[] =
        {

        };

        uint32 cbIdx = 0u;

        /* Check arbiter interrupt source first. */
        if (0u != (intrCause & USBFS_1_INTR_CAUSE_ARB_INTR))
        {
            USBFS_1_isrCallbacks[USBFS_1_ARB_EP_INTR_NUM]();
        }

        /* Check all other interrupt sources (except arbiter and resume). */
        intrCause = (intrCause  & USBFS_1_INTR_CAUSE_CTRL_INTR_MASK) |
                    ((intrCause & USBFS_1_INTR_CAUSE_EP1_8_INTR_MASK) >>
                                  USBFS_1_INTR_CAUSE_EP_INTR_SHIFT);

        /* Call interrupt handlers for active interrupt sources. */
        while (0u != intrCause)
        {
            if (0u != (intrCause & 0x1u))
            {
                 USBFS_1_isrCallbacks[cbIdx]();
            }

            intrCause >>= 1u;
            ++cbIdx;
        }
    }


    /***************************************************************************
    * Function Name: USBFS_1_INTR_HI_ISR
    ************************************************************************//**
    *
    *   Interrupt Service Routine for the high group of the interrupt sources.
    *
    *
    ***************************************************************************/
    CY_ISR(USBFS_1_INTR_HI_ISR)
    {
        USBFS_1_IntrHandler(USBFS_1_INTR_CAUSE_HI_REG);
    }

    /***************************************************************************
    * Function Name: USBFS_1_INTR_MED_ISR
    ************************************************************************//**
    *
    *   Interrupt Service Routine for the medium group of the interrupt sources.
    *
    *
    ***************************************************************************/
    CY_ISR(USBFS_1_INTR_MED_ISR)
    {
       USBFS_1_IntrHandler(USBFS_1_INTR_CAUSE_MED_REG);
    }

    /***************************************************************************
    * Function Name: USBFS_1_INTR_LO_ISR
    ************************************************************************//**
    *
    *   Interrupt Service Routine for the low group of the interrupt sources.
    *
    *
    ***************************************************************************/
    CY_ISR(USBFS_1_INTR_LO_ISR)
    {
        USBFS_1_IntrHandler(USBFS_1_INTR_CAUSE_LO_REG);
    }
#endif /* (CY_PSOC4) */


/* [] END OF FILE */
