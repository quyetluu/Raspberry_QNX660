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


/* TOCR */
#define	RCAR_TMU_TOCR_TCOE		_ONEBIT8L(0)

/* TSTR */
#define	RCAR_TMU_TSTR_STR0		_ONEBIT8L(0)
#define	RCAR_TMU_TSTR_STR1		_ONEBIT8L(1)
#define	RCAR_TMU_TSTR_STR2		_ONEBIT8L(2)

/* TCR */
#define	RCAR_TMU_TCR_UNF			_ONEBIT16L(8)
#define	RCAR_TMU_TCR_UNIE			_ONEBIT16L(5)
#define	RCAR_TMU_TCR_CKEG1		_ONEBIT16L(4)
#define	RCAR_TMU_TCR_CKEG0		_ONEBIT16L(3)
#define	RCAR_TMU_TCR_TPSC_M		_BITFIELD16L( 0, 0x7)
#define	RCAR_TMU_TCR_TPSC_4		_BITFIELD16L( 0, 0x0)
#define	RCAR_TMU_TCR_TPSC_16		_BITFIELD16L( 0, 0x1)
#define	RCAR_TMU_TCR_TPSC_64		_BITFIELD16L( 0, 0x2)
#define	RCAR_TMU_TCR_TPSC_256		_BITFIELD16L( 0, 0x3)
#define	RCAR_TMU_TCR_TPSC_1024	_BITFIELD16L( 0, 0x4)
#define	RCAR_TMU_TCR_TPSC_RTC		_BITFIELD16L( 0, 0x6)
#define	RCAR_TMU_TCR_TPSC_EXT		_BITFIELD16L( 0, 0x7)
/* below is for tmu ch2 only */
#define	RCAR_TMU_TCR_ICPF			_ONEBIT16L(9)
#define	RCAR_TMU_TCR_ICPE1		_ONEBIT16L(7)
#define	RCAR_TMU_TCR_ICPE0		_ONEBIT16L(6)

