/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*  Interaction with DSP
*
*******************************************************************************/

#include "main.h"


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
    /* Enable Global interrupts */
    CyGlobalIntEnable;
    /*Activating UART */
    UARTinit();
    /* Initializing DSP */
    DSPinit();
    /* Activating I2S Communication */
    //I2Sinit();
    //i2s input
    //DSPi2sInput(1);
    /* Activatind PSoC Communication */
    SPISinit();
    
    /***** Initialization completed *****/
    
    //generated input
    DSPi2sInput(0);
    DSPpitch(0u);

    
    for(;;)
    {
//        /* Wert zwischen +-34953 */
//        int32 i;
//        for(i=0;i<=34953;i+=3495)
//        {
//            DSPpitch(i);
//            CyDelay(250);
//            DSPpitch(-i);
//            CyDelay(250);
//        }
        LED_Write(!LED_Read());
        UARTsendNumber(SPISreadNumber());
        


    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
