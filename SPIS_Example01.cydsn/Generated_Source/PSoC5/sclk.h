/*******************************************************************************
* File Name: sclk.h  
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

#if !defined(CY_PINS_sclk_H) /* Pins sclk_H */
#define CY_PINS_sclk_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "sclk_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 sclk__PORT == 15 && ((sclk__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    sclk_Write(uint8 value);
void    sclk_SetDriveMode(uint8 mode);
uint8   sclk_ReadDataReg(void);
uint8   sclk_Read(void);
void    sclk_SetInterruptMode(uint16 position, uint16 mode);
uint8   sclk_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the sclk_SetDriveMode() function.
     *  @{
     */
        #define sclk_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define sclk_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define sclk_DM_RES_UP          PIN_DM_RES_UP
        #define sclk_DM_RES_DWN         PIN_DM_RES_DWN
        #define sclk_DM_OD_LO           PIN_DM_OD_LO
        #define sclk_DM_OD_HI           PIN_DM_OD_HI
        #define sclk_DM_STRONG          PIN_DM_STRONG
        #define sclk_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define sclk_MASK               sclk__MASK
#define sclk_SHIFT              sclk__SHIFT
#define sclk_WIDTH              1u

/* Interrupt constants */
#if defined(sclk__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sclk_SetInterruptMode() function.
     *  @{
     */
        #define sclk_INTR_NONE      (uint16)(0x0000u)
        #define sclk_INTR_RISING    (uint16)(0x0001u)
        #define sclk_INTR_FALLING   (uint16)(0x0002u)
        #define sclk_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define sclk_INTR_MASK      (0x01u) 
#endif /* (sclk__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sclk_PS                     (* (reg8 *) sclk__PS)
/* Data Register */
#define sclk_DR                     (* (reg8 *) sclk__DR)
/* Port Number */
#define sclk_PRT_NUM                (* (reg8 *) sclk__PRT) 
/* Connect to Analog Globals */                                                  
#define sclk_AG                     (* (reg8 *) sclk__AG)                       
/* Analog MUX bux enable */
#define sclk_AMUX                   (* (reg8 *) sclk__AMUX) 
/* Bidirectional Enable */                                                        
#define sclk_BIE                    (* (reg8 *) sclk__BIE)
/* Bit-mask for Aliased Register Access */
#define sclk_BIT_MASK               (* (reg8 *) sclk__BIT_MASK)
/* Bypass Enable */
#define sclk_BYP                    (* (reg8 *) sclk__BYP)
/* Port wide control signals */                                                   
#define sclk_CTL                    (* (reg8 *) sclk__CTL)
/* Drive Modes */
#define sclk_DM0                    (* (reg8 *) sclk__DM0) 
#define sclk_DM1                    (* (reg8 *) sclk__DM1)
#define sclk_DM2                    (* (reg8 *) sclk__DM2) 
/* Input Buffer Disable Override */
#define sclk_INP_DIS                (* (reg8 *) sclk__INP_DIS)
/* LCD Common or Segment Drive */
#define sclk_LCD_COM_SEG            (* (reg8 *) sclk__LCD_COM_SEG)
/* Enable Segment LCD */
#define sclk_LCD_EN                 (* (reg8 *) sclk__LCD_EN)
/* Slew Rate Control */
#define sclk_SLW                    (* (reg8 *) sclk__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define sclk_PRTDSI__CAPS_SEL       (* (reg8 *) sclk__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define sclk_PRTDSI__DBL_SYNC_IN    (* (reg8 *) sclk__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define sclk_PRTDSI__OE_SEL0        (* (reg8 *) sclk__PRTDSI__OE_SEL0) 
#define sclk_PRTDSI__OE_SEL1        (* (reg8 *) sclk__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define sclk_PRTDSI__OUT_SEL0       (* (reg8 *) sclk__PRTDSI__OUT_SEL0) 
#define sclk_PRTDSI__OUT_SEL1       (* (reg8 *) sclk__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define sclk_PRTDSI__SYNC_OUT       (* (reg8 *) sclk__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(sclk__SIO_CFG)
    #define sclk_SIO_HYST_EN        (* (reg8 *) sclk__SIO_HYST_EN)
    #define sclk_SIO_REG_HIFREQ     (* (reg8 *) sclk__SIO_REG_HIFREQ)
    #define sclk_SIO_CFG            (* (reg8 *) sclk__SIO_CFG)
    #define sclk_SIO_DIFF           (* (reg8 *) sclk__SIO_DIFF)
#endif /* (sclk__SIO_CFG) */

/* Interrupt Registers */
#if defined(sclk__INTSTAT)
    #define sclk_INTSTAT            (* (reg8 *) sclk__INTSTAT)
    #define sclk_SNAP               (* (reg8 *) sclk__SNAP)
    
	#define sclk_0_INTTYPE_REG 		(* (reg8 *) sclk__0__INTTYPE)
#endif /* (sclk__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_sclk_H */


/* [] END OF FILE */
