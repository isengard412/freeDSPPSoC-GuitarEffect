/*******************************************************************************
* File Name: main.c
*
* Version: 1.10
*
* Description:
*  The project explains the usage of CapSense CSD component. The 2 buttons and
*  linear sliders are used as sensing elements. Tuner GUI displays buttons 
*  active state and slider position. The defualt parameters of component could 
*  be changed by using Tuner GUI. For more information about Tuner GUI please 
*  refer to CapSense CSD data sheet.
*  The EzI2C component is used to establish communication with Tuner GUI.
*
*  Steps to lanch and use Tunner:
*   1) Select "Launch Tuner" from a CapSense CSD instance context menu to
*      launch the Tuning GUI.
*   2) Open the Configuration Communication dialog and set the communication
*      parameters.
*   3) Press Start on the Tuning GUI. All of the CapSense elements will start
*      showing their values.
*
* Hardware connections:
*  CY8CKIT-001 and MiniProg3 GND should be connected.
*  EzI2C Slave SDA - P12[1] to SDAT on MiniProg3.
*  EzI2C Slave SCL - P12[0] to SCLK on MiniProg3.
*  No connection is required for the modulator capacitor Cmod (P2[7] on
*  CY8C38 Family Processor Module CY8CKIT-009).
*  NOTE: To use this project with CY8C55 Family Processor Module CY8CKIT-010
*        reassign the Cmod to P15[5].
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>



/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Main function performs following functions:
*   1. Enable global interrupts.
*   2. Initialize CapSense CSD and EzI2C Start the sensor scanning loop.
*   3. Process scanning results and communicates with Tuner GUI.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
int main()
{
    /* Enable global interrupts */
    CyGlobalIntEnable;

    /* Initialize CapSense CSD and EzI2C Start the sensor scanning loop */
    CapSense_CSD_TunerStart();

    while(1u)
    {
        /* Process scanning results and communicates with Tuner GUI */
        CapSense_CSD_TunerComm();
    }
}


/* [] END OF FILE */
