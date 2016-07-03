/*******************************************************************************
* File Name: Get_State_Pin.h  
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

#if !defined(CY_PINS_Get_State_Pin_H) /* Pins Get_State_Pin_H */
#define CY_PINS_Get_State_Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Get_State_Pin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Get_State_Pin__PORT == 15 && ((Get_State_Pin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Get_State_Pin_Write(uint8 value);
void    Get_State_Pin_SetDriveMode(uint8 mode);
uint8   Get_State_Pin_ReadDataReg(void);
uint8   Get_State_Pin_Read(void);
void    Get_State_Pin_SetInterruptMode(uint16 position, uint16 mode);
uint8   Get_State_Pin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Get_State_Pin_SetDriveMode() function.
     *  @{
     */
        #define Get_State_Pin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Get_State_Pin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Get_State_Pin_DM_RES_UP          PIN_DM_RES_UP
        #define Get_State_Pin_DM_RES_DWN         PIN_DM_RES_DWN
        #define Get_State_Pin_DM_OD_LO           PIN_DM_OD_LO
        #define Get_State_Pin_DM_OD_HI           PIN_DM_OD_HI
        #define Get_State_Pin_DM_STRONG          PIN_DM_STRONG
        #define Get_State_Pin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Get_State_Pin_MASK               Get_State_Pin__MASK
#define Get_State_Pin_SHIFT              Get_State_Pin__SHIFT
#define Get_State_Pin_WIDTH              1u

/* Interrupt constants */
#if defined(Get_State_Pin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Get_State_Pin_SetInterruptMode() function.
     *  @{
     */
        #define Get_State_Pin_INTR_NONE      (uint16)(0x0000u)
        #define Get_State_Pin_INTR_RISING    (uint16)(0x0001u)
        #define Get_State_Pin_INTR_FALLING   (uint16)(0x0002u)
        #define Get_State_Pin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Get_State_Pin_INTR_MASK      (0x01u) 
#endif /* (Get_State_Pin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Get_State_Pin_PS                     (* (reg8 *) Get_State_Pin__PS)
/* Data Register */
#define Get_State_Pin_DR                     (* (reg8 *) Get_State_Pin__DR)
/* Port Number */
#define Get_State_Pin_PRT_NUM                (* (reg8 *) Get_State_Pin__PRT) 
/* Connect to Analog Globals */                                                  
#define Get_State_Pin_AG                     (* (reg8 *) Get_State_Pin__AG)                       
/* Analog MUX bux enable */
#define Get_State_Pin_AMUX                   (* (reg8 *) Get_State_Pin__AMUX) 
/* Bidirectional Enable */                                                        
#define Get_State_Pin_BIE                    (* (reg8 *) Get_State_Pin__BIE)
/* Bit-mask for Aliased Register Access */
#define Get_State_Pin_BIT_MASK               (* (reg8 *) Get_State_Pin__BIT_MASK)
/* Bypass Enable */
#define Get_State_Pin_BYP                    (* (reg8 *) Get_State_Pin__BYP)
/* Port wide control signals */                                                   
#define Get_State_Pin_CTL                    (* (reg8 *) Get_State_Pin__CTL)
/* Drive Modes */
#define Get_State_Pin_DM0                    (* (reg8 *) Get_State_Pin__DM0) 
#define Get_State_Pin_DM1                    (* (reg8 *) Get_State_Pin__DM1)
#define Get_State_Pin_DM2                    (* (reg8 *) Get_State_Pin__DM2) 
/* Input Buffer Disable Override */
#define Get_State_Pin_INP_DIS                (* (reg8 *) Get_State_Pin__INP_DIS)
/* LCD Common or Segment Drive */
#define Get_State_Pin_LCD_COM_SEG            (* (reg8 *) Get_State_Pin__LCD_COM_SEG)
/* Enable Segment LCD */
#define Get_State_Pin_LCD_EN                 (* (reg8 *) Get_State_Pin__LCD_EN)
/* Slew Rate Control */
#define Get_State_Pin_SLW                    (* (reg8 *) Get_State_Pin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Get_State_Pin_PRTDSI__CAPS_SEL       (* (reg8 *) Get_State_Pin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Get_State_Pin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Get_State_Pin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Get_State_Pin_PRTDSI__OE_SEL0        (* (reg8 *) Get_State_Pin__PRTDSI__OE_SEL0) 
#define Get_State_Pin_PRTDSI__OE_SEL1        (* (reg8 *) Get_State_Pin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Get_State_Pin_PRTDSI__OUT_SEL0       (* (reg8 *) Get_State_Pin__PRTDSI__OUT_SEL0) 
#define Get_State_Pin_PRTDSI__OUT_SEL1       (* (reg8 *) Get_State_Pin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Get_State_Pin_PRTDSI__SYNC_OUT       (* (reg8 *) Get_State_Pin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Get_State_Pin__SIO_CFG)
    #define Get_State_Pin_SIO_HYST_EN        (* (reg8 *) Get_State_Pin__SIO_HYST_EN)
    #define Get_State_Pin_SIO_REG_HIFREQ     (* (reg8 *) Get_State_Pin__SIO_REG_HIFREQ)
    #define Get_State_Pin_SIO_CFG            (* (reg8 *) Get_State_Pin__SIO_CFG)
    #define Get_State_Pin_SIO_DIFF           (* (reg8 *) Get_State_Pin__SIO_DIFF)
#endif /* (Get_State_Pin__SIO_CFG) */

/* Interrupt Registers */
#if defined(Get_State_Pin__INTSTAT)
    #define Get_State_Pin_INTSTAT            (* (reg8 *) Get_State_Pin__INTSTAT)
    #define Get_State_Pin_SNAP               (* (reg8 *) Get_State_Pin__SNAP)
    
	#define Get_State_Pin_0_INTTYPE_REG 		(* (reg8 *) Get_State_Pin__0__INTTYPE)
#endif /* (Get_State_Pin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Get_State_Pin_H */


/* [] END OF FILE */
