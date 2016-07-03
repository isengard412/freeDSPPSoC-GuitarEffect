#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* WS */
WS__0__INTTYPE EQU CYREG_PICU0_INTTYPE3
WS__0__MASK EQU 0x08
WS__0__PC EQU CYREG_PRT0_PC3
WS__0__PORT EQU 0
WS__0__SHIFT EQU 3
WS__AG EQU CYREG_PRT0_AG
WS__AMUX EQU CYREG_PRT0_AMUX
WS__BIE EQU CYREG_PRT0_BIE
WS__BIT_MASK EQU CYREG_PRT0_BIT_MASK
WS__BYP EQU CYREG_PRT0_BYP
WS__CTL EQU CYREG_PRT0_CTL
WS__DM0 EQU CYREG_PRT0_DM0
WS__DM1 EQU CYREG_PRT0_DM1
WS__DM2 EQU CYREG_PRT0_DM2
WS__DR EQU CYREG_PRT0_DR
WS__INP_DIS EQU CYREG_PRT0_INP_DIS
WS__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
WS__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
WS__LCD_EN EQU CYREG_PRT0_LCD_EN
WS__MASK EQU 0x08
WS__PORT EQU 0
WS__PRT EQU CYREG_PRT0_PRT
WS__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
WS__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
WS__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
WS__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
WS__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
WS__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
WS__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
WS__PS EQU CYREG_PRT0_PS
WS__SHIFT EQU 3
WS__SLW EQU CYREG_PRT0_SLW

/* SCK */
SCK__0__INTTYPE EQU CYREG_PICU0_INTTYPE0
SCK__0__MASK EQU 0x01
SCK__0__PC EQU CYREG_PRT0_PC0
SCK__0__PORT EQU 0
SCK__0__SHIFT EQU 0
SCK__AG EQU CYREG_PRT0_AG
SCK__AMUX EQU CYREG_PRT0_AMUX
SCK__BIE EQU CYREG_PRT0_BIE
SCK__BIT_MASK EQU CYREG_PRT0_BIT_MASK
SCK__BYP EQU CYREG_PRT0_BYP
SCK__CTL EQU CYREG_PRT0_CTL
SCK__DM0 EQU CYREG_PRT0_DM0
SCK__DM1 EQU CYREG_PRT0_DM1
SCK__DM2 EQU CYREG_PRT0_DM2
SCK__DR EQU CYREG_PRT0_DR
SCK__INP_DIS EQU CYREG_PRT0_INP_DIS
SCK__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
SCK__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
SCK__LCD_EN EQU CYREG_PRT0_LCD_EN
SCK__MASK EQU 0x01
SCK__PORT EQU 0
SCK__PRT EQU CYREG_PRT0_PRT
SCK__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
SCK__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
SCK__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
SCK__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
SCK__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
SCK__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
SCK__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
SCK__PS EQU CYREG_PRT0_PS
SCK__SHIFT EQU 0
SCK__SLW EQU CYREG_PRT0_SLW

/* SDO */
SDO__0__INTTYPE EQU CYREG_PICU0_INTTYPE2
SDO__0__MASK EQU 0x04
SDO__0__PC EQU CYREG_PRT0_PC2
SDO__0__PORT EQU 0
SDO__0__SHIFT EQU 2
SDO__AG EQU CYREG_PRT0_AG
SDO__AMUX EQU CYREG_PRT0_AMUX
SDO__BIE EQU CYREG_PRT0_BIE
SDO__BIT_MASK EQU CYREG_PRT0_BIT_MASK
SDO__BYP EQU CYREG_PRT0_BYP
SDO__CTL EQU CYREG_PRT0_CTL
SDO__DM0 EQU CYREG_PRT0_DM0
SDO__DM1 EQU CYREG_PRT0_DM1
SDO__DM2 EQU CYREG_PRT0_DM2
SDO__DR EQU CYREG_PRT0_DR
SDO__INP_DIS EQU CYREG_PRT0_INP_DIS
SDO__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
SDO__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
SDO__LCD_EN EQU CYREG_PRT0_LCD_EN
SDO__MASK EQU 0x04
SDO__PORT EQU 0
SDO__PRT EQU CYREG_PRT0_PRT
SDO__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
SDO__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
SDO__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
SDO__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
SDO__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
SDO__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
SDO__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
SDO__PS EQU CYREG_PRT0_PS
SDO__SHIFT EQU 2
SDO__SLW EQU CYREG_PRT0_SLW

/* I2S_1_bI2S */
I2S_1_bI2S_BitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
I2S_1_bI2S_BitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB03_04_CTL
I2S_1_bI2S_BitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB03_04_CTL
I2S_1_bI2S_BitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB03_04_CTL
I2S_1_bI2S_BitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB03_04_CTL
I2S_1_bI2S_BitCounter__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB03_04_MSK
I2S_1_bI2S_BitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB03_04_MSK
I2S_1_bI2S_BitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB03_04_MSK
I2S_1_bI2S_BitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB03_04_MSK
I2S_1_bI2S_BitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
I2S_1_bI2S_BitCounter__CONTROL_REG EQU CYREG_B0_UDB03_CTL
I2S_1_bI2S_BitCounter__CONTROL_ST_REG EQU CYREG_B0_UDB03_ST_CTL
I2S_1_bI2S_BitCounter__COUNT_REG EQU CYREG_B0_UDB03_CTL
I2S_1_bI2S_BitCounter__COUNT_ST_REG EQU CYREG_B0_UDB03_ST_CTL
I2S_1_bI2S_BitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
I2S_1_bI2S_BitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
I2S_1_bI2S_BitCounter__PERIOD_REG EQU CYREG_B0_UDB03_MSK
I2S_1_bI2S_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
I2S_1_bI2S_BitCounter_ST__16BIT_STATUS_REG EQU CYREG_B0_UDB03_04_ST
I2S_1_bI2S_BitCounter_ST__MASK_REG EQU CYREG_B0_UDB03_MSK
I2S_1_bI2S_BitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
I2S_1_bI2S_BitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
I2S_1_bI2S_BitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
I2S_1_bI2S_BitCounter_ST__STATUS_CNT_REG EQU CYREG_B0_UDB03_ST_CTL
I2S_1_bI2S_BitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B0_UDB03_ST_CTL
I2S_1_bI2S_BitCounter_ST__STATUS_REG EQU CYREG_B0_UDB03_ST
I2S_1_bI2S_CtlReg__0__MASK EQU 0x01
I2S_1_bI2S_CtlReg__0__POS EQU 0
I2S_1_bI2S_CtlReg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB02_03_ACTL
I2S_1_bI2S_CtlReg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB02_03_CTL
I2S_1_bI2S_CtlReg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB02_03_CTL
I2S_1_bI2S_CtlReg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB02_03_CTL
I2S_1_bI2S_CtlReg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB02_03_CTL
I2S_1_bI2S_CtlReg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB02_03_MSK
I2S_1_bI2S_CtlReg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB02_03_MSK
I2S_1_bI2S_CtlReg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB02_03_MSK
I2S_1_bI2S_CtlReg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB02_03_MSK
I2S_1_bI2S_CtlReg__2__MASK EQU 0x04
I2S_1_bI2S_CtlReg__2__POS EQU 2
I2S_1_bI2S_CtlReg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB02_ACTL
I2S_1_bI2S_CtlReg__CONTROL_REG EQU CYREG_B0_UDB02_CTL
I2S_1_bI2S_CtlReg__CONTROL_ST_REG EQU CYREG_B0_UDB02_ST_CTL
I2S_1_bI2S_CtlReg__COUNT_REG EQU CYREG_B0_UDB02_CTL
I2S_1_bI2S_CtlReg__COUNT_ST_REG EQU CYREG_B0_UDB02_ST_CTL
I2S_1_bI2S_CtlReg__MASK EQU 0x05
I2S_1_bI2S_CtlReg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB02_MSK_ACTL
I2S_1_bI2S_CtlReg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB02_MSK_ACTL
I2S_1_bI2S_CtlReg__PERIOD_REG EQU CYREG_B0_UDB02_MSK
I2S_1_bI2S_Tx_CH_0__dpTx_u0__16BIT_A0_REG EQU CYREG_B0_UDB02_03_A0
I2S_1_bI2S_Tx_CH_0__dpTx_u0__16BIT_A1_REG EQU CYREG_B0_UDB02_03_A1
I2S_1_bI2S_Tx_CH_0__dpTx_u0__16BIT_D0_REG EQU CYREG_B0_UDB02_03_D0
I2S_1_bI2S_Tx_CH_0__dpTx_u0__16BIT_D1_REG EQU CYREG_B0_UDB02_03_D1
I2S_1_bI2S_Tx_CH_0__dpTx_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB02_03_ACTL
I2S_1_bI2S_Tx_CH_0__dpTx_u0__16BIT_F0_REG EQU CYREG_B0_UDB02_03_F0
I2S_1_bI2S_Tx_CH_0__dpTx_u0__16BIT_F1_REG EQU CYREG_B0_UDB02_03_F1
I2S_1_bI2S_Tx_CH_0__dpTx_u0__A0_A1_REG EQU CYREG_B0_UDB02_A0_A1
I2S_1_bI2S_Tx_CH_0__dpTx_u0__A0_REG EQU CYREG_B0_UDB02_A0
I2S_1_bI2S_Tx_CH_0__dpTx_u0__A1_REG EQU CYREG_B0_UDB02_A1
I2S_1_bI2S_Tx_CH_0__dpTx_u0__D0_D1_REG EQU CYREG_B0_UDB02_D0_D1
I2S_1_bI2S_Tx_CH_0__dpTx_u0__D0_REG EQU CYREG_B0_UDB02_D0
I2S_1_bI2S_Tx_CH_0__dpTx_u0__D1_REG EQU CYREG_B0_UDB02_D1
I2S_1_bI2S_Tx_CH_0__dpTx_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB02_ACTL
I2S_1_bI2S_Tx_CH_0__dpTx_u0__F0_F1_REG EQU CYREG_B0_UDB02_F0_F1
I2S_1_bI2S_Tx_CH_0__dpTx_u0__F0_REG EQU CYREG_B0_UDB02_F0
I2S_1_bI2S_Tx_CH_0__dpTx_u0__F1_REG EQU CYREG_B0_UDB02_F1
I2S_1_bI2S_Tx_CH_0__dpTx_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB02_MSK_ACTL
I2S_1_bI2S_Tx_CH_0__dpTx_u0__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB02_MSK_ACTL
I2S_1_bI2S_Tx_STS_0__Sts__0__MASK EQU 0x01
I2S_1_bI2S_Tx_STS_0__Sts__0__POS EQU 0
I2S_1_bI2S_Tx_STS_0__Sts__1__MASK EQU 0x02
I2S_1_bI2S_Tx_STS_0__Sts__1__POS EQU 1
I2S_1_bI2S_Tx_STS_0__Sts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB02_03_ACTL
I2S_1_bI2S_Tx_STS_0__Sts__16BIT_STATUS_REG EQU CYREG_B0_UDB02_03_ST
I2S_1_bI2S_Tx_STS_0__Sts__MASK EQU 0x03
I2S_1_bI2S_Tx_STS_0__Sts__MASK_REG EQU CYREG_B0_UDB02_MSK
I2S_1_bI2S_Tx_STS_0__Sts__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB02_MSK_ACTL
I2S_1_bI2S_Tx_STS_0__Sts__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB02_MSK_ACTL
I2S_1_bI2S_Tx_STS_0__Sts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB02_ACTL
I2S_1_bI2S_Tx_STS_0__Sts__STATUS_CNT_REG EQU CYREG_B0_UDB02_ST_CTL
I2S_1_bI2S_Tx_STS_0__Sts__STATUS_CONTROL_REG EQU CYREG_B0_UDB02_ST_CTL
I2S_1_bI2S_Tx_STS_0__Sts__STATUS_REG EQU CYREG_B0_UDB02_ST

/* TxDMA */
TxDMA__DRQ_CTL EQU CYREG_IDMUX_DRQ_CTL0
TxDMA__DRQ_NUMBER EQU 0
TxDMA__NUMBEROF_TDS EQU 0
TxDMA__PRIORITY EQU 2
TxDMA__TERMIN_EN EQU 0
TxDMA__TERMIN_SEL EQU 0
TxDMA__TERMOUT0_EN EQU 0
TxDMA__TERMOUT0_SEL EQU 0
TxDMA__TERMOUT1_EN EQU 0
TxDMA__TERMOUT1_SEL EQU 0

/* clock */
clock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
clock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
clock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
clock__CFG2_SRC_SEL_MASK EQU 0x07
clock__INDEX EQU 0x00
clock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
clock__PM_ACT_MSK EQU 0x01
clock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
clock__PM_STBY_MSK EQU 0x01

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 19
CYDEV_CHIP_DIE_PSOC4A EQU 11
CYDEV_CHIP_DIE_PSOC5LP EQU 18
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 11
CYDEV_CHIP_MEMBER_4C EQU 16
CYDEV_CHIP_MEMBER_4D EQU 7
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 12
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 10
CYDEV_CHIP_MEMBER_4I EQU 15
CYDEV_CHIP_MEMBER_4J EQU 8
CYDEV_CHIP_MEMBER_4K EQU 9
CYDEV_CHIP_MEMBER_4L EQU 14
CYDEV_CHIP_MEMBER_4M EQU 13
CYDEV_CHIP_MEMBER_4N EQU 6
CYDEV_CHIP_MEMBER_4O EQU 5
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 18
CYDEV_CHIP_MEMBER_5B EQU 17
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 0
CYDEV_CONFIGURATION_DMA EQU 1
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_DMA
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 0
CYDEV_INTR_RISING EQU 0x00000000
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000001
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */