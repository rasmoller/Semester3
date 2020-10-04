/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.3
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2019 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* LED */
#define LED__0__INTTYPE CYREG_PICU2_INTTYPE1
#define LED__0__MASK 0x02u
#define LED__0__PC CYREG_PRT2_PC1
#define LED__0__PORT 2u
#define LED__0__SHIFT 1u
#define LED__AG CYREG_PRT2_AG
#define LED__AMUX CYREG_PRT2_AMUX
#define LED__BIE CYREG_PRT2_BIE
#define LED__BIT_MASK CYREG_PRT2_BIT_MASK
#define LED__BYP CYREG_PRT2_BYP
#define LED__CTL CYREG_PRT2_CTL
#define LED__DM0 CYREG_PRT2_DM0
#define LED__DM1 CYREG_PRT2_DM1
#define LED__DM2 CYREG_PRT2_DM2
#define LED__DR CYREG_PRT2_DR
#define LED__INP_DIS CYREG_PRT2_INP_DIS
#define LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LED__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LED__LCD_EN CYREG_PRT2_LCD_EN
#define LED__MASK 0x02u
#define LED__PORT 2u
#define LED__PRT CYREG_PRT2_PRT
#define LED__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LED__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LED__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LED__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LED__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LED__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LED__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LED__PS CYREG_PRT2_PS
#define LED__SHIFT 1u
#define LED__SLW CYREG_PRT2_SLW

/* MISO */
#define MISO__0__INTTYPE CYREG_PICU2_INTTYPE4
#define MISO__0__MASK 0x10u
#define MISO__0__PC CYREG_PRT2_PC4
#define MISO__0__PORT 2u
#define MISO__0__SHIFT 4u
#define MISO__AG CYREG_PRT2_AG
#define MISO__AMUX CYREG_PRT2_AMUX
#define MISO__BIE CYREG_PRT2_BIE
#define MISO__BIT_MASK CYREG_PRT2_BIT_MASK
#define MISO__BYP CYREG_PRT2_BYP
#define MISO__CTL CYREG_PRT2_CTL
#define MISO__DM0 CYREG_PRT2_DM0
#define MISO__DM1 CYREG_PRT2_DM1
#define MISO__DM2 CYREG_PRT2_DM2
#define MISO__DR CYREG_PRT2_DR
#define MISO__INP_DIS CYREG_PRT2_INP_DIS
#define MISO__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define MISO__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define MISO__LCD_EN CYREG_PRT2_LCD_EN
#define MISO__MASK 0x10u
#define MISO__PORT 2u
#define MISO__PRT CYREG_PRT2_PRT
#define MISO__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define MISO__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define MISO__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define MISO__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define MISO__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define MISO__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define MISO__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define MISO__PS CYREG_PRT2_PS
#define MISO__SHIFT 4u
#define MISO__SLW CYREG_PRT2_SLW

/* MOSI */
#define MOSI__0__INTTYPE CYREG_PICU2_INTTYPE5
#define MOSI__0__MASK 0x20u
#define MOSI__0__PC CYREG_PRT2_PC5
#define MOSI__0__PORT 2u
#define MOSI__0__SHIFT 5u
#define MOSI__AG CYREG_PRT2_AG
#define MOSI__AMUX CYREG_PRT2_AMUX
#define MOSI__BIE CYREG_PRT2_BIE
#define MOSI__BIT_MASK CYREG_PRT2_BIT_MASK
#define MOSI__BYP CYREG_PRT2_BYP
#define MOSI__CTL CYREG_PRT2_CTL
#define MOSI__DM0 CYREG_PRT2_DM0
#define MOSI__DM1 CYREG_PRT2_DM1
#define MOSI__DM2 CYREG_PRT2_DM2
#define MOSI__DR CYREG_PRT2_DR
#define MOSI__INP_DIS CYREG_PRT2_INP_DIS
#define MOSI__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define MOSI__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define MOSI__LCD_EN CYREG_PRT2_LCD_EN
#define MOSI__MASK 0x20u
#define MOSI__PORT 2u
#define MOSI__PRT CYREG_PRT2_PRT
#define MOSI__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define MOSI__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define MOSI__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define MOSI__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define MOSI__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define MOSI__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define MOSI__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define MOSI__PS CYREG_PRT2_PS
#define MOSI__SHIFT 5u
#define MOSI__SLW CYREG_PRT2_SLW

/* SCLK */
#define SCLK__0__INTTYPE CYREG_PICU2_INTTYPE6
#define SCLK__0__MASK 0x40u
#define SCLK__0__PC CYREG_PRT2_PC6
#define SCLK__0__PORT 2u
#define SCLK__0__SHIFT 6u
#define SCLK__AG CYREG_PRT2_AG
#define SCLK__AMUX CYREG_PRT2_AMUX
#define SCLK__BIE CYREG_PRT2_BIE
#define SCLK__BIT_MASK CYREG_PRT2_BIT_MASK
#define SCLK__BYP CYREG_PRT2_BYP
#define SCLK__CTL CYREG_PRT2_CTL
#define SCLK__DM0 CYREG_PRT2_DM0
#define SCLK__DM1 CYREG_PRT2_DM1
#define SCLK__DM2 CYREG_PRT2_DM2
#define SCLK__DR CYREG_PRT2_DR
#define SCLK__INP_DIS CYREG_PRT2_INP_DIS
#define SCLK__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define SCLK__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define SCLK__LCD_EN CYREG_PRT2_LCD_EN
#define SCLK__MASK 0x40u
#define SCLK__PORT 2u
#define SCLK__PRT CYREG_PRT2_PRT
#define SCLK__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define SCLK__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define SCLK__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define SCLK__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define SCLK__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define SCLK__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define SCLK__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define SCLK__PS CYREG_PRT2_PS
#define SCLK__SHIFT 6u
#define SCLK__SLW CYREG_PRT2_SLW

/* SPIS_BSPIS */
#define SPIS_BSPIS_BitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define SPIS_BSPIS_BitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define SPIS_BSPIS_BitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB13_14_CTL
#define SPIS_BSPIS_BitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define SPIS_BSPIS_BitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB13_14_CTL
#define SPIS_BSPIS_BitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB13_14_MSK
#define SPIS_BSPIS_BitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define SPIS_BSPIS_BitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB13_14_MSK
#define SPIS_BSPIS_BitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define SPIS_BSPIS_BitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define SPIS_BSPIS_BitCounter__CONTROL_REG CYREG_B0_UDB13_CTL
#define SPIS_BSPIS_BitCounter__CONTROL_ST_REG CYREG_B0_UDB13_ST_CTL
#define SPIS_BSPIS_BitCounter__COUNT_REG CYREG_B0_UDB13_CTL
#define SPIS_BSPIS_BitCounter__COUNT_ST_REG CYREG_B0_UDB13_ST_CTL
#define SPIS_BSPIS_BitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define SPIS_BSPIS_BitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define SPIS_BSPIS_BitCounter__PERIOD_REG CYREG_B0_UDB13_MSK
#define SPIS_BSPIS_RxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define SPIS_BSPIS_RxStsReg__16BIT_STATUS_REG CYREG_B0_UDB12_13_ST
#define SPIS_BSPIS_RxStsReg__3__MASK 0x08u
#define SPIS_BSPIS_RxStsReg__3__POS 3
#define SPIS_BSPIS_RxStsReg__4__MASK 0x10u
#define SPIS_BSPIS_RxStsReg__4__POS 4
#define SPIS_BSPIS_RxStsReg__5__MASK 0x20u
#define SPIS_BSPIS_RxStsReg__5__POS 5
#define SPIS_BSPIS_RxStsReg__6__MASK 0x40u
#define SPIS_BSPIS_RxStsReg__6__POS 6
#define SPIS_BSPIS_RxStsReg__MASK 0x78u
#define SPIS_BSPIS_RxStsReg__MASK_REG CYREG_B0_UDB12_MSK
#define SPIS_BSPIS_RxStsReg__STATUS_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define SPIS_BSPIS_RxStsReg__STATUS_REG CYREG_B0_UDB12_ST
#define SPIS_BSPIS_sR8_Dp_u0__16BIT_A0_REG CYREG_B0_UDB13_14_A0
#define SPIS_BSPIS_sR8_Dp_u0__16BIT_A1_REG CYREG_B0_UDB13_14_A1
#define SPIS_BSPIS_sR8_Dp_u0__16BIT_D0_REG CYREG_B0_UDB13_14_D0
#define SPIS_BSPIS_sR8_Dp_u0__16BIT_D1_REG CYREG_B0_UDB13_14_D1
#define SPIS_BSPIS_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define SPIS_BSPIS_sR8_Dp_u0__16BIT_F0_REG CYREG_B0_UDB13_14_F0
#define SPIS_BSPIS_sR8_Dp_u0__16BIT_F1_REG CYREG_B0_UDB13_14_F1
#define SPIS_BSPIS_sR8_Dp_u0__A0_A1_REG CYREG_B0_UDB13_A0_A1
#define SPIS_BSPIS_sR8_Dp_u0__A0_REG CYREG_B0_UDB13_A0
#define SPIS_BSPIS_sR8_Dp_u0__A1_REG CYREG_B0_UDB13_A1
#define SPIS_BSPIS_sR8_Dp_u0__D0_D1_REG CYREG_B0_UDB13_D0_D1
#define SPIS_BSPIS_sR8_Dp_u0__D0_REG CYREG_B0_UDB13_D0
#define SPIS_BSPIS_sR8_Dp_u0__D1_REG CYREG_B0_UDB13_D1
#define SPIS_BSPIS_sR8_Dp_u0__DP_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define SPIS_BSPIS_sR8_Dp_u0__F0_F1_REG CYREG_B0_UDB13_F0_F1
#define SPIS_BSPIS_sR8_Dp_u0__F0_REG CYREG_B0_UDB13_F0
#define SPIS_BSPIS_sR8_Dp_u0__F1_REG CYREG_B0_UDB13_F1
#define SPIS_BSPIS_sR8_Dp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define SPIS_BSPIS_sR8_Dp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define SPIS_BSPIS_TxStsReg__0__MASK 0x01u
#define SPIS_BSPIS_TxStsReg__0__POS 0
#define SPIS_BSPIS_TxStsReg__1__MASK 0x02u
#define SPIS_BSPIS_TxStsReg__1__POS 1
#define SPIS_BSPIS_TxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define SPIS_BSPIS_TxStsReg__16BIT_STATUS_REG CYREG_B0_UDB11_12_ST
#define SPIS_BSPIS_TxStsReg__2__MASK 0x04u
#define SPIS_BSPIS_TxStsReg__2__POS 2
#define SPIS_BSPIS_TxStsReg__6__MASK 0x40u
#define SPIS_BSPIS_TxStsReg__6__POS 6
#define SPIS_BSPIS_TxStsReg__MASK 0x47u
#define SPIS_BSPIS_TxStsReg__MASK_REG CYREG_B0_UDB11_MSK
#define SPIS_BSPIS_TxStsReg__STATUS_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define SPIS_BSPIS_TxStsReg__STATUS_REG CYREG_B0_UDB11_ST

/* SPIS_IntClock */
#define SPIS_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define SPIS_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define SPIS_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define SPIS_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define SPIS_IntClock__INDEX 0x00u
#define SPIS_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define SPIS_IntClock__PM_ACT_MSK 0x01u
#define SPIS_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define SPIS_IntClock__PM_STBY_MSK 0x01u

/* Miscellaneous */
#define isr_spi_rx__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_spi_rx__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_spi_rx__INTC_MASK 0x01u
#define isr_spi_rx__INTC_NUMBER 0u
#define isr_spi_rx__INTC_PRIOR_NUM 7u
#define isr_spi_rx__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define isr_spi_rx__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_spi_rx__INTC_SET_PD_REG CYREG_NVIC_SETPEND0
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "spi_slave"
#define CY_VERSION "PSoC Creator  4.3"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 24u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 24u
#define CYDEV_CHIP_MEMBER_4AA 23u
#define CYDEV_CHIP_MEMBER_4AB 28u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4D 18u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 25u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 22u
#define CYDEV_CHIP_MEMBER_4I 30u
#define CYDEV_CHIP_MEMBER_4J 19u
#define CYDEV_CHIP_MEMBER_4K 20u
#define CYDEV_CHIP_MEMBER_4L 29u
#define CYDEV_CHIP_MEMBER_4M 27u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 26u
#define CYDEV_CHIP_MEMBER_4Q 15u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 21u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 16u
#define CYDEV_CHIP_MEMBER_4Z 17u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 31u
#define CYDEV_CHIP_MEMBER_FM3 35u
#define CYDEV_CHIP_MEMBER_FM4 36u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 32u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 33u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 34u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
