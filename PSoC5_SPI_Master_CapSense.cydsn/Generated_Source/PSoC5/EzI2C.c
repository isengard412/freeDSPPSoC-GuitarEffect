/*******************************************************************************
* File Name: EzI2C.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands for the EZI2C
*  component. The actual protocol and operation code resides in the interrupt
*  service routine file.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "EzI2C_PVT.h"

/**********************************
*      System variables
**********************************/

uint8 EzI2C_initVar = 0u; /* Defines if component was initialized */

/* Status and state variables */
volatile uint8 EzI2C_curStatus; /* Current status of the component */
volatile uint8 EzI2C_curState;  /* Current state of state machine */

/* Primary slave address variables */
volatile uint8* EzI2C_dataPtrS1; /* Pointer to data buffer 1 */
volatile uint16 EzI2C_bufSizeS1; /* Size of buffer 1 in bytes */
volatile uint16 EzI2C_wrProtectS1; /* Start index of write protected area in buffer 1 */
volatile uint16  EzI2C_rwOffsetS1; /* Current offset within buffer 1 */
volatile uint16  EzI2C_rwIndexS1;  /* Current index within buffer 1 */

/* Secondary slave address variables */
#if(EzI2C_ADDRESSES == EzI2C_TWO_ADDRESSES)
    volatile uint8  EzI2C_addrS1; /* Primary slave address: software comparison */
    volatile uint8  EzI2C_addrS2; /* Secondary slave address: software comparison */
    volatile uint8* EzI2C_dataPtrS2; /* Pointer to data buffer 1 */
    volatile uint16 EzI2C_bufSizeS2; /* Size of buffer 2 in bytes */
    volatile uint16 EzI2C_wrProtectS2; /* Start index of write protected area in buffer 2 */
    volatile uint16 EzI2C_rwOffsetS2; /* Current offset within buffer 2 */
    volatile uint16 EzI2C_rwIndexS2;  /* Current index within buffer 2 */
#endif  /* (EzI2C_ADDRESSES == EzI2C_TWO_ADDRESSES) */


/*******************************************************************************
* Function Name: EzI2C_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the component according to the Configure dialog
*  settings. It is not necessary to call EZI2C_Init() because the EZI2C_Start()
*  API calls this function, which is the preferred method to begin component
*  operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  EzI2C_initVar - It is used to indicate the initial configuration
*  of this component.  The variable is initialized to zero and set to 1
*  the first time EzI2C_Start() is called. This allows component  !
*  initialization without re-initialization in all subsequent calls
*  to the EzI2C_Start() routine.
*
*  EzI2C_curStatus - Stores the current status of the component.
*
*  EzI2C_curState- Stores the current state of an I2C state machine.
*
*  EzI2C_rwOffsetS1 - The global variable which stores an offset for read
*  and write operations, is set at each write sequence of the first slave
*  address is reset if EzI2C_initVar is 0, by
*  EzI2C_initVar function call.
*
*  EzI2C_rwIndexS1 - The global variable which stores a pointer to the
*  next value to be read or written for the first slave address is reset if
*  EzI2C_initVar is 0, by EzI2C_initVar function call.
*
* EzI2C_wrProtectS1 - The global variable which stores an offset where data
*  is read only for the first slave address is reset if
*  EzI2C_initVar is 0, by EzI2C_initVar function call.
*
*  EzI2C_rwOffsetS2 - The global variable, which stores an offset for read
*  and write operations, is set at each write sequence of the second slave
*  device is reset if EzI2C_initVar is 0, by EzI2C_initVar
*  function call.
*
*  EzI2C_rwIndexS2 - The global variable which stores a pointer to the
*  next value to be read or written for the second slave address is reset if
*  EzI2C_initVar is 0, by EzI2C_initVar function call.
*
* EzI2C_wrProtectS2 - The global variable which stores an offset where data
*  is read only for the second slave address is reset if
*  EzI2C_initVar is 0, by EzI2C_initVar function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void EzI2C_Init(void) 
{
    /* Configure fixed function block */
    EzI2C_CFG_REG  = EzI2C_DEFAULT_CFG;
    EzI2C_XCFG_REG = EzI2C_DEFAULT_XCFG;
    EzI2C_ADDR_REG = EzI2C_DEFAULT_ADDR;
    EzI2C_CLKDIV1_REG = EzI2C_DEFAULT_CLKDIV1;
    EzI2C_CLKDIV2_REG = EzI2C_DEFAULT_CLKDIV2;

#if (EzI2C_TWO_ADDRESSES == EzI2C_ADDRESSES)
    /* Set address variables */
    EzI2C_SetAddress1(EzI2C_DEFAULT_ADDR1);
    EzI2C_SetAddress2(EzI2C_DEFAULT_ADDR2);
#endif /* #if (EzI2C_TWO_ADDRESSES == EzI2C_ADDRESSES) */

    /* Configure interrupt */
    CyIntDisable         (EzI2C_ISR_NUMBER);
    CyIntSetPriority     (EzI2C_ISR_NUMBER, EzI2C_ISR_PRIORITY);
    (void) CyIntSetVector(EzI2C_ISR_NUMBER, &EzI2C_ISR);

     /* Reset state and status to default */
    EzI2C_curState  = EzI2C_SM_IDLE;
    EzI2C_curStatus = 0u;

    /* Reset all buffer 1 indexes (primary address) */
    EzI2C_rwOffsetS1  = 0u;
    EzI2C_rwIndexS1   = 0u;
    EzI2C_wrProtectS1 = 0u;

#if (EzI2C_ADDRESSES == EzI2C_TWO_ADDRESSES)
    /* Reset all buffer 2 indexes (secondary address) */
    EzI2C_rwOffsetS2  = 0u;
    EzI2C_rwIndexS2   = 0u;
    EzI2C_wrProtectS2 = 0u;
#endif  /* (EzI2C_ADDRESSES == EzI2C_TWO_ADDRESSES) */
}


/*******************************************************************************
* Function Name: EzI2C_Enable
********************************************************************************
*
* Summary:
*  Activates the hardware and begins component operation.Calls EZI2C_EnableInt()
*  to enable the I2C component interrupt. It is not necessary to call
*  EZI2C_Enable() because the EZI2C_Start() API calls this function, which is
*  the preferred method to begin component operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void EzI2C_Enable(void) 
{
    uint8 intState;

    /* Enable power to block */
    intState = CyEnterCriticalSection();
    EzI2C_PM_ACT_CFG_REG  |= EzI2C_ACT_PWR_EN;
    EzI2C_PM_STBY_CFG_REG |= EzI2C_STBY_PWR_EN;
    CyExitCriticalSection(intState);

    /* Enable interrupt to start operation */
    EzI2C_EnableInt();
}


/*******************************************************************************
* Function Name: EzI2C_Start
********************************************************************************
*
* Summary:
*  This is the preferred method to begin component operation. EZI2C_Start(),
*  calls the EZI2C_Init() function, and then calls the EZI2C_Enable() function.
*  It must be executed before I2C bus operation.
*  This function enables the component interrupt because interrupt is required
*  for most component operations.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void EzI2C_Start(void) 
{
    if (0u == EzI2C_initVar)
    {
        EzI2C_Init();
        EzI2C_initVar = 1u; /* Component initialized */
    }

    EzI2C_Enable();
}


/*******************************************************************************
* Function Name: EzI2C_Stop
********************************************************************************
*
* Summary:
*  Disables I2C hardware and component interrupt. The I2C bus is released if it
*  was locked up by the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void EzI2C_Stop(void) 
{
    uint8  intState;
    uint16 blockResetCycles;

    EzI2C_DisableInt();

    /* Store registers effected by block disable */
    EzI2C_backup.adr     = EzI2C_ADDR_REG;
    EzI2C_backup.clkDiv1 = EzI2C_CLKDIV1_REG;
    EzI2C_backup.clkDiv2 = EzI2C_CLKDIV2_REG;

    /* Calculate number of cycles to reset block */
    blockResetCycles = ((uint16) ((uint16) EzI2C_CLKDIV2_REG << 8u) | EzI2C_CLKDIV1_REG) + 1u;

    /* Disable block */
    EzI2C_CFG_REG &= (uint8) ~EzI2C_CFG_EN_SLAVE;
    /* Wait for block reset before disable power */
    CyDelayCycles((uint32) blockResetCycles);

    /* Disable power to block */
    intState = CyEnterCriticalSection();
    EzI2C_PM_ACT_CFG_REG  &= (uint8) ~EzI2C_ACT_PWR_EN;
    EzI2C_PM_STBY_CFG_REG &= (uint8) ~EzI2C_STBY_PWR_EN;
    CyExitCriticalSection(intState);

    /* Enable block */
    EzI2C_CFG_REG |= (uint8) EzI2C_CFG_EN_SLAVE;

    /* Restore registers effected by block disable. Ticket ID#198004 */
    EzI2C_ADDR_REG    = EzI2C_backup.adr;
    EzI2C_ADDR_REG    = EzI2C_backup.adr;
    EzI2C_CLKDIV1_REG = EzI2C_backup.clkDiv1;
    EzI2C_CLKDIV2_REG = EzI2C_backup.clkDiv2;

    EzI2C_ClearPendingInt();

    /* Reset state and status to default */
    EzI2C_curState  = EzI2C_SM_IDLE;
    EzI2C_curStatus = 0u;
}


/*******************************************************************************
* Function Name: EzI2C_SetAddress1
********************************************************************************
*
* Summary:
*  Sets the primary I2C slave address. This address is used by the master to
*  access the primary data buffer.
*
* Parameters:
*  address: Primary I2C slave address.
*           This address is the 7-bit right-justified slave address and does not
*           include the R/W bit.
*           This value can be any address between 0 and 127 (0x00 to 0x7F).
*
* Return:
*  None.
*
* Global variables:
*  EzI2C_addrS1 - A new slave address for the first slave device is
*  saved in it, if the component is configured to act as two slave devices.
*
* Reentrant:
*  No, if two addresses are used.
*
*******************************************************************************/
void EzI2C_SetAddress1(uint8 address) 
{
#if (EzI2C_ONE_ADDRESS == EzI2C_ADDRESSES)
    EzI2C_ADDR_REG = (address & EzI2C_SADDR_MASK);
#else
    EzI2C_addrS1   = (address & EzI2C_SADDR_MASK);
#endif /* (EzI2C_ONE_ADDRESS == EzI2C_ADDRESSES) */
}


/*******************************************************************************
* Function Name: EzI2C_GetAddress1
********************************************************************************
*
* Summary:
*  Returns the primary I2C slave address.
*  This address is the 7-bit right-justified slave address and does not include
*  the R/W bit.
*
* Parameters:
*  None.
*
* Return:
*  Primary I2C slave address.
*
* Global variables:
*  EzI2C_addrS1 - If component is configured to has two slave
*  addresses than the primary address is saved here, otherwise the address is written to
*  the register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 EzI2C_GetAddress1(void) 
{
#if (EzI2C_ONE_ADDRESS == EzI2C_ADDRESSES)
    return (EzI2C_ADDR_REG);
#else
    return (EzI2C_addrS1);
#endif /* (EzI2C_ONE_ADDRESS == EzI2C_ADDRESSES) */
}


/*******************************************************************************
* Function Name: EzI2C_GetActivity
********************************************************************************
*
* Summary:
*  Returns a non-zero value if an I2C read or write cycle has occurred since
*  the last time this function was called. The activity flag resets to zero at
*  the end of this function call.
*  The Read and Write busy flags are cleared when read, but the “BUSY” flag is
*  only cleared when slave is free (i.e master finishes communication with
*  slave generating Stop or repeated Start condition).
*
* Parameters:
*  None
*
* Return:
*  Status of I2C activity.
*
*   EzI2C_STATUS_READ1   Set if a Read sequence is detected for the first
*                                   address. Cleared when the status is read.
*
*   EzI2C_STATUS_WRITE1  Set if a Write sequence is detected for the first
*                                   address. Cleared when the status is  read.
*
*   EzI2C_STATUS_READ2   Set if a Read sequence is detected for the second
*                                   address (if enabled). Cleared when the status
*                                   read.
*
*   EzI2C_STATUS_WRITE2  Set if a Write sequence is detected for the second
*                                   address (if enabled). Cleared when the status is
*                                   read.
*
*   EzI2C_STATUS_BUSY    Set when the master starts communication with
*                                   the slave (the slave is addressed with Start or
*                                   repeated Start) and cleared when the master
*                                   finishes communication (a Stop or repeated
*                                   Start condition is generated).
*
*   EzI2C_STATUS_ERR     Set when the I2C hardware is detected, cleared
*                                   when the status is read.
*
* Global variables:
*  EzI2C_curStatus - The global variable which stores the current
*  component status.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 EzI2C_GetActivity(void) 
{
    uint8 tmpStatus;

    EzI2C_DisableInt(); /* Lock from component interrupt */

    tmpStatus = EzI2C_curStatus;
    /* Clear status bits. Do not touch busy status */
    EzI2C_curStatus &= EzI2C_STATUS_BUSY;

    EzI2C_EnableInt(); /* Release lock */

    return (tmpStatus);
}


/*******************************************************************************
* Function Name: EzI2C_SetBuffer1
********************************************************************************
*
* Summary:
*  Sets up the data buffer to be exposed to the master on a primary slave
*  address request.
*
* Parameters:
*  bufSize:    Size of the buffer in bytes.
*  rwBoundary: Number of data bytes starting from the beginning of the buffer
*              with read and write access. Data bytes located at offset
*              rwBoundary or greater are read only.
*              This value must be less than or equal to the buffer size.
*  dataPtr:    Pointer to the data buffer.
*
* Return:
*  None.
*
* Global variables:
*  EzI2C_dataPtrS1 - Stores the pointer to the data exposed to an I2C
*  master for the first slave address, is modified with the the new pointer to    the    ?? no sense without a comma
*  data passed by the function parameter.
*
*  EzI2C_rwOffsetS1 - Stores an offset for read and write operations, is
*  modified at each write sequence of the first slave address is?? reset.   ?
*
*  EzI2C_rwIndexS1 - Stores the pointer to the next value to be read or
*  written for the first slave address is?? set to 0.  ??
*
* Reentrant:
*  No.
*
*******************************************************************************/
void EzI2C_SetBuffer1(uint16 bufSize, uint16 rwBoundary, volatile uint8 * dataPtr) 
{
    EzI2C_DisableInt(); /* Lock from component interrupt */

    if (NULL != dataPtr)
    {
        /* Configure buffer 1 */
        EzI2C_dataPtrS1   = dataPtr;
        EzI2C_bufSizeS1   = bufSize;
        EzI2C_wrProtectS1 = rwBoundary;
    }

    /* Clear buffer offset and index */
    EzI2C_rwOffsetS1 = 0u;
    EzI2C_rwIndexS1  = 0u;

    EzI2C_EnableInt(); /* Release lock */
}


#if (EzI2C_TWO_ADDRESSES == EzI2C_ADDRESSES)
    /*******************************************************************************
    * Function Name: EzI2C_SetBuffer2
    ********************************************************************************
    *
    * Summary:
    *  Sets up the data buffer to be exposed to the master on a secondary slave
    *  address request.
    *
    * Parameters:
    *  bufSize:    Size of the buffer in bytes.
    *  rwBoundary: Number of data bytes starting from the beginning of the buffer
    *              with read and write access. Data bytes located at offset
    *              rwBoundary or greater are read only.
    *              This value must be less than or equal to the buffer size.
    *  dataPtr:    Pointer to the data buffer.
    *
    * Return:
    *  None.
    *
    * Global variables:
    *  EzI2C_dataPtrS2 - Stores the pointer to the data exposed to an I2C
    *  master for the second slave address, is modified with the the new pointer to the
    *  data, passed by the unction parameter.
    *
    *  EzI2C_rwOffsetS2 - Stores teh offset for read and write operations,
    *  is modified at each write sequence of the second slave address is?? reset.  ??
    *
    *  EzI2C_rwIndexS2 - Stores the pointer to the next value to be read or
    *  written for the second slave address is?? set to 0.  ??
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void EzI2C_SetBuffer2(uint16 bufSize, uint16 rwBoundary, volatile uint8 * dataPtr) 
    {
        EzI2C_DisableInt(); /* Lock from component interrupt */

        if (NULL != dataPtr)
        {
            /* Configure buffer 2 */
            EzI2C_dataPtrS2   = dataPtr;
            EzI2C_bufSizeS2   = bufSize;
            EzI2C_wrProtectS2 = rwBoundary;
        }

        /* Clear buffer offset and index */
        EzI2C_rwOffsetS2 = 0u;
        EzI2C_rwIndexS2  = 0u;

        EzI2C_EnableInt(); /* Release lock */
    }


    /*******************************************************************************
    * Function Name: EzI2C_SetAddress2
    ********************************************************************************
    *
    * Summary:
    *  Sets the secondary I2C slave address. This address is used by the master to
    *  access the secondary data buffer.
    *
    * Parameters:
    *  address: Secondary I2C slave address.
    *           This address is the 7-bit right-justified slave address and does
    *           not include the R/W bit. This value can be any address between
    *           0 and 127 (0x00 to 0x7F).
    *
    * Return:
    *  None.
    *
    * Global variables:
    *  EzI2C_addrS2 - The secondary slave address is modified.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void EzI2C_SetAddress2(uint8 address) 
    {
        EzI2C_addrS2 = (address & EzI2C_SADDR_MASK);
    }


    /*******************************************************************************
    * Function Name: EzI2C_GetAddress2
    ********************************************************************************
    *
    * Summary:
    *  Returns the secondary I2C slave address.
    *  This address is the 7-bit right-justified slave address and does not
    *  include the R/W bit.
    *
    * Parameters:
    *  EzI2C_addrS2 - The global variable which stores the second I2C
    *   address.
    *
    * Return:
    *  Secondary I2C slave address.
    *
    * Global variables:
    *  EzI2C_addrS2 - The secondary slave address is used.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 EzI2C_GetAddress2(void) 
    {
        return (EzI2C_addrS2);
    }

#endif  /* (EzI2C_TWO_ADDRESSES == EzI2C_ADDRESSES) */


/* [] END OF FILE */
