/*******************************************************************************
* File Name: RFVoltage.h  
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

#if !defined(CY_PINS_RFVoltage_H) /* Pins RFVoltage_H */
#define CY_PINS_RFVoltage_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RFVoltage_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RFVoltage__PORT == 15 && ((RFVoltage__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RFVoltage_Write(uint8 value);
void    RFVoltage_SetDriveMode(uint8 mode);
uint8   RFVoltage_ReadDataReg(void);
uint8   RFVoltage_Read(void);
void    RFVoltage_SetInterruptMode(uint16 position, uint16 mode);
uint8   RFVoltage_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RFVoltage_SetDriveMode() function.
     *  @{
     */
        #define RFVoltage_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RFVoltage_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RFVoltage_DM_RES_UP          PIN_DM_RES_UP
        #define RFVoltage_DM_RES_DWN         PIN_DM_RES_DWN
        #define RFVoltage_DM_OD_LO           PIN_DM_OD_LO
        #define RFVoltage_DM_OD_HI           PIN_DM_OD_HI
        #define RFVoltage_DM_STRONG          PIN_DM_STRONG
        #define RFVoltage_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RFVoltage_MASK               RFVoltage__MASK
#define RFVoltage_SHIFT              RFVoltage__SHIFT
#define RFVoltage_WIDTH              1u

/* Interrupt constants */
#if defined(RFVoltage__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RFVoltage_SetInterruptMode() function.
     *  @{
     */
        #define RFVoltage_INTR_NONE      (uint16)(0x0000u)
        #define RFVoltage_INTR_RISING    (uint16)(0x0001u)
        #define RFVoltage_INTR_FALLING   (uint16)(0x0002u)
        #define RFVoltage_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RFVoltage_INTR_MASK      (0x01u) 
#endif /* (RFVoltage__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RFVoltage_PS                     (* (reg8 *) RFVoltage__PS)
/* Data Register */
#define RFVoltage_DR                     (* (reg8 *) RFVoltage__DR)
/* Port Number */
#define RFVoltage_PRT_NUM                (* (reg8 *) RFVoltage__PRT) 
/* Connect to Analog Globals */                                                  
#define RFVoltage_AG                     (* (reg8 *) RFVoltage__AG)                       
/* Analog MUX bux enable */
#define RFVoltage_AMUX                   (* (reg8 *) RFVoltage__AMUX) 
/* Bidirectional Enable */                                                        
#define RFVoltage_BIE                    (* (reg8 *) RFVoltage__BIE)
/* Bit-mask for Aliased Register Access */
#define RFVoltage_BIT_MASK               (* (reg8 *) RFVoltage__BIT_MASK)
/* Bypass Enable */
#define RFVoltage_BYP                    (* (reg8 *) RFVoltage__BYP)
/* Port wide control signals */                                                   
#define RFVoltage_CTL                    (* (reg8 *) RFVoltage__CTL)
/* Drive Modes */
#define RFVoltage_DM0                    (* (reg8 *) RFVoltage__DM0) 
#define RFVoltage_DM1                    (* (reg8 *) RFVoltage__DM1)
#define RFVoltage_DM2                    (* (reg8 *) RFVoltage__DM2) 
/* Input Buffer Disable Override */
#define RFVoltage_INP_DIS                (* (reg8 *) RFVoltage__INP_DIS)
/* LCD Common or Segment Drive */
#define RFVoltage_LCD_COM_SEG            (* (reg8 *) RFVoltage__LCD_COM_SEG)
/* Enable Segment LCD */
#define RFVoltage_LCD_EN                 (* (reg8 *) RFVoltage__LCD_EN)
/* Slew Rate Control */
#define RFVoltage_SLW                    (* (reg8 *) RFVoltage__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RFVoltage_PRTDSI__CAPS_SEL       (* (reg8 *) RFVoltage__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RFVoltage_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RFVoltage__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RFVoltage_PRTDSI__OE_SEL0        (* (reg8 *) RFVoltage__PRTDSI__OE_SEL0) 
#define RFVoltage_PRTDSI__OE_SEL1        (* (reg8 *) RFVoltage__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RFVoltage_PRTDSI__OUT_SEL0       (* (reg8 *) RFVoltage__PRTDSI__OUT_SEL0) 
#define RFVoltage_PRTDSI__OUT_SEL1       (* (reg8 *) RFVoltage__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RFVoltage_PRTDSI__SYNC_OUT       (* (reg8 *) RFVoltage__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RFVoltage__SIO_CFG)
    #define RFVoltage_SIO_HYST_EN        (* (reg8 *) RFVoltage__SIO_HYST_EN)
    #define RFVoltage_SIO_REG_HIFREQ     (* (reg8 *) RFVoltage__SIO_REG_HIFREQ)
    #define RFVoltage_SIO_CFG            (* (reg8 *) RFVoltage__SIO_CFG)
    #define RFVoltage_SIO_DIFF           (* (reg8 *) RFVoltage__SIO_DIFF)
#endif /* (RFVoltage__SIO_CFG) */

/* Interrupt Registers */
#if defined(RFVoltage__INTSTAT)
    #define RFVoltage_INTSTAT            (* (reg8 *) RFVoltage__INTSTAT)
    #define RFVoltage_SNAP               (* (reg8 *) RFVoltage__SNAP)
    
	#define RFVoltage_0_INTTYPE_REG 		(* (reg8 *) RFVoltage__0__INTTYPE)
#endif /* (RFVoltage__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RFVoltage_H */


/* [] END OF FILE */
