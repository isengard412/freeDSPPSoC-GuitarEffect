/*******************************************************************************
* File Name: dsp.h
*
* Version: 1.1
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
* Function Name: DSPwriteWord32
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
void DSPwriteWord32(uint16 address,uint32 data);

/*******************************************************************************
* Function Name: DSPwriteWord16
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
void DSPwriteWord16(uint16 address,uint16 data);

/*******************************************************************************
* Function Name: DSPsafeLoad
********************************************************************************
*
* Summary:
*  Letting the DSP perform a safeload Operation to prevent clicks
*
* Parameters:
*  uint16 address
*  uint32 word of data
*
* Return:
*  None.
*
*******************************************************************************/
void DSPsafeLoad(uint16 address,uint32 data);

/*******************************************************************************
* Function Name: DSPread32
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
void DSPread32(uint16 address, uint8* datatarget, uint16 datasize);


#endif /* (CY_DSP_H) */

/* [] END OF FILE */
