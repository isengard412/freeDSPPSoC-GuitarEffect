/*******************************************************************************
* File Name: ss.h  
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

#if !defined(CY_PINS_ss_H) /* Pins ss_H */
#define CY_PINS_ss_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ss_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ss__PORT == 15 && ((ss__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ss_Write(uint8 value);
void    ss_SetDriveMode(uint8 mode);
uint8   ss_ReadDataReg(void);
uint8   ss_Read(void);
void    ss_SetInterruptMode(uint16 position, uint16 mode);
uint8   ss_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ss_SetDriveMode() function.
     *  @{
     */
        #define ss_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ss_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ss_DM_RES_UP          PIN_DM_RES_UP
        #define ss_DM_RES_DWN         PIN_DM_RES_DWN
        #define ss_DM_OD_LO           PIN_DM_OD_LO
        #define ss_DM_OD_HI           PIN_DM_OD_HI
        #define ss_DM_STRONG          PIN_DM_STRONG
        #define ss_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ss_MASK               ss__MASK
#define ss_SHIFT              ss__SHIFT
#define ss_WIDTH              1u

/* Interrupt constants */
#if defined(ss__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ss_SetInterruptMode() function.
     *  @{
     */
        #define ss_INTR_NONE      (uint16)(0x0000u)
        #define ss_INTR_RISING    (uint16)(0x0001u)
        #define ss_INTR_FALLING   (uint16)(0x0002u)
        #define ss_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ss_INTR_MASK      (0x01u) 
#endif /* (ss__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ss_PS                     (* (reg8 *) ss__PS)
/* Data Register */
#define ss_DR                     (* (reg8 *) ss__DR)
/* Port Number */
#define ss_PRT_NUM                (* (reg8 *) ss__PRT) 
/* Connect to Analog Globals */                                                  
#define ss_AG                     (* (reg8 *) ss__AG)                       
/* Analog MUX bux enable */
#define ss_AMUX                   (* (reg8 *) ss__AMUX) 
/* Bidirectional Enable */                                                        
#define ss_BIE                    (* (reg8 *) ss__BIE)
/* Bit-mask for Aliased Register Access */
#define ss_BIT_MASK               (* (reg8 *) ss__BIT_MASK)
/* Bypass Enable */
#define ss_BYP                    (* (reg8 *) ss__BYP)
/* Port wide control signals */                                                   
#define ss_CTL                    (* (reg8 *) ss__CTL)
/* Drive Modes */
#define ss_DM0                    (* (reg8 *) ss__DM0) 
#define ss_DM1                    (* (reg8 *) ss__DM1)
#define ss_DM2                    (* (reg8 *) ss__DM2) 
/* Input Buffer Disable Override */
#define ss_INP_DIS                (* (reg8 *) ss__INP_DIS)
/* LCD Common or Segment Drive */
#define ss_LCD_COM_SEG            (* (reg8 *) ss__LCD_COM_SEG)
/* Enable Segment LCD */
#define ss_LCD_EN                 (* (reg8 *) ss__LCD_EN)
/* Slew Rate Control */
#define ss_SLW                    (* (reg8 *) ss__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ss_PRTDSI__CAPS_SEL       (* (reg8 *) ss__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ss_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ss__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ss_PRTDSI__OE_SEL0        (* (reg8 *) ss__PRTDSI__OE_SEL0) 
#define ss_PRTDSI__OE_SEL1        (* (reg8 *) ss__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ss_PRTDSI__OUT_SEL0       (* (reg8 *) ss__PRTDSI__OUT_SEL0) 
#define ss_PRTDSI__OUT_SEL1       (* (reg8 *) ss__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ss_PRTDSI__SYNC_OUT       (* (reg8 *) ss__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ss__SIO_CFG)
    #define ss_SIO_HYST_EN        (* (reg8 *) ss__SIO_HYST_EN)
    #define ss_SIO_REG_HIFREQ     (* (reg8 *) ss__SIO_REG_HIFREQ)
    #define ss_SIO_CFG            (* (reg8 *) ss__SIO_CFG)
    #define ss_SIO_DIFF           (* (reg8 *) ss__SIO_DIFF)
#endif /* (ss__SIO_CFG) */

/* Interrupt Registers */
#if defined(ss__INTSTAT)
    #define ss_INTSTAT            (* (reg8 *) ss__INTSTAT)
    #define ss_SNAP               (* (reg8 *) ss__SNAP)
    
	#define ss_0_INTTYPE_REG 		(* (reg8 *) ss__0__INTTYPE)
#endif /* (ss__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ss_H */


/* [] END OF FILE */
