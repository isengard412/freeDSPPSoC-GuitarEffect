/*******************************************************************************
* File Name: timeout_interrupt.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <timeout_interrupt.h>
#include "cyapicallbacks.h"

#if !defined(timeout_interrupt__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START timeout_interrupt_intc` */

/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: timeout_interrupt_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timeout_interrupt_Start(void)
{
    /* For all we know the interrupt is active. */
    timeout_interrupt_Disable();

    /* Set the ISR to point to the timeout_interrupt Interrupt. */
    timeout_interrupt_SetVector(&timeout_interrupt_Interrupt);

    /* Set the priority. */
    timeout_interrupt_SetPriority((uint8)timeout_interrupt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    timeout_interrupt_Enable();
}


/*******************************************************************************
* Function Name: timeout_interrupt_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void timeout_interrupt_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    timeout_interrupt_Disable();

    /* Set the ISR to point to the timeout_interrupt Interrupt. */
    timeout_interrupt_SetVector(address);

    /* Set the priority. */
    timeout_interrupt_SetPriority((uint8)timeout_interrupt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    timeout_interrupt_Enable();
}


/*******************************************************************************
* Function Name: timeout_interrupt_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timeout_interrupt_Stop(void)
{
    /* Disable this interrupt. */
    timeout_interrupt_Disable();

    /* Set the ISR to point to the passive one. */
    timeout_interrupt_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: timeout_interrupt_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for timeout_interrupt.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(timeout_interrupt_Interrupt)
{
    #ifdef timeout_interrupt_INTERRUPT_INTERRUPT_CALLBACK
        timeout_interrupt_Interrupt_InterruptCallback();
    #endif /* timeout_interrupt_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START timeout_interrupt_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: timeout_interrupt_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling timeout_interrupt_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use timeout_interrupt_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void timeout_interrupt_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)timeout_interrupt__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: timeout_interrupt_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress timeout_interrupt_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)timeout_interrupt__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: timeout_interrupt_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling timeout_interrupt_Start or timeout_interrupt_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after timeout_interrupt_Start or timeout_interrupt_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void timeout_interrupt_SetPriority(uint8 priority)
{
    *timeout_interrupt_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: timeout_interrupt_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 timeout_interrupt_GetPriority(void)
{
    uint8 priority;


    priority = *timeout_interrupt_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: timeout_interrupt_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timeout_interrupt_Enable(void)
{
    /* Enable the general interrupt. */
    *timeout_interrupt_INTC_SET_EN = timeout_interrupt__INTC_MASK;
}


/*******************************************************************************
* Function Name: timeout_interrupt_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 timeout_interrupt_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*timeout_interrupt_INTC_SET_EN & (uint32)timeout_interrupt__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: timeout_interrupt_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timeout_interrupt_Disable(void)
{
    /* Disable the general interrupt. */
    *timeout_interrupt_INTC_CLR_EN = timeout_interrupt__INTC_MASK;
}


/*******************************************************************************
* Function Name: timeout_interrupt_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void timeout_interrupt_SetPending(void)
{
    *timeout_interrupt_INTC_SET_PD = timeout_interrupt__INTC_MASK;
}


/*******************************************************************************
* Function Name: timeout_interrupt_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void timeout_interrupt_ClearPending(void)
{
    *timeout_interrupt_INTC_CLR_PD = timeout_interrupt__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
