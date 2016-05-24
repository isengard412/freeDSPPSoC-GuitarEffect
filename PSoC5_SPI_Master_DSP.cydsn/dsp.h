/*******************************************************************************
* File Name: dsp.h
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Interaction with FreeDSP Insanity
*
*******************************************************************************/

#if !defined(CY_DSP_H)
#define CY_DSP_H

#include <project.h>
#include "ADAU1452Registers.h"
#include "stdio.h"
#include "spimaster.h"
//#include "programdata.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif


/*******************************************************************************
* Function Name: DSPinit
********************************************************************************
*
* Summary:
*  Initialize communication
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DSPinit();

/*******************************************************************************
* Function Name: DSPisReady
********************************************************************************
*
* Summary:
*  Sending data to DSP
*
* Parameters:
*  None.
*
* Return:
*  uint8 ready
*
*******************************************************************************/
uint8 DSPisReady();

/*******************************************************************************
* Function Name: DSPwrite
********************************************************************************
*
* Summary:
*  Sending data to DSP
*
* Parameters:
*  uint8  chipaddress + R/(not W)
*  uint16 address
*  uint8  data
*
* Return:
*  None.
*
*******************************************************************************/
void DSPwrite(uint16 address,uint8* data, uint16 datasize);

/*******************************************************************************
* Function Name: DSPwriteWord
********************************************************************************
*
* Summary:
*  Sending word of data to DSP
*
* Parameters:
*  uint16 address
*  uint16 word of data
*
* Return:
*  None.
*
*******************************************************************************/
void DSPwriteWord(uint16 address,uint16 data);

/*******************************************************************************
* Function Name: DSPread
********************************************************************************
*
* Summary:
*  Reading data from DSP
*
* Parameters:
*  uint16 address
*  uint8* datatarget
*  uint16 datasize
*
* Return:
*  uint8* array
*
*******************************************************************************/
void DSPread(uint16 address, uint8* datatarget, uint16 datasize);


#endif /* (CY_DSP_H) */

/* [] END OF FILE */
