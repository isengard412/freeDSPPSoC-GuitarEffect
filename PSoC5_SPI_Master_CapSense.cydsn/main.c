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

//int main()
//{
//    //Tuning
//    CYGlobalIntEnable;
//    CapSense_1_TunerStart();
//    /*All widgets are enabled by default except proximity widgets. Proximity
//    widgets must be manually enabled as their long scan time is incompatible
//    with the fast response required of other widget types.
//    */
//    while(1)
//    {
//    CapSense_1_TunerComm();
//    }
//}

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
    //UARTinit();
    CapSenseInit();
    SPIinit();
    /***** Initialization completed *****/
    
    uint32 pos = 30000;
    
    for(;;)
    {

        LED_Write(!LED_Read());
        /* Next command to be written */
        pos = CapSense_Refresh();
        if(pos!=0xFFFFFFFF){
            //UARTsendNumber((uint8)pos);
            SPIsendNumber((uint8)pos);
        }


    }  /* End of forever loop */
}  /* End of main */


/* [] END OF FILE */
