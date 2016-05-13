/*******************************************************************************
* File Name: Dev_GND.h  
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

#if !defined(CY_PINS_Dev_GND_H) /* Pins Dev_GND_H */
#define CY_PINS_Dev_GND_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dev_GND_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dev_GND__PORT == 15 && ((Dev_GND__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dev_GND_Write(uint8 value);
void    Dev_GND_SetDriveMode(uint8 mode);
uint8   Dev_GND_ReadDataReg(void);
uint8   Dev_GND_Read(void);
void    Dev_GND_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dev_GND_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dev_GND_SetDriveMode() function.
     *  @{
     */
        #define Dev_GND_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dev_GND_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dev_GND_DM_RES_UP          PIN_DM_RES_UP
        #define Dev_GND_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dev_GND_DM_OD_LO           PIN_DM_OD_LO
        #define Dev_GND_DM_OD_HI           PIN_DM_OD_HI
        #define Dev_GND_DM_STRONG          PIN_DM_STRONG
        #define Dev_GND_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dev_GND_MASK               Dev_GND__MASK
#define Dev_GND_SHIFT              Dev_GND__SHIFT
#define Dev_GND_WIDTH              1u

/* Interrupt constants */
#if defined(Dev_GND__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dev_GND_SetInterruptMode() function.
     *  @{
     */
        #define Dev_GND_INTR_NONE      (uint16)(0x0000u)
        #define Dev_GND_INTR_RISING    (uint16)(0x0001u)
        #define Dev_GND_INTR_FALLING   (uint16)(0x0002u)
        #define Dev_GND_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dev_GND_INTR_MASK      (0x01u) 
#endif /* (Dev_GND__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dev_GND_PS                     (* (reg8 *) Dev_GND__PS)
/* Data Register */
#define Dev_GND_DR                     (* (reg8 *) Dev_GND__DR)
/* Port Number */
#define Dev_GND_PRT_NUM                (* (reg8 *) Dev_GND__PRT) 
/* Connect to Analog Globals */                                                  
#define Dev_GND_AG                     (* (reg8 *) Dev_GND__AG)                       
/* Analog MUX bux enable */
#define Dev_GND_AMUX                   (* (reg8 *) Dev_GND__AMUX) 
/* Bidirectional Enable */                                                        
#define Dev_GND_BIE                    (* (reg8 *) Dev_GND__BIE)
/* Bit-mask for Aliased Register Access */
#define Dev_GND_BIT_MASK               (* (reg8 *) Dev_GND__BIT_MASK)
/* Bypass Enable */
#define Dev_GND_BYP                    (* (reg8 *) Dev_GND__BYP)
/* Port wide control signals */                                                   
#define Dev_GND_CTL                    (* (reg8 *) Dev_GND__CTL)
/* Drive Modes */
#define Dev_GND_DM0                    (* (reg8 *) Dev_GND__DM0) 
#define Dev_GND_DM1                    (* (reg8 *) Dev_GND__DM1)
#define Dev_GND_DM2                    (* (reg8 *) Dev_GND__DM2) 
/* Input Buffer Disable Override */
#define Dev_GND_INP_DIS                (* (reg8 *) Dev_GND__INP_DIS)
/* LCD Common or Segment Drive */
#define Dev_GND_LCD_COM_SEG            (* (reg8 *) Dev_GND__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dev_GND_LCD_EN                 (* (reg8 *) Dev_GND__LCD_EN)
/* Slew Rate Control */
#define Dev_GND_SLW                    (* (reg8 *) Dev_GND__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dev_GND_PRTDSI__CAPS_SEL       (* (reg8 *) Dev_GND__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dev_GND_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dev_GND__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dev_GND_PRTDSI__OE_SEL0        (* (reg8 *) Dev_GND__PRTDSI__OE_SEL0) 
#define Dev_GND_PRTDSI__OE_SEL1        (* (reg8 *) Dev_GND__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dev_GND_PRTDSI__OUT_SEL0       (* (reg8 *) Dev_GND__PRTDSI__OUT_SEL0) 
#define Dev_GND_PRTDSI__OUT_SEL1       (* (reg8 *) Dev_GND__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dev_GND_PRTDSI__SYNC_OUT       (* (reg8 *) Dev_GND__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dev_GND__SIO_CFG)
    #define Dev_GND_SIO_HYST_EN        (* (reg8 *) Dev_GND__SIO_HYST_EN)
    #define Dev_GND_SIO_REG_HIFREQ     (* (reg8 *) Dev_GND__SIO_REG_HIFREQ)
    #define Dev_GND_SIO_CFG            (* (reg8 *) Dev_GND__SIO_CFG)
    #define Dev_GND_SIO_DIFF           (* (reg8 *) Dev_GND__SIO_DIFF)
#endif /* (Dev_GND__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dev_GND__INTSTAT)
    #define Dev_GND_INTSTAT            (* (reg8 *) Dev_GND__INTSTAT)
    #define Dev_GND_SNAP               (* (reg8 *) Dev_GND__SNAP)
    
	#define Dev_GND_0_INTTYPE_REG 		(* (reg8 *) Dev_GND__0__INTTYPE)
#endif /* (Dev_GND__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dev_GND_H */


/* [] END OF FILE */
