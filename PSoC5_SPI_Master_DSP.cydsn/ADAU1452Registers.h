/* ========================================
 *
 * ADAU1452Registers.h
 *
 * Author:     Lukas Creutzburg
 * Created on: 16.05.16
 * Version:    0.1
 *
 * ========================================
*/

#define PROGRAM_RAM_SIZE 480
#define DM0_RAM_SIZE 176
#define DM1_RAM_SIZE 32
#define DUMMY_SIZE 4
#define SERIAL_OUTPUT_SIZE 24

#define CHIPADDRESS 0x00
#define WRITE_DSP 0x00
#define READ_DSP 0x01

/* init sequence registers */
#define DUMMY_REGISTER      0x4FFF
#define SOFT_RESET          0xF890
#define HYPERNATE           0xF400
#define KILL_CORE           0xF403
#define PLL_CTRL_0          0xF000
#define PLL_CTRL_1          0xF001
#define PLL_CLK_SRC         0xF002
#define MCLK_OUT            0xF005
#define PLL_ENABLE          0xF003
#define POWER_ENABLE0       0xF050
#define POWER_ENABLE1       0xF051
#define PROGRAM_RAM_DATA    0xC000  //Data from Sigma Studio
#define DM0_RAM_DATA        0x0000  //Data from Sigma Studio
#define DM1_RAM_DATA        0x6004  //Data from Sigma Studio !!datasheet: 0x6000
#define START_ADDRESS       0xF404
#define START_PULSE         0xF401
#define START_CORE          0xF402
#define SERIAL_OUTPUT       0xF180

/* Volume Registers */
#define VOLADDRESS          0x0026
#define SLEWADDRESS         0x0027

/* [] END OF FILE */
