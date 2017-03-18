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


#define		CMT1				0xE6130000
#define		CMCLKE				0xE6131000
#define		CMSTR(i)			(CMT1+(i*0x100) +0x00)
#define		CMSTR_STR0			(1<<0)
#define		CMSTR_STR1			(1<<1)
#define		CMSTR_STR2			(1<<2)
#define		CMSTR_STR3			(1<<3)
#define		CMSTR_STR4			(1<<4)
#define		CMSTR_STR5			(1<<5)
#define		CMSTR_STR0_RS		(1<<8)

#define		CMCSR(i)			(CMT1+(i*0x100) +0x10)
#define		CMCSR_CMF			(1<<15)
#define		CMCSR_OVF			(1<<14)
#define		CMCSR_WRFLG			(1<<13)
#define		CMCSR_CH0STTF		(1<<12)
#define		CMCSR_CH0STPF		(1<<11)
#define		CMCSR_CH0SSIE		(1<<10)
#define		CMCSR_CMS			(1<<9)
#define		CMCSR_CMM			(1<<8)
#define		CMCSR_CMR_01		(1<<4)				//Enables a DMA transfer request
#define		CMCSR_CMR_10		(1<<5)				//Enables an internal interrupt request
#define		CMCSR_CMR_00		(~(3<<4))			//Disables a DMA transfer request or internal interrupt request

#define		CMCSR_CKS_AP_8		(~(7<<0))
#define		CMCSR_CKS_AP_32		(1<<0)
#define		CMCSR_CKS_AP_128	(1<<1)
#define		CMCSR_CKS_AP_1		(3<<0)
#define		CMCSR_CKS_RCLK_8	(1<<2)
#define		CMCSR_CKS_RCLK_32	(5)
#define		CMCSR_CKS_RCLK_128	(6)
#define		CMCSR_CKS_RCLK_1	(7)

#define		CMCSRH(i)			(CMT1+(i*0x100) +0x20)
#define		CMCSRH_CMSH			(1<<9)
#define		CMCSRH_CKH			(1<<0)

#define		CMCNT(i)			(CMT1+(i*0x100) +0x14)

#define		CMCNTH(i)			(CMT1+(i*0x100) +0x24)
#define		CMCOR(i)			(CMT1+(i*0x100) +0x18)
#define		CMCORH(i)			(CMT1+(i*0x100) +0x28)
#define		CMCSRM0				0xE6130040
#define		CMCNTM0				0xE6130044
#define		CMCSRM3				0xE6130340
#define		CMCNTM3				0xE6130344


