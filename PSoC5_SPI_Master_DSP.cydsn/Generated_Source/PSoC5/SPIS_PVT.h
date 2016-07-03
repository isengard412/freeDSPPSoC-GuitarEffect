/*******************************************************************************
* File Name: .h
* Version 2.70
*
* Description:
*  This private header file contains internal definitions for the SPIS
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIS_PVT_SPIS_H)
#define CY_SPIS_PVT_SPIS_H

#include "SPIS.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/
extern volatile uint8 SPIS_swStatusTx;
extern volatile uint8 SPIS_swStatusRx;

#if (SPIS_RX_SOFTWARE_BUF_ENABLED)

    extern volatile uint8 SPIS_rxBuffer[SPIS_RX_BUFFER_SIZE];
    extern volatile uint8 SPIS_rxBufferRead;
    extern volatile uint8 SPIS_rxBufferWrite;
    extern volatile uint8 SPIS_rxBufferFull;

#endif /* SPIS_RX_SOFTWARE_BUF_ENABLED */

#if (SPIS_TX_SOFTWARE_BUF_ENABLED)

    extern volatile uint8 SPIS_txBuffer[SPIS_TX_BUFFER_SIZE];
    extern volatile uint8 SPIS_txBufferRead;
    extern volatile uint8 SPIS_txBufferWrite;
    extern volatile uint8 SPIS_txBufferFull;

#endif /* SPIS_TX_SOFTWARE_BUF_ENABLED */

#endif /* CY_SPIS_PVT_SPIS_H */


/* [] END OF FILE */
