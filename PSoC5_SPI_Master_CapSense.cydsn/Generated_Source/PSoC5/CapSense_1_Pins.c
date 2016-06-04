/*******************************************************************************
* File Name: CapSense_1_Pins.c
* Version 3.50
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_1_Pins.h"


/*******************************************************************************
* Function Name: CapSense_1_SetAllSensorsDriveMode
********************************************************************************
*
* Summary:
*  Sets the drive mode for the all pins used by capacitive sensors within 
*  CapSense component.
* 
* Parameters:  
*  mode: Desired drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void CapSense_1_SetAllSensorsDriveMode(uint8 mode) 
{
    /* Set pins drive mode */
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__Button0__BTN, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__Button1__BTN, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__Button2__BTN, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e0__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e1__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e2__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e3__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e4__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e5__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e6__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e7__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e8__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e9__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e10__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e11__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e12__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e13__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e14__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e15__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e16__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e17__LS, mode);
    CyPins_SetPinDriveMode(CapSense_1_PortCH0__LinearSlider0_e18__LS, mode);

}



/*******************************************************************************
* Function Name: CapSense_1_SetAllCmodsDriveMode
********************************************************************************
*
* Summary:
*  Sets the drive mode for the all pins used by Cmod capacitors within CapSense 
*  component.
* 
* Parameters:  
*  mode: Desired drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void CapSense_1_SetAllCmodsDriveMode(uint8 mode) 
{
   /* Set pins drive mode */
    CyPins_SetPinDriveMode(CapSense_1_CmodCH0_Cmod_CH0, mode);

}


#if (CapSense_1_CURRENT_SOURCE == CapSense_1_EXTERNAL_RB)
    /*******************************************************************************
    * Function Name: CapSense_1_SetAllRbsDriveMode
    ********************************************************************************
    *
    * Summary:
    *  Sets the drive mode for the all pins used by bleed resistors (Rb) within 
    *  CapSense component. Only available when Current Source is external resistor.
    * 
    * Parameters:  
    *  mode: Desired drive mode.
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void CapSense_1_SetAllRbsDriveMode(uint8 mode) 
    {
        /* Set pins drive mode */
      
    }
#endif  /* (CapSense_1_CURRENT_SOURCE == CapSense_1_EXTERNAL_RB) */


/* [] END OF FILE */
