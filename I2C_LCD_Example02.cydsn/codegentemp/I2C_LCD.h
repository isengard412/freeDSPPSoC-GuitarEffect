/*******************************************************************************
* File Name: I2C_LCD.h
* Version 1.20
*
* Description:
*  This header file contains registers and constants associated with the
*  I2C LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_I2C_LCD_I2C_LCD_H)
#define CY_I2C_LCD_I2C_LCD_H

#include "cytypes.h"
#include "cyfitter.h"

#include "I2C_M.h"

#if defined(I2C_M_SCB_MODE)
    #include "I2C_M_I2C.h"
#endif /* I2C_M_SCB_MODE */


/***************************************
*   Conditional Compilation Parameters
***************************************/

/* This condition checks if I2C Master implemented on SCB
* block. There is mismatch in function names between I2C Master that is
* implemented on SCB and I2C Master that is implemented on UDB.
*/
#if defined(I2C_M_SCB_MODE)
    /* In this case always returns - "true" */
    #define I2C_LCD_IS_SCB_MASTER_USED     (0x01u == 0x01u)
#else
    /* Always "false" */
    #define I2C_LCD_IS_SCB_MASTER_USED     (0x01u == 0x00u)
#endif /* I2C_M_SCB_MODE */

#define I2C_LCD_CUSTOM_CHAR_SET            (0x03u)

/* Custom character set types */
#define I2C_LCD_NONE                       (0u)    /* No Custom Fonts      */
#define I2C_LCD_HORIZONTAL_BG              (1u)    /* Horizontal Bar Graph */
#define I2C_LCD_VERTICAL_BG                (2u)    /* Vertical Bar Graph   */
#define I2C_LCD_USER_DEFINED               (3u)    /* User Defined Fonts   */

#define I2C_LCD_COMMAND_FORMAT             (0u)

/* Possible command format values */
#define I2C_LCD_NXP_PCF2119X               (0x00u)
#define I2C_LCD_CUSTOM                     (0x01u)

/********************
* Generated Code
********************/
/* Indexes of command patterns in the look-up array. Required for a quick 
* access for the command.
*/
#define I2C_LCD_WRITE_DATA (0x00u)
#define I2C_LCD_DISPLAY_ON_CURSOR_OFF (0x0Cu)
#define I2C_LCD_DISPLAY_CURSOR_OFF (0x08u)
#define I2C_LCD_DDRAM_0 (0x80u)
#define I2C_LCD_CURSOR_HOME (0x02u)
#define I2C_LCD_RESET_CURSOR_POSITION (0x03u)
#define I2C_LCD_CURSOR_SH_LEFT (0x10u)
#define I2C_LCD_CURSOR_SH_RIGHT (0x14u)
#define I2C_LCD_DISPLAY_CURSOR_ON (0x0Eu)
#define I2C_LCD_CURSOR_WINK (0x0Du)
#define I2C_LCD_CURSOR_BLINK (0x0Fu)
#define I2C_LCD_CLEAR_DISPLAY (0x01u)
#define I2C_LCD_CGRAM_0 (0x40u)
#define I2C_LCD_DISPLAY_2_LINES_5X10 (0x24u)
#define I2C_LCD_CURSOR_RIGHT (0x06u)
#define I2C_LCD_CURSOR_LEFT (0x04u)
#define I2C_LCD_SELECTEXTENDEDFUNCS (0x25u)
#define I2C_LCD_SETBOTTOMTOTOP (0x05u)
#define I2C_LCD_SETTOPTOBOTTOM (0x04u)


/***************************************
*        Function Prototypes
***************************************/
void I2C_LCD_Init(void) ;
void I2C_LCD_Enable(void) ;
void I2C_LCD_Start(void) ;
void I2C_LCD_Stop(void) ;
void I2C_LCD_WriteControl(uint8 cByte) ;
void I2C_LCD_WriteData(uint8 dByte) ;
void I2C_LCD_PrintString(char8 const string[]) ;
void I2C_LCD_Position(uint8 row, uint8 column) ;
void I2C_LCD_PutChar(char8 character) ;
void I2C_LCD_SetAddr(uint8 address) ;
void I2C_LCD_HandleCustomCommand(uint8 cmdId, uint8 dataLength, uint8 const cmdData[])
                                            ;
void I2C_LCD_HandleOneByteCommand(uint8 cmdId, uint8 cmdByte)
                                                        ;
/* ASCII Conversion Routines */
void I2C_LCD_PrintInt8(uint8 value) ;
void I2C_LCD_PrintInt16(uint16 value) ;
void I2C_LCD_PrintNumber(uint16 value) ;

#if((I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_VERTICAL_BG) || \
                (I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_HORIZONTAL_BG))

    void  I2C_LCD_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void I2C_LCD_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_VERTICAL_BG) ||
       * (I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_HORIZONTAL_BG))
       */

#if(I2C_LCD_CUSTOM_CHAR_SET != I2C_LCD_NONE)

    void I2C_LCD_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_USER_DEFINED) */


/***************************************
*        Macros
***************************************/

/* Clear Macro */
#define I2C_LCD_ClearDisplay()            I2C_LCD_WriteControl(I2C_LCD_CLEAR_DISPLAY)
/* Off Macro */
#define I2C_LCD_DisplayOff()              I2C_LCD_WriteControl(I2C_LCD_DISPLAY_CURSOR_OFF)
/* On Macro */
#define I2C_LCD_DisplayOn()               I2C_LCD_WriteControl(I2C_LCD_DISPLAY_ON_CURSOR_OFF)

/* Function-like macros for handling I2C MAster API names on SCB and UDB */
#if(I2C_LCD_IS_SCB_MASTER_USED)
    #define I2C_LCD_MasterWriteBuf(slaveAddress, wrData, cnt, mode)  \
                                I2C_M_I2CMasterWriteBuf(slaveAddress, wrData, cnt, mode)

    #define I2C_LCD_MasterReadStatus()     I2C_M_I2CMasterStatus()
#else
    #define I2C_LCD_MasterWriteBuf(slaveAddress, wrData, cnt, mode)  \
                                I2C_M_MasterWriteBuf(slaveAddress, wrData, cnt, mode)

    #define I2C_LCD_MasterReadStatus()     I2C_M_MasterStatus()
#endif /* I2C_LCD_IS_SCB_MASTER_USED */


#define I2C_LCD_AddrStart(addr) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_Start();\
                                                }while(0)

#define I2C_LCD_AddrStop(addr) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_Stop(); \
                                                }while(0)

#define I2C_LCD_AddrDisplayOn(addr) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_DisplayOn();\
                                                }while(0)

#define I2C_LCD_AddrDisplayOff(addr) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_DisplayOff();\
                                                }while(0)

#define I2C_LCD_AddrPrintString(addr, str) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_PrintString(str);\
                                                }while(0)

#define I2C_LCD_AddrPutChar(addr, ch) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_PutChar(ch);\
                                               }while(0)

#define I2C_LCD_AddrPosition(addr, row, col) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_Position(row, col);\
                                                }while(0)

#define I2C_LCD_AddrWriteData(addr, dByte) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_WriteData(dByte);\
                                                }while(0)

#define I2C_LCD_AddrWriteControl(addr, cByte) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_WriteControl(cByte);\
                                                }while(0)

#define I2C_LCD_AddrClearDisplay(addr) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_ClearDisplay();\
                                                }while(0)

#define I2C_LCD_AddrEnable(addr) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr); \
                                                    I2C_LCD_Enable();\
                                                }while(0)

#define I2C_LCD_AddrPrintInt8(addr, value) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr); \
                                                    I2C_LCD_PrintInt8(value);\
                                                }while(0)
                                                
#define I2C_LCD_AddrPrintInt16(addr, value) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr); \
                                                    I2C_LCD_PrintInt16(value);\
                                                }while(0)
                                                
#define I2C_LCD_AddrPrintNumber(addr, value) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr); \
                                                    I2C_LCD_PrintNumber(value);\
                                                }while(0)

#if(I2C_LCD_CUSTOM_CHAR_SET != I2C_LCD_NONE)

    #define I2C_LCD_AddrLoadCustomFonts(addr, customFont) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_LoadCustomFonts(customFont);\
                                                }while(0)

#endif /* (I2C_LCD_CUSTOM_CHAR_SET != I2C_LCD_NONE) */


#if((I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_VERTICAL_BG) || \
                (I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_HORIZONTAL_BG))

    #define I2C_LCD_AddrDrawHorizontalBG(addr, row, column, maxCharacters, value) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_DrawHorizontalBG(row,column,maxCharacters,value);\
                                                }while(0)


    #define I2C_LCD_AddrDrawVerticalBG(addr, row, column, maxCharacters, value) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_DrawVerticalBG(row, column, maxCharacters, value);\
                                                }while(0)

#endif /* ((I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_VERTICAL_BG) ||
       * (I2C_LCD_CUSTOM_CHAR_SET == I2C_LCD_HORIZONTAL_BG))
       */

#define I2C_LCD_AddrHandleCustomCommand(addr, cmdId, dataLength, cmdData) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_HandleCustomCommand(cmdId, dataLength, cmdData);\
                                                }while(0)

#define I2C_LCD_AddrHandleOneByteCommand(addr, cmdId, cmdByte) \
                                                do {\
                                                    I2C_LCD_SetAddr(addr);\
                                                    I2C_LCD_HandleOneByteCommand(cmdId, cmdByte);\
                                                }while(0)

/********************
* Generated Code
********************/
#define I2C_LCD_SelectExtendedFuncs() I2C_LCD_WriteControl(I2C_LCD_SELECTEXTENDEDFUNCS)
#define I2C_LCD_AddrSelectExtendedFuncs(addr) I2C_LCD_AddrWriteControl(addr, I2C_LCD_SELECTEXTENDEDFUNCS)
#define I2C_LCD_SetBottomToTop() I2C_LCD_WriteControl(I2C_LCD_SETBOTTOMTOTOP)
#define I2C_LCD_AddrSetBottomToTop(addr) I2C_LCD_AddrWriteControl(addr, I2C_LCD_SETBOTTOMTOTOP)
#define I2C_LCD_SetTopToBottom() I2C_LCD_WriteControl(I2C_LCD_SETTOPTOBOTTOM)
#define I2C_LCD_AddrSetTopToBottom(addr) I2C_LCD_AddrWriteControl(addr, I2C_LCD_SETTOPTOBOTTOM)


/***************************************
*           Global Variables
***************************************/

extern uint8 I2C_LCD_initVar;
extern uint8 const CYCODE I2C_LCD_customFonts[64u];


/***************************************
*           API Constants
***************************************/

#define I2C_LCD_ADDRESS_SHIFT              (0x01u)

/* Default I2C address in 7-bit mode */
#define I2C_LCD_DEFAULT_I2C_ADDRESS        ((uint8)((uint8)(116u) >> \
                                                                            I2C_LCD_ADDRESS_SHIFT))

/* This value should be generated by API customizer */
#define I2C_LCD_NUM_COMMANDS               (19u)

/********************
* Generated Code
********************/
/* Legacy names from Character LCD */
#define I2C_LCD_WRITE_DATA_IDX (0x00u)
#define I2C_LCD_DISPLAY_ON_CURSOR_OFF_IDX (0x01u)
#define I2C_LCD_DISPLAY_CURSOR_OFF_IDX (0x02u)
#define I2C_LCD_DDRAM_0_IDX (0x03u)
#define I2C_LCD_CURSOR_HOME_IDX (0x04u)
#define I2C_LCD_RESET_CURSOR_POSITION_IDX (0x05u)
#define I2C_LCD_CURSOR_SH_LEFT_IDX (0x06u)
#define I2C_LCD_CURSOR_SH_RIGHT_IDX (0x07u)
#define I2C_LCD_DISPLAY_CURSOR_ON_IDX (0x08u)
#define I2C_LCD_CURSOR_WINK_IDX (0x09u)
#define I2C_LCD_CURSOR_BLINK_IDX (0x0Au)
#define I2C_LCD_CLEAR_DISPLAY_IDX (0x0Bu)
#define I2C_LCD_CGRAM_0_IDX (0x0Cu)
#define I2C_LCD_DISPLAY_2_LINES_5X10_IDX (0x0Du)
#define I2C_LCD_CURSOR_RIGHT_IDX (0x0Eu)
#define I2C_LCD_CURSOR_LEFT_IDX (0x0Fu)
#define I2C_LCD_SELECTEXTENDEDFUNCS_IDX (0x0010u)
#define I2C_LCD_SETBOTTOMTOTOP_IDX (0x0011u)
#define I2C_LCD_SETTOPTOBOTTOM_IDX (0x0012u)

#define I2C_LCD_DISPLAY_2_LINES_5x10       (I2C_LCD_DISPLAY_2_LINES_5X10)
#define I2C_LCD_CURSOR_AUTO_INCR_ON        (I2C_LCD_CURSOR_RIGHT)

/********************
* Generated Code
********************/
#define I2C_LCD_DDRAM_0_DATA_LEN (0x01u)
#define I2C_LCD_CGRAM_0_DATA_LEN (0x09u)

#if(I2C_LCD_IS_SCB_MASTER_USED)
    #define I2C_LCD_MODE_COMPLETE_XFER         (I2C_M_I2C_MODE_COMPLETE_XFER)
    #define I2C_LCD_WRITE_COMPLETE             (I2C_M_I2C_MSTAT_WR_CMPLT)
#else
    #define I2C_LCD_MODE_COMPLETE_XFER         (I2C_M_MODE_COMPLETE_XFER)
    #define I2C_LCD_WRITE_COMPLETE             (I2C_M_MSTAT_WR_CMPLT)
#endif /* I2C_LCD_IS_SCB_MASTER_USED */

/* Constants for PrintNumber routine */
#define I2C_LCD_NUMBER_OF_REMAINDERS           (0x05u)
#define I2C_LCD_TEN                            (0x0Au)

/* Nibble Offset and Mask */
#define I2C_LCD_NIBBLE_SHIFT                   (0x04u)
#define I2C_LCD_NIBBLE_MASK                    (0x0Fu)
#define I2C_LCD_BUFF_SIZE                      (0x100u)
#define I2C_LCD_LENGTH_2_BYTES                 (0x02u)
#define I2C_LCD_COMMAND_BYTE_INDEX             (0x02u)

/* Delay value required for some commands to execute */
#define I2C_LCD_CMOMMAND_DELAY                 (1500u)

/* LCD Module RAM Address Constants */
#if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)
    #define I2C_LCD_ROW_0_START                    (0x80u)
    #define I2C_LCD_ROW_1_START                    (0xC0u)
    #define I2C_LCD_ROW_2_START                    (0x94u)
    #define I2C_LCD_ROW_3_START                    (0xD4u)
#else
    #define I2C_LCD_ROW_0_START                    (0x00u)
    #define I2C_LCD_ROW_1_START                    (0x40u)
    #define I2C_LCD_ROW_2_START                    (0x14u)
    #define I2C_LCD_ROW_3_START                    (0x54u)
#endif /* (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)  */

/* Custom character handling related constants */
#if(I2C_LCD_CUSTOM_CHAR_SET != I2C_LCD_NONE)
    #define I2C_LCD_CHARACTER_WIDTH                (0x05u)
    #define I2C_LCD_CHARACTER_HEIGHT               (0x08u)
    #define I2C_LCD_CUSTOM_CHAR_SET_LEN            (0x40u)
#endif /* (I2C_LCD_CUSTOM_CHAR_SET != I2C_LCD_NONE) */

#define I2C_LCD_CUSTOM_CHAR_NUM                (0x08u)

#define I2C_LCD_ONE_BYTE_LEN                   (0x01u)

/* Other constants */
#define I2C_LCD_BYTE_UPPER_NIBBLE_SHIFT        (0x04u)
#define I2C_LCD_BYTE_LOWER_NIBBLE_MASK         (0x0Fu)
#define I2C_LCD_U16_UPPER_BYTE_SHIFT           (0x08u)
#define I2C_LCD_U16_LOWER_BYTE_MASK            (0xFFu)
                                                    
/* Custom Character References */
#define I2C_LCD_CUSTOM_0                       (0x00u)
#define I2C_LCD_CUSTOM_1                       (0x01u)
#define I2C_LCD_CUSTOM_2                       (0x02u)
#define I2C_LCD_CUSTOM_3                       (0x03u)
#define I2C_LCD_CUSTOM_4                       (0x04u)
#define I2C_LCD_CUSTOM_5                       (0x05u)
#define I2C_LCD_CUSTOM_6                       (0x06u)
#define I2C_LCD_CUSTOM_7                       (0x07u)

#if (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X)
    
    /* Command send opcode */
    #define I2C_LCD_COMMAND_SEND               (0x00u) 
    
    #define I2C_LCD_SET_EXTENDED_FUNC          (0x35u)      
    #define I2C_LCD_SPLIT_SCREEN               (0x02u)
    #define I2C_LCD_DISP_CONF                  (0x04u)
    
    #define I2C_LCD_ICON_CTL                   (0x08u)  
    #define I2C_LCD_VLCD_SET                   (0xA0u)
    #define I2C_LCD_FUNCTION_SET_STANDARD      (0x34u)  /* Select Standard Instruction set, 2x16 display */

    /* This is mask for character set "S" that is used in NXP
    * compatible LCD Module.
    */
    #define I2C_LCD_CHARACTER_SET_S_MASK       ((uint8) (0x80u))
    
#endif /* (I2C_LCD_COMMAND_FORMAT == I2C_LCD_NXP_PCF2119X) */


#endif /* CY_I2C_LCD_I2C_LCD_H */


/* [] END OF FILE */
