/*******************************************************************************
* File Name: SPI_Clock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_SPI_Clock_H)
#define CY_CLOCK_SPI_Clock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void SPI_Clock_Start(void) ;
void SPI_Clock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SPI_Clock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SPI_Clock_StandbyPower(uint8 state) ;
void SPI_Clock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SPI_Clock_GetDividerRegister(void) ;
void SPI_Clock_SetModeRegister(uint8 modeBitMask) ;
void SPI_Clock_ClearModeRegister(uint8 modeBitMask) ;
uint8 SPI_Clock_GetModeRegister(void) ;
void SPI_Clock_SetSourceRegister(uint8 clkSource) ;
uint8 SPI_Clock_GetSourceRegister(void) ;
#if defined(SPI_Clock__CFG3)
void SPI_Clock_SetPhaseRegister(uint8 clkPhase) ;
uint8 SPI_Clock_GetPhaseRegister(void) ;
#endif /* defined(SPI_Clock__CFG3) */

#define SPI_Clock_Enable()                       SPI_Clock_Start()
#define SPI_Clock_Disable()                      SPI_Clock_Stop()
#define SPI_Clock_SetDivider(clkDivider)         SPI_Clock_SetDividerRegister(clkDivider, 1u)
#define SPI_Clock_SetDividerValue(clkDivider)    SPI_Clock_SetDividerRegister((clkDivider) - 1u, 1u)
#define SPI_Clock_SetMode(clkMode)               SPI_Clock_SetModeRegister(clkMode)
#define SPI_Clock_SetSource(clkSource)           SPI_Clock_SetSourceRegister(clkSource)
#if defined(SPI_Clock__CFG3)
#define SPI_Clock_SetPhase(clkPhase)             SPI_Clock_SetPhaseRegister(clkPhase)
#define SPI_Clock_SetPhaseValue(clkPhase)        SPI_Clock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SPI_Clock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SPI_Clock_CLKEN              (* (reg8 *) SPI_Clock__PM_ACT_CFG)
#define SPI_Clock_CLKEN_PTR          ((reg8 *) SPI_Clock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SPI_Clock_CLKSTBY            (* (reg8 *) SPI_Clock__PM_STBY_CFG)
#define SPI_Clock_CLKSTBY_PTR        ((reg8 *) SPI_Clock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SPI_Clock_DIV_LSB            (* (reg8 *) SPI_Clock__CFG0)
#define SPI_Clock_DIV_LSB_PTR        ((reg8 *) SPI_Clock__CFG0)
#define SPI_Clock_DIV_PTR            ((reg16 *) SPI_Clock__CFG0)

/* Clock MSB divider configuration register. */
#define SPI_Clock_DIV_MSB            (* (reg8 *) SPI_Clock__CFG1)
#define SPI_Clock_DIV_MSB_PTR        ((reg8 *) SPI_Clock__CFG1)

/* Mode and source configuration register */
#define SPI_Clock_MOD_SRC            (* (reg8 *) SPI_Clock__CFG2)
#define SPI_Clock_MOD_SRC_PTR        ((reg8 *) SPI_Clock__CFG2)

#if defined(SPI_Clock__CFG3)
/* Analog clock phase configuration register */
#define SPI_Clock_PHASE              (* (reg8 *) SPI_Clock__CFG3)
#define SPI_Clock_PHASE_PTR          ((reg8 *) SPI_Clock__CFG3)
#endif /* defined(SPI_Clock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SPI_Clock_CLKEN_MASK         SPI_Clock__PM_ACT_MSK
#define SPI_Clock_CLKSTBY_MASK       SPI_Clock__PM_STBY_MSK

/* CFG2 field masks */
#define SPI_Clock_SRC_SEL_MSK        SPI_Clock__CFG2_SRC_SEL_MASK
#define SPI_Clock_MODE_MASK          (~(SPI_Clock_SRC_SEL_MSK))

#if defined(SPI_Clock__CFG3)
/* CFG3 phase mask */
#define SPI_Clock_PHASE_MASK         SPI_Clock__CFG3_PHASE_DLY_MASK
#endif /* defined(SPI_Clock__CFG3) */

#endif /* CY_CLOCK_SPI_Clock_H */


/* [] END OF FILE */
