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
void NRF24L01initRX();
void NRF24L01initTX();

/*******************************************************************************
* Function Name: NRF24L01ReadReg
********************************************************************************
*
* Summary:
*  Getting data from RX
*
* Parameters:
*  uint8 addressfivebit
*
* Return:
*  uint16 data
*
*******************************************************************************/
uint16 NRF24L01readReg(uint8 addressfivebit);

/*******************************************************************************
* Function Name: NRF24L01GetReg
********************************************************************************
*
*******************************************************************************/
void NRF24L01writeReg(uint8 address, uint8 data);

/*******************************************************************************
* Function Name: DSPwrite
********************************************************************************
*
*******************************************************************************/
void NRF24L01readRXpayload(uint8 numberOfbytes, uint8* target);

/*******************************************************************************
* Function Name: NRF24L01writeTXpayload
********************************************************************************
*
*******************************************************************************/
void NRF24L01writeTXpayload(uint8 numberOfbytes, uint8* data);

#endif /* (CY_NRF24L01_H) */

/* [] END OF FILE */
