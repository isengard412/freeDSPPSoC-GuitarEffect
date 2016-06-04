/*******************************************************************************
* File Name: main.c
*
* Version: 1.00
*
* Description:
*  This is the source code for the Interrupts example project of the Interrupt
*  and cy_boot components.
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>

#define NESTED_ISR                          (1u)
#define DEFAULT_PRIORITY                    (3u)
#define HIGHER_PRIORITY                     (2u)

#if(CY_PSOC4)
    #define LIGHT_OFF                       (1u)
    #define LIGHT_ON                        (0u)
#else
    #define LIGHT_OFF                       (0u)
    #define LIGHT_ON                        (1u)
#endif /* (CY_PSOC4) */

/* Interrupt prototypes */
CY_ISR_PROTO(GPIOIsrHandler);
CY_ISR_PROTO(NestedIsrHandler);


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  At the beginning of the main function, the GPIO interrupt is set up and
*  enabled. After that, initial priority for the GPIO interrupt is changed from
*  1 to 3 (DEFAULT_PRIORITY). The custom interrupt (nested) is configured
*  (sets up, sets priority) and enabled. In GPIOIsrHandler, the isr_GPIO
*  pending interrupt clears, the green LED turns on, the nested software
*  interrupt causes after approximately 1 second delay, green LED turns off.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{
    /* Set initial state (off) for LED */
    LED_Isr_Write(LIGHT_OFF);
    LED_Nested_Write(LIGHT_OFF);

    /* Sets up the GPIO interrupt and enables it */
    isr_GPIO_StartEx(GPIOIsrHandler);

    /* Changes initial priority for the GPIO interrupt */
    isr_GPIO_SetPriority(DEFAULT_PRIORITY);

    /* Sets up the nested interrupt, sets priority and enables it */
    CyIntSetVector(NESTED_ISR,NestedIsrHandler);
    CyIntSetPriority(NESTED_ISR,HIGHER_PRIORITY);
    CyIntEnable(NESTED_ISR);

    /* Enable global interrupts */
    CyGlobalIntEnable;

    for(;;)
    {
    }
}


/*******************************************************************************
* Function Name: GPIOIsrHandler
********************************************************************************
* Summary:
*  The interrupt handler for GPIO interrupts.
*  Clears a pending Interrupt.
*  Clears a pin Interrupt.
*  Blinks the LED with the LED_Isr pin.
*  Calls nested interrupt.

*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(GPIOIsrHandler)
{
    /* Clear pending Interrupt */
    isr_GPIO_ClearPending();
    
    /* Clear pin Interrupt */
    Pin_Sw_ClearInterrupt();
    
    /* Turn On the LED */
    LED_Isr_Write(LIGHT_ON);

    /* Cause nested software interrupt after 1000 ms */
    CyDelay(1000u);
    CyIntSetPending(NESTED_ISR);

    /* Turn Off the LED */
    LED_Isr_Write(LIGHT_OFF);
}


/*******************************************************************************
* Function Name: NestedIsrHandler
********************************************************************************
* Summary:
*  The interrupt handler for nested interrupt.
*  Blinks the LED with the LED_Nested pin.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(NestedIsrHandler)
{
    /* Clear pending Interrupt */
    CyIntClearPending(NESTED_ISR);

    /* Turn On the LED for 1000 ms */
    LED_Nested_Write(LIGHT_ON);
    CyDelay(1000u);

    /* Turn Off the LED and wait for 1000 ms */
    LED_Nested_Write(LIGHT_OFF);
    CyDelay(1000u);
}

/* [] END OF FILE */
