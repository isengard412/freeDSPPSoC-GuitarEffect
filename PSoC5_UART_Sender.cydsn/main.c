/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Interacts with UART component
*
*******************************************************************************/

#include "main.h"


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Interaction with UART component
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
    
    CyGlobalIntEnable;

    UARTinit();
    
    for(;;)
    {

        UARTsendString("Blabla\n");
        UARTsendNumber(1234);
        
        CyDelay(500);
        
        
    }
}



/* [] END OF FILE */
