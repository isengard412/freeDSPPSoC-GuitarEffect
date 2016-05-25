/*******************************************************************************
* File Name: uart.c
*
* Version: 1.0
* Author: Lukas Creutzburg
*
* Description:
*   Component sends data via UART
*
*******************************************************************************/

#include "uart.h"

char8* parity[] = {"None", "Odd", "Even", "Mark", "Space"};
char8* stop[]   = {"1", "1.5", "2"};

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Initialize communication
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void UARTinit()
{
    /* Start USBFS operation with 5-V operation. */
    USBUART_Start(USBFS_DEVICE, USBUART_5V_OPERATION); 
}

/*******************************************************************************
* Function Name: UARTsendString
********************************************************************************
*
* Summary:
*  Sending a string via UART
*
* Parameters:
*  char string[]
*
* Return:
*  None.
*
*******************************************************************************/
void UARTsendString(char string[])
{
    /* Host can send double SET_INTERFACE request. */
    if (0u != USBUART_IsConfigurationChanged())
    {
        /* Initialize IN endpoints when device is configured. */
        if (0u != USBUART_GetConfiguration())
        {
            /* Enumeration is done, enable OUT endpoint to receive data 
             * from host. */
            USBUART_CDC_Init();
        }
    }

    /* Service USB CDC when device is configured. */
    if (0u != USBUART_GetConfiguration())
    {
        /* Wait until component is ready to send data to host. */
        while (0u == USBUART_CDCIsReady())
        {
        }

        /* Send data back to host. */
        //USBUART_PutData(buffer, count);
        USBUART_PutString(string);       
    }
}

/*******************************************************************************
* Function Name: UARTsendNumber
********************************************************************************
*
* Summary:
*  Sending a number via UART
*
* Parameters:
*  char string[]
*
* Return:
*  None.
*
*******************************************************************************/
void UARTsendNumber(uint32 number)
{
    /* Host can send double SET_INTERFACE request. */
    if (0u != USBUART_IsConfigurationChanged())
    {
        /* Initialize IN endpoints when device is configured. */
        if (0u != USBUART_GetConfiguration())
        {
            /* Enumeration is done, enable OUT endpoint to receive data 
             * from host. */
            USBUART_CDC_Init();
        }
    }

    /* Service USB CDC when device is configured. */
    if (0u != USBUART_GetConfiguration())
    {
        /* Wait until component is ready to send data to host. */
        while (0u == USBUART_CDCIsReady())
        {
        }

        /* Send data back to host. */
        //USBUART_PutData(buffer, count);
        int bytesWritten; 
        char myString[50]; 
        bytesWritten = sprintf(myString, "%lu", number); 
        myString[bytesWritten]='\r';
        myString[bytesWritten+1]='\n';
        myString[bytesWritten+2]='\0';
        USBUART_PutString(myString);       
    }
}



/* [] END OF FILE */
