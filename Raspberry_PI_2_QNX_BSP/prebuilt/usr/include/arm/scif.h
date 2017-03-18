/*
 * $QNXLicenseC: 
 * Copyright 2007, QNX Software Systems.  
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
 
#define _BITFIELD32L(__start_bit,__value)	((__value) << (__start_bit))
#define _BITFIELD16L(__start_bit,__value)	((__value) << (__start_bit))
#define _BITFIELD8L(__start_bit,__value)	((__value) << (__start_bit))

/* registers addresses */
#define	RCAR_SCIF_SCSMR_OFF		0x0
#define	RCAR_SCIF_SCBRR_OFF		0x4
#define	RCAR_SCIF_SCSCR_OFF		0x8
#define	RCAR_SCIF_SCFTDR_OFF		0xC
#define	RCAR_SCIF_SCFSR_OFF		0x10
#define	RCAR_SCIF_SCFRDR_OFF		0x14
#define	RCAR_SCIF_SCFCR_OFF		0x18
#define	RCAR_SCIF_SCFDR_OFF		0x1c
#define	RCAR_SCIF_SCSPTR_OFF		0x20
#define	RCAR_SCIF_SCLSR_OFF		0x24

#define	RCAR_SCIF_HSSRR_OFF		0x40				//Sampling rate register
#define	RCAR_SCIF_HSRER_OFF		0x44				//Serial error register
#define	RCAR_SCIF_HSRTGR_OFF		0x50				//RTS output active trigger count register
#define	RCAR_SCIF_HSRTRGR_OFF		0x54				//Receive FIFO data count trigger register
#define	RCAR_SCIF_HSTTRGR_OFF		0x58				//Transmit FIFO data count trigger register
/* SCSMR */
#define	RCAR_SCIF_SCSMR_CHR		(1<<6)
#define	RCAR_SCIF_SCSMR_PE		    (1<<5)
#define	RCAR_SCIF_SCSMR_OE		    (1<<4)
#define	RCAR_SCIF_SCSMR_STOP		(1<<3)
#define	RCAR_SCIF_SCSMR_CKS_M		_BITFIELD16L(0,3)
#define	RCAR_SCIF_SCSMR_CKS_0		_BITFIELD16L(0,0)
#define	RCAR_SCIF_SCSMR_CKS_4		_BITFIELD16L(0,1)
#define	RCAR_SCIF_SCSMR_CKS_16	    _BITFIELD16L(0,2)
#define	RCAR_SCIF_SCSMR_CKS_64	    _BITFIELD16L(0,3)

/* SCSCR */

#define	RCAR_SCIF_SCSCR_TEIE		(1<<11)
#define	RCAR_SCIF_SCSCR_TIE		(1<<7)
#define	RCAR_SCIF_SCSCR_RIE		(1<<6)
#define	RCAR_SCIF_SCSCR_TE		    (1<<5)
#define	RCAR_SCIF_SCSCR_RE		    (1<<4)
#define	RCAR_SCIF_SCSCR_REIE		(1<<3)
#define	RCAR_SCIF_SCSCR_CKE1		(1<<1)

/* SCFSR */
#define	RCAR_SCIF_SCFSR_PERF(x)	((x>>12)&0xf)
#define	RCAR_SCIF_SCFSR_FERF(x)	((x>>8)&0xf)
#define	RCAR_SCIF_SCFSR_ER		    (1<<7)
#define	RCAR_SCIF_SCFSR_TEND		(1<<6)
#define	RCAR_SCIF_SCFSR_TDFE		(1<<5)
#define	RCAR_SCIF_SCFSR_BRK		(1<<4)
#define	RCAR_SCIF_SCFSR_FER		(1<<3)
#define	RCAR_SCIF_SCFSR_PER		(1<<2)
#define	RCAR_SCIF_SCFSR_RDF		(1<<1)
#define	RCAR_SCIF_SCFSR_DR		    (1<<0)

/* SCFDR */
#define	RCAR_SCIF_SCFDR_TX(x)		((x>>8)&0x1f)
#define	RCAR_SCIF_SCFDR_RX(x)		(x&0x1f)

#define	RCAR_SCIF_HSCFDR_TX(x)	    ((x>>8)&0xff)
#define	RCAR_SCIF_HSCFDR_RX(x)	    (x&0xff)

/* SCSPTR */
#define	RCAR_SCIF_SCSPTR_RTSIO	    (1<<7)
#define	RCAR_SCIF_SCSPTR_RTSDT	    (1<<6)
#define	RCAR_SCIF_SCSPTR_CTSIO	    (1<<5)
#define	RCAR_SCIF_SCSPTR_CTSDT	    (1<<4)
#define	RCAR_SCIF_SCSPTR_SPB2IO	(1<<1)
#define	RCAR_SCIF_SCSPTR_SPB2DT	(1<<0)

/* SCLSR */
#define	RCAR_SCIF_SCLSR_ORER		(1<<0)

/* SCFCR */
#define	RCAR_SCIF_SCFCR_RTRG_M	    _BITFIELD16L(6,3)
#define	RCAR_SCIF_SCFCR_RTRG_1	    _BITFIELD16L(6,0)
#define	RCAR_SCIF_SCFCR_RTRG_4	    _BITFIELD16L(6,1)
#define	RCAR_SCIF_SCFCR_RTRG_8	    _BITFIELD16L(6,2)
#define	RCAR_SCIF_SCFCR_RTRG_E	    _BITFIELD16L(6,3)
#define	RCAR_SCIF_SCFCR_TTRG_E	    _BITFIELD16L(4,3)
#define RCAR_SCIF_SCFCR_TTRG_M     _BITFIELD16L(4,3)
#define RCAR_SCIF_SCFCR_TTRG_1     _BITFIELD16L(4,3)
#define RCAR_SCIF_SCFCR_TTRG_2     _BITFIELD16L(4,2)
#define RCAR_SCIF_SCFCR_TTRG_4     _BITFIELD16L(4,1)
#define RCAR_SCIF_SCFCR_TTRG_8     _BITFIELD16L(4,0)
#define	RCAR_SCIF_SCFCR_MCE		(1<<3)
#define	RCAR_SCIF_SCFCR_TFRST		(1<<2)
#define	RCAR_SCIF_SCFCR_RFRST		(1<<1)
#define	RCAR_SCIF_SCFCR_LOOP		(1<<0)

#define	RCAR_SCIF_FIFO_LEN		    16

/* Different RCAR_W2H base addresses */
#define RCAR_SCIF_BASE0		0xE6E60000
#define RCAR_SCIF_BASE1		0xE6E68000
#define RCAR_SCIF_BASE2		0xE6E58000

/* New R_CAR bits */
#define	RCAR_SCIF_SCFCR_RSTRG_15	_BITFIELD16L(8, 0)
#define	RCAR_SCIF_SCFCR_RSTRG_1	_BITFIELD16L(8, 1)
#define	RCAR_SCIF_SCFCR_RSTRG_4	_BITFIELD16L(8, 2)
#define	RCAR_SCIF_SCFCR_RSTRG_6	_BITFIELD16L(8, 3)
#define	RCAR_SCIF_SCFCR_RSTRG_8	_BITFIELD16L(8, 4)
#define	RCAR_SCIF_SCFCR_RSTRG_10	_BITFIELD16L(8, 5)
#define	RCAR_SCIF_SCFCR_RSTRG_12	_BITFIELD16L(8, 6)
#define	RCAR_SCIF_SCFCR_RSTRG_14	_BITFIELD16L(8, 7)