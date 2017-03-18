/*
 * $QNXLicenseC:
 * Copyright 2015, QNX Software Systems.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */


/*
 * Renesas R-Car processor with ARMv7 Cortex-A7 core
 */

#ifndef __ARM_RCAR_H_INCLUDED
#define __ARM_RCAR_H_INCLUDED

#define RCAR_EXT_CLK            20000000        /* External crystal clock */

/*
 * GPIO
 */
#define RCAR_GPIO0_BASE         0xE6050000
#define RCAR_GPIO1_BASE         0xE6051000
#define RCAR_GPIO2_BASE         0xE6052000
#define RCAR_GPIO3_BASE         0xE6053000
#define RCAR_GPIO4_BASE         0xE6054000
#define RCAR_GPIO5_BASE         0xE6055000
#define RCAR_GPIO6_BASE         0xE6055400
#define RCAR_GPIO7_BASE         0xE6055800

 // GPIO Registers, offset from GPIO_BASE
 #define RCAR_GPIO_IOINTSEL     0x0000
 #define RCAR_GPIO_INOUTSEL     0x0004
 #define RCAR_GPIO_OUTDT        0x0008
 #define RCAR_GPIO_INDT         0x000C
 #define RCAR_GPIO_INTDT        0x0010
 #define RCAR_GPIO_INTCLR       0x0014
 #define RCAR_GPIO_INTMSK       0x0018
 #define RCAR_GPIO_MSKCLR       0x001C
 #define RCAR_GPIO_POSNEG       0x0020
 #define RCAR_GPIO_EDGLEVEL     0x0024
 #define RCAR_GPIO_FILONOFF     0x0028
 #define RCAR_GPIO_INTMSKS      0x0038
 #define RCAR_GPIO_MSKCLRS      0x003C
 #define RCAR_GPIO_OUTDTSEL     0x0040
 #define RCAR_GPIO_OUTDTH       0x0044
 #define RCAR_GPIO_OUTDTL       0x0048
 #define RCAR_GPIO_BOTHEDGE     0x004C


/*
 * Pin Function Control
 */
#define RCAR_PFC_BASE               0xE6060000

 /* PFC registers, offset from RCAR_PFC_BASE */
 #define RCAR_PFC_PMMR              0x000
 #define RCAR_PFC_GPSR0             0x004
 #define RCAR_PFC_GPSR1             0x008
 #define RCAR_PFC_GPSR2             0x00C
 #define RCAR_PFC_GPSR3             0x010
 #define RCAR_PFC_GPSR4             0x014
 #define RCAR_PFC_GPSR5             0x018
 #define RCAR_PFC_IPSR0             0x040
 #define RCAR_PFC_IPSR1             0x044
 #define RCAR_PFC_IPSR2             0x048
 #define RCAR_PFC_IPSR3             0x04C
 #define RCAR_PFC_IPSR4             0x050
 #define RCAR_PFC_IPSR5             0x054
 #define RCAR_PFC_IPSR6             0x058
 #define RCAR_PFC_IPSR7             0x05C
 #define RCAR_PFC_IPSR8             0x060
 #define RCAR_PFC_IPSR9             0x064
 #define RCAR_PFC_IPSR10            0x068
 #define RCAR_PFC_IPSR11            0x06C
 #define RCAR_PFC_IPSR12            0x070
 #define RCAR_PFC_IPSR13            0x074
 #define RCAR_PFC_IPSR14            0x078
 #define RCAR_PFC_IPSR15            0x07C
 #define RCAR_PFC_IPSR16            0x080
 #define RCAR_PFC_IPSR17            0x084
 #define RCAR_PFC_MODSEL0           0x0C0
 #define RCAR_PFC_MODSEL1           0x0C4
 #define RCAR_PFC_MODSEL2           0x0C8 
 #define RCAR_PFC_PUPR0             0x100
 #define RCAR_PFC_PUPR1             0x104
 #define RCAR_PFC_PUPR2             0x108
 #define RCAR_PFC_PUPR3             0x10C
 #define RCAR_PFC_PUPR4             0x110
 #define RCAR_PFC_PUPR5             0x114
 #define RCAR_PFC_IOCTRL0           0x094
 #define RCAR_PFC_IOCTRL1           0x098
 #define RCAR_PFC_IOCTRL2           0x09C     
 #define RCAR_PFC_IOCTRL3           0x0A0     
 #define RCAR_PFC_IOCTRL4           0x0A4
 #define RCAR_PFC_IOCTRL5           0x0A8
 #define RCAR_PFC_IOCTRL6           0x0AC

/*
 * Clock Pulse Generator
 */
#define RCAR_CPG_BASE               0xE6150000
#define RCAR_CPG_SIZE               0x1000

 /* CPG registers, offset from RCAR_CPG_BASE */
 #define RCAR_CPG_FRQCRB            0x004       // Frequency Control Register B
 #define RCAR_CPG_PLLECR            0x0D0       // PLL Enable Control Register
 #define RCAR_CPG_PLL0CR            0x0D8       // PLL0 Control Register
 #define RCAR_CPG_SDCKCR            0x074       // SDHI Clock Frequency Control Register
 #define RCAR_CPG_SD2CKCR           0x078       // SDHI 2 Clock Frequency Control Register
 #define RCAR_CPG_RCANCKCR          0x270       // RCAN Clock Frequency Control Register

 #define RCAR_CPG_MSTPSR0           0x030       // Module Stop Status Register 0
 #define RCAR_CPG_MSTPSR1           0x038       // Module Stop Status Register 1
 #define RCAR_CPG_MSTPSR2           0x040       // Module Stop Status Register 2
 #define RCAR_CPG_MSTPSR3           0x048       // Module Stop Status Register 3
 #define RCAR_CPG_MSTPSR4           0x04C       // Module Stop Status Register 4
 #define RCAR_CPG_MSTPSR5           0x03C       // Module Stop Status Register 5
 #define RCAR_CPG_MSTPSR7           0x1C4       // Module Stop Status Register 7
 #define RCAR_CPG_MSTPSR8           0x9A0       // Module Stop Status Register 8
 #define RCAR_CPG_MSTPSR9           0x9A4       // Module Stop Status Register 9
 #define RCAR_CPG_MSTPSR10          0x9A8       // Module Stop Status Register 10

 #define RCAR_CPG_RMSTPCR0          0x110       // Realtime Module Stop Control Register 0
 #define RCAR_CPG_RMSTPCR1          0x114       // Realtime Module Stop Control Register 1
 #define RCAR_CPG_RMSTPCR2          0x118       // Realtime Module Stop Control Register 2
 #define RCAR_CPG_RMSTPCR3          0x11C       // Realtime Module Stop Control Register 3
 #define RCAR_CPG_RMSTPCR4          0x120       // Realtime Module Stop Control Register 4
 #define RCAR_CPG_RMSTPCR5          0x124       // Realtime Module Stop Control Register 5
 #define RCAR_CPG_RMSTPCR7          0x12C       // Realtime Module Stop Control Register 7
 #define RCAR_CPG_RMSTPCR8          0x980       // Realtime Module Stop Control Register 8
 #define RCAR_CPG_RMSTPCR9          0x984       // Realtime Module Stop Control Register 9
 #define RCAR_CPG_RMSTPCR10         0x988       // Realtime Module Stop Control Register 10

 #define RCAR_CPG_SMSTPCR0          0x130       // System Module Stop Control Register 0
 #define RCAR_CPG_SMSTPCR1          0x134       // System Module Stop Control Register 1
 #define RCAR_CPG_SMSTPCR2          0x138       // System Module Stop Control Register 2
 #define RCAR_CPG_SMSTPCR3          0x13C       // System Module Stop Control Register 3
 #define RCAR_CPG_SMSTPCR4          0x140       // System Module Stop Control Register 4
 #define RCAR_CPG_SMSTPCR5          0x144       // System Module Stop Control Register 5
 #define RCAR_CPG_SMSTPCR7          0x14C       // System Module Stop Control Register 7
 #define RCAR_CPG_SMSTPCR8          0x990       // System Module Stop Control Register 8
 #define RCAR_CPG_SMSTPCR9          0x994       // System Module Stop Control Register 9
 #define RCAR_CPG_SMSTPCR10         0x998       // System Module Stop Control Register 10

 #define RCAR_CPG_SRCR0             0x0A0       // Software Reset Register 0
 #define RCAR_CPG_SRCR1             0x0A8       // Software Reset Register 1
 #define RCAR_CPG_SRCR2             0x0B0       // Software Reset Register 2
 #define RCAR_CPG_SRCR3             0x0B8       // Software Reset Register 3
 #define RCAR_CPG_SRCR4             0x0BC       // Software Reset Register 4
 #define RCAR_CPG_SRCR5             0x0C4       // Software Reset Register 5
 #define RCAR_CPG_SRCR7             0x1CC       // Software Reset Register 7
 #define RCAR_CPG_SRCR8             0x920       // Software Reset Register 8
 #define RCAR_CPG_SRCR9             0x924       // Software Reset Register 9
 #define RCAR_CPG_SRCR10            0x928       // Software Reset Register 10

 #define RCAR_CPG_SRSTCLR0          0x940       // Software Reset Clear Register 0
 #define RCAR_CPG_SRSTCLR1          0x944       // Software Reset Clear Register 1
 #define RCAR_CPG_SRSTCLR2          0x948       // Software Reset Clear Register 2
 #define RCAR_CPG_SRSTCLR3          0x94C       // Software Reset Clear Register 3
 #define RCAR_CPG_SRSTCLR4          0x950       // Software Reset Clear Register 4
 #define RCAR_CPG_SRSTCLR5          0x954       // Software Reset Clear Register 5
 #define RCAR_CPG_SRSTCLR7          0x95C       // Software Reset Clear Register 7
 #define RCAR_CPG_SRSTCLR8          0x960       // Software Reset Clear Register 8
 #define RCAR_CPG_SRSTCLR9          0x964       // Software Reset Clear Register 9
 #define RCAR_CPG_SRSTCLR10         0x968       // Software Reset Clear Register 10

/*
 * Reset registers
 */
#define RCAR_RESET_BASE             0xE6160000
 #define RCAR_WDTRSTCR              0x54        // Watchdog reset control register

/*
 * SYStem Controller
 */
#define RCAR_SYSC_BASE              0xE6180000
 #define RCAR_SYSC_SR               0x00        // Status Register
 #define RCAR_SYSC_ISR              0x04        // Interrupt Status Register
 #define RCAR_SYSC_ISCR             0x08        // Interrupt Status Clear Register
 #define RCAR_SYSC_IER              0x0C        // Interrupt Enable Register
 #define RCAR_SYSC_IMR              0x10        // Interrupt Mask Register
 #define RCAR_SYSC_PWRSR2           0xC0        // Power Status Register 2
 #define RCAR_SYSC_PWROFFCR2        0xC4        // Power Shutoff Control Register 2
 #define RCAR_SYSC_PWROFFSR2        0xC8        // Power Shutoff Status Register 2
 #define RCAR_SYSC_PWRONCR2         0xCC        // Power Resume Control Register 2
 #define RCAR_SYSC_PWRONSR2         0xD0        // Power Resume Status Register 2
 #define RCAR_SYSC_PWRER2           0xD4        // Power shutoff/resume Error Register 2


/*
 * Watchdog Timer
 */
#define RCAR_RWDT_BASE              0xE6020000  // RCLK Watchdog Timer
#define RCAR_SWDT_BASE              0xE6030000  // Secure Watchdog Timer
 #define RCAR_WDT_CNT               0x00        // Count Register
 #define RCAR_WDT_CSRA              0x04        // Control/Status Register A
 #define RCAR_WDT_CSRB              0x08        // Control/Status Register B

/*
 * SCU
 */
#define RCAR_SCU_BASE               0xEC500000
#define RCAR_SCU_SIZE               0x1000

/*
 * SSIU
 */
#define RCAR_SSIU_BASE              0xEC540000
 #define RCAR_SSIU_MODE0            0x800
 #define RCAR_SSIU_MODE1            0x804
 #define RCAR_SSIU_MODE2            0x808
 #define RCAR_SSIU_MODE3            0x80C
 #define RCAR_SSIU_CONTROL          0x810


/*
 * SSI
 */
#define RCAR_SSI_BASE               0xEC541000
 #define RCAR_SSI_CR                0x00        // Control Register
 #define RCAR_SSI_SR                0x04        // Status Register
 #define RCAR_SSI_TDR               0x08        // Transmit Data Register
 #define RCAR_SSI_RDR               0x0C        // Receive Data Register
 #define RCAR_SSI_WSR               0x20        // WS Mode Register
 #define RCAR_SSI_FMR               0x24        // FS Mode Register
 #define RCAR_SSI_FSR               0x28        // FS Status Register

/*
 * GIC
 */
#define RCAR_GIC_BASE               0xF1000000
#define RCAR_GIC_CPU_BASE           0xF1002000
#define RCAR_GIC_DIST_BASE          0xF1001000

/*
 * INTC
 */
#define RCAR_IRQC0_BASE             0xE61C0000
#define RCAR_IRQC1_BASE             0xE61C0200
 #define RCAR_INTREQ_STS0           0x000       /* R */
 #define RCAR_INTEN_STS0            0x004       /* R/WC1 */
 #define RCAR_INTEN_SET0            0x008       /* W */
 #define RCAR_INTREQ_STS1           0x010       /* R */
 #define RCAR_INTEN_STS1            0x014       /* R/WC1 */
 #define RCAR_INTEN_SET1            0x018       /* W */
 #define RCAR_DETECT_STATUS         0x100       /* R/WC1 */
 #define RCAR_CONFIG_00             0x180       /* R/W */


/*
 * SDH interface
 */
#define RCAR_SDHI0_BASE             0xEE100000  // SDHI0 Base
#define RCAR_SDHI1_BASE             0xEE300000  // SDHI1 Base
#define RCAR_SDHI2_BASE             0xEE160000  // SDHI3 Base
#define RCAR_SDHI_SIZE              0x2000

/*
 * MMCIF
 */
#define RCAR_MMCIF_BASE             0xEE300000
#define RCAR_MMCIF_SIZE             0x1000

/*
 * SYSDMAC
 */
#define RCAR_SYSDMAC0_BASE          0xE6700000
#define RCAR_SYSDMAC1_BASE          0xE6720000

 /* SYSDMAC global registers, offset from BASE */
 #define RCAR_SYSDMAC_DMAISTA       0x0020      // DMA interrupt status register
 #define RCAR_SYSDMAC_DMASEC        0x0030      // DMA secure control register
 #define RCAR_SYSDMAC_DMAOR         0x0060      // DMA operation register
 #define RCAR_SYSDMAC_DMACHCLR      0x0080      // DMA channel clear register
 #define RCAR_SYSDMAC_DMADPSEC      0x00A0      // DPRAM secure control register

/* SYSDMAC register offset */
#define RCAR_SYSDMAC_REGS           0x8000
#define RCAR_SYSDMAC_REGSIZE        0x80

 /* SYSDMAC registers, offset from BASE + SYSDMAC_REG */
 #define RCAR_SYSDMAC_DMASAR        0x00
 #define RCAR_SYSDMAC_DMADAR        0x04
 #define RCAR_SYSDMAC_DMATCR        0x08
 #define RCAR_SYSDMAC_DMACHCR       0x0C
 #define RCAR_SYSDMAC_DMAFIXSAR     0x10
 #define RCAR_SYSDMAC_DMAFIXDAR     0x14
 #define RCAR_SYSDMAC_DMATCRB       0x18
 #define RCAR_SYSDMAC_DMACHCRB      0x1C
 #define RCAR_SYSDMAC_DMASART       0x20
 #define RCAR_SYSDMAC_DMADART       0x24
 #define RCAR_SYSDMAC_DMATSR        0x28
 #define RCAR_SYSDMAC_DMACHCRT      0x2C
 #define RCAR_SYSDMAC_DMATSRB       0x38
 #define RCAR_SYSDMAC_DMARS         0x40
 #define RCAR_SYSDMAC_DMABUFCR      0x48
 #define RCAR_SYSDMAC_DMADPBASE     0x50
 #define RCAR_SYSDMAC_DMADPCR       0x54
 #define RCAR_SYSDMAC_DMAFIXDPBASE  0x60
/*
 * AUDIODMAC
 */
#define RCAR_AUDIODMAC0_BASE        0xEC700000

/*
 * AUDIODMACPP
 */
#define RCAR_AUDIODMACPP_BASE       0xEC740000
#define RCAR_AUDIODMACPP_SIZE       0x1000
 #define RCAR_PDMASAR(x)            (0x20 + 0x10 * (x))
 #define RCAR_PDMADAR(x)            (0x24 + 0x10 * (x))
 #define RCAR_PDMACHAR(x)           (0x28 + 0x10 * (x))

/*
 * I2C
 */
#define RCAR_I2C0_BASE              0xE6508000
#define RCAR_I2C1_BASE              0xE6518000
#define RCAR_I2C2_BASE              0xE6530000
#define RCAR_I2C3_BASE              0xE6540000
#define RCAR_I2C4_BASE              0xE6520000
#define RCAR_I2C5_BASE              0xE6528000

#define RCAR_I2C_SIZE               0x100

 /* I2C registers, offset from I2C base */
 #define RCAR_I2C_ICSCR             0x00        // Slave Control Register
 #define RCAR_I2C_ICMCR             0x04        // Master Control Register
 #define RCAR_I2C_ICSSR             0x08        // Slave Status Register
 #define RCAR_I2C_ICMSR             0x0C        // Master Status Register
 #define RCAR_I2C_ICSIER            0x10        // Slave Interrupt Enable Register
 #define RCAR_I2C_ICMIER            0x14        // Master Interrupt Enable Register
 #define RCAR_I2C_ICCCR             0x18        // Clock Control Register
 #define RCAR_I2C_ICSAR             0x1C        // Slave Address Register
 #define RCAR_I2C_ICMAR             0x20        // Master Address Register
 #define RCAR_I2C_ICRXD             0x24        // Receive Data Register
 #define RCAR_I2C_ICTXD             0x24        // Transmit Data Register
 #define RCAR_I2C_ICCCR2            0x28
 #define RCAR_I2C_ICMPR             0x2C
 #define RCAR_I2C_ICHPR             0x30
 #define RCAR_I2C_ICLPR             0x34

  /* ICSCR bit definition */
  #define RCAR_ICSCR_SDBS           (1 << 3)
  #define RCAR_ICSCR_SIE            (1 << 2)
  #define RCAR_ICSCR_GCAE           (1 << 1)
  #define RCAR_ICSCR_FNA            (1 << 0)

  /* ICSSR bit definition */
  #define RCAR_ICSSR_GCAR           (1 << 6)
  #define RCAR_ICSSR_STM            (1 << 5)
  #define RCAR_ICSSR_SSR            (1 << 4)
  #define RCAR_ICSSR_SDE            (1 << 3)
  #define RCAR_ICSSR_SDT            (1 << 2)
  #define RCAR_ICSSR_SDR            (1 << 1)
  #define RCAR_ICSSR_SAR            (1 << 0)

  /* ICSIER bit definition */
  #define RCAR_ICSIER_SSRE          (1 << 4)
  #define RCAR_ICSIER_SDEE          (1 << 3)
  #define RCAR_ICSIER_SDTE          (1 << 2)
  #define RCAR_ICSIER_SDRE          (1 << 1)
  #define RCAR_ICSIER_SARE          (1 << 0)

  /* ICMCR bit definition */
  #define RCAR_ICMCR_MDBS           (1 << 7)
  #define RCAR_ICMCR_FSCL           (1 << 6)
  #define RCAR_ICMCR_FSDA           (1 << 5)
  #define RCAR_ICMCR_OBPC           (1 << 4)
  #define RCAR_ICMCR_MIE            (1 << 3)
  #define RCAR_ICMCR_TSBE           (1 << 2)
  #define RCAR_ICMCR_FSB            (1 << 1)
  #define RCAR_ICMCR_ESG            (1 << 0)

  /* ICMSR bit definition */
  #define RCAR_ICMSR_MNR            (1 << 6)
  #define RCAR_ICMSR_MAL            (1 << 5)
  #define RCAR_ICMSR_MST            (1 << 4)
  #define RCAR_ICMSR_MDE            (1 << 3)
  #define RCAR_ICMSR_MDT            (1 << 2)
  #define RCAR_ICMSR_MDR            (1 << 1)
  #define RCAR_ICMSR_MAT            (1 << 0)
 
  /* ICMIER bit definition */
  #define RCAR_ICMIER_MNRE          (1 << 6)
  #define RCAR_ICMIER_MALE          (1 << 5)
  #define RCAR_ICMIER_MSTE          (1 << 4)
  #define RCAR_ICMIER_MDEE          (1 << 3)
  #define RCAR_ICMIER_MDTE          (1 << 2)
  #define RCAR_ICMIER_MDRE          (1 << 1)
  #define RCAR_ICMIER_MATE          (1 << 0)

  /* ICMAR bit definition */
  #define RCAR_ICMAR_STM1           (1 << 0)

  /* ICCCR bit definition */
  #define RCAR_ICCCR_SCGD(x)        ((x) << 3)
  #define RCAR_ICCCR_CDF(x)         ((x) & 0x7)

/*
 * IIC
 */
#define RCAR_IIC0_BASE              0xE6500000
#define RCAR_IIC1_BASE              0xE6510000
#define RCAR_IIC2_BASE              0xE6520000
#define RCAR_IIC3_BASE              0xE60B0000

#define RCAR_IIC_SIZE               0x100

 /* IIC registers, offset from base */
 #define RCAR_IIC_ICDR              0x0000      // Data Register
 #define RCAR_IIC_ICCR              0x0004      // Control Register
 #define RCAR_IIC_ICSR              0x0008      // Status Register
 #define RCAR_IIC_ICIC              0x000C      // Interrupt Control Register
 #define RCAR_IIC_ICCL              0x0010      // Clock Control Register Low
 #define RCAR_IIC_ICCH              0x0014      // Clock Control Register High

  /* ICCR bit definition */
  #define   RCAR_ICCR_ICE           (1 << 7)    // IIC Interface Enable
  #define   RCAR_ICCR_RACK          (1 << 6)    // Receive Acknowledge
  #define   RCAR_ICCR_MTM           (1 << 4)    // Master Transmit Mode
  #define   RCAR_ICCR_MRM           (0 << 4)    // Master Receive Mode
  #define   RCAR_ICCR_BBSY          (1 << 2)    // Bus Busy
  #define   RCAR_ICCR_SCP           (1 << 0)    // START/STOP Condition Prohibit

  /* ICSR bit definition */
  #define   RCAR_ICSR_DTE           (1 << 0)    // Data Transmit Enable
  #define   RCAR_ICSR_WAIT          (1 << 1)    // Wait
  #define   RCAR_ICSR_TACK          (1 << 2)    // Transmit Acknowledge
  #define   RCAR_ICSR_AL            (1 << 3)    // Arbitration Lost
  #define   RCAR_ICSR_BUSY          (1 << 4)    // Transmit Busy

  /* ICIC bit definition */
  #define   RCAR_ICIC_DTE           (1 << 0)    // Data Transmit Enable
  #define   RCAR_ICIC_WAIT          (1 << 1)    // Wait
  #define   RCAR_ICIC_TACK          (1 << 2)    // Transmit Acknowledge
  #define   RCAR_ICIC_AL            (1 << 3)    // Arbitration Lost

/*
 * Clock Synchronized Serial Interface with FIFO
 */
#define RCAR_MSIOF0_BASE            0xE6E20000
#define RCAR_MSIOF1_BASE            0xE6E10000
#define RCAR_MSIOF2_BASE            0xE6E00000
#define RCAR_MSIOF3_BASE            0xE6C90000

#define RCAR_MSIOF_SIZE             0x100

 /* MSIOF registers, offset from base */
 #define RCAR_MSIOF_TMDR1           0x00
 #define RCAR_MSIOF_TMDR2           0x04
 #define RCAR_MSIOF_TMDR3           0x08
 #define RCAR_MSIOF_RMDR1           0x10
 #define RCAR_MSIOF_RMDR2           0x14
 #define RCAR_MSIOF_RMDR3           0x18
 #define RCAR_MSIOF_TSCR            0x20
 #define RCAR_MSIOF_RSCR            0x22
 #define RCAR_MSIOF_CTR             0x28
 #define RCAR_MSIOF_FCTR            0x30
 #define RCAR_MSIOF_STR             0x40
 #define RCAR_MSIOF_IER             0x44
 #define RCAR_MSIOF_TFDR            0x50
 #define RCAR_MSIOF_RFDR            0x60


/*
 * SCIF
 */
#define RCAR_SCIF0_BASE             0xE6E60000
#define RCAR_SCIF1_BASE             0xE6E68000
#define RCAR_SCIF2_BASE             0xE6E58000
#define RCAR_SCIF3_BASE             0xE6EA8000
#define RCAR_SCIF4_BASE             0xE6EE0000
#define RCAR_SCIF5_BASE             0xE6EE8000

#define RCAR_SCIF_SIZE              0x100

#define RCAR_SCIF_FIFO_SIZE         16

 /* SCIF registers, offset from SCIF_BASE */
 #define RCAR_SCIF_SCSMR            0x00
 #define RCAR_SCIF_SCBRR            0x04
 #define RCAR_SCIF_SCSCR            0x08
 #define RCAR_SCIF_SCFTDR           0x0C
 #define RCAR_SCIF_SCFSR            0x10
 #define RCAR_SCIF_SCFRDR           0x14
 #define RCAR_SCIF_SCFCR            0x18
 #define RCAR_SCIF_SCFDR            0x1C
 #define RCAR_SCIF_SCSPTR           0x20
 #define RCAR_SCIF_SCLSR            0x24
 #define RCAR_SCIF_BRG_DL           0x30
 #define RCAR_SCIF_BRG_CKS          0x34

 /* SCSMR bit definition */
 #define RCAR_SCIF_SCSMR_CHR        (1 << 6)
 #define RCAR_SCIF_SCSMR_PE         (1 << 5)
 #define RCAR_SCIF_SCSMR_OE         (1 << 4)
 #define RCAR_SCIF_SCSMR_STOP       (1 << 3)
 #define RCAR_SCIF_SCSMR_CKS_0      (0 << 0)
 #define RCAR_SCIF_SCSMR_CKS_4      (1 << 0)
 #define RCAR_SCIF_SCSMR_CKS_16     (2 << 0)
 #define RCAR_SCIF_SCSMR_CKS_64     (3 << 0)

  /* SCSCR bit definition */
  #define RCAR_SCIF_SCSCR_TEIE      (1 << 11)
  #define RCAR_SCIF_SCSCR_TIE       (1 << 7)
  #define RCAR_SCIF_SCSCR_RIE       (1 << 6)
  #define RCAR_SCIF_SCSCR_TE        (1 << 5)
  #define RCAR_SCIF_SCSCR_RE        (1 << 4)
  #define RCAR_SCIF_SCSCR_REIE      (1 << 3)
  #define RCAR_SCIF_SCSCR_CKE_MASK  (3 << 0)

  /* SCFSR bit definition */
  #define RCAR_SCIF_SCFSR_PERF(x)   (((x) >> 12) & 0xF)
  #define RCAR_SCIF_SCFSR_FERF(x)   (((x) >> 8) & 0xF)
  #define RCAR_SCIF_SCFSR_ER        (1 << 7)
  #define RCAR_SCIF_SCFSR_TEND      (1 << 6)
  #define RCAR_SCIF_SCFSR_TDFE      (1 << 5)
  #define RCAR_SCIF_SCFSR_BRK       (1 << 4)
  #define RCAR_SCIF_SCFSR_FER       (1 << 3)
  #define RCAR_SCIF_SCFSR_PER       (1 << 2)
  #define RCAR_SCIF_SCFSR_RDF       (1 << 1)
  #define RCAR_SCIF_SCFSR_DR        (1 << 0)

  /* SCFCR bit definition */
  #define RCAR_SCIF_SCFCR_RTRG_1    (0 << 6)
  #define RCAR_SCIF_SCFCR_RTRG_4    (1 << 6)
  #define RCAR_SCIF_SCFCR_RTRG_8    (2 << 6)
  #define RCAR_SCIF_SCFCR_RTRG_14   (3 << 6)
  #define RCAR_SCIF_SCFCR_TTRG_0    (3 << 4)
  #define RCAR_SCIF_SCFCR_TTRG_2    (2 << 4)
  #define RCAR_SCIF_SCFCR_TTRG_4    (1 << 4)
  #define RCAR_SCIF_SCFCR_TTRG_8    (0 << 4)
  #define RCAR_SCIF_SCFCR_MCE       (1 << 3)
  #define RCAR_SCIF_SCFCR_TFRST     (1 << 2)
  #define RCAR_SCIF_SCFCR_RFRST	    (1 << 1)
  #define RCAR_SCIF_SCFCR_LOOP      (1 << 0)

  /* SCFDR bit definition */
  #define RCAR_SCIF_SCFDR_TX(x)     (((x) >> 8) & 0x1F)
  #define RCAR_SCIF_SCFDR_RX(x)     ((x) & 0x1F)

  /* SCSPTR bit definition */
  #define RCAR_SCIF_SCSPTR_RTSIO    (1 << 7)
  #define RCAR_SCIF_SCSPTR_RTSDT    (1 << 6)
  #define RCAR_SCIF_SCSPTR_CTSIO    (1 << 5)
  #define RCAR_SCIF_SCSPTR_CTSDT    (1 << 4)
  #define RCAR_SCIF_SCSPTR_SPB2IO   (1 << 1)
  #define RCAR_SCIF_SCSPTR_SPB2DT   (1 << 0)

  /* SCLSR bit definition */
  #define RCAR_SCIF_SCLSR_ORER      (1 << 0)

/*
 * QSPI
 */
#define RCAR_QSPI_BASE              0xE6B10000
#define RCAR_QSPI_SIZE              0x1000

 /* QSPI registers, offset from QSPI_BASE */
 #define RCAR_QSPI_SPCR             0x00    // Control Register
 #define RCAR_QSPI_SSLP             0x01    // Slave Polarity
 #define RCAR_QSPI_SPPCR            0x02    // Pin Control Register
 #define RCAR_QSPI_SPSR             0x03    // Status Register
 #define RCAR_QSPI_SPDR             0x04    // Data Register
 #define RCAR_QSPI_SPSCR            0x08    // Sequence Control Register
 #define RCAR_QSPI_SPSSR            0x09    // Sequence Status Register
 #define RCAR_QSPI_SPBR             0x0A    // Bit Rate Register
 #define RCAR_QSPI_SPDCR            0x0B    // Data Control Register
 #define RCAR_QSPI_SPCKD            0x0C    // Clock Delay Register
 #define RCAR_QSPI_SSLND            0x0D    // Slave Negation Delay Register
 #define RCAR_QSPI_SPND             0x0E    // Next Access Delay Register
 #define RCAR_QSPI_SPCMD0           0x10    // Command Register 0
 #define RCAR_QSPI_SPCMD1           0x12    // Command Register 1
 #define RCAR_QSPI_SPCMD2           0x14    // Command Register 2
 #define RCAR_QSPI_SPCMD3           0x16    // Command Register 3
 #define RCAR_QSPI_SPBFCR           0x18    // Buffer Control Register
 #define RCAR_QSPI_SPBDCR           0x1A    // Buffer Data Count Register
 #define RCAR_QSPI_SPBMUL0          0x1C    // Tansfer Data Length Multiplier Register 0
 #define RCAR_QSPI_SPBMUL1          0x20    // Tansfer Data Length Multiplier Register 1
 #define RCAR_QSPI_SPBMUL2          0x24    // Tansfer Data Length Multiplier Register 2
 #define RCAR_QSPI_SPBMUL3          0x28    // Tansfer Data Length Multiplier Register 3

  /* SPCR bit definition */
  #define RCAR_QSPI_SPCR_SPRIE      (1 << 7)    // Receive Interrupt Enable
  #define RCAR_QSPI_SPCR_SPE        (1 << 6)    // SPI Function Enable
  #define RCAR_QSPI_SPCR_SPTIE      (1 << 5)    // Transmit Interrupt Enable
  #define RCAR_QSPI_SPCR_SPEIE      (1 << 4)    // Error Interrupt Enable
  #define RCAR_QSPI_SPCR_MSTR       (1 << 3)    // Master mode
  #define RCAR_QSPI_SPCR_WSWAP      (1 << 1)    // Word swap
  #define RCAR_QSPI_SPCR_BSWAP      (1 << 0)    // Byte swap

  /* SPSCR bit definition */
  #define RCAR_QSPI_SPSCR_1CMD      (0 << 0)    // single comand
  #define RCAR_QSPI_SPSCR_2CMD      (1 << 0)    // two comands
  #define RCAR_QSPI_SPSCR_3CMD      (2 << 0)    // three comands
  #define RCAR_QSPI_SPSCR_4CMD      (3 << 0)    // four comands

  /* SPDCR bit definition */
  #define RCAR_QSPI_SPDCR_TXDMY     (1 << 7)    // Dummy date transmission enable

  /* SPCMD bit definition */
  #define RCAR_QSPI_SPCMD_SCKDEN    (1 << 15)   // Clock delay setting enable
  #define RCAR_QSPI_SPCMD_SLNDEN    (1 << 14)   // SSL delay setting enable
  #define RCAR_QSPI_SPCMD_SPNDEN    (1 << 13)   // Next-access delay enable
  #define RCAR_QSPI_SPCMD_LSBF      (1 << 12)   // LSB first
  #define RCAR_QSPI_SPCMD_SPB8      (1 << 8)    // 8 bits data length
  #define RCAR_QSPI_SPCMD_SPB16     (2 << 8)    // 16 bits data length
  #define RCAR_QSPI_SPCMD_SPB32     (3 << 8)    // 32 bits data length
  #define RCAR_QSPI_SPCMD_SSLKP     (1 << 7)    // SSL Signal level keeping
  #define RCAR_QSPI_SPCMD_DUAL      (1 << 5)    // Dual mode
  #define RCAR_QSPI_SPCMD_QUAD      (2 << 5)    // Quad mode
  #define RCAR_QSPI_SPCMD_READ      (1 << 4)    // Read access
  #define RCAR_QSPI_SPCMD_CPOL_N    (1 << 1)    // Clock polarity negative
  #define RCAR_QSPI_SPCMD_CPHA_H    (1 << 0)    // Clock phase half clock delay

  /* SPBFCR bit definition */
  #define RCAR_QSPI_SPBFCR_TXRST    (1 << 7)    // Transmit buffer reset
  #define RCAR_QSPI_SPBFCR_RXRST    (1 << 6)    // Receive buffer reset
  #define RCAR_QSPI_SPBFCR_TXTRG_31BYTES	(0 << 4)	// Transmit Buffer Data Triggering Number
  #define RCAR_QSPI_SPBFCR_TXTRG_30BYTES	(1 << 4)
  #define RCAR_QSPI_SPBFCR_TXTRG_28BYTES	(2 << 4)
  #define RCAR_QSPI_SPBFCR_TXTRG_0BYTE		(3 << 4)
  #define RCAR_QSPI_SPBFCR_RXTRG_1BYTE		(0 << 0)	// Receive Buffer Data Triggering Number
  #define RCAR_QSPI_SPBFCR_RXTRG_2BYTES		(1 << 0)
  #define RCAR_QSPI_SPBFCR_RXTRG_4BYTES		(2 << 0)
  #define RCAR_QSPI_SPBFCR_RXTRG_5BYTES		(3 << 0)
  #define RCAR_QSPI_SPBFCR_RXTRG_8BYTE		(4 << 0)
  #define RCAR_QSPI_SPBFCR_RXTRG_16BYTES	(5 << 0)
  #define RCAR_QSPI_SPBFCR_RXTRG_24BYTES	(6 << 0)
  #define RCAR_QSPI_SPBFCR_RXTRG_32BYTES	(7 << 0)

/*
 * USB
 */
#define RCAR_USB3_BASE              0xEE000000  // USB3.0
#define RCAR_EHCI0_BASE             0xEE080000  // USB0, EHCI
#define RCAR_EHCI1_BASE             0xEE0A0000  // USB1, EHCI
#define RCAR_EHCI2_BASE             0xEE0C0000  // USB2, EHCI

#define RCAR_PCI_CONF_EHCI          0x10100     // Offset to PCI configuration Register

/*
 * HSUSB
 */
#define RCAR_HSUSB_BASE0            0xE6590000 // channel 0
#define RCAR_HSUSB_BASE1            0xE6598000 // channel 1

 #define RCAR_HSUSB_SYSCFG          0x0000
 #define RCAR_HSUSB_INTENB0         0x0030
 #define RCAR_HSUSB_UGCTRL          0x0180
 #define RCAR_HSUSB_UGCTRL2         0x0184

/*
 * DDR3 Controller
 */
#define RCAR_DBSC3_0_BASE           0xE6790000

 #define RCAR_DBSC3_DBSTATE1        0x00C
 #define RCAR_DBSC3_DBACEN          0x010
 #define RCAR_DBSC3_DBRFEN          0x014
 #define RCAR_DBSC3_DBCMD           0x018
 #define RCAR_DBSC3_DBWAIT          0x01C
 #define RCAR_DBSC3_DBKIND          0x020
 #define RCAR_DBSC3_DBCONF0         0x024
 #define RCAR_DBSC3_DBPHYTYPE       0x030
 #define RCAR_DBSC3_DBTR0           0x040
 #define RCAR_DBSC3_DBTR1           0x044
 #define RCAR_DBSC3_DBTR2           0x048
 #define RCAR_DBSC3_DBTR3           0x050
 #define RCAR_DBSC3_DBTR4           0x054
 #define RCAR_DBSC3_DBTR5           0x058
 #define RCAR_DBSC3_DBTR6           0x05C
 #define RCAR_DBSC3_DBTR7           0x060
 #define RCAR_DBSC3_DBTR8           0x064
 #define RCAR_DBSC3_DBTR9           0x068
 #define RCAR_DBSC3_DBTR10          0x06C
 #define RCAR_DBSC3_DBTR11          0x070
 #define RCAR_DBSC3_DBTR12          0x074
 #define RCAR_DBSC3_DBTR13          0x078
 #define RCAR_DBSC3_DBTR14          0x07C
 #define RCAR_DBSC3_DBTR15          0x080
 #define RCAR_DBSC3_DBTR16          0x084
 #define RCAR_DBSC3_DBTR17          0x088
 #define RCAR_DBSC3_DBTR18          0x08C
 #define RCAR_DBSC3_DBTR19          0x090
 #define RCAR_DBSC3_DBBL            0x0B0
 #define RCAR_DBSC3_DBADJ0          0x0C0
 #define RCAR_DBSC3_DBADJ2          0x0C8
 #define RCAR_DBSC3_DBRFCNF0        0x0E0
 #define RCAR_DBSC3_DBRFCNF1        0x0E4
 #define RCAR_DBSC3_DBRFCNF2        0x0E8
 #define RCAR_DBSC3_DBCALCNF        0x0F4
 #define RCAR_DBSC3_DBCALTR         0x0F8
 #define RCAR_DBSC3_DBRNK0          0x100
 #define RCAR_DBSC3_DBPDNCNF        0x180
 #define RCAR_DBSC3_DBDFISTAT       0x240
 #define RCAR_DBSC3_DBDFICNT        0x244
 #define RCAR_DBSC3_DBPDLCK         0x280       // PHY unit lock register
 #define RCAR_DBSC3_DBPDRGA         0x290
 #define RCAR_DBSC3_DBPDRGD         0x2A0
 #define RCAR_DBSC3_DBBS0CNT1       0x304
 #define RCAR_DBSC3_DBWT0CNF0       0x380
 #define RCAR_DBSC3_DBWT0CNF4       0x390
 #define RCAR_DBSC3_DBSCHECNT0      0x500
 #define RCAR_DBSC3_DBRSTLCK        0x4000
 #define RCAR_DBSC3_DBRST           0x4008
 #define RCAR_DBSC3_DBPDCNT0		0x200
 #define RCAR_DBSC3_DBPDCNT1		0x204
 #define RCAR_DBSC3_DBPDCNT2		0x208
 #define RCAR_DBSC3_DBPDCNT3		0x20C



/*
 * Audio Clock Generator
 */
#define RCAR_ADG_BASE               0xEC5A0000

 #define RCAR_ADG_BRRA              0x00
 #define RCAR_ADG_BRRB              0x04
 #define RCAR_ADG_SSICKR            0x08
 #define RCAR_ADG_CKSEL0            0x0C
 #define RCAR_ADG_CKSEL1            0x10
 #define RCAR_ADG_CKSEL2            0x14
 #define RCAR_ADG_DIV_EN            0x30
 #define RCAR_ADG_SRCIN_TIMSEL0     0x34
 #define RCAR_ADG_SRCIN_TIMSEL1     0x38
 #define RCAR_ADG_SRCIN_TIMSEL2     0x3C
 #define RCAR_ADG_SRCIN_TIMSEL3     0x40
 #define RCAR_ADG_SRCIN_TIMSEL4     0x44
 #define RCAR_ADG_SRCOUT_TIMSEL0    0x48
 #define RCAR_ADG_SRCOUT_TIMSEL1    0x4C
 #define RCAR_ADG_SRCOUT_TIMSEL2    0x50
 #define RCAR_ADG_SRCOUT_TIMSEL3    0x54
 #define RCAR_ADG_SRCOUT_TIMSEL4    0x58
 #define RCAR_ADG_CMDOUT_TIMSEL     0x5C
    
/*
 * L2 Cache
 */
#define RCAR_L2CPL310_BASE          0xF0100000

/*
 * LBSC
 */
#define RCAR_LBSC_BASE              0xFEC00000

 #define RCAR_LBSC_CS0CTRL          0x200
 #define RCAR_LBSC_CS1CTRL          0x204
 #define RCAR_LBSC_ECS0CTRL         0x208
 #define RCAR_LBSC_ECS1CTRL         0x20C
 #define RCAR_LBSC_CSWCR0           0x230
 #define RCAR_LBSC_CSWCR1           0x234
 #define RCAR_LBSC_ECSWCR0          0x238
 #define RCAR_LBSC_ECSWCR1          0x23C
 #define RCAR_LBSC_CSPWCR0          0x280
 #define RCAR_LBSC_CSPWCR1          0x284
 #define RCAR_LBSC_ECSPWCR0         0x288
 #define RCAR_LBSC_ECSPWCR1         0x28C
 #define RCAR_LBSC_EXWTSYNC         0x2A0
 #define RCAR_LBSC_CS1GDST          0x2C0
 #define RCAR_LBSC_ECS0GDST         0x2C4
 #define RCAR_LBSC_ECS1GDST         0x2C8
 #define RCAR_LBSC_ATACSCTRL        0x380

/***************************
 * Interrupt ID 
 ************************* */
#define RCAR_INTCSYS_IRQ0           (  0 + 32)
#define RCAR_INTCSYS_IRQ1           (  1 + 32)
#define RCAR_INTCSYS_IRQ2           (  2 + 32)
#define RCAR_INTCSYS_IRQ3           (  3 + 32)
#define RCAR_INTCSYS_GPIO0          (  4 + 32)
#define RCAR_INTCSYS_GPIO1          (  5 + 32)
#define RCAR_INTCSYS_GPIO2          (  6 + 32)
#define RCAR_INTCSYS_GPIO3          (  7 + 32)
#define RCAR_INTCSYS_GPIO4          (  8 + 32)
#define RCAR_INTCSYS_GPIO5          (  9 + 32)
#define RCAR_INTCSYS_IRQ4           ( 12 + 32)
#define RCAR_INTCSYS_IRQ5           ( 13 + 32)
#define RCAR_INTCSYS_IRQ6           ( 14 + 32)
#define RCAR_INTCSYS_IRQ7           ( 15 + 32)
#define RCAR_INTCSYS_IRQ8           ( 16 + 32)
#define RCAR_INTCSYS_IRQ9           ( 17 + 32)
#define RCAR_INTCSYS_I2C4           ( 19 + 32)
#define RCAR_INTCSYS_HSCIF2         ( 21 + 32)
#define RCAR_INTCSYS_SCIF2          ( 22 + 32)
#define RCAR_INTCSYS_SCIF3          ( 23 + 32)
#define RCAR_INTCSYS_SCIF4          ( 24 + 32)
#define RCAR_INTCSYS_SCIF5          ( 25 + 32)
#define RCAR_INTCSYS_SCIF0          (152 + 32)
#define RCAR_INTCSYS_SCIF1          (153 + 32)
#define RCAR_INTCSYS_HSCIF0         (154 + 32)
#define RCAR_INTCSYS_HSCIF1         (155 + 32)
#define RCAR_INTCSYS_MSIOF0         (156 + 32)
#define RCAR_INTCSYS_MSIOF1         (157 + 32)
#define RCAR_INTCSYS_MSIOF2         (158 + 32)
#define RCAR_INTCSYS_MSIOF3         (159 + 32)
#define RCAR_INTCSYS_SDHI0          (165 + 32)
#define RCAR_INTCSYS_SDHI1          (166 + 32)
#define RCAR_INTCSYS_SDHI2          (167 + 32)
#define RCAR_INTCSYS_QSPI0          (184 + 32)
#define RCAR_INTCSYS_QSPI1          (239 + 32)
#define RCAR_INTCSYS_I2C2           (286 + 32)
#define RCAR_INTCSYS_I2C0           (287 + 32)
#define RCAR_INTCSYS_I2C1           (288 + 32)
#define RCAR_INTCSYS_I2C3           (290 + 32)

/*
 * DMA request ID
 */
#define RCAR_DREQ_HSCIF0_TXI        0x39
#define RCAR_DREQ_HSCIF0_RXI        0x3A
#define RCAR_DREQ_HSCIF1_TXI        0x4D
#define RCAR_DREQ_HSCIF1_RXI        0x4E
#define RCAR_DREQ_HSCIF2_TXI        0x3B
#define RCAR_DREQ_HSCIF2_RXI        0x3C
#define RCAR_DREQ_SCIF0_TXI         0x29
#define RCAR_DREQ_SCIF0_RXI         0x2A
#define RCAR_DREQ_SCIF1_TXI         0x2D
#define RCAR_DREQ_SCIF1_RXI         0x2E
#define RCAR_DREQ_SCIF2_TXI         0x2B
#define RCAR_DREQ_SCIF2_RXI         0x2C
#define RCAR_DREQ_SCIF3_TXI         0x2f
#define RCAR_DREQ_SCIF3_RXI         0x30
#define RCAR_DREQ_SCIF4_TXI         0xFB
#define RCAR_DREQ_SCIF4_RXI         0xFC
#define RCAR_DREQ_SCIF5_TXI         0xFD
#define RCAR_DREQ_SCIF5_RXI         0xFE 
#define RCAR_DREQ_MSIOF0_TXI        0x51
#define RCAR_DREQ_MSIOF0_RXI        0x52
#define RCAR_DREQ_MSIOF1_TXI        0x55
#define RCAR_DREQ_MSIOF1_RXI        0x56
#define RCAR_DREQ_MSIOF2_TXI        0x41
#define RCAR_DREQ_MSIOF2_RXI        0x42
#define RCAR_DREQ_QSPI0_TXI         0x17
#define RCAR_DREQ_QSPI0_RXI         0x18
#define RCAR_DREQ_QSPI1_TXI         0xD1
#define RCAR_DREQ_QSPI1_RXI         0xD2
#define RCAR_DREQ_SDHI0_TXI         0xCD
#define RCAR_DREQ_SDHI0_RXI         0xCE
#define RCAR_DREQ_SDHI2_TXI         0xD3
#define RCAR_DREQ_SDHI2_RXI         0xD4
#define RCAR_DREQ_AXISTATR_RXI      0xA6
#define RCAR_DREQ_AXISTATR0_RXI     0xAC
#define RCAR_DREQ_AXISTAT2_RXI      0xA8
#define RCAR_DREQ_AXISTAT3C_RXI     0xA4


#endif /* __ARM_RCAR_H_INCLUDED */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL$ $Rev$")
#endif
