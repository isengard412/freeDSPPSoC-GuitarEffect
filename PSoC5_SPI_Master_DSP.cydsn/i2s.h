/*******************************************************************************
* File Name: i2s.h
*
* Version: 0.0
* Author: Lukas Creutzburg
*
* Description:
*   Interaction with FreeDSP Insanity
*
*******************************************************************************/

#if !defined(CY_I2S_H)
#define CY_I2S_H

#include <project.h>

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif


/*******************************************************************************
* Function Name: I2Sinit
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
void I2Sinit();

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
//uint8 DSPisReady();

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
//void DSPwrite(uint16 address,uint8* data, uint16 datasize);

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
//void DSPwriteWord32(uint16 address,uint32 data);

#endif /* (CY_I2S_H) */

/* [] END OF FILE */
