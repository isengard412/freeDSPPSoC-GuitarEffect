/*******************************************************************************
* File Name: MOSI_S.h  
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

#if !defined(CY_PINS_MOSI_S_H) /* Pins MOSI_S_H */
#define CY_PINS_MOSI_S_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOSI_S_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOSI_S__PORT == 15 && ((MOSI_S__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MOSI_S_Write(uint8 value);
void    MOSI_S_SetDriveMode(uint8 mode);
uint8   MOSI_S_ReadDataReg(void);
uint8   MOSI_S_Read(void);
void    MOSI_S_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOSI_S_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MOSI_S_SetDriveMode() function.
     *  @{
     */
        #define MOSI_S_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MOSI_S_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MOSI_S_DM_RES_UP          PIN_DM_RES_UP
        #define MOSI_S_DM_RES_DWN         PIN_DM_RES_DWN
        #define MOSI_S_DM_OD_LO           PIN_DM_OD_LO
        #define MOSI_S_DM_OD_HI           PIN_DM_OD_HI
        #define MOSI_S_DM_STRONG          PIN_DM_STRONG
        #define MOSI_S_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MOSI_S_MASK               MOSI_S__MASK
#define MOSI_S_SHIFT              MOSI_S__SHIFT
#define MOSI_S_WIDTH              1u

/* Interrupt constants */
#if defined(MOSI_S__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOSI_S_SetInterruptMode() function.
     *  @{
     */
        #define MOSI_S_INTR_NONE      (uint16)(0x0000u)
        #define MOSI_S_INTR_RISING    (uint16)(0x0001u)
        #define MOSI_S_INTR_FALLING   (uint16)(0x0002u)
        #define MOSI_S_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MOSI_S_INTR_MASK      (0x01u) 
#endif /* (MOSI_S__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOSI_S_PS                     (* (reg8 *) MOSI_S__PS)
/* Data Register */
#define MOSI_S_DR                     (* (reg8 *) MOSI_S__DR)
/* Port Number */
#define MOSI_S_PRT_NUM                (* (reg8 *) MOSI_S__PRT) 
/* Connect to Analog Globals */                                                  
#define MOSI_S_AG                     (* (reg8 *) MOSI_S__AG)                       
/* Analog MUX bux enable */
#define MOSI_S_AMUX                   (* (reg8 *) MOSI_S__AMUX) 
/* Bidirectional Enable */                                                        
#define MOSI_S_BIE                    (* (reg8 *) MOSI_S__BIE)
/* Bit-mask for Aliased Register Access */
#define MOSI_S_BIT_MASK               (* (reg8 *) MOSI_S__BIT_MASK)
/* Bypass Enable */
#define MOSI_S_BYP                    (* (reg8 *) MOSI_S__BYP)
/* Port wide control signals */                                                   
#define MOSI_S_CTL                    (* (reg8 *) MOSI_S__CTL)
/* Drive Modes */
#define MOSI_S_DM0                    (* (reg8 *) MOSI_S__DM0) 
#define MOSI_S_DM1                    (* (reg8 *) MOSI_S__DM1)
#define MOSI_S_DM2                    (* (reg8 *) MOSI_S__DM2) 
/* Input Buffer Disable Override */
#define MOSI_S_INP_DIS                (* (reg8 *) MOSI_S__INP_DIS)
/* LCD Common or Segment Drive */
#define MOSI_S_LCD_COM_SEG            (* (reg8 *) MOSI_S__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOSI_S_LCD_EN                 (* (reg8 *) MOSI_S__LCD_EN)
/* Slew Rate Control */
#define MOSI_S_SLW                    (* (reg8 *) MOSI_S__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOSI_S_PRTDSI__CAPS_SEL       (* (reg8 *) MOSI_S__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOSI_S_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOSI_S__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOSI_S_PRTDSI__OE_SEL0        (* (reg8 *) MOSI_S__PRTDSI__OE_SEL0) 
#define MOSI_S_PRTDSI__OE_SEL1        (* (reg8 *) MOSI_S__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOSI_S_PRTDSI__OUT_SEL0       (* (reg8 *) MOSI_S__PRTDSI__OUT_SEL0) 
#define MOSI_S_PRTDSI__OUT_SEL1       (* (reg8 *) MOSI_S__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOSI_S_PRTDSI__SYNC_OUT       (* (reg8 *) MOSI_S__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MOSI_S__SIO_CFG)
    #define MOSI_S_SIO_HYST_EN        (* (reg8 *) MOSI_S__SIO_HYST_EN)
    #define MOSI_S_SIO_REG_HIFREQ     (* (reg8 *) MOSI_S__SIO_REG_HIFREQ)
    #define MOSI_S_SIO_CFG            (* (reg8 *) MOSI_S__SIO_CFG)
    #define MOSI_S_SIO_DIFF           (* (reg8 *) MOSI_S__SIO_DIFF)
#endif /* (MOSI_S__SIO_CFG) */

/* Interrupt Registers */
#if defined(MOSI_S__INTSTAT)
    #define MOSI_S_INTSTAT            (* (reg8 *) MOSI_S__INTSTAT)
    #define MOSI_S_SNAP               (* (reg8 *) MOSI_S__SNAP)
    
	#define MOSI_S_0_INTTYPE_REG 		(* (reg8 *) MOSI_S__0__INTTYPE)
#endif /* (MOSI_S__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOSI_S_H */


/* [] END OF FILE */
