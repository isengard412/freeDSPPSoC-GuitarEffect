/*******************************************************************************
* File Name: CapSense_1_Pins.h
* Version 3.40
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAPSENSE_CSD_Pins_CapSense_1_H)
#define CY_CAPSENSE_CSD_Pins_CapSense_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CapSense_1.h"


/***************************************
*        Function Prototypes
***************************************/

void CapSense_1_SetAllSensorsDriveMode(uint8 mode) ;
void CapSense_1_SetAllCmodsDriveMode(uint8 mode) ;
#if (CapSense_1_CURRENT_SOURCE == CapSense_1_EXTERNAL_RB)
    void CapSense_1_SetAllRbsDriveMode(uint8 mode) ;    
#endif  /* (CapSense_1_CURRENT_SOURCE == CapSense_1_EXTERNAL_RB) */   


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CapSense_1_DM_ALG_HIZ         (PIN_DM_ALG_HIZ)
#define CapSense_1_DM_DIG_HIZ         (PIN_DM_DIG_HIZ)
#define CapSense_1_DM_RES_UP          (PIN_DM_RES_UP)
#define CapSense_1_DM_RES_DWN         (PIN_DM_RES_DWN)
#define CapSense_1_DM_OD_LO           (PIN_DM_OD_LO)
#define CapSense_1_DM_OD_HI           (PIN_DM_OD_HI)
#define CapSense_1_DM_STRONG          (PIN_DM_STRONG)
#define CapSense_1_DM_RES_UPDWN       (PIN_DM_RES_UPDWN)

/* PC registers defines for sensors */
#define CapSense_1_PortCH0__Button0__BTN  CapSense_1_PortCH0__Button0__BTN__PC
#define CapSense_1_PortCH0__LinearSlider0_e0__LS  CapSense_1_PortCH0__LinearSlider0_e0__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e1__LS  CapSense_1_PortCH0__LinearSlider0_e1__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e2__LS  CapSense_1_PortCH0__LinearSlider0_e2__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e3__LS  CapSense_1_PortCH0__LinearSlider0_e3__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e4__LS  CapSense_1_PortCH0__LinearSlider0_e4__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e5__LS  CapSense_1_PortCH0__LinearSlider0_e5__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e6__LS  CapSense_1_PortCH0__LinearSlider0_e6__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e7__LS  CapSense_1_PortCH0__LinearSlider0_e7__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e8__LS  CapSense_1_PortCH0__LinearSlider0_e8__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e9__LS  CapSense_1_PortCH0__LinearSlider0_e9__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e10__LS  CapSense_1_PortCH0__LinearSlider0_e10__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e11__LS  CapSense_1_PortCH0__LinearSlider0_e11__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e12__LS  CapSense_1_PortCH0__LinearSlider0_e12__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e13__LS  CapSense_1_PortCH0__LinearSlider0_e13__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e14__LS  CapSense_1_PortCH0__LinearSlider0_e14__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e15__LS  CapSense_1_PortCH0__LinearSlider0_e15__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e16__LS  CapSense_1_PortCH0__LinearSlider0_e16__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e17__LS  CapSense_1_PortCH0__LinearSlider0_e17__LS__PC
#define CapSense_1_PortCH0__LinearSlider0_e18__LS  CapSense_1_PortCH0__LinearSlider0_e18__LS__PC
#define CapSense_1_PortCH0__Button1__BTN  CapSense_1_PortCH0__Button1__BTN__PC
#define CapSense_1_PortCH0__Button2__BTN  CapSense_1_PortCH0__Button2__BTN__PC
/* For Cmods*/
#define CapSense_1_CmodCH0_Cmod_CH0       CapSense_1_CmodCH0__Cmod_CH0__PC


#endif /* (CY_CAPSENSE_CSD_Pins_CapSense_1_H) */


/* [] END OF FILE */
