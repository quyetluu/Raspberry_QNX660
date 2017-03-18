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
 
// Module Description:  Header file for usb 2.0 module
#define RCAR_USB20_BASE0 0xEE080000 // base address of channel 0
#define RCAR_USB20_BASE1 0xEE0C0000 // base address of channel 1

/* Register offset */
#define OHCI_OFFSET	0x00
#define OHCI_SIZE	0x100
#define EHCI_OFFSET	0x100		/* offset: 0100H */
#define EHCI_SIZE	0x100
#define USB_AHB_OFFSET	0x200
#define USB_CORE_OFFSET	0x300

#define EHCI_USBCMD	(EHCI_OFFSET + 0x0020)

/* AHB bridge registers */
#define INT_ENABLE  0x00
#define WAKEON_INTEN	(1 << 4)
#define UCOM_INTEN		(1 << 3)
#define USBH_INTBEN		(1 << 2)
#define USBH_INTAEN		(1 << 1)
#define AHB_INTEN		(1 << 0)
#define FULL_INTEN		0x1f
 
//#define INT_ENABLE_INIT (USBH_INTBEN | USBH_INTAEN)
 #define INT_ENABLE_INIT FULL_INTEN

#define INT_STATUS    0x04

#define USBCTR    0x0C
#define USBCTR_DIRPD      (1 << 2)
#define USBCTR_PLL_RST    (1 << 1)

/* Core defined registers */
#define SPD_RSM_TIMSET	0x0C
#define OC_TIMSET	0x10

/* USBCTR */
#define DIRPD		(1 << 2)
#define PLL_RST		(1 << 1)

/* AHB_BUS_CTR */				/* hw default is .. */
#define PROT_TYPE_CACHEABLE	(1 << 15)	/* 0: non-cacheable trns */
#define PROT_TYPE_BUFFERABLE	(1 << 14)	/* 0: non-bufferable trns */
#define PROT_TYPE_PRIVILEGED	(1 << 13)	/* 0: user access */
#define PROT_TYPE_DATA		(1 << 12)	/* 0: opcode */
#define PROT_MODE		(1 << 8)
#define ALIGN_ADDRESS_1K	(0 << 4)	/* h/w default */
#define ALIGN_ADDRESS_64BYTE	(1 << 4)
#define ALIGN_ADDRESS_32BYTE	(2 << 4)
#define ALIGN_ADDRESS_16BYTE	(3 << 4)
#define MAX_BURST_LEN_INCR16	(0 << 0)	/* h/w default */
#define MAX_BURST_LEN_INCR8	(1 << 0)
#define MAX_BURST_LEN_INCR4	(2 << 0)
#define MAX_BURST_LEN_SINGLE	(3 << 0)

/* Init AHB master and slave functions of the host logic */
#define AHB_BUS_CTR_INIT 0

#define USBSEL_MASK	    0x00000030
#define USBSEL_EHCI_OHCI	0x00000010
#define USBSEL_HSUSB	    0x00000020

#define USBHS_UGCTRL_PLLRESET  (1 << 0)
#define OC_TIMSET_INIT         0x000209ab
#define SPD_RSM_TIMSET_INIT    0x014e029b