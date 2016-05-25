/*******************************************************************************
* File Name: AMuxSeq.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the AMuxSeq.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUXSEQ_AMuxSeq_H)
#define CY_AMUXSEQ_AMuxSeq_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define AMuxSeq_MUX_SINGLE 1
#define AMuxSeq_MUX_DIFF   2
#define AMuxSeq_MUXTYPE    2


/***************************************
*        Function Prototypes
***************************************/

void AMuxSeq_Start(void);
void AMuxSeq_Init(void);
void AMuxSeq_Stop(void);
#if (AMuxSeq_MUXTYPE == AMuxSeq_MUX_DIFF)
void AMuxSeq_Next(void);
void AMuxSeq_DisconnectAll(void);
#else
/* The Next and DisconnectAll functions are declared in cyfitter_cfg.h. */
/* void AMuxSeq_Next(void); */
/* void AMuxSeq_DisconnectAll(void); */
#endif
int8 AMuxSeq_GetChannel(void);


/***************************************
*           Global Variables
***************************************/

extern uint8 AMuxSeq_initVar;


/***************************************
*         Parameter Constants
***************************************/
#define AMuxSeq_CHANNELS 8


#endif /* CY_AMUXSEQ_AMuxSeq_H */


/* [] END OF FILE */
