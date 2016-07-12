/*******************************************************************************
* File Name: Timeout_timer.c
* Version 2.70
*
* Description:
*  The Timer component consists of a 8, 16, 24 or 32-bit timer with
*  a selectable period between 2 and 2^Width - 1.  The timer may free run
*  or be used as a capture timer as well.  The capture can be initiated
*  by a positive or negative edge signal as well as via software.
*  A trigger input can be programmed to enable the timer on rising edge
*  falling edge, either edge or continous run.
*  Interrupts may be generated due to a terminal count condition
*  or a capture event.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timeout_timer.h"

uint8 Timeout_timer_initVar = 0u;


/*******************************************************************************
* Function Name: Timeout_timer_Init
********************************************************************************
*
* Summary:
*  Initialize to the schematic state
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_Init(void) 
{
    #if(!Timeout_timer_UsingFixedFunction)
            /* Interrupt State Backup for Critical Region*/
            uint8 Timeout_timer_interruptState;
    #endif /* Interrupt state back up for Fixed Function only */

    #if (Timeout_timer_UsingFixedFunction)
        /* Clear all bits but the enable bit (if it's already set) for Timer operation */
        Timeout_timer_CONTROL &= Timeout_timer_CTRL_ENABLE;

        /* Clear the mode bits for continuous run mode */
        #if (CY_PSOC5A)
            Timeout_timer_CONTROL2 &= ((uint8)(~Timeout_timer_CTRL_MODE_MASK));
        #endif /* Clear bits in CONTROL2 only in PSOC5A */

        #if (CY_PSOC3 || CY_PSOC5LP)
            Timeout_timer_CONTROL3 &= ((uint8)(~Timeout_timer_CTRL_MODE_MASK));
        #endif /* CONTROL3 register exists only in PSoC3 OR PSoC5LP */

        /* Check if One Shot mode is enabled i.e. RunMode !=0*/
        #if (Timeout_timer_RunModeUsed != 0x0u)
            /* Set 3rd bit of Control register to enable one shot mode */
            Timeout_timer_CONTROL |= 0x04u;
        #endif /* One Shot enabled only when RunModeUsed is not Continuous*/

        #if (Timeout_timer_RunModeUsed == 2)
            #if (CY_PSOC5A)
                /* Set last 2 bits of control2 register if one shot(halt on
                interrupt) is enabled*/
                Timeout_timer_CONTROL2 |= 0x03u;
            #endif /* Set One-Shot Halt on Interrupt bit in CONTROL2 for PSoC5A */

            #if (CY_PSOC3 || CY_PSOC5LP)
                /* Set last 2 bits of control3 register if one shot(halt on
                interrupt) is enabled*/
                Timeout_timer_CONTROL3 |= 0x03u;
            #endif /* Set One-Shot Halt on Interrupt bit in CONTROL3 for PSoC3 or PSoC5LP */

        #endif /* Remove section if One Shot Halt on Interrupt is not enabled */

        #if (Timeout_timer_UsingHWEnable != 0)
            #if (CY_PSOC5A)
                /* Set the default Run Mode of the Timer to Continuous */
                Timeout_timer_CONTROL2 |= Timeout_timer_CTRL_MODE_PULSEWIDTH;
            #endif /* Set Continuous Run Mode in CONTROL2 for PSoC5A */

            #if (CY_PSOC3 || CY_PSOC5LP)
                /* Clear and Set ROD and COD bits of CFG2 register */
                Timeout_timer_CONTROL3 &= ((uint8)(~Timeout_timer_CTRL_RCOD_MASK));
                Timeout_timer_CONTROL3 |= Timeout_timer_CTRL_RCOD;

                /* Clear and Enable the HW enable bit in CFG2 register */
                Timeout_timer_CONTROL3 &= ((uint8)(~Timeout_timer_CTRL_ENBL_MASK));
                Timeout_timer_CONTROL3 |= Timeout_timer_CTRL_ENBL;

                /* Set the default Run Mode of the Timer to Continuous */
                Timeout_timer_CONTROL3 |= Timeout_timer_CTRL_MODE_CONTINUOUS;
            #endif /* Set Continuous Run Mode in CONTROL3 for PSoC3ES3 or PSoC5A */

        #endif /* Configure Run Mode with hardware enable */

        /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        Timeout_timer_RT1 &= ((uint8)(~Timeout_timer_RT1_MASK));
        Timeout_timer_RT1 |= Timeout_timer_SYNC;

        /*Enable DSI Sync all all inputs of the Timer*/
        Timeout_timer_RT1 &= ((uint8)(~Timeout_timer_SYNCDSI_MASK));
        Timeout_timer_RT1 |= Timeout_timer_SYNCDSI_EN;

        /* Set the IRQ to use the status register interrupts */
        Timeout_timer_CONTROL2 |= Timeout_timer_CTRL2_IRQ_SEL;
    #endif /* Configuring registers of fixed function implementation */

    /* Set Initial values from Configuration */
    Timeout_timer_WritePeriod(Timeout_timer_INIT_PERIOD);
    Timeout_timer_WriteCounter(Timeout_timer_INIT_PERIOD);

    #if (Timeout_timer_UsingHWCaptureCounter)/* Capture counter is enabled */
        Timeout_timer_CAPTURE_COUNT_CTRL |= Timeout_timer_CNTR_ENABLE;
        Timeout_timer_SetCaptureCount(Timeout_timer_INIT_CAPTURE_COUNT);
    #endif /* Configure capture counter value */

    #if (!Timeout_timer_UsingFixedFunction)
        #if (Timeout_timer_SoftwareCaptureMode)
            Timeout_timer_SetCaptureMode(Timeout_timer_INIT_CAPTURE_MODE);
        #endif /* Set Capture Mode for UDB implementation if capture mode is software controlled */

        #if (Timeout_timer_SoftwareTriggerMode)
            #if (!Timeout_timer_UDB_CONTROL_REG_REMOVED)
                if (0u == (Timeout_timer_CONTROL & Timeout_timer__B_TIMER__TM_SOFTWARE))
                {
                    Timeout_timer_SetTriggerMode(Timeout_timer_INIT_TRIGGER_MODE);
                }
            #endif /* (!Timeout_timer_UDB_CONTROL_REG_REMOVED) */
        #endif /* Set trigger mode for UDB Implementation if trigger mode is software controlled */

        /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
        /* Enter Critical Region*/
        Timeout_timer_interruptState = CyEnterCriticalSection();

        /* Use the interrupt output of the status register for IRQ output */
        Timeout_timer_STATUS_AUX_CTRL |= Timeout_timer_STATUS_ACTL_INT_EN_MASK;

        /* Exit Critical Region*/
        CyExitCriticalSection(Timeout_timer_interruptState);

        #if (Timeout_timer_EnableTriggerMode)
            Timeout_timer_EnableTrigger();
        #endif /* Set Trigger enable bit for UDB implementation in the control register*/
		
		
        #if (Timeout_timer_InterruptOnCaptureCount && !Timeout_timer_UDB_CONTROL_REG_REMOVED)
            Timeout_timer_SetInterruptCount(Timeout_timer_INIT_INT_CAPTURE_COUNT);
        #endif /* Set interrupt count in UDB implementation if interrupt count feature is checked.*/

        Timeout_timer_ClearFIFO();
    #endif /* Configure additional features of UDB implementation */

    Timeout_timer_SetInterruptMode(Timeout_timer_INIT_INTERRUPT_MODE);
}


/*******************************************************************************
* Function Name: Timeout_timer_Enable
********************************************************************************
*
* Summary:
*  Enable the Timer
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Timeout_timer_UsingFixedFunction)
        Timeout_timer_GLOBAL_ENABLE |= Timeout_timer_BLOCK_EN_MASK;
        Timeout_timer_GLOBAL_STBY_ENABLE |= Timeout_timer_BLOCK_STBY_EN_MASK;
    #endif /* Set Enable bit for enabling Fixed function timer*/

    /* Remove assignment if control register is removed */
    #if (!Timeout_timer_UDB_CONTROL_REG_REMOVED || Timeout_timer_UsingFixedFunction)
        Timeout_timer_CONTROL |= Timeout_timer_CTRL_ENABLE;
    #endif /* Remove assignment if control register is removed */
}


/*******************************************************************************
* Function Name: Timeout_timer_Start
********************************************************************************
*
* Summary:
*  The start function initializes the timer with the default values, the
*  enables the timerto begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timeout_timer_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Timeout_timer_Start(void) 
{
    if(Timeout_timer_initVar == 0u)
    {
        Timeout_timer_Init();

        Timeout_timer_initVar = 1u;   /* Clear this bit for Initialization */
    }

    /* Enable the Timer */
    Timeout_timer_Enable();
}


/*******************************************************************************
* Function Name: Timeout_timer_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the timer, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the timer.
*
*******************************************************************************/
void Timeout_timer_Stop(void) 
{
    /* Disable Timer */
    #if(!Timeout_timer_UDB_CONTROL_REG_REMOVED || Timeout_timer_UsingFixedFunction)
        Timeout_timer_CONTROL &= ((uint8)(~Timeout_timer_CTRL_ENABLE));
    #endif /* Remove assignment if control register is removed */

    /* Globally disable the Fixed Function Block chosen */
    #if (Timeout_timer_UsingFixedFunction)
        Timeout_timer_GLOBAL_ENABLE &= ((uint8)(~Timeout_timer_BLOCK_EN_MASK));
        Timeout_timer_GLOBAL_STBY_ENABLE &= ((uint8)(~Timeout_timer_BLOCK_STBY_EN_MASK));
    #endif /* Disable global enable for the Timer Fixed function block to stop the Timer*/
}


/*******************************************************************************
* Function Name: Timeout_timer_SetInterruptMode
********************************************************************************
*
* Summary:
*  This function selects which of the interrupt inputs may cause an interrupt.
*  The twosources are caputure and terminal.  One, both or neither may
*  be selected.
*
* Parameters:
*  interruptMode:   This parameter is used to enable interrups on either/or
*                   terminal count or capture.
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_SetInterruptMode(uint8 interruptMode) 
{
    Timeout_timer_STATUS_MASK = interruptMode;
}


/*******************************************************************************
* Function Name: Timeout_timer_SoftwareCapture
********************************************************************************
*
* Summary:
*  This function forces a capture independent of the capture signal.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Side Effects:
*  An existing hardware capture could be overwritten.
*
*******************************************************************************/
void Timeout_timer_SoftwareCapture(void) 
{
    /* Generate a software capture by reading the counter register */
    #if(Timeout_timer_UsingFixedFunction)
        (void)CY_GET_REG16(Timeout_timer_COUNTER_LSB_PTR);
    #else
        (void)CY_GET_REG8(Timeout_timer_COUNTER_LSB_PTR_8BIT);
    #endif/* (Timeout_timer_UsingFixedFunction) */
    /* Capture Data is now in the FIFO */
}


/*******************************************************************************
* Function Name: Timeout_timer_ReadStatusRegister
********************************************************************************
*
* Summary:
*  Reads the status register and returns it's state. This function should use
*  defined types for the bit-field information as the bits in this register may
*  be permuteable.
*
* Parameters:
*  void
*
* Return:
*  The contents of the status register
*
* Side Effects:
*  Status register bits may be clear on read.
*
*******************************************************************************/
uint8   Timeout_timer_ReadStatusRegister(void) 
{
    return (Timeout_timer_STATUS);
}


#if (!Timeout_timer_UDB_CONTROL_REG_REMOVED) /* Remove API if control register is unused */


/*******************************************************************************
* Function Name: Timeout_timer_ReadControlRegister
********************************************************************************
*
* Summary:
*  Reads the control register and returns it's value.
*
* Parameters:
*  void
*
* Return:
*  The contents of the control register
*
*******************************************************************************/
uint8 Timeout_timer_ReadControlRegister(void) 
{
    #if (!Timeout_timer_UDB_CONTROL_REG_REMOVED) 
        return ((uint8)Timeout_timer_CONTROL);
    #else
        return (0);
    #endif /* (!Timeout_timer_UDB_CONTROL_REG_REMOVED) */
}


/*******************************************************************************
* Function Name: Timeout_timer_WriteControlRegister
********************************************************************************
*
* Summary:
*  Sets the bit-field of the control register.
*
* Parameters:
*  control: The contents of the control register
*
* Return:
*
*******************************************************************************/
void Timeout_timer_WriteControlRegister(uint8 control) 
{
    #if (!Timeout_timer_UDB_CONTROL_REG_REMOVED) 
        Timeout_timer_CONTROL = control;
    #else
        control = 0u;
    #endif /* (!Timeout_timer_UDB_CONTROL_REG_REMOVED) */
}

#endif /* Remove API if control register is unused */


/*******************************************************************************
* Function Name: Timeout_timer_ReadPeriod
********************************************************************************
*
* Summary:
*  This function returns the current value of the Period.
*
* Parameters:
*  void
*
* Return:
*  The present value of the counter.
*
*******************************************************************************/
uint8 Timeout_timer_ReadPeriod(void) 
{
   #if(Timeout_timer_UsingFixedFunction)
       return ((uint8)CY_GET_REG16(Timeout_timer_PERIOD_LSB_PTR));
   #else
       return (CY_GET_REG8(Timeout_timer_PERIOD_LSB_PTR));
   #endif /* (Timeout_timer_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Timeout_timer_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period: This value may be between 1 and (2^Resolution)-1.  A value of 0 will
*          result in the counter remaining at zero.
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_WritePeriod(uint8 period) 
{
    #if(Timeout_timer_UsingFixedFunction)
        uint16 period_temp = (uint16)period;
        CY_SET_REG16(Timeout_timer_PERIOD_LSB_PTR, period_temp);
    #else
        CY_SET_REG8(Timeout_timer_PERIOD_LSB_PTR, period);
    #endif /*Write Period value with appropriate resolution suffix depending on UDB or fixed function implementation */
}


/*******************************************************************************
* Function Name: Timeout_timer_ReadCapture
********************************************************************************
*
* Summary:
*  This function returns the last value captured.
*
* Parameters:
*  void
*
* Return:
*  Present Capture value.
*
*******************************************************************************/
uint8 Timeout_timer_ReadCapture(void) 
{
   #if(Timeout_timer_UsingFixedFunction)
       return ((uint8)CY_GET_REG16(Timeout_timer_CAPTURE_LSB_PTR));
   #else
       return (CY_GET_REG8(Timeout_timer_CAPTURE_LSB_PTR));
   #endif /* (Timeout_timer_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Timeout_timer_WriteCounter
********************************************************************************
*
* Summary:
*  This funtion is used to set the counter to a specific value
*
* Parameters:
*  counter:  New counter value.
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_WriteCounter(uint8 counter) 
{
   #if(Timeout_timer_UsingFixedFunction)
        /* This functionality is removed until a FixedFunction HW update to
         * allow this register to be written
         */
        CY_SET_REG16(Timeout_timer_COUNTER_LSB_PTR, (uint16)counter);
        
    #else
        CY_SET_REG8(Timeout_timer_COUNTER_LSB_PTR, counter);
    #endif /* Set Write Counter only for the UDB implementation (Write Counter not available in fixed function Timer */
}


/*******************************************************************************
* Function Name: Timeout_timer_ReadCounter
********************************************************************************
*
* Summary:
*  This function returns the current counter value.
*
* Parameters:
*  void
*
* Return:
*  Present compare value.
*
*******************************************************************************/
uint8 Timeout_timer_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(Timeout_timer_UsingFixedFunction)
        (void)CY_GET_REG16(Timeout_timer_COUNTER_LSB_PTR);
    #else
        (void)CY_GET_REG8(Timeout_timer_COUNTER_LSB_PTR_8BIT);
    #endif/* (Timeout_timer_UsingFixedFunction) */

    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(Timeout_timer_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Timeout_timer_CAPTURE_LSB_PTR));
    #else
        return (CY_GET_REG8(Timeout_timer_CAPTURE_LSB_PTR));
    #endif /* (Timeout_timer_UsingFixedFunction) */
}


#if(!Timeout_timer_UsingFixedFunction) /* UDB Specific Functions */

    
/*******************************************************************************
 * The functions below this point are only available using the UDB
 * implementation.  If a feature is selected, then the API is enabled.
 ******************************************************************************/


#if (Timeout_timer_SoftwareCaptureMode)


/*******************************************************************************
* Function Name: Timeout_timer_SetCaptureMode
********************************************************************************
*
* Summary:
*  This function sets the capture mode to either rising or falling edge.
*
* Parameters:
*  captureMode: This parameter sets the capture mode of the UDB capture feature
*  The parameter values are defined using the
*  #define Timeout_timer__B_TIMER__CM_NONE 0
#define Timeout_timer__B_TIMER__CM_RISINGEDGE 1
#define Timeout_timer__B_TIMER__CM_FALLINGEDGE 2
#define Timeout_timer__B_TIMER__CM_EITHEREDGE 3
#define Timeout_timer__B_TIMER__CM_SOFTWARE 4
 identifiers
*  The following are the possible values of the parameter
*  Timeout_timer__B_TIMER__CM_NONE        - Set Capture mode to None
*  Timeout_timer__B_TIMER__CM_RISINGEDGE  - Rising edge of Capture input
*  Timeout_timer__B_TIMER__CM_FALLINGEDGE - Falling edge of Capture input
*  Timeout_timer__B_TIMER__CM_EITHEREDGE  - Either edge of Capture input
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_SetCaptureMode(uint8 captureMode) 
{
    /* This must only set to two bits of the control register associated */
    captureMode = ((uint8)((uint8)captureMode << Timeout_timer_CTRL_CAP_MODE_SHIFT));
    captureMode &= (Timeout_timer_CTRL_CAP_MODE_MASK);

    #if (!Timeout_timer_UDB_CONTROL_REG_REMOVED)
        /* Clear the Current Setting */
        Timeout_timer_CONTROL &= ((uint8)(~Timeout_timer_CTRL_CAP_MODE_MASK));

        /* Write The New Setting */
        Timeout_timer_CONTROL |= captureMode;
    #endif /* (!Timeout_timer_UDB_CONTROL_REG_REMOVED) */
}
#endif /* Remove API if Capture Mode is not Software Controlled */


#if (Timeout_timer_SoftwareTriggerMode)


/*******************************************************************************
* Function Name: Timeout_timer_SetTriggerMode
********************************************************************************
*
* Summary:
*  This function sets the trigger input mode
*
* Parameters:
*  triggerMode: Pass one of the pre-defined Trigger Modes (except Software)
    #define Timeout_timer__B_TIMER__TM_NONE 0x00u
    #define Timeout_timer__B_TIMER__TM_RISINGEDGE 0x04u
    #define Timeout_timer__B_TIMER__TM_FALLINGEDGE 0x08u
    #define Timeout_timer__B_TIMER__TM_EITHEREDGE 0x0Cu
    #define Timeout_timer__B_TIMER__TM_SOFTWARE 0x10u
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_SetTriggerMode(uint8 triggerMode) 
{
    /* This must only set to two bits of the control register associated */
    triggerMode &= Timeout_timer_CTRL_TRIG_MODE_MASK;

    #if (!Timeout_timer_UDB_CONTROL_REG_REMOVED)   /* Remove assignment if control register is removed */
    
        /* Clear the Current Setting */
        Timeout_timer_CONTROL &= ((uint8)(~Timeout_timer_CTRL_TRIG_MODE_MASK));

        /* Write The New Setting */
        Timeout_timer_CONTROL |= (triggerMode | Timeout_timer__B_TIMER__TM_SOFTWARE);
    #endif /* Remove code section if control register is not used */
}
#endif /* Remove API if Trigger Mode is not Software Controlled */

#if (Timeout_timer_EnableTriggerMode)


/*******************************************************************************
* Function Name: Timeout_timer_EnableTrigger
********************************************************************************
*
* Summary:
*  Sets the control bit enabling Hardware Trigger mode
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_EnableTrigger(void) 
{
    #if (!Timeout_timer_UDB_CONTROL_REG_REMOVED)   /* Remove assignment if control register is removed */
        Timeout_timer_CONTROL |= Timeout_timer_CTRL_TRIG_EN;
    #endif /* Remove code section if control register is not used */
}


/*******************************************************************************
* Function Name: Timeout_timer_DisableTrigger
********************************************************************************
*
* Summary:
*  Clears the control bit enabling Hardware Trigger mode
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_DisableTrigger(void) 
{
    #if (!Timeout_timer_UDB_CONTROL_REG_REMOVED )   /* Remove assignment if control register is removed */
        Timeout_timer_CONTROL &= ((uint8)(~Timeout_timer_CTRL_TRIG_EN));
    #endif /* Remove code section if control register is not used */
}
#endif /* Remove API is Trigger Mode is set to None */

#if(Timeout_timer_InterruptOnCaptureCount)


/*******************************************************************************
* Function Name: Timeout_timer_SetInterruptCount
********************************************************************************
*
* Summary:
*  This function sets the capture count before an interrupt is triggered.
*
* Parameters:
*  interruptCount:  A value between 0 and 3 is valid.  If the value is 0, then
*                   an interrupt will occur each time a capture occurs.
*                   A value of 1 to 3 will cause the interrupt
*                   to delay by the same number of captures.
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_SetInterruptCount(uint8 interruptCount) 
{
    /* This must only set to two bits of the control register associated */
    interruptCount &= Timeout_timer_CTRL_INTCNT_MASK;

    #if (!Timeout_timer_UDB_CONTROL_REG_REMOVED)
        /* Clear the Current Setting */
        Timeout_timer_CONTROL &= ((uint8)(~Timeout_timer_CTRL_INTCNT_MASK));
        /* Write The New Setting */
        Timeout_timer_CONTROL |= interruptCount;
    #endif /* (!Timeout_timer_UDB_CONTROL_REG_REMOVED) */
}
#endif /* Timeout_timer_InterruptOnCaptureCount */


#if (Timeout_timer_UsingHWCaptureCounter)


/*******************************************************************************
* Function Name: Timeout_timer_SetCaptureCount
********************************************************************************
*
* Summary:
*  This function sets the capture count
*
* Parameters:
*  captureCount: A value between 2 and 127 inclusive is valid.  A value of 1
*                to 127 will cause the interrupt to delay by the same number of
*                captures.
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_SetCaptureCount(uint8 captureCount) 
{
    Timeout_timer_CAP_COUNT = captureCount;
}


/*******************************************************************************
* Function Name: Timeout_timer_ReadCaptureCount
********************************************************************************
*
* Summary:
*  This function reads the capture count setting
*
* Parameters:
*  void
*
* Return:
*  Returns the Capture Count Setting
*
*******************************************************************************/
uint8 Timeout_timer_ReadCaptureCount(void) 
{
    return ((uint8)Timeout_timer_CAP_COUNT);
}
#endif /* Timeout_timer_UsingHWCaptureCounter */


/*******************************************************************************
* Function Name: Timeout_timer_ClearFIFO
********************************************************************************
*
* Summary:
*  This function clears all capture data from the capture FIFO
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Timeout_timer_ClearFIFO(void) 
{
    while(0u != (Timeout_timer_ReadStatusRegister() & Timeout_timer_STATUS_FIFONEMP))
    {
        (void)Timeout_timer_ReadCapture();
    }
}

#endif /* UDB Specific Functions */


/* [] END OF FILE */
