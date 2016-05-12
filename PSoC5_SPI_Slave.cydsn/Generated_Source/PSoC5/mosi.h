/*******************************************************************************
* File Name: mosi.h  
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

#if !defined(CY_PINS_mosi_H) /* Pins mosi_H */
#define CY_PINS_mosi_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "mosi_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 mosi__PORT == 15 && ((mosi__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    mosi_Write(uint8 value);
void    mosi_SetDriveMode(uint8 mode);
uint8   mosi_ReadDataReg(void);
uint8   mosi_Read(void);
void    mosi_SetInterruptMode(uint16 position, uint16 mode);
uint8   mosi_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the mosi_SetDriveMode() function.
     *  @{
     */
        #define mosi_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define mosi_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define mosi_DM_RES_UP          PIN_DM_RES_UP
        #define mosi_DM_RES_DWN         PIN_DM_RES_DWN
        #define mosi_DM_OD_LO           PIN_DM_OD_LO
        #define mosi_DM_OD_HI           PIN_DM_OD_HI
        #define mosi_DM_STRONG          PIN_DM_STRONG
        #define mosi_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define mosi_MASK               mosi__MASK
#define mosi_SHIFT              mosi__SHIFT
#define mosi_WIDTH              1u

/* Interrupt constants */
#if defined(mosi__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in mosi_SetInterruptMode() function.
     *  @{
     */
        #define mosi_INTR_NONE      (uint16)(0x0000u)
        #define mosi_INTR_RISING    (uint16)(0x0001u)
        #define mosi_INTR_FALLING   (uint16)(0x0002u)
        #define mosi_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define mosi_INTR_MASK      (0x01u) 
#endif /* (mosi__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define mosi_PS                     (* (reg8 *) mosi__PS)
/* Data Register */
#define mosi_DR                     (* (reg8 *) mosi__DR)
/* Port Number */
#define mosi_PRT_NUM                (* (reg8 *) mosi__PRT) 
/* Connect to Analog Globals */                                                  
#define mosi_AG                     (* (reg8 *) mosi__AG)                       
/* Analog MUX bux enable */
#define mosi_AMUX                   (* (reg8 *) mosi__AMUX) 
/* Bidirectional Enable */                                                        
#define mosi_BIE                    (* (reg8 *) mosi__BIE)
/* Bit-mask for Aliased Register Access */
#define mosi_BIT_MASK               (* (reg8 *) mosi__BIT_MASK)
/* Bypass Enable */
#define mosi_BYP                    (* (reg8 *) mosi__BYP)
/* Port wide control signals */                                                   
#define mosi_CTL                    (* (reg8 *) mosi__CTL)
/* Drive Modes */
#define mosi_DM0                    (* (reg8 *) mosi__DM0) 
#define mosi_DM1                    (* (reg8 *) mosi__DM1)
#define mosi_DM2                    (* (reg8 *) mosi__DM2) 
/* Input Buffer Disable Override */
#define mosi_INP_DIS                (* (reg8 *) mosi__INP_DIS)
/* LCD Common or Segment Drive */
#define mosi_LCD_COM_SEG            (* (reg8 *) mosi__LCD_COM_SEG)
/* Enable Segment LCD */
#define mosi_LCD_EN                 (* (reg8 *) mosi__LCD_EN)
/* Slew Rate Control */
#define mosi_SLW                    (* (reg8 *) mosi__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define mosi_PRTDSI__CAPS_SEL       (* (reg8 *) mosi__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define mosi_PRTDSI__DBL_SYNC_IN    (* (reg8 *) mosi__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define mosi_PRTDSI__OE_SEL0        (* (reg8 *) mosi__PRTDSI__OE_SEL0) 
#define mosi_PRTDSI__OE_SEL1        (* (reg8 *) mosi__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define mosi_PRTDSI__OUT_SEL0       (* (reg8 *) mosi__PRTDSI__OUT_SEL0) 
#define mosi_PRTDSI__OUT_SEL1       (* (reg8 *) mosi__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define mosi_PRTDSI__SYNC_OUT       (* (reg8 *) mosi__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(mosi__SIO_CFG)
    #define mosi_SIO_HYST_EN        (* (reg8 *) mosi__SIO_HYST_EN)
    #define mosi_SIO_REG_HIFREQ     (* (reg8 *) mosi__SIO_REG_HIFREQ)
    #define mosi_SIO_CFG            (* (reg8 *) mosi__SIO_CFG)
    #define mosi_SIO_DIFF           (* (reg8 *) mosi__SIO_DIFF)
#endif /* (mosi__SIO_CFG) */

/* Interrupt Registers */
#if defined(mosi__INTSTAT)
    #define mosi_INTSTAT            (* (reg8 *) mosi__INTSTAT)
    #define mosi_SNAP               (* (reg8 *) mosi__SNAP)
    
	#define mosi_0_INTTYPE_REG 		(* (reg8 *) mosi__0__INTTYPE)
#endif /* (mosi__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_mosi_H */


/* [] END OF FILE */
