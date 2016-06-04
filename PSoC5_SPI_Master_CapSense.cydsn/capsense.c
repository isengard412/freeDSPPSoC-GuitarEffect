/* ========================================
* File Name: capsense.h
*
* Version: 0
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

//_________________________________

/*******************************************************************************
* Function Name:  CapSenseInit
********************************************************************************
*
* Summary:
*   Initializes CapSense  
*
* Parameters:  
*  None
*
* Return: 
*  None 
*  
*******************************************************************************/
void CapSenseInit(void)
{
    /* Start CapSense components */
    CapSense_1_Start();
    
    /* Initialize baselines */
    CapSense_1_InitializeAllBaselines();
}
//_________________________________________________________

/*******************************************************************************
* Function Name: CapSense_DisplayState
********************************************************************************
*
* Summary:
*  Get current CapSense State
*
* Parameters:  
*   None
* Return: 
*   uint32: Position on slider
*
*******************************************************************************/
uint32 CapSense_DisplayState(void)
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
            uint32 myInt = (uint32)curPos << SLIDER_POS_TO_COMPARE_SHIFT; 
            return myInt;
        }
    }
    //not moved
    return -1;
}
//_________________________________________________________

/*******************************************************************************
* Function Name: CapSense_Refresh
********************************************************************************
*
* Summary:
*  Refresh CapSense
*
* Parameters:  
*   None
* Return: 
*   uint32: Position on slider
*
*******************************************************************************/
int32 CapSense_Refresh(void)
{
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
//_________________________________________________________

//[] END OF FILE
