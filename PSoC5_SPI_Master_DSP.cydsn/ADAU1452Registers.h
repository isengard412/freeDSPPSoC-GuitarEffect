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

/* init sequence registers */
#define SOFT_RESET          0xF890
#define PLL_CTRL_0          0xF000
#define PLL_CTRL_1          0xF001
#define PLL_CLK_SRC         0xF002
#define MCLK_OUT            0xF005
#define PLL_ENABLE          0xF003
#define POWER_ENABLE0       0xF050
#define POWER_ENABLE1       0xF051
#define PROGRAM_RAM_DATA    0xC000  //Data from Sigma Studio
#define DM0_RAM_DATA        0x0000  //Data from Sigma Studio
#define DM1_RAM_DATA        0x6000  //Data from Sigma Studio
#define START_ADDRESS       0xF404
#define START_PULSE         0xF401
#define START_CORE          0xF402

/* [] END OF FILE */
