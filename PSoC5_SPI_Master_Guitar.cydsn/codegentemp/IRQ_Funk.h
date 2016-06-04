/*******************************************************************************
* File Name: IRQ_Funk.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_IRQ_Funk_H) /* Pins IRQ_Funk_H */
#define CY_PINS_IRQ_Funk_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IRQ_Funk_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IRQ_Funk__PORT == 15 && ((IRQ_Funk__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IRQ_Funk_Write(uint8 value);
void    IRQ_Funk_SetDriveMode(uint8 mode);
uint8   IRQ_Funk_ReadDataReg(void);
uint8   IRQ_Funk_Read(void);
void    IRQ_Funk_SetInterruptMode(uint16 position, uint16 mode);
uint8   IRQ_Funk_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IRQ_Funk_SetDriveMode() function.
     *  @{
     */
        #define IRQ_Funk_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IRQ_Funk_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IRQ_Funk_DM_RES_UP          PIN_DM_RES_UP
        #define IRQ_Funk_DM_RES_DWN         PIN_DM_RES_DWN
        #define IRQ_Funk_DM_OD_LO           PIN_DM_OD_LO
        #define IRQ_Funk_DM_OD_HI           PIN_DM_OD_HI
        #define IRQ_Funk_DM_STRONG          PIN_DM_STRONG
        #define IRQ_Funk_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IRQ_Funk_MASK               IRQ_Funk__MASK
#define IRQ_Funk_SHIFT              IRQ_Funk__SHIFT
#define IRQ_Funk_WIDTH              1u

/* Interrupt constants */
#if defined(IRQ_Funk__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IRQ_Funk_SetInterruptMode() function.
     *  @{
     */
        #define IRQ_Funk_INTR_NONE      (uint16)(0x0000u)
        #define IRQ_Funk_INTR_RISING    (uint16)(0x0001u)
        #define IRQ_Funk_INTR_FALLING   (uint16)(0x0002u)
        #define IRQ_Funk_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IRQ_Funk_INTR_MASK      (0x01u) 
#endif /* (IRQ_Funk__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IRQ_Funk_PS                     (* (reg8 *) IRQ_Funk__PS)
/* Data Register */
#define IRQ_Funk_DR                     (* (reg8 *) IRQ_Funk__DR)
/* Port Number */
#define IRQ_Funk_PRT_NUM                (* (reg8 *) IRQ_Funk__PRT) 
/* Connect to Analog Globals */                                                  
#define IRQ_Funk_AG                     (* (reg8 *) IRQ_Funk__AG)                       
/* Analog MUX bux enable */
#define IRQ_Funk_AMUX                   (* (reg8 *) IRQ_Funk__AMUX) 
/* Bidirectional Enable */                                                        
#define IRQ_Funk_BIE                    (* (reg8 *) IRQ_Funk__BIE)
/* Bit-mask for Aliased Register Access */
#define IRQ_Funk_BIT_MASK               (* (reg8 *) IRQ_Funk__BIT_MASK)
/* Bypass Enable */
#define IRQ_Funk_BYP                    (* (reg8 *) IRQ_Funk__BYP)
/* Port wide control signals */                                                   
#define IRQ_Funk_CTL                    (* (reg8 *) IRQ_Funk__CTL)
/* Drive Modes */
#define IRQ_Funk_DM0                    (* (reg8 *) IRQ_Funk__DM0) 
#define IRQ_Funk_DM1                    (* (reg8 *) IRQ_Funk__DM1)
#define IRQ_Funk_DM2                    (* (reg8 *) IRQ_Funk__DM2) 
/* Input Buffer Disable Override */
#define IRQ_Funk_INP_DIS                (* (reg8 *) IRQ_Funk__INP_DIS)
/* LCD Common or Segment Drive */
#define IRQ_Funk_LCD_COM_SEG            (* (reg8 *) IRQ_Funk__LCD_COM_SEG)
/* Enable Segment LCD */
#define IRQ_Funk_LCD_EN                 (* (reg8 *) IRQ_Funk__LCD_EN)
/* Slew Rate Control */
#define IRQ_Funk_SLW                    (* (reg8 *) IRQ_Funk__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IRQ_Funk_PRTDSI__CAPS_SEL       (* (reg8 *) IRQ_Funk__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IRQ_Funk_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IRQ_Funk__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IRQ_Funk_PRTDSI__OE_SEL0        (* (reg8 *) IRQ_Funk__PRTDSI__OE_SEL0) 
#define IRQ_Funk_PRTDSI__OE_SEL1        (* (reg8 *) IRQ_Funk__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IRQ_Funk_PRTDSI__OUT_SEL0       (* (reg8 *) IRQ_Funk__PRTDSI__OUT_SEL0) 
#define IRQ_Funk_PRTDSI__OUT_SEL1       (* (reg8 *) IRQ_Funk__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IRQ_Funk_PRTDSI__SYNC_OUT       (* (reg8 *) IRQ_Funk__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IRQ_Funk__SIO_CFG)
    #define IRQ_Funk_SIO_HYST_EN        (* (reg8 *) IRQ_Funk__SIO_HYST_EN)
    #define IRQ_Funk_SIO_REG_HIFREQ     (* (reg8 *) IRQ_Funk__SIO_REG_HIFREQ)
    #define IRQ_Funk_SIO_CFG            (* (reg8 *) IRQ_Funk__SIO_CFG)
    #define IRQ_Funk_SIO_DIFF           (* (reg8 *) IRQ_Funk__SIO_DIFF)
#endif /* (IRQ_Funk__SIO_CFG) */

/* Interrupt Registers */
#if defined(IRQ_Funk__INTSTAT)
    #define IRQ_Funk_INTSTAT            (* (reg8 *) IRQ_Funk__INTSTAT)
    #define IRQ_Funk_SNAP               (* (reg8 *) IRQ_Funk__SNAP)
    
	#define IRQ_Funk_0_INTTYPE_REG 		(* (reg8 *) IRQ_Funk__0__INTTYPE)
#endif /* (IRQ_Funk__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IRQ_Funk_H */


/* [] END OF FILE */
