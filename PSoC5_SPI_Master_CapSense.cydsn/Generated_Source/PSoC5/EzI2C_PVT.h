/*******************************************************************************
* File Name: .h
* Version 2.0
*
* Description:
*  This file provides private constants and parameter values for the EZI2C
*  component.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_EZI2C_PVT_EzI2C_H)
#define CY_EZI2C_PVT_EzI2C_H

#include "EzI2C.h"


/***************************************
*     Vars with External Linkage
***************************************/

extern EzI2C_BACKUP_STRUCT  EzI2C_backup;

/* Status and state variables */
extern volatile uint8 EzI2C_curStatus;
extern volatile uint8 EzI2C_curState;

/* Primary slave address variables */
extern volatile uint8* EzI2C_dataPtrS1;
extern volatile uint16 EzI2C_bufSizeS1;
extern volatile uint16 EzI2C_wrProtectS1;
extern volatile uint16 EzI2C_rwOffsetS1;
extern volatile uint16 EzI2C_rwIndexS1;

/* Secondary slave address variables */
#if (EzI2C_ADDRESSES == EzI2C_TWO_ADDRESSES)
    extern volatile uint8  EzI2C_addrS1;
    extern volatile uint8  EzI2C_addrS2;
    extern volatile uint8* EzI2C_dataPtrS2;
    extern volatile uint16 EzI2C_bufSizeS2;
    extern volatile uint16 EzI2C_wrProtectS2;
    extern volatile uint16 EzI2C_rwOffsetS2;
    extern volatile uint16 EzI2C_rwIndexS2;
#endif  /* (EzI2C_ADDRESSES == EzI2C_TWO_ADDRESSES) */

#if (EzI2C_WAKEUP_ENABLED)
    extern volatile uint8 EzI2C_wakeupSource;
#endif /* (EzI2C_WAKEUP_ENABLED) */

#endif /* CY_EZI2C_PVT_EzI2C_H */


/* [] END OF FILE */
