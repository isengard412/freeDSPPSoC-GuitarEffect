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
#include "ADAU1701Registers.h"
#include "stdio.h"
#include "spimaster.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

#define E2PROM_HEX_SIZE 544
#define CHIPADDRESS 0x00
#define WRITE_DSP 0x00
#define READ_DSP 0x01

#define VOLUME0_ADDR  0x0000 
#define VOLUME1_ADDR  0x0001

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


#endif /* (CY_DSP_H) */

/* [] END OF FILE */
