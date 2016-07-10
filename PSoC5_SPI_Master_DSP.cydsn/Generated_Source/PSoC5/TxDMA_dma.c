/***************************************************************************
* File Name: TxDma_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <TxDma_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* TxDma__DRQ_CTL_REG
* 
* 
* TxDma__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* TxDma__NUMBEROF_TDS
* 
* Priority of this channel.
* TxDma__PRIORITY
* 
* True if TxDma_TERMIN_SEL is used.
* TxDma__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* TxDma__TERMIN_SEL
* 
* 
* True if TxDma_TERMOUT0_SEL is used.
* TxDma__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* TxDma__TERMOUT0_SEL
* 
* 
* True if TxDma_TERMOUT1_SEL is used.
* TxDma__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* TxDma__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of TxDma dma channel */
uint8 TxDma_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 TxDma_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 TxDma_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    TxDma_DmaHandle = (uint8)TxDma__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(TxDma_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)TxDma__TERMOUT0_SEL,
                                  (uint8)TxDma__TERMOUT1_SEL,
                                  (uint8)TxDma__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(TxDma_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(TxDma_DmaHandle, (uint8)TxDma__PRIORITY);
    
    return TxDma_DmaHandle;
}

/*********************************************************************
* Function Name: void TxDma_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with TxDma.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void TxDma_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(TxDma_DmaHandle);
}

