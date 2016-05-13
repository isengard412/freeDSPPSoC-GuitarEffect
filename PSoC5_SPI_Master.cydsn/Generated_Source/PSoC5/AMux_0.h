/*******************************************************************************
* File Name: AMux_0.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_AMux_0_H)
#define CY_AMUX_AMux_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void AMux_0_Start(void) ;
#define AMux_0_Init() AMux_0_Start()
void AMux_0_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void AMux_0_Stop(void); */
/* void AMux_0_Select(uint8 channel); */
/* void AMux_0_Connect(uint8 channel); */
/* void AMux_0_Disconnect(uint8 channel); */
/* void AMux_0_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define AMux_0_CHANNELS  4u
#define AMux_0_MUXTYPE   2
#define AMux_0_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define AMux_0_NULL_CHANNEL 0xFFu
#define AMux_0_MUX_SINGLE   1
#define AMux_0_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if AMux_0_MUXTYPE == AMux_0_MUX_SINGLE
# if !AMux_0_ATMOSTONE
#  define AMux_0_Connect(channel) AMux_0_Set(channel)
# endif
# define AMux_0_Disconnect(channel) AMux_0_Unset(channel)
#else
# if !AMux_0_ATMOSTONE
void AMux_0_Connect(uint8 channel) ;
# endif
void AMux_0_Disconnect(uint8 channel) ;
#endif

#if AMux_0_ATMOSTONE
# define AMux_0_Stop() AMux_0_DisconnectAll()
# define AMux_0_Select(channel) AMux_0_FastSelect(channel)
void AMux_0_DisconnectAll(void) ;
#else
# define AMux_0_Stop() AMux_0_Start()
void AMux_0_Select(uint8 channel) ;
# define AMux_0_DisconnectAll() AMux_0_Start()
#endif

#endif /* CY_AMUX_AMux_0_H */


/* [] END OF FILE */
