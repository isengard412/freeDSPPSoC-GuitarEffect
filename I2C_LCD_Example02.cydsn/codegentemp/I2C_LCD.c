/*******************************************************************************
* File Name: I2C_LCD.c
* Version 1.20
*
* Description:
*  This file provides source code for the I2C LCD component's API.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2C_LCD.h"


/* Internal function ptototypes */
static void I2C_LCD_WrDataToBuff(uint8 dByte) CYREENTRANT;
static void I2C_LCD_WrCntrlPatt(uint8 cmdIndex) CYREENTRANT;
static void I2C_LCD_SendSequence(void) CYREENTRANT;

#if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)
    static void I2C_LCD_SendCmd(uint8 cmd) CYREENTRANT;
#endif /* I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X */

uint8 I2C_LCD_initVar = 0u;

/* Buffer that holds data to be send to LCD slave */
static uint8 I2C_LCD_buff[I2C_LCD_BUFF_SIZE];

/* Need to have I2C_LCD_buffIndex of different size to avoid MISRA
* warning when SCB based I2C Master is used. 
*/
#if(I2C_LCD_IS_SCB_MASTER_USED)
    /* Variable used for buffer indexing */
    static uint32 I2C_LCD_buffIndex = 0u;
    /* Variable stores the I2C address */
    static uint32 I2C_LCD_address = I2C_LCD_DEFAULT_I2C_ADDRESS;
#else
    /* Variable used for buffer indexing */
    static uint8 I2C_LCD_buffIndex = 0u;
    /* Variable stores the I2C address */
    static uint8 I2C_LCD_address = I2C_LCD_DEFAULT_I2C_ADDRESS;
#endif /* (I2C_LCD_IS_SCB_MASTER_USED) */

/********************
* Generated Code
********************/
/* Array with command patterns */
static const uint8 CYCODE I2C_LCD_cmdPatt[19u][3u] =
{
    /* Command pattern for writing data */
    {0x01u, 0x40u, 0x00u},
    /* Display on, cursor off */
    {0x02u, 0x00u, 0x0Cu},
    /* Display and cursor off */
    {0x02u, 0x00u, 0x08u},
    /* Set cursor position */
    {0x01u, 0x00u, 0x80u},
    /* Cursor home */
    {0x02u, 0x00u, 0x02u},
    /* Reset cursor position */
    {0x02u, 0x00u, 0x03u},
    /* Move cursor left one place */
    {0x02u, 0x00u, 0x10u},
    /* Move cursor right one place */
    {0x02u, 0x00u, 0x14u},
    /* Underline cursor on */
    {0x02u, 0x00u, 0x0Eu},
    /* Display - on, cursor - off, set cursor wink */
    {0x02u, 0x00u, 0x0Du},
    /* Display - on, cursor - off, set cursor blink */
    {0x02u, 0x00u, 0x0Fu},
    /* Clear screen */
    {0x02u, 0x00u, 0x01u},
    /* Load custom character */
    {0x02u, 0x00u, 0x40u},
    /* Set display for 2 lines and 16 characters */
    {0x02u, 0x00u, 0x24u},
    /* Move cursor/shift display right (cursor position auto increment) */
    {0x02u, 0x00u, 0x06u},
    /* Move cursor/shift display right (cursor position auto decrement) */
    {0x02u, 0x00u, 0x04u},
    /* Custom command */
    {0x02u, 0x00u, 0x25u},
    /* Custom command */
    {0x02u, 0x00u, 0x05u},
    /* Custom command */
    {0x02u, 0x00u, 0x04u}
};

/********************
* Generated Code 
********************/
/* Optional: Array with custom character set */
uint8 const CYCODE I2C_LCD_customFonts[64u] =
{
    0x00u, 0x0Eu, 0x08u, 0x08u, 0x08u, 0x0Eu, 0x00u, 0x00u, 
    0x00u, 0x0Au, 0x0Au, 0x04u, 0x04u, 0x04u, 0x00u, 0x00u, 
    0x00u, 0x0Eu, 0x0Au, 0x0Eu, 0x08u, 0x08u, 0x00u, 0x00u, 
    0x00u, 0x0Eu, 0x0Au, 0x0Cu, 0x0Au, 0x0Au, 0x00u, 0x00u, 
    0x00u, 0x0Eu, 0x08u, 0x0Cu, 0x08u, 0x0Eu, 0x00u, 0x00u, 
    0x00u, 0x0Eu, 0x08u, 0x0Eu, 0x02u, 0x0Eu, 0x00u, 0x00u, 
    0x00u, 0x0Eu, 0x08u, 0x0Eu, 0x02u, 0x0Eu, 0x00u, 0x00u, 
    0x00u, 0x04u, 0x04u, 0x04u, 0x00u, 0x04u, 0x00u, 0x00u
};


/*******************************************************************************
* Function Name: I2C_LCD_Init
********************************************************************************
*
* Summary:
*  Performs initialization required for the component's normal work.
*  I2C_LCD_Init() also loads the custom character set if it was defined in the
*  Configure dialog.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_Init(void) 
{
    /* Following part of code is only applicable for NXP LCDs */
    #if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)
        /* Select Extended Instruction set, 2x16 display */
        I2C_LCD_SendCmd(I2C_LCD_SET_EXTENDED_FUNC);
        /* Split screen configuration  */
        I2C_LCD_SendCmd(I2C_LCD_SPLIT_SCREEN);
        /* LCD Module format: left to right column, and top to bottom rows  */
        I2C_LCD_SendCmd(I2C_LCD_DISP_CONF);
        /* Icon mode not supported. Disable all icon enable settings */
        I2C_LCD_SendCmd(I2C_LCD_ICON_CTL);
        /* Set LCD bias voltage to 4.38 V since LCD module datasheet recommends 4.4 V */
        I2C_LCD_SendCmd(I2C_LCD_VLCD_SET);
        /* Select Standard Instruction set, 2x16 display */
        I2C_LCD_SendCmd(I2C_LCD_FUNCTION_SET_STANDARD);
    #endif /* (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X) */
    
    /* Configure LCD for 2 lines and 16 characters */
    I2C_LCD_WriteControl(I2C_LCD_DISPLAY_2_LINES_5x10);
    /* Turn on both display and cursor */
    I2C_LCD_WriteControl(I2C_LCD_DISPLAY_CURSOR_ON);
    /* Turn on cursor auto incrementing */
    I2C_LCD_WriteControl(I2C_LCD_CURSOR_AUTO_INCR_ON);
    /* Turn off cursor underlining */
    I2C_LCD_WriteControl(I2C_LCD_DISPLAY_ON_CURSOR_OFF);
    /* Clear the Display */
    I2C_LCD_ClearDisplay();
    
    /* Load custom character set */
    #if(I2C_LCD_CUSTOM_CHAR_SET != I2C_LCD_NONE)
        I2C_LCD_LoadCustomFonts(I2C_LCD_customFonts);
    #endif /* I2C_LCD_CUSTOM_CHAR_SET != I2C_LCD_NONE */
}


/*******************************************************************************
* Function Name: I2C_LCD_Enable
********************************************************************************
*
* Summary:
*  Turns on the display.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
* Theory:
*  This function has no effect when it called first time as
*  I2C_LCD_Init() turns on the LCD.
*
*******************************************************************************/
void I2C_LCD_Enable(void) 
{
    I2C_LCD_DisplayOn();
}


/*******************************************************************************
* Function Name: I2C_LCD_Start
********************************************************************************
*
* Summary:
*  This function initializes the LCD hardware module as follows:
*       Initialize the I2C bus if it hasn't already been
*       Clears the display;
*       Enables auto cursor increment;
*       Resets the cursor to start position;
*       It also loads a custom character set to LCD if it was defined in the
*  customizer's GUI.
*
* Parameters:
*  I2C_LCD_initVar - global variable.
*
* Return:
*  I2C_LCD_initVar - global variable.
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_Start(void) 
{
    /* If not initialized then perform initialization */
    if(I2C_LCD_initVar == 0u)
    {
        I2C_LCD_Init();
        I2C_LCD_initVar = 1u;
    }

    /* Turn on the LCD */
    I2C_LCD_Enable();
}


/*******************************************************************************
* Function Name: I2C_LCD_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen but does not stop the I2C Master
*  component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_Stop(void) 
{
    I2C_LCD_DisplayOff();
}


/*******************************************************************************
*  Function Name: I2C_LCD_Position
********************************************************************************
*
* Summary:
*  Moves the cursor to the location specified by arguments row and column.
*
* Parameters:
*  row:     The row number at which to position the cursor. Minimum value is
*           zero.
*  column:  The column number at which to position the cursor. Minimum value is
*           zero.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_Position(uint8 row, uint8 column) 
{
    /* Write command pattern for "Set cursor position" to buffer */
    I2C_LCD_WrCntrlPatt(I2C_LCD_DDRAM_0_IDX);

    #if(I2C_LCD_LENGTH_2_BYTES == I2C_LCD_DDRAM_0_DATA_LEN)
        /* In case when there two bytes of data for "Set cursor position" it is
        * required to send both row and column. The numeration of rows and 
        * columns starts from '1' so the row and column should be incremented.
        */
        I2C_LCD_WrDataToBuff(column + 1u);
        I2C_LCD_WrDataToBuff(row + 1u);
    #else
        /* Position is sent as one byte so it is required to calculate the position */
        switch (row)
        {
            case (uint8) 0u:
                /* To avoid MISRA warnig */
                #if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)
                    I2C_LCD_WrDataToBuff(I2C_LCD_ROW_0_START + column);
                #else
                    I2C_LCD_WrDataToBuff(column);
                #endif /* (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X) */
                
                break;
            
            case (uint8) 1u:
                I2C_LCD_WrDataToBuff(I2C_LCD_ROW_1_START + column);
                break;
            
            case (uint8) 2u:
                I2C_LCD_WrDataToBuff(I2C_LCD_ROW_2_START + column);
                break;
            
            case (uint8) 3u:
                I2C_LCD_WrDataToBuff(I2C_LCD_ROW_3_START + column);
                break;
            
            default:
                /* if default case is hit, invalid row argument was passed.*/
                break;
        }        
    #endif /* (I2C_LCD_LENGTH_2_BYTES == I2C_LCD_SET_POS_DATA_LEN) */

    /* Send data to LCD and wait when transaction complete */
    I2C_LCD_SendSequence();
}


/*******************************************************************************
*  Function Name: I2C_LCD_WriteData
********************************************************************************
*
* Summary:
*  Writes data to the LCD RAM in the current position. Upon write completion,
*  the position is incremented or decremented depending on the entry mode
*  specified.
*
* Parameters:
*  dByte:  The byte to be written to the LCD module.
*
* Return:
*  None.
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_WriteData(uint8 dByte) 
{
    /* Send required control byte value to address data register */
    I2C_LCD_WrCntrlPatt(I2C_LCD_WRITE_DATA_IDX);

    /* Add byte of data to buffer */
    I2C_LCD_WrDataToBuff(dByte);

    /* Send data to LCD and wait when transaction complete */
    I2C_LCD_SendSequence();
}


/*******************************************************************************
*  Function Name: I2C_LCD_WrDataToBuff
********************************************************************************
*
* Summary:
*  Writes a byte of data to the display buffer.
*
* Parameters:
*  nibble:  the byte containing nibble in least significant nibble to be written
*           to the LCD module.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
static void I2C_LCD_WrDataToBuff(uint8 dByte) CYREENTRANT
{
    /* Put one byte of data to buffer at location of I2C_LCD_buffIndex */
    I2C_LCD_buff[I2C_LCD_buffIndex] = dByte;
    /* Increment I2C_LCD_buffIndex to point to next free position */
    I2C_LCD_buffIndex++;
}


/*******************************************************************************
*  Function Name: I2C_LCD_WriteControl
********************************************************************************
*
* Summary:
*  Writes a command byte to the LCD module. Different LCD models can have their
*  own commands. Review the specific LCD datasheet for commands valid for that
*  model.
*
* Parameters:
*  cByte:   An 8-bit value representing the command to be loaded into the command
*  register of the LCD module. Valid command parameters are specified in the
*  table below:
*   I2C_LCD_CLEAR_DISPLAY          Clear display.
*   I2C_LCD_CURSOR_HOME            Return cursor and LCD to home
*                                           position.
*   I2C_LCD_SET_CURSOR_POSITION    Set position of cursor.
*   I2C_LCD_DISPLAY_CURSOR_OFF     Disable display and cursor.
*   I2C_LCD_DISPLAY_CURSOR_ON      Enable display and cursor.
*   I2C_LCD_DISPLAY_ON_CURSOR_OFF
*   I2C_LCD_DISPLAY_ON             Enable display, cursor off.
*   I2C_LCD_CURSOR_BLINKING_ON     Enable display, cursor on, set
*                                           cursor blink.
*   I2C_LCD_CURSOR_BLINKING_OFF    Enable display, cursor on, cursor
*                                           blinking off.
*   I2C_LCD_SET_CGRAM_ADDR         Set position to the specific
*                                           address in CGRAM (used for loading
*                                           custom characters).
*   I2C_LCD_CURSOR_AUTO_INCR_ON    Enable auto increment of cursor
*                                           position.
*   I2C_LCD_DISPLAY_2_LINES_16     Set display to be 2 lines 16
*                                           characters.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_WriteControl(uint8 cByte) 
{
    uint8 cmdIndx = 0u;
    
    while(cmdIndx < I2C_LCD_NUM_COMMANDS)
    {   
        if (cByte == I2C_LCD_cmdPatt[cmdIndx][I2C_LCD_COMMAND_BYTE_INDEX])
        {
            /* Fill control pattern based on found index */
            I2C_LCD_WrCntrlPatt(cmdIndx);

            /* Send data to LCD and wait when transaction complete */
            I2C_LCD_SendSequence();

            /* Following commands require 1.5 ms delay to execute */
            switch(cByte)
            {
                case I2C_LCD_CLEAR_DISPLAY :
                case I2C_LCD_CURSOR_HOME :
                case I2C_LCD_DISPLAY_CURSOR_ON :
                case I2C_LCD_DISPLAY_CURSOR_OFF :
                    CyDelayUs(I2C_LCD_CMOMMAND_DELAY);
                    break;
                default:
                    break;
            }
            /* Command index was found - break while() loop */
            break;
        }
        /* Increment command pattern index */
        cmdIndx++;
    } 
}


/*******************************************************************************
*  Function Name: I2C_LCD_WrCntrlPatt
********************************************************************************
*
* Summary:
*  Writes a control pattern to the buffer that will be later send to the LCD
*  module.
*
* Parameters:
*  cmdIndex: Index of the command pattern in the look-up array.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
static void I2C_LCD_WrCntrlPatt(uint8 cmdIndex) CYREENTRANT
{
    /* Need to have index 'i' of different size to avoid MISRA
    * warning when SCB based I2C Master is used. 
    */
    #if(I2C_LCD_IS_SCB_MASTER_USED)
        uint32 i;
    #else
        uint8 i;
    #endif /* (I2C_LCD_IS_SCB_MASTER_USED) */

    /* Fill buffer with command pattern */
    for(i = 1u; i <= I2C_LCD_cmdPatt[cmdIndex][0u]; i++)
    {
        I2C_LCD_buff[i - 1u] =  I2C_LCD_cmdPatt[cmdIndex][i];
    }

    /* Set index to point on next free position in buffer */
    I2C_LCD_buffIndex = i - 1u;
}


/*******************************************************************************
*  Function Name: I2C_LCD_SendSequence
********************************************************************************
*
* Summary:
*  Sends the content of the buffer to the LCD module and waits while transaction
*  completes. In the end resets index to point to the start of the buffer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
static void I2C_LCD_SendSequence(void) CYREENTRANT
{
    /* Send command pattern to LCD */
    (void) I2C_LCD_MasterWriteBuf(I2C_LCD_address,
                                           I2C_LCD_buff,
                                           I2C_LCD_buffIndex,
                                           I2C_LCD_MODE_COMPLETE_XFER);

    while(0u == (I2C_LCD_MasterReadStatus() & I2C_LCD_WRITE_COMPLETE))
    {
        /* Wait until I2C Master finishes transaction */
    }

    /* Reset buffer index */
    I2C_LCD_buffIndex = 0u;
}


/*******************************************************************************
* Function Name: I2C_LCD_HandleCustomCommand
********************************************************************************
*
* Summary:
*  This command adds a support of sending custom commands with parameters.
*
* Parameters:
*  uint8 cmdId: Command code.
*  uint8 dataLength: The length of data to be send for this command.
*  uint8 cmdData[]: The data to be send to I2C LCD.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_HandleCustomCommand(uint8 cmdId, uint8 dataLength, uint8 const cmdData[])
                                                        
{
    uint8 i;
    uint8 ch;
    uint8 cmdIndx = 0u;
    
    while(cmdIndx < I2C_LCD_NUM_COMMANDS)
    {   
        if (cmdId == I2C_LCD_cmdPatt[cmdIndx][I2C_LCD_COMMAND_BYTE_INDEX])
        {
             /* Write control pattern for specific command */
            I2C_LCD_WrCntrlPatt(cmdIndx);

            for(i = 0u; i < dataLength; i++)
            {
                /* Get next byte from array of data */
                ch = cmdData[i];

                /* Add current byte to buffer */
                I2C_LCD_WrDataToBuff((uint8) ch);
            }

            /* Send data to LCD and wait when transaction completes */
            I2C_LCD_SendSequence();
            /* The command index was found - break while() loop */
            break;
        }
        /* Increment command pattern index */
        cmdIndx++;
    } 
}


/*******************************************************************************
* Function Name: I2C_LCD_HandleOneByteCommand
********************************************************************************
*
* Summary:
*  This command adds a support of sending custom commands with 1 byte parameter.
*
* Parameters:
*  uint8 cmdId: Command code.
*  uint8 cmdByte: One byte of data to be send to I2C LCD.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_HandleOneByteCommand(uint8 cmdId, uint8 cmdByte)
                                                        
{
    uint8 oneByteArray[I2C_LCD_ONE_BYTE_LEN];
    
    oneByteArray[0u] = cmdByte;
    
    I2C_LCD_HandleCustomCommand(cmdId, I2C_LCD_ONE_BYTE_LEN, oneByteArray);
}


/*******************************************************************************
* Function Name: I2C_LCD_PrintString
********************************************************************************
*
* Summary:
*  Write a null-terminated string of characters to the screen beginning at the
*  current cursor location.
*
* Parameters:
*  string:  Null-terminated array of ASCII characters to be displayed on the LCD
*           module's screen.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_PrintString(char8 const string[]) 
{
    uint8 chIdx = 1u;
    char8 current = *string;

    /* Send required control byte value to address data register */
    I2C_LCD_WrCntrlPatt(I2C_LCD_WRITE_DATA_IDX);

    /* Until null is reached, put next character into buffer */
    while((char8) '\0' != current)
    {
        /* Add current byte to buffer */
        #if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)
            /* In case of NXP PCF2119x, LCD modules use character set "S"
            * (see LCD's module datasheet) that has English letters located in
            * "extended" area (ASCII code > 128) so it is required to handle
            * that. But the first eight generated character are exceptions.
            */
            if(((char8)(I2C_LCD_CUSTOM_CHAR_NUM)) > current)
            {
                I2C_LCD_WrDataToBuff((uint8) current);
            }
            else
            {
                I2C_LCD_WrDataToBuff(((uint8) current) ^ I2C_LCD_CHARACTER_SET_S_MASK);
            }
        #else
            I2C_LCD_WrDataToBuff((uint8) current);
        #endif /* ((I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X) && \
               * (I2C_LCD_CUSTOM_CHAR_SET != I2C_LCD_NONE))
               */

        /* Get next byte from string */
        current = string[chIdx];
        chIdx++;
    }

    /* Send data to LCD and wait when transaction completes */
    I2C_LCD_SendSequence();
}


/*******************************************************************************
*  Function Name: I2C_LCD_PutChar
********************************************************************************
*
* Summary:
*  Writes an individual character to the screen at the current cursor location.
*  Used to display custom characters through their named values.
*  (I2C_LCD_CUSTOM_0 through I2C_LCD_CUSTOM_7).
*
* Parameters:
*  character:  An ASCII character to be displayed on the LCD module's screen.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_PutChar(char8 character) 
{
    /* Send one byte of data with I2C_LCD_WriteData() */
    #if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)
        /* In case of NXP PCF2119x, the LCD modules use character set "S"
        * (see LCD's module datasheet) that has English letters located in
        * "extended" area (ASCII code > 128) so it is required to handle
        * that. But the first eight generated character are exceptions.
        */
        if(((char8) (I2C_LCD_CUSTOM_CHAR_NUM)) >  character)
        {
            I2C_LCD_WriteData((uint8) character);
        }
        else
        {
            I2C_LCD_WriteData(((uint8) character) ^ I2C_LCD_CHARACTER_SET_S_MASK);
        }
    #else
        I2C_LCD_WriteData((uint8) character);
    #endif /* (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X) */
}


/*******************************************************************************
*  Function Name: I2C_LCD_PrintInt8
********************************************************************************
*
* Summary:
*  Print a byte as two ASCII characters.
*
* Parameters:
*  value: The byte to be printed out as ASCII characters.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_PrintInt8(uint8 value) 
{
    static char8 const CYCODE I2C_LCD_hex[16u] = "0123456789ABCDEF";

    /* Send required control byte value to address data register */
    I2C_LCD_WrCntrlPatt(I2C_LCD_WRITE_DATA_IDX);

    /* Add current byte to buffer */
    #if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)
        /* In case of NXP PCF2119x, LCD modules use character set "S"
        * (see LCD's module datasheet) that has English letters located in
        * "extended" area (ASCII code > 128) so it is required to handle
        * that.
        */
        I2C_LCD_WrDataToBuff(((uint8) I2C_LCD_hex[value >> I2C_LCD_BYTE_UPPER_NIBBLE_SHIFT])
                                               ^ I2C_LCD_CHARACTER_SET_S_MASK );
        I2C_LCD_WrDataToBuff(((uint8) I2C_LCD_hex[value & I2C_LCD_BYTE_LOWER_NIBBLE_MASK]) ^
                                               I2C_LCD_CHARACTER_SET_S_MASK);
    #else
        I2C_LCD_WrDataToBuff((uint8) I2C_LCD_hex[value >> I2C_LCD_BYTE_UPPER_NIBBLE_SHIFT]);
        I2C_LCD_WrDataToBuff((uint8) I2C_LCD_hex[value & I2C_LCD_BYTE_LOWER_NIBBLE_MASK]);
    #endif /* (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X) */

    /* Send data to LCD and wait when transaction complete */
    I2C_LCD_SendSequence();
}


/*******************************************************************************
*  Function Name: I2C_LCD_PrintInt16
********************************************************************************
*
* Summary:
*  Print a uint16 as four ASCII characters.
*
* Parameters:
*  value:   The uint16 to be printed out as ASCII characters.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_PrintInt16(uint16 value) 
{
    I2C_LCD_PrintInt8((uint8)(value >> I2C_LCD_U16_UPPER_BYTE_SHIFT));
    I2C_LCD_PrintInt8((uint8)(value & I2C_LCD_U16_LOWER_BYTE_MASK));
}


/*******************************************************************************
*  Function Name: I2C_LCD_PrintNumber
********************************************************************************
*
* Summary:
*  Print a uint16 value as a left-justified decimal value.
*
* Parameters:
*  value:  The byte to be printed out as ASCII characters.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_PrintNumber(uint16 value) 
{
    char8 number[I2C_LCD_NUMBER_OF_REMAINDERS];
    char8 temp[I2C_LCD_NUMBER_OF_REMAINDERS];

    uint8 digIndex = 0u;
    uint8 numDigits;

    /* Load these in reverse order */
    while(value >= I2C_LCD_TEN)
    {
        temp[digIndex] = (value % I2C_LCD_TEN) + '0';
        value /= I2C_LCD_TEN;
        digIndex++;
    }

    temp[digIndex] = (value % I2C_LCD_TEN) + '0';
    numDigits = digIndex;

    /* While index is greater than or equal to zero copy number
    * from temporary array to number[].
    */
    while (digIndex != 0u)
    {
        number[numDigits - digIndex] = temp[digIndex];
        digIndex--;
    }

    /* Copy last digit */
    number[numDigits] = temp[0u];

    /* Null Termination */
    number[numDigits + 1u] = (char8) '\0';

    /* Print out number */
    I2C_LCD_PrintString(&number[0u]);
}


/*******************************************************************************
* Function Name: I2C_LCD_SetAddr
********************************************************************************
*
* Summary:
*  This function allows the user to change the default I2C address of the LCD.
*  This function is not used for designs with a single LCD. Systems that have 2
*  or more LCDs on a single I2C bus, use this function to select which LCD to
*  communicate. A uint8 variable I2C_LCD_address, will be will be set
*  to the "address" parameter and be used for all further communication until
*  it is changed to a new address.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void I2C_LCD_SetAddr(uint8 address) 
{
    #if(I2C_LCD_IS_SCB_MASTER_USED)
        I2C_LCD_address = ((uint32) address >> I2C_LCD_ADDRESS_SHIFT);
    #else
        I2C_LCD_address = ((uint8) address >> I2C_LCD_ADDRESS_SHIFT);
    #endif /* (I2C_LCD_IS_SCB_MASTER_USED) */
}


#if (I2C_LCD_CUSTOM_CHAR_SET != I2C_LCD_NONE)

    /*******************************************************************************
    * Function Name: I2C_LCD_LoadCustomFonts
    ********************************************************************************
    *
    * Summary:
    *  Loads 8 custom font characters into the LCD Module for use.  Cannot use
    *  characters from two different font sets at once, but font sets can be
    *  switched out during runtime.
    *
    * Parameters:
    *  customData:  The pointer to a constant array of 64 bytes representing 
    *               8 custom font characters.
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    * Theory:
    *  Prior to using this function user need to import the pointer to custom
    *  font array to your project by writing the following in the source code file
    *  where custom font will be used:
    *       extern uint8 const CYCODE LCD_Char_customFonts[];
    *  This function is not automatically called by the Start() routine and must be
    *  called manually by the user.
    *
    *******************************************************************************/
    void I2C_LCD_LoadCustomFonts(uint8 const customData[])
                                                            
    {
        uint8 i;

        #if (I2C_LCD_COMMAND_FORMAT != I2C_LCD_NXP_PCF2119X)
            uint8 addrOffset = 0u;
            uint8 count = 0u;
        #endif /* (I2C_LCD_COMMAND_FORMAT != I2C_LCD_NXP_PCF2119X) */

        #if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)
            /* Set starting address in LCD Module as it is location of CGRAM */
            I2C_LCD_WriteControl(I2C_LCD_CGRAM_0);

            /* Set Control pattern for data writing */
            I2C_LCD_WrCntrlPatt(I2C_LCD_WRITE_DATA_IDX);

            /* Load in 64 bytes of CustomChar Data */
            for(i = 0u; i < I2C_LCD_CUSTOM_CHAR_SET_LEN; i++)
            {
                /* Variable 'i' defines character ID (character address) */
                I2C_LCD_WrDataToBuff(customData[i]);
            }

            /* Send data to LCD and wait when transaction completes */
            I2C_LCD_SendSequence();
            
            /* Set the LCD modules address register back to the start of the data RAM */
            I2C_LCD_Position(0u ,0u);
        #else
            while(addrOffset < I2C_LCD_CUSTOM_CHAR_SET_LEN)
            {
                /* Set starting address in LCD Module as it is location of CGRAM. */
                I2C_LCD_WrCntrlPatt(I2C_LCD_CGRAM_0_IDX);
                
                /* Variable 'i' defines character ID (character address) */
                I2C_LCD_WrDataToBuff(count);
                
                /* Increment count (actually means to increment custom character address) */
                count++;
                
                for(i = 0u; i < I2C_LCD_CHARACTER_HEIGHT; i++)
                {
                    I2C_LCD_WrDataToBuff(customData[addrOffset + i]);
                }

                /* Send data to LCD and wait when transaction complete */
                I2C_LCD_SendSequence();
                
                /* Calculate next offset value */
                addrOffset += I2C_LCD_CHARACTER_HEIGHT;
            }
        #endif /* (I2C_LCD_COMMAND_FORMAT != I2C_LCD_NXP_PCF2119X) */
    }

#endif /* I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_NONE */


#if((I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_VERTICAL_BG) || \
                (I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_HORIZONTAL_BG))

    /*******************************************************************************
    * Function Name: I2C_LCD_DrawHorizontalBG
    ********************************************************************************
    *
    * Summary:
    *  Draws the horizontal bargraph.
    *
    * Parameters:
    *  row:            The row in which the bar graph starts.
    *  column:         The column in which the bar graph starts.
    *  maxCharacters:  The max length of the graph in whole characters.
    *  value:          The current length or height of the graph in pixels.
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *******************************************************************************/
    void I2C_LCD_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value) \
                                                            
    {
        /* 8-bit Counter */
        uint8 count8;
        uint8 fullChars;
        uint8 remainingPixels;

        /* Number of full characters to draw */
        fullChars = value / I2C_LCD_CHARACTER_WIDTH;

        /* Number of remaining pixels to draw */
        remainingPixels = value % I2C_LCD_CHARACTER_WIDTH;

        /* Ensure that maximum character limit is followed. */
        if(fullChars >= maxCharacters)
        {
            fullChars = maxCharacters;
        }

        /* Put Cursor at start position */
        I2C_LCD_Position(row, column);

        /* Set Control pattern for data writing */
        I2C_LCD_WrCntrlPatt(I2C_LCD_WRITE_DATA_IDX);

        /* Write full characters */
        for(count8 = 0u; count8 < fullChars; count8++)
        {
            I2C_LCD_WrDataToBuff(I2C_LCD_CUSTOM_5);
        }

        if(fullChars < maxCharacters)
        {
            /* Write remaining pixels */
            I2C_LCD_WrDataToBuff(remainingPixels);

            if(fullChars < (maxCharacters - 1u))
            {
                /* Fill with whitespace to end of bar graph */
                for(count8 = 0u; count8 < (maxCharacters - fullChars - 1u); count8++)
                {
                    I2C_LCD_WrDataToBuff(I2C_LCD_CUSTOM_0);
                }
            }
        }

        /* Send data to LCD and wait when transaction complete */
        I2C_LCD_SendSequence();
    }


    /*******************************************************************************
    *  Function Name: I2C_LCD_DrawVerticalBG
    ********************************************************************************
    *
    * Summary:
    *  Draws the vertical bargraph.
    *
    * Parameters:
    *  row:            The row in which the bar graph starts.
    *  column:         The column in which the bar graph starts.
    *  maxCharacters:  The max height of the graph in whole characters.
    *  value:          The current length or height of the graph in pixels.
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *******************************************************************************/
    void I2C_LCD_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                                                            
    {
        /* 8-bit Counter */
        uint8 count8 = 0u;
        /* Current Row Tracker */
        int8 currentRow;
        uint8 fullChars;
        uint8 remainingPixels;

        /* Number of full characters to draw */
        fullChars = value / I2C_LCD_CHARACTER_HEIGHT;

        /* Number of remaining pixels to draw */
        remainingPixels = value % I2C_LCD_CHARACTER_HEIGHT;

        /* Put Cursor at start position */
        I2C_LCD_Position(row, column);

        /* Make sure the bar graph fits inside the space allotted */
        if(fullChars >= maxCharacters)
        {
            fullChars = maxCharacters;
        }

        /*  Write full characters */
        while(count8 < fullChars)
        {
            I2C_LCD_WriteData(I2C_LCD_CUSTOM_7);

            count8++;

            /* Each pass through, move one row higher */
            if((((int8) row) - ((int8) count8)) >= 0)
            {
                I2C_LCD_Position(row - count8, column);
            }
            else
            {
                break;
            }
        }

        if(((((int8) row) - ((int8) count8)) >= 0) && (fullChars < maxCharacters))
        {
            /* Write remaining pixels */
            if(remainingPixels == 0u)
            {
                I2C_LCD_WriteData((uint8) ' ');
            }
            else
            {
                I2C_LCD_WriteData(remainingPixels - 1u);
            }

            currentRow = ((int8) row) - ((int8) count8) - 1;

            if(currentRow >= 0)
            {
                /* Move up one row and fill with white space till top of bar graph */
                for(count8 = 0u; count8 < (maxCharacters - fullChars - 1u); count8++)
                {
                    I2C_LCD_Position((uint8)currentRow, column);
                    I2C_LCD_WriteData((uint8) ' ');
                    currentRow --;
                }
            }
        }
    }

#endif /* ((I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_VERTICAL_BG) || \
                (I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_HORIZONTAL_BG)) */


#if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)

    /*******************************************************************************
    * Function Name: I2C_LCD_SendCmd
    ********************************************************************************
    *
    * Summary:
    *  This function used to send the specific for NXP PCF2119X commands that are 
    *  used to configure the LCD panel.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    static void I2C_LCD_SendCmd(uint8 cmd) CYREENTRANT
    {
        I2C_LCD_buff[0u] = I2C_LCD_COMMAND_SEND;
        I2C_LCD_buff[1u] = cmd;
        I2C_LCD_buffIndex = I2C_LCD_LENGTH_2_BYTES;
        
        I2C_LCD_SendSequence();
    }

#endif /* (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X) */

/* [] END OF FILE */
