/*******************************************************************************
* File Name: NRF24L01.h
*
* Version: 0.0
* Author: Lukas Creutzburg
*
* Description:
*   Funk Modul Interaktion
*
*******************************************************************************/

#if !defined(CY_NRF24L01_H)
#define CY_NRF24L01_H

#include <project.h>
#include "spimaster.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif


/*******************************************************************************
* Function Name: NRF24L01init
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
void NRF24L01init();

/*******************************************************************************
* Function Name: NRF24L01GetReg
********************************************************************************
*
* Summary:
*  Getting data from RX
*
* Parameters:
*  uint8 register
*
* Return:
*  uint8 data
*
*******************************************************************************/
uint16 NRF24L01readReg(uint8 addressfivebit);
void NRF24L01writeReg(uint8 fivebit);

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

#endif /* (CY_NRF24L01_H) */

/* [] END OF FILE */
