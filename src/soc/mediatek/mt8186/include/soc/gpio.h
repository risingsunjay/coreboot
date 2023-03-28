/* SPDX-License-Identifier: GPL-2.0-only */

/*
 * This file is created based on MT8186 Functional Specification
 * Chapter number: 5.1
 */

#ifndef SOC_MEDIATEK_MT8186_GPIO_H
#define SOC_MEDIATEK_MT8186_GPIO_H

#include <soc/addressmap.h>
#include <soc/gpio_common.h>
#include <types.h>

#define GPIO_NUM 185

enum {
	MAX_GPIO_REG_BITS = 32,
	MAX_GPIO_MODE_PER_REG = 8,
	GPIO_MODE_BITS = 4,
};

enum gpio_drv {
	GPIO_DRV_2_MA = 0,
	GPIO_DRV_4_MA = 1,
	GPIO_DRV_6_MA = 2,
	GPIO_DRV_8_MA = 3,
	GPIO_DRV_10_MA = 4,
	GPIO_DRV_12_MA = 5,
	GPIO_DRV_14_MA = 6,
	GPIO_DRV_16_MA = 7,
};

#define GPIO_ID(name) PAD_##name##_ID

#define PIN(id, name, flag, bit, base, offset, \
	    func1, func2, func3, func4, func5, func6, func7) \
	PAD_##name##_ID = id, \
	PAD_##name##_FLAG = flag, \
	PAD_##name##_BIT = bit, \
	PAD_##name##_BASE = base, \
	PAD_##name##_OFFSET = offset, \
	PAD_##name##_FUNC_##func1 = 1, \
	PAD_##name##_FUNC_##func2 = 2, \
	PAD_##name##_FUNC_##func3 = 3, \
	PAD_##name##_FUNC_##func4 = 4, \
	PAD_##name##_FUNC_##func5 = 5, \
	PAD_##name##_FUNC_##func6 = 6, \
	PAD_##name##_FUNC_##func7 = 7

#define GPIO(name) ((gpio_t){ \
		.id = PAD_##name##_ID, \
		.flag = PAD_##name##_FLAG, \
		.bit = PAD_##name##_BIT, \
		.base = PAD_##name##_BASE, \
		.offset = PAD_##name##_OFFSET \
	})

enum {
	PIN(0, EINT0, 0, 13, 0x16, 0x50,
	    I2S0_MCK, SPI0_CLK_B, I2S2_MCK, CMFLASH0,
	    SCP_SPI0_CK, TP_GPIO0_AO, dbg_mon_a0),
	PIN(1, EINT1, 0, 14, 0x16, 0x50,
	    I2S0_BCK, SPI0_CSB_B, I2S2_BCK, CMFLASH1,
	    SCP_SPI0_CS, TP_GPIO1_AO, RES7),
	PIN(2, EINT2, 0, 17, 0x16, 0x50,
	    I2S0_LRCK, SPI0_MO_B, I2S2_LRCK, CMFLASH2,
	    SCP_SPI0_MO, TP_GPIO2_AO, RES7),
	PIN(3, EINT3, 0, 18, 0x16, 0x50,
	    I2S0_DI, SPI0_MI_B, I2S2_DI, SRCLKENAI1,
	    SCP_SPI0_MI, TP_GPIO3_AO, RES7),
	PIN(4, EINT4, 0, 19, 0x16, 0x50,
	    I2S3_DO, RES2, I2S1_DO, RES4,
	    RES5, TP_GPIO4_AO, RES7),
	PIN(5, EINT5, 0, 20, 0x16, 0x50,
	    EXT_FRAME_SYNC, RES2, RES3, RES4,
	    RES5, TP_GPIO5_AO, RES7),
	PIN(6, EINT6, 0, 19, 0x24, 0x60,
	    I2S3_MCK, SPI1_CLK_B, I2S1_MCK, DPI_DATA22,
	    RES5, TP_GPIO6_AO, RES7),
	PIN(7, EINT7, 0, 20, 0x24, 0x60,
	    I2S3_BCK, SPI1_CSB_B, I2S1_BCK, DPI_DATA23,
	    RES5, TP_GPIO7_AO, RES7),
	PIN(8, EINT8, 0, 21, 0x24, 0x60,
	    I2S3_LRCK, SPI1_MO_B, I2S1_LRCK, CONN_UART0_RXD,
	    SSPM_URXD_AO, ADSP_UART_RX, CONN_MCU_DBGACK_N),
	PIN(9, EINT9, 0, 22, 0x24, 0x60,
	    I2S3_DO, SPI1_MI_B, I2S1_DO, CONN_UART0_TXD,
	    SSPM_UTXD_AO, ADSP_UART_TX, CONN_MCU_DBGI_N),
	PIN(10, EINT10, 0, 16, 0x24, 0x60,
	    I2S0_MCK, SPI4_CLK_A, I2S2_MCK, SPM_JTAG_TDI,
	    SCP_JTAG_TDI, ADSP_JTAG_TDI, CONN_MCU_TDI),
	PIN(11, EINT11, 0, 17, 0x24, 0x60,
	    I2S0_BCK, SPI4_CSB_A, I2S2_BCK, SPM_JTAG_TRSTN,
	    SCP_JTAG_TRSTN, ADSP_JTAG_TRSTN, CONN_MCU_TRST_B),
	PIN(12, EINT12, 0, 18, 0x24, 0x60,
	    I2S0_LRCK, SPI4_MO_A, I2S2_LRCK, SPM_JTAG_TCK,
	    SCP_JTAG_TCK, ADSP_JTAG_TCK, CONN_MCU_TCK),
	PIN(13, EINT13, 0, 0, 0x23, 0x80,
	    I2S0_DI, SPI4_MI_A, I2S2_DI, SPM_JTAG_TDO,
	    SCP_JTAG_TDO, ADSP_JTAG_TDO, CONN_MCU_TDO),
	PIN(14, EINT14, 0, 1, 0x23, 0x80,
	    RES1, RES2, CLKM0, SPM_JTAG_TMS,
	    SCP_JTAG_TMS, ADSP_JTAG_TMS, CONN_MCU_TMS),
	PIN(15, EINT15, 0, 15, 0x16, 0x50,
	    EXT_FRAME_SYNC, SRCLKENAI1, CLKM1, PWM0,
	    RES5, RES6, RES7),
	PIN(16, EINT16, 0, 16, 0x16, 0x50,
	    CONN_WIFI_TXD, SRCLKENAI0, CLKM2, PWM1,
	    RES5, RES6, RES7),
	PIN(17, EINT17, 0, 9, 0x25, 0x90,
	    RES1, RES2, CLKM3, PWM2,
	    RES5, RES6, dbg_mon_a32),
	PIN(18, EINT18, 0, 10, 0x25, 0x90,
	    RES1, CMVREF0, RES3, RES4,
	    RES5, SPI2_CLK_B, dbg_mon_a26),
	PIN(19, CAM_PDN0, 0, 3, 0x25, 0x90,
	    RES1, CMVREF1, RES3, RES4,
	    ANT_SEL3, SPI2_CSB_B, dbg_mon_a2),
	PIN(20, CAM_RST0, 0, 6, 0x25, 0x90,
	    RES1, CMVREF2, RES3, RES4,
	    ANT_SEL4, SPI2_MO_B, dbg_mon_a3),
	PIN(21, CAM_PDN1, 0, 4, 0x25, 0x90,
	    I2S0_MCK, I2S1_MCK, I2S3_MCK, RES4,
	    ANT_SEL5, SPI2_MI_B, dbg_mon_a4),
	PIN(22, CAM_RST1, 0, 7, 0x25, 0x90,
	    I2S0_BCK, I2S1_BCK, I2S3_BCK, TDM_RX_LRCK,
	    ANT_SEL6, RES6, dbg_mon_a5),
	PIN(23, CAM_PDN2, 0, 5, 0x25, 0x90,
	    I2S0_LRCK, I2S1_LRCK, I2S3_LRCK, TDM_RX_BCK,
	    ANT_SEL7, RES6, dbg_mon_a6),
	PIN(24, CAM_RST2, 0, 8, 0x25, 0x90,
	    I2S0_DI, I2S1_DO, I2S3_DO, TDM_RX_MCK,
	    RES5, RES6, dbg_mon_a7),
	PIN(25, I2S2_MCK, 0, 18, 0x25, 0x90,
	    I2S2_MCK, PCM_CLK, SPI4_CLK_B, TDM_RX_DATA0,
	    RES5, RES6, dbg_mon_a8),
	PIN(26, I2S2_BCK, 0, 15, 0x25, 0x90,
	    I2S2_BCK, PCM_SYNC, SPI4_CSB_B, TDM_RX_DATA1,
	    RES5, RES6, dbg_mon_a9),
	PIN(27, I2S2_LRCK, 0, 17, 0x25, 0x90,
	    I2S2_LRCK, PCM_DI, SPI4_MO_B, TDM_RX_DATA2,
	    RES5, RES6, dbg_mon_a10),
	PIN(28, I2S2_DI, 0, 16, 0x25, 0x90,
	    I2S2_DI, PCM_DO, SPI4_MI_B, TDM_RX_DATA3,
	    RES5, RES6, RES7),
	PIN(29, ANT_SEL0, 0, 0, 0x16, 0x50,
	    ANT_SEL0, GPS_L1_ELNA_EN, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(30, ANT_SEL1, 0, 1, 0x16, 0x50,
	    ANT_SEL1, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(31, ANT_SEL2, 0, 2, 0x16, 0x50,
	    ANT_SEL2, EXT_FRAME_SYNC, SRCLKENAI1, RES4,
	    RES5, RES6, RES7),
	PIN(32, URXD0, 0, 25, 0x12, 0x60,
	    URXD0, UTXD0, ADSP_UART_RX, TP_URXD1_AO,
	    RES5, RES6, RES7),
	PIN(33, UTXD0, 0, 27, 0x12, 0x60,
	    UTXD0, URXD0, ADSP_UART_TX, TP_UTXD1_AO,
	    RES5, RES6, RES7),
	PIN(34, URXD1, 0, 26, 0x12, 0x60,
	    URXD1, TP_URXD2_AO, SSPM_URXD_AO, ADSP_UART_RX,
	    CONN_UART0_RXD, RES6, RES7),
	PIN(35, UTXD1, 0, 28, 0x12, 0x60,
	    UTXD1, TP_UTXD2_AO, SSPM_UTXD_AO, ADSP_UART_TX,
	    CONN_UART0_TXD, CONN_WIFI_TXD, RES7),
	PIN(36, SPI0_CLK, 0, 9, 0x12, 0x60,
	    SPI0_CLK_A, CLKM0, RES3, SCP_SPI0_CK,
	    SPINOR_CK, RES6, dbg_mon_a11),
	PIN(37, SPI0_CSB, 0, 10, 0x12, 0x60,
	    SPI0_CSB_A, CLKM1, PWM0, SCP_SPI0_CS,
	    SPINOR_CS, RES6, dbg_mon_a12),
	PIN(38, SPI0_MO, 0, 12, 0x12, 0x60,
	    SPI0_MO_A, CLKM2, PWM1, SCP_SPI0_MO,
	    SPINOR_IO0, RES6, dbg_mon_a13),
	PIN(39, SPI0_MI, 0, 11, 0x12, 0x60,
	    SPI0_MI_A, CLKM3, PWM2, SCP_SPI0_MI,
	    SPINOR_IO1, RES6, dbg_mon_a14),
	PIN(40, SPI1_CLK, 0, 13, 0x12, 0x60,
	    SPI1_CLK_A, SCP_SPI1_CK, RES3, UCTS0,
	    SPINOR_IO2, TP_UCTS1_AO, dbg_mon_a15),
	PIN(41, SPI1_CSB, 0, 14, 0x12, 0x60,
	    SPI1_CSB_A, SCP_SPI1_CS, PWM0, URTS0,
	    SPINOR_IO3, TP_URTS1_AO, dbg_mon_a16),
	PIN(42, SPI1_MO, 0, 16, 0x12, 0x60,
	    SPI1_MO_A, SCP_SPI1_MO, PWM1, UCTS1,
	    RES5, TP_UCTS2_AO, dbg_mon_a17),
	PIN(43, SPI1_MI, 0, 15, 0x12, 0x60,
	    SPI1_MI_A, SCP_SPI1_MI, PWM2, URTS1,
	    RES5, TP_URTS2_AO, dbg_mon_a18),
	PIN(44, SPI2_CK, 0, 28, 0x25, 0x90,
	    SPI2_CLK_A, SCP_SPI0_CK, RES3, RES4,
	    RES5, RES6, dbg_mon_a19),
	PIN(45, SPI2_CSB, 0, 29, 0x25, 0x90,
	    SPI2_CSB_A, SCP_SPI0_CS, RES3, RES4,
	    RES5, RES6, dbg_mon_a20),
	PIN(46, SPI2_MO, 0, 31, 0x25, 0x90,
	    SPI2_MO_A, SCP_SPI0_MO, RES3, RES4,
	    RES5, RES6, dbg_mon_a21),
	PIN(47, SPI2_MI, 0, 30, 0x25, 0x90,
	    SPI2_MI_A, SCP_SPI0_MI, RES3, RES4,
	    RES5, RES6, dbg_mon_a22),
	PIN(48, SPI3_CLK, 0, 17, 0x12, 0x60,
	    SPI3_CLK, TP_URXD1_AO, TP_URXD2_AO, URXD1,
	    I2S2_MCK, SCP_SPI0_CK, RES7),
	PIN(49, SPI3_CSB, 0, 18, 0x12, 0x60,
	    SPI3_CSB, TP_UTXD1_AO, TP_UTXD2_AO, UTXD1,
	    I2S2_BCK, SCP_SPI0_CS, RES7),
	PIN(50, SPI3_MO, 0, 20, 0x12, 0x60,
	    SPI3_MO, RES2, RES3, RES4,
	    I2S2_LRCK, SCP_SPI0_MO, RES7),
	PIN(51, SPI3_MI, 0, 19, 0x12, 0x60,
	    SPI3_MI, RES2, RES3, RES4,
	    I2S2_DI, SCP_SPI0_MI, RES7),
	PIN(52, SPI5_CLK, 0, 12, 0x23, 0x80,
	    SPI5_CLK, I2S2_MCK, I2S1_MCK, SCP_SPI1_CK,
	    LVTS_26M, DFD_TCK_XI, dbg_mon_b30),
	PIN(53, SPI5_CSB, 0, 13, 0x23, 0x80,
	    SPI5_CSB, I2S2_BCK, I2S1_BCK, SCP_SPI1_CS,
	    LVTS_FOUT, DFD_TDI, dbg_mon_b31),
	PIN(54, SPI5_MO, 0, 15, 0x23, 0x80,
	    SPI5_MO, I2S2_LRCK, I2S1_LRCK, SCP_SPI1_MO,
	    LVTS_SCK, DFD_TDO, dbg_mon_a1),
	PIN(55, SPI5_MI, 0, 14, 0x23, 0x80,
	    SPI5_MI, I2S2_DI, I2S1_DO, SCP_SPI1_MI,
	    LVTS_SDO, DFD_TMS, dbg_mon_b32),
	PIN(56, I2S1_DO, 0, 12, 0x25, 0x90,
	    I2S1_DO, I2S3_DO, RES3, RES4,
	    RES5, RES6, dbg_mon_a23),
	PIN(57, I2S1_BCK, 0, 11, 0x25, 0x90,
	    I2S1_BCK, I2S3_BCK, RES3, RES4,
	    RES5, RES6, dbg_mon_a24),
	PIN(58, I2S1_LRCK, 0, 13, 0x25, 0x90,
	    I2S1_LRCK, I2S3_LRCK, RES3, RES4,
	    RES5, RES6, dbg_mon_a25),
	PIN(59, I2S1_MCK, 0, 14, 0x25, 0x90,
	    I2S1_MCK, I2S3_MCK, RES3, RES4,
	    RES5, RES6, dbg_mon_a27),
	PIN(60, TDM_RX_LRCK, 0, 21, 0x23, 0x80,
	    TDM_RX_LRCK, ANT_SEL3, RES3, RES4,
	    CONN_MCU_DBGACK_N, RES6, RES7),
	PIN(61, TDM_RX_BCK, 0, 16, 0x23, 0x80,
	    TDM_RX_BCK, ANT_SEL4, RES3, SPINOR_CK,
	    CONN_MCU_DBGI_N, RES6, RES7),
	PIN(62, TDM_RX_MCLK, 0, 22, 0x23, 0x80,
	    TDM_RX_MCK, ANT_SEL5, RES3, SPINOR_CS,
	    CONN_MCU_TDI, RES6, RES7),
	PIN(63, TDM_RX_DATA0, 0, 17, 0x23, 0x80,
	    TDM_RX_DATA0, ANT_SEL6, RES3, SPINOR_IO0,
	    CONN_MCU_TRST_B, RES6, RES7),
	PIN(64, TDM_RX_DATA1, 0, 18, 0x23, 0x80,
	    TDM_RX_DATA1, ANT_SEL7, PWM0, SPINOR_IO1,
	    CONN_MCU_TCK, RES6, RES7),
	PIN(65, TDM_RX_DATA2, 0, 19, 0x23, 0x80,
	    TDM_RX_DATA2, UCTS0, PWM1, SPINOR_IO2,
	    CONN_MCU_TDO, TP_UCTS1_AO, TP_UCTS2_AO),
	PIN(66, TDM_RX_DATA3, 0, 20, 0x23, 0x80,
	    TDM_RX_DATA3, URTS0, PWM2, SPINOR_IO3,
	    CONN_MCU_TMS, TP_URTS1_AO, TP_URTS2_AO),
	PIN(67, MSDC0_DSL, 1, 10, 0x21, 0x70,
	    MSDC0_DSL, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(68, MSDC0_CLK, 1, 0, 0x21, 0x70,
	    MSDC0_CLK, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(69, MSDC0_CMD, 1, 1, 0x21, 0x70,
	    MSDC0_CMD, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(70, MSDC0_RSTB, 1, 11, 0x21, 0x70,
	    MSDC0_RSTB, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(71, MSDC0_DAT0, 1, 2, 0x21, 0x70,
	    MSDC0_DAT0, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(72, MSDC0_DAT1, 1, 3, 0x21, 0x70,
	    MSDC0_DAT1, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(73, MSDC0_DAT2, 1, 4, 0x21, 0x70,
	    MSDC0_DAT2, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(74, MSDC0_DAT3, 1, 5, 0x21, 0x70,
	    MSDC0_DAT3, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(75, MSDC0_DAT4, 1, 6, 0x21, 0x70,
	    MSDC0_DAT4, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(76, MSDC0_DAT5, 1, 7, 0x21, 0x70,
	    MSDC0_DAT5, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(77, MSDC0_DAT6, 1, 8, 0x21, 0x70,
	    MSDC0_DAT6, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(78, MSDC0_DAT7, 1, 9, 0x21, 0x70,
	    MSDC0_DAT7, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(79, KPCOL0, 1, 0, 0x25, 0x80,
	    KPCOL0, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(80, KPCOL1, 1, 1, 0x25, 0x80,
	    KPCOL1, GPS_L1_ELNA_EN, PWM0, CLKM0,
	    RES5, RES6, RES7),
	PIN(81, KPROW0, 1, 2, 0x25, 0x80,
	    KPROW0, RES2, PWM1, CLKM1,
	    RES5, RES6, RES7),
	PIN(82, KPROW1, 1, 3, 0x25, 0x80,
	    KPROW1, RES2, PWM2, CLKM2,
	    RES5, RES6, RES7),
	PIN(83, AP_GOOD, 0, 3, 0x16, 0x50,
	    AP_GOOD, GPS_PPS, RES3, EXT_FRAME_SYNC,
	    RES5, RES6, dbg_mon_a28),
	PIN(84, MSDC1_CLK, 1, 0, 0x23, 0x70,
	    MSDC1_CLK, ADSP_JTAG_TCK, RES3, UDI_TCK,
	    CONN_DSP_JCK, SSPM_JTAG_TCK, DFD_TCK_XI),
	PIN(85, MSDC1_CMD, 1, 1, 0x23, 0x70,
	    MSDC1_CMD, ADSP_JTAG_TMS, CONN_MCU_AICE_TMSC, UDI_TMS,
	    CONN_DSP_JMS, SSPM_JTAG_TMS, DFD_TMS),
	PIN(86, MSDC1_DAT0, 1, 2, 0x23, 0x70,
	    MSDC1_DAT0, ADSP_JTAG_TDI, RES3, UDI_TDI,
	    CONN_DSP_JDI, SSPM_JTAG_TDI, DFD_TDI),
	PIN(87, MSDC1_DAT1, 1, 3, 0x23, 0x70,
	    MSDC1_DAT1, ADSP_JTAG_TDO, RES3, UDI_TDO,
	    CONN_DSP_JDO, SSPM_JTAG_TDO, DFD_TDO),
	PIN(88, MSDC1_DAT2, 1, 4, 0x23, 0x70,
	    MSDC1_DAT2, ADSP_JTAG_TRSTN, CONN_MCU_AICE_TCKC, UDI_NTRST,
	    CONN_WIFI_TXD, SSPM_JTAG_TRSTN, RES7),
	PIN(89, MSDC1_DAT3, 1, 5, 0x23, 0x70,
	    MSDC1_DAT3, RES2, RES3, RES4,
	    CONN_DSP_JINTP, RES6, RES7),
	PIN(90, IDDIG_P0, 0, 2, 0x23, 0x80,
	    IDDIG_P0, RES2, RES3, PGD_HV_HSC_PWR4,
	    GDU_SUM_TROOP2_2, RES6, RES7),
	PIN(91, USB_DRVVBUS_P0, 0, 23, 0x23, 0x80,
	    USB_DRVVBUS_P0, RES2, RES3, PGD_HV_HSC_PWR5,
	    GDU_TROOPS_DET0, RES6, RES7),
	PIN(92, VBUS_VALID_P0, 0, 25, 0x23, 0x80,
	    VBUS_VALID_P0, RES2, RES3, PGD_DA_EFUSE_RDY,
	    GDU_TROOPS_DET1, RES6, RES7),
	PIN(93, IDDIG_P1, 0, 3, 0x23, 0x80,
	    IDDIG_P1, PWM0, CLKM0, PGD_DA_EFUSE_RDY_PRE,
	    GDU_TROOPS_DET2, RES6, RES7),
	PIN(94, USB_DRVVBUS_P1, 0, 24, 0x23, 0x80,
	    USB_DRVVBUS_P1, PWM1, CLKM1, PGD_DA_PWRGD_RESET,
	    RES5, RES6, RES7),
	PIN(95, VBUS_VALID_P1, 0, 26, 0x23, 0x80,
	    VBUS_VALID_P1, PWM2, CLKM2, PGD_DA_PWRGD_ENB,
	    RES5, RES6, RES7),
	PIN(96, DSI_TE, 0, 1, 0x12, 0x60,
	    DSI_TE, RES2, RES3, RES4,
	    RES5, RES6, dbg_mon_a29),
	PIN(97, DISP_PWM, 0, 0, 0x12, 0x60,
	    DISP_PWM, RES2, RES3, RES4,
	    RES5, RES6, dbg_mon_a30),
	PIN(98, LCM_RST, 0, 2, 0x12, 0x60,
	    LCM_RST, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(99, DPI_PCLK, 0, 14, 0x24, 0x60,
	    DPI_PCLK, GPS_L1_ELNA_EN, SSPM_JTAG_TCK, RES4,
	    ANT_SEL0, TP_GPIO0_AO, PGD_LV_LSC_PWR0),
	PIN(100, DPI_VSYNC, 0, 15, 0x24, 0x60,
	    DPI_VSYNC, KPCOL2, SSPM_JTAG_TMS, RES4,
	    ANT_SEL1, TP_GPIO1_AO, PGD_LV_LSC_PWR1),
	PIN(101, DPI_HSYNC, 0, 13, 0x24, 0x60,
	    DPI_HSYNC, KPROW2, SSPM_JTAG_TDI, RES4,
	    ANT_SEL2, TP_GPIO2_AO, PGD_LV_LSC_PWR2),
	PIN(102, DPI_DE, 0, 12, 0x24, 0x60,
	    DPI_DE, RES2, SSPM_JTAG_TDO, RES4,
	    ANT_SEL3, TP_GPIO3_AO, PGD_LV_LSC_PWR3),
	PIN(103, DPI_DATA0, 0, 0, 0x24, 0x60,
	    DPI_DATA0, RES2, SSPM_JTAG_TRSTN, CLKM0,
	    ANT_SEL4, TP_GPIO4_AO, PGD_LV_LSC_PWR4),
	PIN(104, DPI_DATA1, 0, 1, 0x24, 0x60,
	    DPI_DATA1, GPS_PPS, UCTS2, CLKM1,
	    ANT_SEL5, TP_GPIO5_AO, PGD_LV_LSC_PWR5),
	PIN(105, DPI_DATA2, 0, 4, 0x24, 0x60,
	    DPI_DATA2, CONN_TCXOENA_REQ, URTS2, CLKM2,
	    ANT_SEL6, TP_GPIO6_AO, PGD_LV_HSC_PWR0),
	PIN(106, DPI_DATA3, 0, 5, 0x24, 0x60,
	    DPI_DATA3, TP_UTXD1_AO, UTXD2, PWM0,
	    ANT_SEL7, TP_GPIO7_AO, PGD_LV_HSC_PWR1),
	PIN(107, DPI_DATA4, 0, 6, 0x24, 0x60,
	    DPI_DATA4, TP_URXD1_AO, URXD2, PWM1,
	    RES5, GDU_SUM_TROOP0_0, PGD_LV_HSC_PWR2),
	PIN(108, DPI_DATA5, 0, 7, 0x24, 0x60,
	    DPI_DATA5, TP_UCTS1_AO, UCTS0, PWM2,
	    RES5, GDU_SUM_TROOP0_1, PGD_LV_HSC_PWR3),
	PIN(109, DPI_DATA6, 0, 8, 0x24, 0x60,
	    DPI_DATA6, TP_URTS1_AO, URTS0, I2S0_DI,
	    I2S2_DI, GDU_SUM_TROOP0_2, PGD_LV_HSC_PWR4),
	PIN(110, DPI_DATA7, 0, 9, 0x24, 0x60,
	    DPI_DATA7, TP_UCTS2_AO, UCTS1, I2S3_BCK,
	    I2S1_BCK, GDU_SUM_TROOP1_0, PGD_LV_HSC_PWR5),
	PIN(111, DPI_DATA8, 0, 10, 0x24, 0x60,
	    DPI_DATA8, TP_URTS2_AO, URTS1, I2S3_MCK,
	    I2S1_MCK, GDU_SUM_TROOP1_1, PGD_HV_HSC_PWR0),
	PIN(112, DPI_DATA9, 0, 11, 0x24, 0x60,
	    DPI_DATA9, TP_URXD2_AO, URXD1, I2S3_LRCK,
	    I2S1_LRCK, GDU_SUM_TROOP1_2, PGD_HV_HSC_PWR1),
	PIN(113, DPI_DATA10, 0, 2, 0x24, 0x60,
	    DPI_DATA10, TP_UTXD2_AO, UTXD1, I2S3_DO,
	    I2S1_DO, GDU_SUM_TROOP2_0, PGD_HV_HSC_PWR2),
	PIN(114, DPI_DATA11, 0, 3, 0x24, 0x60,
	    DPI_DATA11, RES2, RES3, RES4,
	    RES5, GDU_SUM_TROOP2_1, PGD_HV_HSC_PWR3),
	PIN(115, PCM_CLK, 0, 4, 0x23, 0x80,
	    PCM_CLK, I2S0_BCK, I2S2_BCK, RES4,
	    RES5, RES6, RES7),
	PIN(116, PCM_SYNC, 0, 7, 0x23, 0x80,
	    PCM_SYNC, I2S0_LRCK, I2S2_LRCK, RES4,
	    RES5, RES6, RES7),
	PIN(117, PCM_DI, 0, 5, 0x23, 0x80,
	    PCM_DI, I2S0_DI, I2S2_DI, RES4,
	    RES5, RES6, RES7),
	PIN(118, PCM_DO, 0, 6, 0x23, 0x80,
	    PCM_DO, I2S0_MCK, I2S2_MCK, I2S3_DO,
	    I2S1_DO, RES6, RES7),
	PIN(119, JTMS_SEL1, 0, 22, 0x25, 0x90,
	    JTMS_SEL1, UDI_TMS, DFD_TMS, SPM_JTAG_TMS,
	    SCP_JTAG_TMS, ADSP_JTAG_TMS, RES7),
	PIN(120, JTCK_SEL1, 0, 19, 0x25, 0x90,
	    JTCK_SEL1, UDI_TCK, DFD_TCK_XI, SPM_JTAG_TCK,
	    SCP_JTAG_TCK, ADSP_JTAG_TCK, RES7),
	PIN(121, JTDI_SEL1, 0, 20, 0x25, 0x90,
	    JTDI_SEL1, UDI_TDI, DFD_TDI, SPM_JTAG_TDI,
	    SCP_JTAG_TDI, ADSP_JTAG_TDI, RES7),
	PIN(122, JTDO_SEL1, 0, 21, 0x25, 0x90,
	    JTDO_SEL1, UDI_TDO, DFD_TDO, SPM_JTAG_TDO,
	    SCP_JTAG_TDO, ADSP_JTAG_TDO, RES7),
	PIN(123, JTRSTN_SEL1, 0, 23, 0x25, 0x90,
	    JTRSTN_SEL1, UDI_NTRST, RES3, SPM_JTAG_TRSTN,
	    SCP_JTAG_TRSTN, ADSP_JTAG_TRSTN, RES7),
	PIN(124, CAM_CLK0, 0, 0, 0x25, 0x90,
	    CMMCLK0, CLKM0, PWM0, RES4,
	    RES5, RES6, RES7),
	PIN(125, CAM_CLK1, 0, 1, 0x25, 0x90,
	    CMMCLK1, CLKM1, PWM1, RES4,
	    RES5, RES6, dbg_mon_b0),
	PIN(126, CAM_CLK2, 0, 2, 0x25, 0x90,
	    CMMCLK2, CLKM2, PWM2, RES4,
	    RES5, RES6, dbg_mon_b1),
	PIN(127, SCL0, 0, 8, 0x23, 0x80,
	    SCL0, RES2, RES3, SCP_SCL0,
	    SCP_SCL1, RES6, RES7),
	PIN(128, SDA0, 0, 10, 0x23, 0x80,
	    SDA0, RES2, RES3, SCP_SDA0,
	    SCP_SDA1, RES6, RES7),
	PIN(129, SCL1, 0, 24, 0x25, 0x90,
	    SCL1, RES2, RES3, SCP_SCL0,
	    SCP_SCL1, RES6, dbg_mon_b4),
	PIN(130, SDA1, 0, 26, 0x25, 0x90,
	    SDA1, RES2, RES3, SCP_SDA0,
	    SCP_SDA1, RES6, dbg_mon_b5),
	PIN(131, SCL2, 0, 25, 0x25, 0x90,
	    SCL2, SSPM_UTXD_AO, CONN_UART0_TXD, SCP_SCL0,
	    SCP_SCL1, RES6, dbg_mon_b6),
	PIN(132, SDA2, 0, 27, 0x25, 0x90,
	    SDA2, SSPM_URXD_AO, CONN_UART0_RXD, SCP_SDA0,
	    SCP_SDA1, RES6, dbg_mon_b7),
	PIN(133, SCL3, 0, 9, 0x21, 0x80,
	    SCL3, RES2, RES3, SCP_SCL0,
	    SCP_SCL1, RES6, dbg_mon_b8),
	PIN(134, SDA3, 0, 12, 0x21, 0x80,
	    SDA3, RES2, GPS_PPS, SCP_SDA0,
	    SCP_SDA1, RES6, dbg_mon_b9),
	PIN(135, SCL4, 0, 21, 0x16, 0x50,
	    SCL4, TP_UTXD1_AO, UTXD1, SCP_SCL0,
	    SCP_SCL1, RES6, dbg_mon_b10),
	PIN(136, SDA4, 0, 24, 0x16, 0x50,
	    SDA4, TP_URXD1_AO, URXD1, SCP_SDA0,
	    SCP_SDA1, RES6, dbg_mon_b11),
	PIN(137, SCL5, 0, 10, 0x21, 0x80,
	    SCL5, UTXD2, UCTS1, SCP_SCL0,
	    SCP_SCL1, RES6, RES7),
	PIN(138, SDA5, 0, 13, 0x21, 0x80,
	    SDA5, URXD2, URTS1, SCP_SDA0,
	    SCP_SDA1, RES6, RES7),
	PIN(139, SCL6, 0, 7, 0x12, 0x60,
	    SCL6, UTXD1, TP_UTXD1_AO, SCP_SCL0,
	    SCP_SCL1, RES6, dbg_mon_b12),
	PIN(140, SDA6, 0, 8, 0x12, 0x60,
	    SDA6, URXD1, TP_URXD1_AO, SCP_SDA0,
	    SCP_SDA1, RES6, dbg_mon_b13),
	PIN(141, SCL7, 0, 9, 0x23, 0x80,
	    SCL7, URTS0, TP_URTS1_AO, SCP_SCL0,
	    SCP_SCL1, UDI_TCK, dbg_mon_b14),
	PIN(142, SDA7, 0, 11, 0x23, 0x80,
	    SDA7, UCTS0, TP_UCTS1_AO, SCP_SDA0,
	    SCP_SDA1, RES6, RES7),
	PIN(143, SCL8, 0, 22, 0x16, 0x50,
	    SCL8, RES2, RES3, SCP_SCL0,
	    SCP_SCL1, RES6, dbg_mon_b16),
	PIN(144, SDA8, 0, 25, 0x16, 0x50,
	    SDA8, RES2, RES3, SCP_SDA0,
	    SCP_SDA1, RES6, dbg_mon_b17),
	PIN(145, SCL9, 0, 23, 0x16, 0x50,
	    SCL9, CMVREF1, GPS_PPS, SCP_SCL0,
	    SCP_SCL1, RES6, dbg_mon_b18),
	PIN(146, SDA9, 0, 26, 0x16, 0x50,
	    SDA9, CMVREF0, RES3, SCP_SDA0,
	    SCP_SDA1, RES6, dbg_mon_b19),
	PIN(147, PERIPHERAL_EN0, 0, 23, 0x24, 0x60,
	    CMFLASH0, LVTS_SDI, DPI_DATA12, TP_GPIO0_AO,
	    ANT_SEL3, DFD_TCK_XI, dbg_mon_b20),
	PIN(148, PERIPHERAL_EN1, 0, 24, 0x24, 0x60,
	    CMFLASH1, LVTS_SCF, DPI_DATA13, TP_GPIO1_AO,
	    ANT_SEL4, DFD_TMS, dbg_mon_b21),
	PIN(149, PERIPHERAL_EN2, 0, 25, 0x24, 0x60,
	    CMFLASH2, CLKM0, DPI_DATA14, TP_GPIO2_AO,
	    ANT_SEL5, DFD_TDI, dbg_mon_b22),
	PIN(150, PERIPHERAL_EN3, 0, 26, 0x24, 0x60,
	    RES1, CLKM1, DPI_DATA15, TP_GPIO3_AO,
	    ANT_SEL6, DFD_TDO, dbg_mon_b23),
	PIN(151, PERIPHERAL_EN4, 0, 27, 0x24, 0x60,
	    GPS_L1_ELNA_EN, CLKM2, DPI_DATA16, TP_GPIO4_AO,
	    ANT_SEL7, UDI_TMS, dbg_mon_b24),
	PIN(152, PERIPHERAL_EN5, 0, 28, 0x24, 0x60,
	    RES1, CLKM3, DPI_DATA17, TP_GPIO5_AO,
	    RES5, RES6, RES7),
	PIN(153, PERIPHERAL_EN6, 0, 29, 0x24, 0x60,
	    CONN_TCXOENA_REQ, RES2, DPI_DATA18, TP_GPIO6_AO,
	    RES5, UDI_TDI, dbg_mon_b26),
	PIN(154, PERIPHERAL_EN7, 0, 30, 0x24, 0x60,
	    PWM0, CMVREF2, DPI_DATA19, TP_GPIO7_AO,
	    RES5, UDI_TDO, dbg_mon_b27),
	PIN(155, PERIPHERAL_EN8, 0, 31, 0x24, 0x60,
	    PWM1, CMVREF1, DPI_DATA20, RES4,
	    RES5, UDI_NTRST, dbg_mon_b28),
	PIN(156, PERIPHERAL_EN9, 0, 0, 0x24, 0x70,
	    PWM2, CMVREF0, DPI_DATA21, RES4,
	    RES5, RES6, RES7),
	PIN(157, PWRAP_SPI0_CSN, 0, 4, 0x12, 0x60,
	    PWRAP_SPI0_CSN, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(158, PWRAP_SPI0_CK, 0, 3, 0x12, 0x60,
	    PWRAP_SPI0_CK, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(159, PWRAP_SPI0_MO, 0, 6, 0x12, 0x60,
	    PWRAP_SPI0_MO, PWRAP_SPI0_MI, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(160, PWRAP_SPI0_MI, 0, 5, 0x12, 0x60,
	    PWRAP_SPI0_MI, PWRAP_SPI0_MO, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(161, SRCLKENA0, 0, 23, 0x12, 0x60,
	    SRCLKENA0, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(162, SRCLKENA1, 0, 24, 0x12, 0x60,
	    SRCLKENA1, RES2, RES3, RES4,
	    RES5, RES6, dbg_mon_a31),
	PIN(163, SCP_VREQ_VAO, 0, 11, 0x21, 0x80,
	    SCP_VREQ_VAO, DVFSRC_EXT_REQ, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(164, RTC32K_CK, 0, 8, 0x21, 0x80,
	    RTC32K_CK, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(165, WATCHDOG, 0, 16, 0x21, 0x80,
	    WATCHDOG, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(166, AUD_CLK_MOSI, 0, 1, 0x21, 0x80,
	    AUD_CLK_MOSI, AUD_CLK_MISO, I2S1_MCK, RES4,
	    RES5, RES6, RES7),
	PIN(167, AUD_SYNC_MOSI, 0, 7, 0x21, 0x80,
	    AUD_SYNC_MOSI, AUD_SYNC_MISO, I2S1_BCK, RES4,
	    RES5, RES6, RES7),
	PIN(168, AUD_DAT_MOSI0, 0, 4, 0x21, 0x80,
	    AUD_DAT_MOSI0, AUD_DAT_MISO0, I2S1_LRCK, RES4,
	    RES5, RES6, RES7),
	PIN(169, AUD_DAT_MOSI1, 0, 5, 0x21, 0x80,
	    AUD_DAT_MOSI1, AUD_DAT_MISO1, I2S1_DO, RES4,
	    RES5, RES6, RES7),
	PIN(170, AUD_CLK_MISO, 0, 0, 0x21, 0x80,
	    AUD_CLK_MISO, AUD_CLK_MOSI, I2S2_MCK, RES4,
	    RES5, RES6, RES7),
	PIN(171, AUD_SYNC_MISO, 0, 6, 0x21, 0x80,
	    AUD_SYNC_MISO, AUD_SYNC_MOSI, I2S2_BCK, RES4,
	    RES5, RES6, RES7),
	PIN(172, AUD_DAT_MISO0, 0, 2, 0x21, 0x80,
	    AUD_DAT_MISO0, AUD_DAT_MOSI0, I2S2_LRCK, VOW_DAT_MISO,
	    RES5, RES6, RES7),
	PIN(173, AUD_DAT_MISO1, 0, 3, 0x21, 0x80,
	    AUD_DAT_MISO1, AUD_DAT_MOSI1, I2S2_DI, VOW_CLK_MISO,
	    RES5, RES6, RES7),
	PIN(174, CONN_TOP_CLK, 0, 7, 0x16, 0x50,
	    CONN_TOP_CLK, AUXIF_CLK, DFD_TCK_XI, RES4,
	    RES5, RES6, dbg_mon_b3),
	PIN(175, CONN_TOP_DATA, 0, 8, 0x16, 0x50,
	    CONN_TOP_DATA, AUXIF_ST, DFD_TMS, RES4,
	    RES5, RES6, dbg_mon_b15),
	PIN(176, CONN_BT_CLK, 0, 4, 0x16, 0x50,
	    CONN_BT_CLK, RES2, DFD_TDI, RES4,
	    RES5, RES6, dbg_mon_b2),
	PIN(177, CONN_BT_DATA, 0, 5, 0x16, 0x50,
	    CONN_BT_DATA, RES2, DFD_TDO, RES4,
	    RES5, RES6, RES7),
	PIN(178, CONN_HRST_B, 0, 6, 0x16, 0x50,
	    CONN_HRST_B, RES2, UDI_TMS, RES4,
	    RES5, RES6, dbg_mon_b25),
	PIN(179, CONN_WB_PTA, 0, 9, 0x16, 0x50,
	    CONN_WB_PTA, RES2, UDI_TCK, RES4,
	    RES5, RES6, dbg_mon_b29),
	PIN(180, CONN_WF_CTRL0, 0, 10, 0x16, 0x50,
	    CONN_WF_CTRL0, RES2, UDI_TDI, RES4,
	    RES5, RES6, RES7),
	PIN(181, CONN_WF_CTRL1, 0, 11, 0x16, 0x50,
	    CONN_WF_CTRL1, RES2, UDI_TDO, RES4,
	    RES5, RES6, RES7),
	PIN(182, CONN_WF_CTRL2, 0, 12, 0x16, 0x50,
	    CONN_WF_CTRL2, RES2, UDI_NTRST, RES4,
	    RES5, RES6, RES7),
	PIN(183, SPMI_SCL, 0, 21, 0x12, 0x60,
	    SPMI_SCL, RES2, RES3, RES4,
	    RES5, RES6, RES7),
	PIN(184, SPMI_SDA, 0, 22, 0x12, 0x60,
	    SPMI_SDA, RES2, RES3, RES4,
	    RES5, RES6, RES7),
};

struct val_regs {
	uint32_t val;
	uint32_t set;
	uint32_t rst;
	uint32_t align;
};

struct gpio_regs {
	struct val_regs dir[7];
	uint8_t rsv00[144];
	struct val_regs dout[7];
	uint8_t rsv01[144];
	struct val_regs din[7];
	uint8_t rsv02[144];
	struct val_regs mode[28];
	uint8_t rsv03[560];
	uint32_t dram_pinmux_trapping;
};

check_member(gpio_regs, mode[27].val, 0x4b0);
check_member(gpio_regs, dram_pinmux_trapping, 0x6f0);

static struct gpio_regs *const mtk_gpio = (void *)(GPIO_BASE);

#endif
