/*******************************************************************************
* File: main.c
*
* Version: 2.2
*
* Description:
*   This is a basic design source code.
*
* Note:
*  Pin_Vin pin (P0[4]) should be connected to the VR.
*  Verify that VR_PWR(J11) is jumpered to ON.
*
* Hardware Dependency:
*  CY8CKIT-001 DVK
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>

#define ADC_NUMBER_SAMPLES (15)

/* Initialize array elements to zero. */
int16 samples[ADC_NUMBER_SAMPLES] = {0};

/* Defining and initializing the index */
int8 sampleIndex = 0u;

/* Sample read from ADC */
volatile int16 currentSample;

/* Indicator for when sample is available */
volatile uint8 sampleAvailable = 0u;


/*******************************************************************************
* Function Name: InterruptHandler
********************************************************************************
*
* Summary:
*   The Interrupt Service Routine for isr_1.
*
* Parameters:
*   None.
*
* Return:
*   void.
*
*******************************************************************************/
CY_ISR(InterruptHandler)
{
    /* Get the result */
    currentSample = ADC_DelSig_1_GetResult16();
    sampleAvailable = 1u;
}


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
* Main function performs following functions:
* 1: Start the LCD
* 2: Start ADC DelSig and its interrupt
* 3: Start the Timer
* 4: Testing for sample available from ADC
* 5: Storing the sample into the array
* 6: Calculate and show average voltage
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
    int8 i;
    int16 voltageMv;
    int32 sampleAverage;
    
    /* Start and initialize the LCD */
    LCD_Start();
    LCD_PrintString("ADC OUTPUT: ");
    LCD_Position(1u, 0u);
    LCD_PrintString("Voltage=     mV");

    /* Start the ADC */
    ADC_DelSig_1_Start();

    /* Start the embedded in the DelSig Interrupt and change the vector to the InterruptHandler */
    ADC_DelSig_1_IRQ_StartEx(InterruptHandler);

    /* Start the Timer which will start the ADC conversion */
    Timer_1_Start();

    CyGlobalIntEnable;

    for(;;)
    {
        /* Check whether ADC conversion complete or not */
        if (sampleAvailable)
        {
            sampleAvailable = 0u;

            /* storing the sample into the array, based on the index */
            samples[sampleIndex++] = currentSample;
            
            /* Print the ADC result on LCD */
            LCD_Position(0u, 11u);
            LCD_PrintInt16(currentSample);

            /* Calculate average result */
            if (sampleIndex == ADC_NUMBER_SAMPLES)
            {
                sampleAverage = 0u;
                for (i = 0u; i < ADC_NUMBER_SAMPLES; i++)
                {
                    sampleAverage += samples[i];
                }    
                sampleAverage /= ADC_NUMBER_SAMPLES;
                sampleIndex = 0u;

                /* Convert results to mV */
                voltageMv = ADC_DelSig_1_CountsTo_mVolts(sampleAverage);

                /* Print the averaged ADC voltage on LCD */
                LCD_Position(1u, 8u);
                LCD_PrintString("     ");
                if(voltageMv < 0)
                {
                    LCD_Position(1u, 8u);
                    LCD_PrintString("-");
                    voltageMv = -voltageMv;
                }    
                LCD_Position(1u, 9u);
                LCD_PrintNumber(voltageMv);
            }
        }
    }
}


/* [] END OF FILE */
