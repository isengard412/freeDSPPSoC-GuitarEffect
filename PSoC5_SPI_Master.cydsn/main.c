/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is source code for example project of the 4ch dual SAR with SPI Master
*  and USBUART.
*
* Parameters used:
*  SPI Master
*   Mode                0(CPHA ==0, CPOL ==0)
*   Data lines          MOSI+MISO
*   Shift direction     MSB First
*   DataBits            16
*   Bit Rate            1Mbit/s
*   Clock source        External
*
*  USBFS
*    Configured as a CDC device (see datasheet and USBUART example project)
*    Note that for USB operation, a 24MHz crystal needs to be installed on
*    processor module for CY8CKIT-001.
*
*  SAR ADCs
*      Sample mode             Triggered
*     Clock source         Internal
*    Resolution            12 bits
*    Conversion Rate        100000 SPS
*    Input range            +/- Vdda (Differential)
*    Reference            Internal Vref bypassed
*    Bypass Capacitors    10uF each
*
*  IDAC
*    Polarity            Positive
*    Range                0-31.875 uA
*    Speed                Slow
*    Value                10uA
*
*  Analog Mux
*    Mux type            Differential
*    Channels            4
*
*  Clocking
*    IMO source            24 MHz Xtal
*    USB                    48 MHz (IMO*2)
*    ILO                    100 kHz
*
* In this project, data input to two 4ch SAR ADCs via two 4ch analog muxes
* is converted and sent to a USB host device and a SPI slave device. To
* accomplish this, the central PSoC device implements a SPI Master and USB UART
* for communication. The USB host device can select which channel of the mux is
* to be read.
*
* To access the PSoC using the USBUART follow these steps:
*    1. Connect CY8CKIT-001 to the PC using USB cable.
*    2. Select the USB_UART.inf file from the project directory, as the driver
*      for this example once Windows asks for it.
*    3. Go to Start > Devices and Printers and identify COM port number
*       associated with the project.
*    4. Open a terminal emulation software and connect to COM port number
*       identified in previous step.
*    5. The input window will open with a blank screen. Type in a channel value.
*******************************************************************************/

#include "main.h"

/* Function that encapsulates the process of writing text strings to USBUART */
void PrintToUSBUART(char8 * outText);


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main() sends things via SPI and UART simmultaniously
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
    /* adcReading holds the converted 16-bit data from the ADC */
    uint16 value = 255u;


    /* Enable Global interrupts - used for USB communication */
    CyGlobalIntEnable;

    SPIinit();
    UARTinit();

    for(;;)
    {
        //PrintToUSBUART("Please choose the channel (0-7) \n\r");
        UARTsendString("Now sending via SPI\n\r");

        value++;
        SPIsendNumber(value);
        
        sprintf((char *)wrBuffer, "The value is: 0x%4x \n\r\n\r", value);
        UARTsendString((char8 *)wrBuffer);
        CyDelay(500);
        
        

    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
