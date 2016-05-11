/*******************************************************************************
* File Name: AMuxSeq.c
* Version 1.80
*
*  Description:
*    This file contains functions for the AMuxSeq.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "AMuxSeq.h"

uint8 AMuxSeq_initVar = 0u;


/*******************************************************************************
* Function Name: AMuxSeq_Start
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMuxSeq_Start(void)
{
    AMuxSeq_DisconnectAll();
    AMuxSeq_initVar = 1u;
}


/*******************************************************************************
* Function Name: AMuxSeq_Init
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMuxSeq_Init(void)
{
    AMuxSeq_DisconnectAll();
}


/*******************************************************************************
* Function Name: AMuxSeq_Stop
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMuxSeq_Stop(void)
{
    AMuxSeq_DisconnectAll();
}

#if (AMuxSeq_MUXTYPE == AMuxSeq_MUX_DIFF)

/*******************************************************************************
* Function Name: AMuxSeq_Next
********************************************************************************
* Summary:
*  Disconnects the previous channel and connects the next one in the sequence.
*  When Next is called for the first time after Init, Start, Enable, Stop, or
*  DisconnectAll, it connects channel 0.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMuxSeq_Next(void)
{
    AMuxSeq_CYAMUXSIDE_A_Next();
    AMuxSeq_CYAMUXSIDE_B_Next();
}


/*******************************************************************************
* Function Name: AMuxSeq_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels. The next time Next is called, channel
*  0 will be connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMuxSeq_DisconnectAll(void)
{
    AMuxSeq_CYAMUXSIDE_A_DisconnectAll();
    AMuxSeq_CYAMUXSIDE_B_DisconnectAll();
}


/*******************************************************************************
* Function Name: AMuxSeq_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 AMuxSeq_GetChannel(void)
{
    return AMuxSeq_CYAMUXSIDE_A_curChannel;
}

#else

/*******************************************************************************
* Function Name: AMuxSeq_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 AMuxSeq_GetChannel(void)
{
    return AMuxSeq_curChannel;
}

#endif


/* [] END OF FILE */
