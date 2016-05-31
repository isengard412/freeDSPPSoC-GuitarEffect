/*******************************************************************************
* File Name: i2s.c
*
* Version: 0.0 
* Author: Lukas Creutzburg
*
* Description:
*   Interaction with DSP via I2S
*
*
*******************************************************************************/

#include "i2s.h"


void I2Sinit()
{
    I2S_1_Start();
    I2S_1_EnableTx();
}


/* [] END OF FILE */
