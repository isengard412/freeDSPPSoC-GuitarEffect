/*******************************************************************************
* File Name: clock.h
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

#if !defined(CY_CLOCK_clock_H)
#define CY_CLOCK_clock_H

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

void clock_Start(void) ;
void clock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void clock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void clock_StandbyPower(uint8 state) ;
void clock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 clock_GetDividerRegister(void) ;
void clock_SetModeRegister(uint8 modeBitMask) ;
void clock_ClearModeRegister(uint8 modeBitMask) ;
uint8 clock_GetModeRegister(void) ;
void clock_SetSourceRegister(uint8 clkSource) ;
uint8 clock_GetSourceRegister(void) ;
#if defined(clock__CFG3)
void clock_SetPhaseRegister(uint8 clkPhase) ;
uint8 clock_GetPhaseRegister(void) ;
#endif /* defined(clock__CFG3) */

#define clock_Enable()                       clock_Start()
#define clock_Disable()                      clock_Stop()
#define clock_SetDivider(clkDivider)         clock_SetDividerRegister(clkDivider, 1u)
#define clock_SetDividerValue(clkDivider)    clock_SetDividerRegister((clkDivider) - 1u, 1u)
#define clock_SetMode(clkMode)               clock_SetModeRegister(clkMode)
#define clock_SetSource(clkSource)           clock_SetSourceRegister(clkSource)
#if defined(clock__CFG3)
#define clock_SetPhase(clkPhase)             clock_SetPhaseRegister(clkPhase)
#define clock_SetPhaseValue(clkPhase)        clock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(clock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define clock_CLKEN              (* (reg8 *) clock__PM_ACT_CFG)
#define clock_CLKEN_PTR          ((reg8 *) clock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define clock_CLKSTBY            (* (reg8 *) clock__PM_STBY_CFG)
#define clock_CLKSTBY_PTR        ((reg8 *) clock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define clock_DIV_LSB            (* (reg8 *) clock__CFG0)
#define clock_DIV_LSB_PTR        ((reg8 *) clock__CFG0)
#define clock_DIV_PTR            ((reg16 *) clock__CFG0)

/* Clock MSB divider configuration register. */
#define clock_DIV_MSB            (* (reg8 *) clock__CFG1)
#define clock_DIV_MSB_PTR        ((reg8 *) clock__CFG1)

/* Mode and source configuration register */
#define clock_MOD_SRC            (* (reg8 *) clock__CFG2)
#define clock_MOD_SRC_PTR        ((reg8 *) clock__CFG2)

#if defined(clock__CFG3)
/* Analog clock phase configuration register */
#define clock_PHASE              (* (reg8 *) clock__CFG3)
#define clock_PHASE_PTR          ((reg8 *) clock__CFG3)
#endif /* defined(clock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define clock_CLKEN_MASK         clock__PM_ACT_MSK
#define clock_CLKSTBY_MASK       clock__PM_STBY_MSK

/* CFG2 field masks */
#define clock_SRC_SEL_MSK        clock__CFG2_SRC_SEL_MASK
#define clock_MODE_MASK          (~(clock_SRC_SEL_MSK))

#if defined(clock__CFG3)
/* CFG3 phase mask */
#define clock_PHASE_MASK         clock__CFG3_PHASE_DLY_MASK
#endif /* defined(clock__CFG3) */

#endif /* CY_CLOCK_clock_H */


/* [] END OF FILE */
