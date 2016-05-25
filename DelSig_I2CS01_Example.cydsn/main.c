/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is source code for the 8-ch DelSig ADC and I2C Slave Example Project.
*
* Parameters used:
*  I2C Slave
*   Implementation        Fixed function
*   Data rate            100kbps
*   SDA SCL config         Open drain, drives low
*   Pull-up resistors    2.67k each
*    Address                8
*    Address decode        Hardware
*
*  Delta Sigma ADC
*      Conversion mode     1-Multi Sample
*    Resolution            16 bits
*    Conversion Rate        5000 SPS
*    Input mode            Differential
*
*  IDAC
*    Polarity            Positive
*    Range                0-31.875 uA
*    Speed                Slow
*    Output Current        10uA
*
*  Sequencing Max
*    Mux type            Differential
*    Channels            8
*
* In this project, data converted by the 8-channel, sequenced ADC is sent via
* I2C. The main project containing an I2C slave is tested with a separate
* project containing an I2C master. The data output by the ADC is made
* visible on an Character LCD. This can be used to verify the data
* received by the I2C master which is also displayed on an LCD screen.
*
* The communication flow is as follows:
* When the device is reset, all components are started and an initial ADC
* reading is taken. This is stored in the read buffer of the I2C slave and
* the ADC is stopped. Then the infinite 'for' loop begins. Only if the correct
* number of bytes of the read buffer are read by the I2C master, a new reading
* is taken from the ADC and the loop continues.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/
#include <device.h>

/* Set the write buffer length to be 16 bites or 2 bytes */
#define RD_BUFFER_SIZE        (2u)


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main function performs following functions:
*   1. Starts all used components.
*   2. Controls sequencing of ADC inputs.
*   3. Reads ADC converted data, puts this in a read buffer to be read by the
*       I2C Master.
*   4. Displays ADC converted data on Character LCD.
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
    /* To conserve memory space, set up temporary variable for storing ADC
     * converted values and the write buffer as a union.
     */

    uint8 byteCount = 0u;
    uint8 sample_segment[RD_BUFFER_SIZE];
    uint16 sample_full = 0u;

    /* Set up slave read data buffer */
    I2CS_SlaveInitReadBuf((uint8 *) sample_segment, RD_BUFFER_SIZE);

    I2CS_Start();
    IDAC8_Start();

    /* The Start API for Mux sets it up, but disconnects all the channels.
     * To connect the first channel, call the 'AMuxSeq_Next' function
     */
    AMuxSeq_Start();
    AMuxSeq_Next();

    LCD_Char_Start();
    ADC_DelSig_Start();
    ADC_DelSig_StartConvert();

    /* Enable global interrupts - needed for I2C operation */
    CyGlobalIntEnable;

    for(;;)
    {
        /* Check if the slave buffer has been read */
        if(I2CS_SlaveStatus() & I2CS_SSTAT_RD_CMPLT)
        {
            ADC_DelSig_StartConvert();
            ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT);
            ADC_DelSig_StopConvert();
            AMuxSeq_Next();
        
            byteCount = I2CS_SlaveGetReadBufSize();
            I2CS_SlaveClearReadStatus();
            I2CS_SlaveClearReadBuf();

            /* If both bytes of the read buffer have been read */
            if(byteCount == RD_BUFFER_SIZE)
            {
                /* Display data that was placed in the buffer on the LCD and verify
                 * this is same as that received by master */
                LCD_Char_ClearDisplay();
                LCD_Char_PrintString("0x");
                LCD_Char_PrintInt16(sample_full);

                /* Disable the interrupts when writing to the Read buffer
                 * so that the Master cannot read the slave buffer during the act of writing
                 * to the buffer.
                 */
                CyGlobalIntDisable;
                sample_full = ADC_DelSig_GetResult16();
                sample_segment[0] = sample_full >> 8u & 0x00FF;
                sample_segment[1] = sample_full & 0x00FF;
                CyGlobalIntEnable;
            }

            else /* Wrong number of bytes read - place error handling code here */
            {
                LCD_Char_ClearDisplay();
                LCD_Char_PrintString("I2C Error!");
            }
        }
    } /* End of forever loop */
} /* End of main */


/* [] END OF FILE */
