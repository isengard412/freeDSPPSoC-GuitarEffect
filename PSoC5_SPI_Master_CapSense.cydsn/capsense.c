/* ========================================
* File Name: capsense.h
*
* Version: 1
* Author: Lukas Creutzburg
*
*  Description:
*  CapSense module
*
* ===========================================================================================================
*/
#include "capsense.h"

/* Variables */

uint16 curPos, oldPos;


void CapSenseInit(void)
{
    /* Start CapSense components */
    CapSense_1_Start();
    
    /* Initialize baselines */
    CapSense_1_InitializeAllBaselines();
}

int16 CapSense_DisplayState(void)
{
    /* Find Slider Position */
    curPos = CapSense_1_GetCentroidPos(CapSense_1_LINEARSLIDER0__LS);

    /* Reset position */
    if(curPos == 0xFFFFu)
    {
        curPos = 0u;
    }

    /* Move bargraph */
    if (curPos != oldPos)
    {
        oldPos = curPos;
        /* Display Slider bargraph */
        if (curPos != 0u)
        {
            int16 myInt = (uint32)curPos; 
            return myInt;
        }
    }
    //not moved
    return -1;
}

int32 CapSense_Refresh(void)
{
    CapSense_Button0();
    CapSense_Button1();
    CapSense_Button2();
    /* Check whether the scanning of all enabled widgets is completed. */
        if(0u == CapSense_1_IsBusy())
        {
            /* Update all baselines */
            CapSense_1_UpdateEnabledBaselines();

            /* Start scanning all enabled sensors */
            CapSense_1_ScanEnabledWidgets();
        }

        /* Display CapSense state using LEDs */
        return CapSense_DisplayState();
}

void CapSense_Button0(void)
{
    /* Display BUTTON0 state */
    if (CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON0__BTN))
    {
        //is pressed
        UARTsendString("Button 0\n");
    }
    else
    {
        //is notpressed
    }
}

void CapSense_Button1(void)
{
    /* Display BUTTON1 state */
    if (CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON1__BTN))
    {
        //is pressed
        UARTsendString("Button 1\n");
    }
    else
    {
        //is notpressed
    }
}

void CapSense_Button2(void)
{
    /* Display BUTTON2 state */
    if (CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON2__BTN))
    {
        //is pressed
        UARTsendString("Button 2\n");
    }
    else
    {
        //is notpressed
    }
}


//[] END OF FILE
