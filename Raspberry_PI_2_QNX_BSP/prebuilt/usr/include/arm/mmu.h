/*
 * $QNXLicenseC:
 * Copyright 2007, 2009, QNX Software Systems.
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
 * ARM MMU (coprocessor 15) Support
 */

#ifndef	__ARM_MMU_H_INCLUDED
#define	__ARM_MMU_H_INCLUDED

/*
 * MMU control register
 */
#define	ARM_MMU_CR_M	((unsigned)1 <<  0)	/* enable MMU                               1 */
#define	ARM_MMU_CR_A	((unsigned)1 <<  1)	/* enable alignment faults                  2 */
#define	ARM_MMU_CR_C	((unsigned)1 <<  2)	/* enable data/IDC cache                    4 */
#define	ARM_MMU_CR_W	((unsigned)1 <<  3)	/* enable write buffer                      8 */
#define	ARM_MMU_CR_P	((unsigned)1 <<  4)	/* 32-bit exception handling               10 */
#define	ARM_MMU_CR_D	((unsigned)1 <<  5)	/* 32-bit data address range               20 */
#define	ARM_MMU_CR_L	((unsigned)1 <<  6)	/* late aborts                             40 */
#define	ARM_MMU_CR_B	((unsigned)1 <<  7)	/* big endian                              80 */
#define	ARM_MMU_CR_S	((unsigned)1 <<  8)	/* system protection                      100 */
#define	ARM_MMU_CR_R	((unsigned)1 <<  9)	/* ROM protection                         200 */
#define	ARM_MMU_CR_F	((unsigned)1 << 10)	/* implementation defined                 400 */
#define	ARM_MMU_CR_Z	((unsigned)1 << 11)	/* implementation defined                 800 */
#define	ARM_MMU_CR_I	((unsigned)1 << 12)	/* enable instruction cache              1000 */
#define	ARM_MMU_CR_X	((unsigned)1 << 13)	/* exception vector adjust               2000 */
#define	ARM_MMU_CR_V	ARM_MMU_CR_X
#define	ARM_MMU_CR_RR	((unsigned)1 << 14)	/* round robin cache replacement         4000 */
#define	ARM_MMU_CR_L4	((unsigned)1 << 15)	/* load PC instr can set T bit           8000 */
#define	ARM_MMU_CR_DT	((unsigned)1 << 16)	/* data TCM enable                      10000 */
/* reserved				((unsigned)1 << 17)                                           20000 */
#define	ARM_MMU_CR_IT	((unsigned)1 << 18)	/* instruction TCM enable               40000 */
/* reserved				((unsigned)1 << 19)                                           80000 */
/* reserved				((unsigned)1 << 20)                                          100000 */
#define	ARM_MMU_CR_FI	((unsigned)1 << 21)	/* fast interrupt config enable        200000 */
#define	ARM_MMU_CR_U	((unsigned)1 << 22)	/* unaligned/mixed-endian enable       400000 */
#define	ARM_MMU_CR_XP	((unsigned)1 << 23)	/* enable ARMv6 page table descriptors 800000 */
#define	ARM_MMU_CR_VE	((unsigned)1 << 24)	/* vectored interrupt enable                  */
#define	ARM_MMU_CR_EE	((unsigned)1 << 25)	/* mixed-endian exception entry               */
#define	ARM_MMU_CR_L2	((unsigned)1 << 26)	/* L2 unified cache enable                    */
#define	ARM_MMU_CR_NMFI	((unsigned)1 << 27)	/* FIQs behave as NMFI                        */
#define	ARM_MMU_CR_TR	((unsigned)1 << 28)	/* use TEX remap registers                    */
#define	ARM_MMU_CR_FA	((unsigned)1 << 29)	/* force use of AP[0] as access bit           */
#define	ARM_MMU_CR_nF	((unsigned)1 << 30)	/* ARM920 only: not FastBus select            */
#define	ARM_MMU_CR_iA	((unsigned)1 << 31)	/* ARM920 only: async clock select            */


/*
 * Non-LPAE case; short descriptor table
 * L1 has 4k  32-bit entries;
 *     each can point to a single 1MB section (or a string of 16 for a supersection) or an L2 page table. (total 4G)
 *
 * L2 has 256 32-bit entries;
 *     each can point to a single 4k entry (or a string of 16 for a 64kb large page) (1M range per L2)
 *
 * L1/PTP size is  4k * 32 bits = 16 kb.  User and system mappings each use half this, or 8k.
 * L2/PTE size is 256 * 32 bits = 1 kb    Always handled in groups of four.
 */


#define	ARM_L1_SIZE		16384
#define	ARM_L2_SIZE		1024
#define	PGMASK			(__PAGESIZE-1)

/* Section */
#define	ARM_SCSIZE		(1024*1024)
#define	ARM_SCMASK		(ARM_SCSIZE-1)

/* Large page */
#define	ARM_LPSIZE		65536
#define	ARM_LPMASK		(ARM_LPSIZE-1)

/*
 * Page/Section access permissions.
 * NB: assumes the MMU control register has been set with S=1,R=0
 */
#define	ARM_PTE_RO		0			/* read-only  access */
#define	ARM_PTE_RW		1			/* read-write access */
#define	ARM_PTE_U		2			/* user mode  access */
#define	ARM_PTE_AP_MASK	3

#define	ARM_PTE_B		4			/* bufferable */
#define	ARM_PTE_C		8			/* machine-dependent (see below) */
#define	ARM_PTE_CB		12			/* cacheable and bufferable */

/*
 * L1 descriptors
 */
typedef unsigned	ptp_t;
#define	ARM_PTP_L2		0x11
#define	ARM_PTP_SC		0x12
#define	ARM_PTP_V6_L2	0x01		/* ARMv6 L1 descriptor */
#define	ARM_PTP_V6_SC	0x02		/* ARMv6 L1 descriptor */
#define	ARM_PTP_VALID	3

#define	ARM_PTP_P		(1 << 9)	/* ECC enabled */
#define	ARM_PTP_SUPER	(1 <<18)	/* supersection descriptor */

/*
 * L1 section cacheability
 */
#define	ARM_PTP_B		4			/* bufferable */
#define	ARM_PTP_C		8			/* machine-dependent (see below) */
#define	ARM_PTP_CB		12			/* cacheable and bufferable */
#define	ARM_PTP_WB		ARM_PTP_CB	/* write-back cacheable */
#define	ARM_PTP_WT		ARM_PTP_C	/* write-thru cacheable */


/*
 * ARMv5 TEX bits
 */
#define	ARM_PTP_V5_TEX(x)	(((x) & 0xf) << 12)
#define	ARM_PTP_V5_TEX_MASK	ARM_PTP_V5_TEX(0xf)
#define	ARM_PTP_XS_WA		(ARM_PTP_CB | ARM_PTP_V5_TEX(1))	/* Xscale write-alloc */

/*
 * ARMv6 L1 descriptor bits
 */
#define	ARM_PTP_V6_XN		(1 << 4)
#define	ARM_PTP_V6_AP0		(1 << 10)
#define	ARM_PTP_V6_AP1		(1 << 11)
#define	ARM_PTP_V6_APX		(1 << 15)
#define	ARM_PTP_V6_S		(1 << 16)
#define	ARM_PTP_V6_nG		(1 << 17)

#define	ARM_PTP_V6_TEX(x)	(((x) & 7) << 12)
#define	ARM_PTP_V6_TEX_MASK	ARM_PTP_V6_TEX(7)

/*
 * Section access permissions when S=1,R=0
 */
#define	ARM_PTP_AP_RO		(0)			/* RO section permission */
#define	ARM_PTP_AP_RW		(1 << 10)	/* RW section permission */
#define	ARM_PTP_AP_U		(1 << 11)	/* user access allowed   */

/*
 * ARMv6 section access permissions
 *
 * APX bit determines whether write access is allowed
 * AP1 bit determines whether user access is allowed
 *
 * The encodings below reflect the ARMv6 encoding in ARMARMrevF:
 *
 * APX AP1 AP0
 * --- --- ---
 *   1   0   1	priv RO / user NA
 *   0   0   1	priv RW / user NA
 *   1   1   0	priv RO / user RO
 *   0   1   1	priv RW / user RW
 */
#define	ARM_PTP_V6_AP_U		ARM_PTP_V6_AP1
#define	ARM_PTP_V6_AP_URO	(ARM_PTP_V6_AP1|ARM_PTP_V6_APX)
#define	ARM_PTP_V6_AP_URW	(ARM_PTP_V6_AP1|ARM_PTP_V6_AP0)
#define	ARM_PTP_V6_AP_KRO	(ARM_PTP_V6_AP0|ARM_PTP_V6_APX)
#define	ARM_PTP_V6_AP_KRW	(ARM_PTP_V6_AP0)

/*
 * L2 descriptors
 */
typedef unsigned	pte_t;
#define	ARM_PTE_LP		1
#define	ARM_PTE_SP		2
#define	ARM_PTE_XSP		3			/* ARMv5 extended small page */
#define	ARM_PTE_VALID	3

#define	ARM_PTE_PROT(f)	(((f) << 4) | ((f) << 6) | ((f) << 8) | ((f) << 10))
#define	ARM_XSP_PROT(f)	((f) << 4)

#define	ARM_PTE_WT		ARM_PTE_C			/* write-thru (non-SA11x0) */
#define	ARM_PTE_WB		ARM_PTE_CB			/* write-back (all cores)  */
#define	ARM_PTE_SA_MC	ARM_PTE_C			/* mini-cache (SA11x0)     */

#define	ARM_PTE_XS_X	0x40						/* Xscale X-bit */
#define	ARM_PTE_XS_MC	(ARM_PTE_XS_X | ARM_PTE_C)	/* mini-cache (Xscale) */
#define	ARM_PTE_XS_WA	(ARM_PTE_XS_X | ARM_PTE_WB)	/* write-allocate */

#define	ARM_PTE_V5_LP_TEX_MASK	0xf000
#define	ARM_PTE_V5_SP_TEX_MASK	0x3c0

#define	ARM_PTE_V6_AP0		(1 << 4)
#define	ARM_PTE_V6_AP1		(1 << 5)
#define	ARM_PTE_V6_APX		(1 << 9)
#define	ARM_PTE_V6_S		(1 << 10)
#define	ARM_PTE_V6_nG		(1 << 11)

/*
 * APX bit determines whether write access is allowed
 * AP1 bit determines whether user access is allowed
 *
 * The encodings below reflect the ARMv6 encoding in ARMARMrevF:
 *
 * APX AP1 AP0
 * --- --- ---
 *   1   0   1	priv RO / user NA
 *   0   0   1	priv RW / user NA
 *   1   1   0	priv RO / user RO
 *   0   1   1	priv RW / user RW
 */
#define	ARM_PTE_V6_AP_U		ARM_PTE_V6_AP1
#define	ARM_PTE_V6_AP_URO	(ARM_PTE_V6_AP1|ARM_PTE_V6_APX)
#define	ARM_PTE_V6_AP_URW	(ARM_PTE_V6_AP1|ARM_PTE_V6_AP0)
#define	ARM_PTE_V6_AP_KRO	(ARM_PTE_V6_AP0|ARM_PTE_V6_APX)
#define	ARM_PTE_V6_AP_KRW	(ARM_PTE_V6_AP0)

#define	ARM_PTE_V6_SP_XN		(1 << 0)	/* XN for small pages only */
#define	ARM_PTE_V6_SP_TEX(x)	(((x) & 7) << 6)
#define	ARM_PTE_V6_SP_TEX_MASK	ARM_PTE_V6_SP_TEX(7)

#define	ARM_PTE_V6_LP_XN		(1 << 15)
#define	ARM_PTE_V6_LP_TEX(x)	(((x) & 7) << 12)
#define	ARM_PTE_V6_LP_TEX_MASK	ARM_PTE_V6_LP_TEX(7)

#define ARM_PTE_V6_WA		(ARM_PTE_V6_SP_TEX(1) | ARM_PTE_CB)

/*
 * ARMv6 TTBR0/TTBR1 attributes
 */
#define ARM_TTBR_ATTR_MASK	0x7f
#define	ARM_TTBR_C			(1 << 0)			/* inner cacheable */
#define	ARM_TTBR_S			(1 << 1)			/* shared memory */
#define	ARM_TTBR_P			(1 << 2)			/* ECC enabled */
#define	ARM_TTBR_RGN(x)		(((x) & 3) << 3)	/* outer cacheable type */
#define ARM_TTBR_IRGN(x)	((((x) & 1) << 6) | (((x) & 2) >> 1))
#define ARM_TTBR_NOS		(1 << 5)

#define ARM_TTBR_RGN_NC		ARM_TTBR_RGN(0)
#define ARM_TTBR_RGN_WA		ARM_TTBR_RGN(1)
#define ARM_TTBR_RGN_WT		ARM_TTBR_RGN(2)
#define ARM_TTBR_RGN_WB		ARM_TTBR_RGN(3)

#define ARM_TTBR_IRGN_NC	ARM_TTBR_IRGN(0)
#define ARM_TTBR_IRGN_WA	ARM_TTBR_IRGN(1)
#define ARM_TTBR_IRGN_WT	ARM_TTBR_IRGN(2)
#define ARM_TTBR_IRGN_WB	ARM_TTBR_IRGN(3)

/*
 * Old definitions for backwards compatibility
 */
#define	ARM_MMU_TTBR_C		(1 << 0)			/* inner cacheable */
#define	ARM_MMU_TTBR_S		(1 << 1)			/* shared memory */
#define	ARM_MMU_TTBR_P		(1 << 2)			/* ECC enabled */
#define	ARM_MMU_TTBR_RGN(x)	(((x) & 3) << 3)	/* outer cacheable type */

/*
 * Address translation support.
 *
 * The virtual address space contains the following reserved regions:
 *	ff800000-ffbfffff	maps page tables that map 00000000-ffffffff
 *	ffff0000-ffff0fff	trap vector table for processors with vector adjust
 *
 * The startup normally arranges the following mappings:
 *	e0000000-efffffff	maps up to 256MB of system RAM
 *	fc400000-fdffffff	maps L1 page table and mappings for callouts
 *	fe000000-ff7fffff	maps boot programs (kdebug/procnto)
 *
 * For ARMv6 processors, there are some additions:
 *
 *	fc000000-fc1fffff	maps page tables for user address space on ARMv6
 *	fc200000-fc3fffff	reserved (mapped by user "page directory" page
 *	ff000000-ff7fffff	used for message passing
 *	ffc00000-ffc3ffff	used for cache colour operations
 *	ffff1000-ffff1fff	cpupage on SMP systems
 *	ffff2000-ffff3fff	8K L1 table for ARMv6 user address space
 *	ffff4000-ffff7fff	8K used to map L1 tables for message passing
 *	ffff8000-ffff9fff	8K used to map L1 tables for inactive address spaces
 *	ffffa000-ffffafff	4K used to map L2 tables for inactive address spaces
 *	ffffe000-ffffefff	scratch page used for zeroing page tables
 *	fffff000-ffffffff	scratch page used for planting breakpoints
 */

#define	ARM_1TO1_BASE		0xe0000000
#define	ARM_1TO1_SIZE		0x10000000

/* Available system virtual address range, used by cpu_sysvaddr_find() */
#define	ARM_SYSVADDR_BASE	0xc0000000
#define	ARM_SYSVADDR_END	0xdfffffff

#define	ARM_STARTUP_BASE	0xfc400000
#define	ARM_BOOTPGM_BASE	0xfe000000

#define ARM_TRAP_VECTORS    0xffff0000

#define	ARM_PTE_MAP			1022
#define	ARM_PTE_BASE		(ARM_PTE_MAP << 22)
#define	ARM_PTP_BASE		(ARM_PTE_BASE | (ARM_PTE_MAP << 12))

#define	VTOPDIR(v)	(ptp_t *)(ARM_PTP_BASE | (((unsigned)(v) >> 20) & ~3))
#define	VTOPTEP(v)	(pte_t *)(ARM_PTE_BASE | (((unsigned)(v) >> 10) & ~3))
#define	VTOPTP(v)	(pte_t *)(ARM_PTE_BASE | (((unsigned)(v) >> 10) & 0x3ff000))
#define	VTOP(v)		((*(VTOPTEP(v)) & ~PG_MASK) | ((unsigned)(v) & PG_MASK))

/*
 * ARMv6-specific macros
 */
#define	ARM_V6_XFER_BASE	0xff000000
#define	ARM_V6_XFER_SIZE	0x00800000
#define	ARM_SMP_CPUPAGE		0xffff1000
#define	ARM_V6_USER_L1		0xffff2000
#define	ARM_V6_XFER_L1		0xffff4000
#define	ARM_V6_INACTIVE_L1	0xffff8000
#define	ARM_V6_INACTIVE_L2	0xffffa000
#define	ARM_V6_SCRATCH_PTBL	0xffffe000
#define	ARM_V6_SCRATCH_BKPT	0xfffff000
#define	ARM_V6_COLOUR_BASE	0xffc00000

/*
 * Macros to manipulate system mappings (80000000-ffffffff)
 */
#define	ARM_KPTE_BASE	ARM_PTE_BASE
#define	ARM_KPTP_BASE	ARM_PTP_BASE
#define	KTOPDIR(v)		VTOPDIR(v)
#define	KTOPTEP(v)		VTOPTEP(v)
#define	KTOPTP(v)		VTOPTP(v)
#define	KTOP(v)			VTOP(v)

/*
 * Macros to manipulate user mappings (00000000-7fffffff)
 */
#define	ARM_UPTE_MAP	1008
#define	ARM_UPTE_BASE	(ARM_UPTE_MAP << 22)
#define	ARM_UPTP_BASE	(ARM_KPTE_BASE | (ARM_UPTE_MAP << 12))
#define	UTOPDIR(v)		(ptp_t *)(ARM_UPTP_BASE | (((unsigned)(v) >> 20) & ~3))
#define	UTOPTEP(v)		(pte_t *)(ARM_UPTE_BASE | (((unsigned)(v) >> 10) & ~3))
#define	UTOPTP(v)		(pte_t *)(ARM_UPTE_BASE | (((unsigned)(v) >> 10) & 0x3ff000))
#define	UTOP(v)			((*(UTOPTEP(v)) & ~PG_MASK) | ((unsigned)(v) & PG_MASK))



/*
 * LPAE
 *
 * LPAE case; long descriptor table
 * For 32 bit VAs, we need only stage 1 translations.  (stage 2 supports virtualization, with VADDR > 32 bits)
 *
 * L1 has   4 64-bit entries; each entry can point to a single 1GB block or to an L2 table. (4G total)
 * L2 has 512 64-bit entries; each entry can point to a single 2MB block or to an L3 table. (512 * 2MB = 1GB per L2)
 * L3 has 512 64-bit entries; each entry points to a single 4Kb page. (512 * 4kb = 2MB per L3) 
 *
 * L1 is 4   * 8 bytes = 32 bytes 
 * L2 is 512 * 8 bytes = 4kb in size
 * L3 is 512 * 8 bytes = 4kb in size
 * 
 * Under LPAE, we have 3GB of user space and 1GB of kernel space
 *
 * So a user process L2 table consists of three of the above L2 entries.
 * The architecture doesn't require these to be contiguous but that's the way we do them.
 * The kernel L2 is a single L2 page of entries.
*/

/*
 * Virtual ranges used by the kernel to access user L3 page tables
 */
#define ARM_LPAE_USER_L3    ((uintptr_t)0xfc000000)  /* size 0x00600000 user L3 */
#define ARM_LPAE_INACT_L3   ((uintptr_t)0xfc600000)  /* size 0x00600000 inactive L3*/
#define ARM_LPAE_KERN_L3    ((uintptr_t)0xfcc00000)  /* size 0x00200000 kernel L3 */

/* Startup begins assigning virtual addresses starting at this address */
#define ARM_LPAE_STARTUP_BASE   ((uintptr_t)0xfce00000)

/* By default, kernel is linked to start at ARM_BOOTPGM_BASE; 0xfe000000 */
#define ARM_LPAE_BOOTPGM_BASE   ((uintptr_t)ARM_BOOTPGM_BASE)

/*
 * Virtual address ranges used for msgpass
 */
#define ARM_LPAE_XFER_BASE  ((uintptr_t)0xff000000)  /* same as ARM_V6_XFER_BASE */
#define ARM_LPAE_XFER_SIZE  ((uintptr_t)0x00800000)  /* same as ARM_V6_XFER_SIZE */


/*
  Mappings from 0xffff0000:
  
  0000 - exception vector table
  1000 - cpupage
  2000 - user l2
  3000 - user l2
  4000 - user l2
  5000 - xfer l2
  6000 - xfer l2
  7000 - xfer l2
  8000 - inact l2
  9000 - inact l2
  a000 - inact l2
  b000 - kernel l2
  c000 - free
  d000 - free
  e000 - temp mapping for initing memory
  f000 - temp mapping for installing breakpoints
*/

 /* 
 * Virtual address ranges used by the kernel to access L2 page tables
 */
#define ARM_LPAE_USER_L2    ((uintptr_t)0xffff2000)  /* 2000/3000/4000 size 0x3000 User L2 */
#define ARM_LPAE_XFER_L2    ((uintptr_t)0xffff5000)  /* 5000/6000/7000 size 0x3000 Xfer L2 */
#define ARM_LPAE_INACT_L2   ((uintptr_t)0xffff8000)  /* 8000/9000/a000 size 0x3000 Inactive L2*/
#define ARM_LPAE_KERN_L2    ((uintptr_t)0xffffb000)  /* b000 size 0x1000 kernel L2 */
#define ARM_LPAE_TEMP_PTBL  ((uintptr_t)0xffffe000)  /* Used for zeroing memory */
#define ARM_LPAE_TEMP_BKPT  ((uintptr_t)0xfffff000)  /* Used for installing breakpoint (see ARM_V6_SCRATCH_BKPT) */                                         

/*
 * lpae_pd_t is a page descriptor.
 *
 * The ARM documentation distinguishes between table, block, and page descriptors.
 * Table descriptors point to other tables.      (L1/L2)
 * Block descriptors describe 2MB memory blocks. (L2)
 * Page descriptors describe 4Kb memory pages.   (L3)
 *
 * These are mostly the same; there are differences in what fields are valid.
 * This code uses the lpae_pd_t type for all of these uses.
 * 
 */
  

typedef unsigned long long lpae_pd_t;

#define ARM_LPAE_L1_ENTRIES 4
#define ARM_LPAE_L2_ENTRIES 512
#define ARM_LPAE_L3_ENTRIES 512

#define ARM_LPAE_L1_SIZE (ARM_LPAE_L1_ENTRIES * sizeof(lpae_pd_t))   // 32 bytes
#define ARM_LPAE_L2_SIZE (ARM_LPAE_L2_ENTRIES * sizeof(lpae_pd_t))   // 4k bytes
#define ARM_LPAE_L3_SIZE (ARM_LPAE_L3_ENTRIES * sizeof(lpae_pd_t))   // 4k bytes


/*
 * 3:1 split between user and kernel memory
 */

#define ARM_LPAE_KERN_VADDR_BASE ((uintptr_t)0xc0000000)
#define ARM_LPAE_USER_SPACE(va)  ((uintptr_t)(va) < ARM_LPAE_KERN_VADDR_BASE)

#define ARM_LPAE_USER_L2_PAGES (3)
#define ARM_LPAE_KERN_L2_PAGES (1)
#define ARM_LPAE_USER_L2_SIZE (ARM_LPAE_L2_SIZE * ARM_LPAE_USER_L2_PAGES)         // size in bytes
#define ARM_LPAE_KERN_L2_SIZE (ARM_LPAE_L2_SIZE * ARM_LPAE_KERN_L2_PAGES)         // size in bytes
#define ARM_LPAE_FULL_L2_SIZE (ARM_LPAE_USER_L2_SIZE + ARM_LPAE_SYS_L2_SIZE)      // size in bytes


/* We can have 2M and 1GB blocks with LPAE.  We will just be using 2M blocks */
#define	ARM_LPAE_BSIZE		(2*1024*1024)
#define	ARM_LPAE_BMASK		(ARM_LPAE_BSIZE-1)


/* Bits to shift to turn a vaddr into an L1/L2/L3 table index */
#define ARM_LPAE_L1_IDX_SHIFT 30
#define ARM_LPAE_L2_IDX_SHIFT 21   /* Assumes full 4-page L2 - mask upper bit for 2-page kern/user l2 */
#define ARM_LPAE_L3_IDX_SHIFT 12

#define ARM_LPAE_L1_IDX_MASK (ARM_LPAE_L1_ENTRIES-1)
#define ARM_LPAE_L2_IDX_MASK (ARM_LPAE_L2_ENTRIES-1)
#define ARM_LPAE_L3_IDX_MASK (ARM_LPAE_L3_ENTRIES-1)

#define ARM_LPAE_L2_1G_VMASK ((uintptr_t)0x3fe00000)  /* bits 29:21, shift 21 to select range 0-511  */
#define ARM_LPAE_L2_2G_VMASK ((uintptr_t)0x7fe00000)  /* bits 30:21, shift 21 to select range 0-1023 */
#define ARM_LPAE_L2_3G_VMASK ((uintptr_t)0xffe00000)  /* bits 31:21, shift 21 to select range 0-1535 */
/*      For the 3G range, we assume this is user space and the address range starts at zero. */
#define ARM_LPAE_L2_4G_VMASK ((uintptr_t)0xffe00000)  /* bits 31:21, shift 21 to select range 0-2047 */
#define ARM_LPAE_L3_VMASK    ((uintptr_t)0x001ff000)  /* bits 20:12, shift 12 to select range 0-511  */
 
/* Get the right index within an single, four-entry L1 table. Nice and easy.  */
#define ARM_LPAE_VADDR_TO_L1_IDX(vaddr)   (((uintptr_t)vaddr & (uintptr_t)0xc0000000) >> 30)


/*
   L2s are a bit trickier; under LPAE each L1 entry points to a fixed-size L2 table/block covering 1G
   They are independant as far as the L1 is concerned, but we handle them as a contiguous block
   of 2 tables for a 2G range.

   For completeness, these macros are defined for indexing into a 1, 2, 3, or 4 table set of L2s.
*/
#define ARM_LPAE_VADDR_TO_4GL2_IDX(vaddr) (((uintptr_t)vaddr & ARM_LPAE_L2_4G_VMASK) >> 21)  /* idx 0-2047 */
#define ARM_LPAE_VADDR_TO_3GL2_IDX(vaddr) (((uintptr_t)vaddr & ARM_LPAE_L2_3G_VMASK) >> 21)  /* idx 0-1535 */
#define ARM_LPAE_VADDR_TO_2GL2_IDX(vaddr) (((uintptr_t)vaddr & ARM_LPAE_L2_2G_VMASK) >> 21)  /* idx 0-1023 */
#define ARM_LPAE_VADDR_TO_1GL2_IDX(vaddr) (((uintptr_t)vaddr & ARM_LPAE_L2_1G_VMASK) >> 21)  /* idx 0-511  */


/*
  In procnto, we map whole user L2 tables as a set of kernel L2 entries covering 6M.
  This gives us a window into the L3 tables themselves in order manipulate the page tables.
  This means we see the overall L3 as a table of:
    256k entries for a 1G block
    512k entries for a 2G range
    768k entries for a 3G range
  These macros let us index from the base of the range to access the page table for a given vaddr.
*/
#define ARM_LPAE_VADDR_TO_L3_IDX(vaddr)   (((uintptr_t)vaddr & 0x001ff000) >> 12)  /* within a single L3 page; idx 0-511 */
#define ARM_LPAE_VADDR_TO_1GL3_IDX(vaddr) (((uintptr_t)vaddr & 0x3ffff000) >> 12)  /* bits 29:12, shift 12 for idx 0-256k */
#define ARM_LPAE_VADDR_TO_2GL3_IDX(vaddr) (((uintptr_t)vaddr & 0x7ffff000) >> 12)  /* bits 30:21, shift 12 for idx 0-512k */
#define ARM_LPAE_VADDR_TO_3GL3_IDX(vaddr) (((uintptr_t)vaddr & 0xfffff000) >> 12)  /* bits 31:21, shift 12 for idx 0-768k */
#define ARM_LPAE_VADDR_TO_4GL3_IDX(vaddr) (((uintptr_t)vaddr & 0xfffff000) >> 12)  /* bits 31:21, shift 12 for idx 0-1M */
/* For 3GL3 version, we have to use the whole address but it's only valid for if address <3G boundary */


/* Bits to shift to turn a vaddr into an index * size of descriptor entry  (don't forget to mask the lower 3 bits) */
#define ARM_LPAE_L2_ADDR_SHIFT 18
#define ARM_LPAE_L3_ADDR_SHIFT 9

/* To get the asid where it belongs  */
#define ARM_LPAE_TTBR_ASID_SHIFT 48

/* To extract the asid */
#define ARM_LPAE_TTBR_ASID_MASK  (0x00ff000000000000ULL)
#define ARM_LPAE_TTBR_ADDR_MASK  (0x000000ffffffffffULL)

/*
  For LPAE table descriptors, 40-bit physical addr (page aligned) is 28 bits from 39:12
  Use this mask to retrieve the address part of a L1, L2, or L3 descriptor
*/
#define ARM_LPAE_DESC_ADDR_MASK  (0x000000fffffff000ULL)
#define ARM_LPAE_DESC_ATTR_MASK  (0xffffff0000000fffULL)

#define ARM_LPAE_4G_BOUNDARY     (0x0000000100000000ULL)


/*
 * Some macros to return various addresses used for page table manipulation
 * These are also used by kdumper, so they're put here to be shared.
 * The MMU is turned on - these all return virtual addresses
 */

#define	ARM_LPAE_L1(cpu)	    (lpae_l1_vaddr + (cpu*ARM_LPAE_L1_ENTRIES))

// Returns a pointer to the lpae_pd_t that covers vaddr 'v' for the kernel on this cpu
// Vaddrs ARM_LPAE_KERN_L2/ARM_LPAE_KERN_L3 are mapped per-cpu
#define ARM_LPAE_KERN_VTOL2(v)  ((lpae_pd_t*)ARM_LPAE_KERN_L2 + ARM_LPAE_VADDR_TO_1GL2_IDX(v))
#define ARM_LPAE_KERN_VTOL3(v)  ((lpae_pd_t*)ARM_LPAE_KERN_L3 + ARM_LPAE_VADDR_TO_1GL3_IDX(v))

// Returns a pointer to the lpae_pd_t that covers vaddr 'v' for the active user
// valid for the current CPU
#define ARM_LPAE_USER_VTOL2(v)  ((lpae_pd_t*)ARM_LPAE_USER_L2 + ARM_LPAE_VADDR_TO_3GL2_IDX(v))
#define ARM_LPAE_USER_VTOL3(v)  ((lpae_pd_t*)ARM_LPAE_USER_L3 + ARM_LPAE_VADDR_TO_3GL3_IDX(v))

// Returns a pointer to the lpae_pd_t that covers vaddr 'v' for a temporarily mapped inactive user
// valid for the current CPU
#define ARM_LPAE_INACT_VTOL2(v)  ((lpae_pd_t*)ARM_LPAE_INACT_L2 + ARM_LPAE_VADDR_TO_3GL2_IDX(v))
#define ARM_LPAE_INACT_VTOL3(v)  ((lpae_pd_t*)ARM_LPAE_INACT_L3 + ARM_LPAE_VADDR_TO_3GL3_IDX(v))



/*
  LPAE Descriptor bits
*/


/*
 * NSTable, APTable, XNTable, PXNTable are  
 * only valid for L1/L2 table descriptor (not a 1GB/2MB block)
 */
#define ARM_LPAE_DESC_NS_TBL      (((_Uint64t)1)<<63)        /* If 1, next lookup is from non-secure address space */

/*
  APTable - can override access permissions for subsequent lookups.
   00 = No effect
   01 = No user access permitted
   10 = No write access from any privilege level
   11 = No user access, read-only privileged access
*/
#define ARM_LPAE_DESC_AP_TBL_PRIV    (                    ((_Uint64t)1)<<61) 
#define ARM_LPAE_DESC_AP_TBL_RO      (((_Uint64t)1)<<62                    ) 
#define ARM_LPAE_DESC_AP_TBL_PRIV_RO (((_Uint64t)1)<<62 | ((_Uint64t)1)<<61) 
#define ARM_LPAE_DESC_AP_TBL_MASK    (((_Uint64t)1)<<62 | ((_Uint64t)1)<<61) 

#define ARM_LPAE_DESC_XN_TBL         (((_Uint64t)1)<<60)   /* XNTable - Use XN of 1 for all subsequent lookups */
#define ARM_LPAE_DESC_PXN_TBL        (((_Uint64t)1)<<59)   /* PXNTable - Use PXN of 1 for all subsequent lookups */


/* Upper descriptor block */
#define ARM_LPAE_DESC_SW_58  (((_Uint64t)1) << 58)  /* reserved for software use */
#define ARM_LPAE_DESC_SW_57  (((_Uint64t)1) << 57)  /* reserved for software use */
#define ARM_LPAE_DESC_SW_56  (((_Uint64t)1) << 56)  /* reserved for software use */
#define ARM_LPAE_DESC_SW_55  (((_Uint64t)1) << 55)  /* reserved for software use */

#define ARM_LPAE_DESC_XN     (((_Uint64t)1) << 54)  /* execute never */
#define ARM_LPAE_DESC_PXN    (((_Uint64t)1) << 53)  /* privileged execute never */
#define ARM_LPAE_DESC_CONTIG (((_Uint64t)1) << 52)  /* Contiguous hint */
#define ARM_LPAE_UDB_MASK    (ARM_LPAE_DESC_XN|ARM_LPAE_DESC_PXN)  /* Upper descriptor bits mask */


/* Lower descriptor block */
#define ARM_LPAE_DESC_NG     ((_Uint64t)1 << 11)                 /* 0x800  non-global */
#define ARM_LPAE_DESC_AF     ((_Uint64t)1 << 10)                 /* 0x400  access flag; faults on access if zero */

/* Bits 9&8 define SH[1:0] ; Shareability */
#define ARM_LPAE_DESC_SH_MASK            ((_Uint64t)(1<<9 | 1<<8)) /* 0x300 */
#define ARM_LPAE_DESC_SH_INNER_SHAREABLE ((_Uint64t)(1<<9 | 1<<8)) /* 0x300 */
#define ARM_LPAE_DESC_SH_OUTER_SHAREABLE ((_Uint64t)(1<<9)       ) /* 0x200 */
#define ARM_LPAE_DESC_SH_NON_SHAREABLE   ((_Uint64t)0)

/* Bits 7&6 define AP[2:1] ; Access Permissions
   AP2 ; 0 = r/w, 1= r/o.   AP1 ; 0 = priv-only, 1=all 
   00 = priv r/w, no access to users
   01 = all  r/w,
   10 = priv r/o, no access to users
   11 = all  r/o

   Note: there is no way to describe PRIV-RW/USER-RO, as formerly used for syspage mappings
   Instead, we create a separate mapping for user and system use
*/
#define ARM_LPAE_DESC_AP_MASK       ((_Uint64t)(1<<7 | 1<<6))     /* 0x0c0 */
#define ARM_LPAE_DESC_AP_ALL        ((_Uint64t)(       1<<6))     /* 0x040 all have access if this bit set, otherwise priv-only */
#define ARM_LPAE_DESC_AP_RO         ((_Uint64t)(1<<7       ))     /* 0x080 read-only if this bit set, otherwise r/w             */

#define ARM_LPAE_DESC_AP_PRIV_RW    ((_Uint64t)0)
#define ARM_LPAE_DESC_AP_ALL_RO     ((_Uint64t)(1<<7 | 1<<6))     /* 0x0c0 */
#define ARM_LPAE_DESC_AP_PRIV_RO    ((_Uint64t)(1<<7       ))     /* 0x080 */
#define ARM_LPAE_DESC_AP_ALL_RW     ((_Uint64t)(       1<<6))     /* 0x040 */

#define ARM_LPAE_PTE_NS             ((_Uint64t)(1 << 5))          /* 0x020 1==Not_Secure. Ignored from non-secure state */

/*
  Bits 4,3,2 define AttrIndex[2:0]    selects MAIR0/1 entry Attr0-7
  Attr0 = inner/outer wb-cachable, read+write allocate
          (v6 appears to have been read allocate, but read+write should be fastest)
  Attr1 = non-cachable
  Attr2 = device
  Attr3 = strongly ordered
  Attr4 = write-through cacheable, read+write allocate 
  Attr5 = write-back cacheable, no read+write allocate 
  Attr6 = write-through cacheable, no read+write allocate 
  Attr7 is unused
  
  This way, setting the bits to 0 == Attr0 == 'normal' memory.
*/
#define ARM_LPAE_DESC_ATTRINDX_MASK ((_Uint64t)(1<<4 | 1<<3 | 1<<2))  /* Mask   0x01c */
#define ARM_LPAE_DESC_ATTR_NORMAL   ((_Uint64t)(              0   ))  /* Attr0  0x000 */
#define ARM_LPAE_DESC_ATTR_NOCACHE  ((_Uint64t)(              1<<2))  /* Attr1  0x004 */
#define ARM_LPAE_DESC_ATTR_DEVICE   ((_Uint64t)(       1<<3       ))  /* Attr2  0x008 */
#define ARM_LPAE_DESC_ATTR_STORDER  ((_Uint64t)(       1<<3 | 1<<2))  /* Attr3  0x00c */
#define ARM_LPAE_DESC_ATTR_WT       ((_Uint64t)(1<<4 |            ))  /* Attr4  0x010 */
#define ARM_LPAE_DESC_ATTR_WB_NORW  ((_Uint64t)(1<<4 |        1<<2))  /* Attr5  0x014 */
#define ARM_LPAE_DESC_ATTR_WT_NORW  ((_Uint64t)(1<<4 | 1<<3       ))  /* Attr6  0x018 */
#define ARM_LPAE_DESC_ATTR_7        ((_Uint64t)(1<<4 | 1<<3 | 1<<2))  /* Attr7  0x01c unused */

#define ARM_LPAE_DESC_VT_MASK       ((_Uint64t)3)               /* 0x003 Valid and Table bits mask bits*/
#define ARM_LPAE_DESC_TABLE         ((_Uint64t)2)               /* 0x002  descriptor contains table (otherwise block) */
#define ARM_LPAE_DESC_VALID         ((_Uint64t)1)               /* 0x001  descriptor is valid */

#define ARM_LPAE_L3_DESC_BAD        ((_Uint64t)1)               /* L3 with table bit not set is reserved & invalid (though okay for L2...) */

/*
 * --------------------------------------------------------------------------
 * Cache/TLB manipulation
 * --------------------------------------------------------------------------
 */

/*
 * Read MMU ID register
 */
static __inline__ unsigned
arm_mmu_cpuid(void)
{
	unsigned	val;
	__asm__ __volatile__("mrc	p15, 0, %0, c0, c0, 0" : "=r" (val));
	return val;
}

/*
 * Read MMU cache type register
 */
static __inline__ unsigned
arm_mmu_cache_type(void)
{
	unsigned	val;
	__asm__ __volatile__("mrc	p15, 0, %0, c0, c0, 1" : "=r" (val));
	return val;
}

/*
 * Read the MMU control register
 */
static __inline__ unsigned
arm_mmu_getcr()
{
	unsigned	val;
	__asm__ __volatile__("mrc	p15, 0, %0, c1, c0, 0" : "=r" (val));
	return val;
}

/*
 * Flush data TLBs
 */
static __inline__ void
arm_v4_dtlb_flush(void)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c6, 0" : : "r" (0));
}

/*
 * Flush the instruction and data TLBs
 */
static __inline__ void
arm_v4_idtlb_flush(void)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c7, 0" : : "r" (0));
}

/*
 * Flush the data TLB by address
 */
static __inline__ void
arm_v4_dtlb_addr(unsigned addr)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c6, 1" : : "r" (addr));
}

/*
 * Flush the instruction and data TLBs by address
 */
static __inline__ void
arm_v4_idtlb_addr(unsigned addr)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c7, 1" : : "r" (addr));
}

/*
 * Get FCSE PID register
 */
static __inline__ unsigned
arm_v4_fcse_get(void)
{
	unsigned	pid;
	__asm__ __volatile__("mrc	p15, 0, %0, c13, c0, 0" : "=r" (pid));
	return pid;
}

/*
 * Set FCSE PID register
 */
static __inline__ void
arm_v4_fcse_set(unsigned pid)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c13, c0, 0" : : "r" (pid));
}

/*
 * Data Synchronisation barrier
 * Deprecated in ARMv7 - replaced by dsb instruction
 */
static __inline__ void
arm_v6_dsb(void)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c7, c10, 4" : : "r" (0) : "memory");
}

/*
 * Data Memory Barrier
 * Deprecated in ARMv7 - replaced by dmb instruction
 */
static __inline__ void
arm_v6_dmb()
{
	__asm__ __volatile__("mcr	p15, 0, %0, c7, c10, 5" : : "r" (0) : "memory");
}

/*
 * Set TTBR0 register
 */
static __inline__ void
arm_v6_ttbr0_set(unsigned ttbr0)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c2, c0, 0" : : "r" (ttbr0));
}

/*
 * Get TTBR0 register
 */
static __inline__ unsigned
arm_v6_ttbr0_get()
{
	unsigned	ttbr0;

	__asm__ __volatile__("mrc	p15, 0, %0, c2, c0, 0" :  "=r" (ttbr0));
	return ttbr0;
}

/*
 * Set current ASID
 */
static __inline__ void
arm_v6_asid_set(unsigned asid)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c13, c0, 1" : : "r" (asid));
}

/*
 * Flush Branch Target Cache
 */
static __inline__ void
arm_v6_flush_btc(void)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c7, c5, 6" : : "r" (0));
}

/*
 * Flush all TLB entries matching ASID
 */
static __inline__ void
arm_v6_tlb_asid(unsigned asid)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c7, 2" : : "r" (asid));
	arm_v6_dsb();
}

/*
 * Get CPU number on MPcore
 */
static __inline__ unsigned
arm_v6_cpunum(void)
{
	unsigned n;
	__asm__ __volatile__("mrc	p15, 0, %0, c0, c0, 5" : "=r" (n));
	return n & 0xf;
}

/*
 * Invalidate data TLBs by MVA/ASID
 */
static __inline__ void
arm_v6_dtlb_addr(unsigned addr)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c6, 1" : : "r" (addr));
	arm_v6_dsb();
}

/*
 * Invalidate instruction/data TLBs by MVA/ASID
 */
static __inline__ void
arm_v6_idtlb_addr(unsigned addr)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c7, 1" : : "r" (addr));
	arm_v6_dsb();
}

/*
 * Invalidate data TLBs
 */
static __inline__ void
arm_v6_dtlb_flush(void)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c6, 0" : : "r" (0));
	arm_v6_dsb();
}

/*
 * Inner-shareable invalidate TLB by va/asid on all inner-shared cpus
 * VA must be page-aligned with asid in the lower 8 bits of addr
 *
 * If there is a global entry for this VA, the ASID is not checked (ARM ARM B4-1744)
 */
static __inline__ void
arm_v7_tlbimvais(unsigned addr)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c3, 1" : : "r"(addr));
	__asm__ __volatile__("dsb");
}

/*
 * Inner-shareable invalidate TLB by asid on all inner-shared cpus
 */
static __inline__ void
arm_v7_tlbiasidis(unsigned asid)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c3, 2" : : "r"(asid));
	__asm__ __volatile__("dsb");
}

/*
 * Invalidate TLB by va/asid on the local cpu
 * VA must be page-aligned with asid in the lower 8 bits of addr
 *
 * If there is a global entry for this VA, the ASID is not checked (ARM ARM B4-1744)
 */
static __inline__ void
arm_v7_tlbimva(unsigned addr)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c7, 1" : : "r"(addr));
	__asm__ __volatile__("dsb");
}

/*
 * Invalidate TLB by va on the local cpu for all asid values
 */
static __inline__ void
arm_v7_tlbimvaa(unsigned addr)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c7, 3" : : "r"(addr));
	__asm__ __volatile__("dsb");
}

/*
 * Invalidate TLB by asid on local cpu
 */
static __inline__ void
arm_v7_tlbiasid(unsigned asid)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c7, 2" : : "r"(asid));
	__asm__ __volatile__("dsb");
}

/*
 * Invalidate the entire unified TLB on all inner-shared cpus
 */
static __inline__ void
arm_v7_tlbiallis(void)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c3, 0" : : "r" (0) );
	__asm__ __volatile__("dsb");
}


/*
 * Invalidate the entire unified TLB on the local cpu
 */
static __inline__ void
arm_v7_tlbiall(void)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c8, c7, 0" : : "r" (0) );
	__asm__ __volatile__("dsb");
}




/*
 * Set current ASID
 */
static __inline__ void
arm_v7_asid_set(unsigned asid)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c13, c0, 1" : : "r" (asid));
	__asm__ __volatile__("isb");
}

/*
 * Set TTBR0 register
 */
static __inline__ void
arm_v7_ttbr0_set(unsigned ttbr0)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c2, c0, 0" : : "r" (ttbr0));
	__asm__ __volatile__("isb");
}


/*
 * Set TTBR0 register in lpae mode
 */
static __inline__ void
arm_lpae_ttbr0_set(_Uint64t ttbr0)
{
	_Uint32t ttbr0_low  = ttbr0 & 0xffffffff;
	_Uint32t ttbr0_high = ttbr0>>32;
	
    /* format "code" : output: input : clobber */
	__asm__ __volatile__("mcrr	p15, 0, %0, %1, c2"
						 : /* no output */
						 : "r" (ttbr0_low), "r" (ttbr0_high) );
	__asm__ __volatile__("isb");

	return;
}

/*
 * Get TTBR0 register in lpae mode
 */
static __inline__ _Uint64t
arm_lpae_ttbr0_get()
{
	_Uint32t ttbr0_low;
	_Uint32t ttbr0_high;
	_Uint64t ttbr;
	
    /* format "code" : output: input : clobber */
	__asm__ __volatile__("mrrc	p15, 0, %0, %1, c2"
						 : "=r" (ttbr0_low), "=r" (ttbr0_high)
		                 : /* no input, no clobber */ );

	ttbr = ((_Uint64t) ttbr0_high) << 32 | ttbr0_low;
	return (ttbr);
}


/*
 * Set TTBR1 register in lpae mode
 */
static __inline__ void
arm_lpae_ttbr1_set(_Uint64t ttbr1)
{
	_Uint32t ttbr1_low  = ttbr1 & 0xffffffff;
	_Uint32t ttbr1_high = ttbr1>>32;
	
    /* format "code" : output: input : clobber */
	__asm__ __volatile__("mcrr	p15, 1, %0, %1, c2"
						 : /* no output */
						 : "r" (ttbr1_low), "r" (ttbr1_high) );
	__asm__ __volatile__("isb");

	return;
}

/*
 * Get TTBR1 register in lpae mode
 */
static __inline__ _Uint64t
arm_lpae_ttbr1_get()
{
	_Uint32t ttbr1_low;
	_Uint32t ttbr1_high;
	_Uint64t ttbr;
	
    /* format "code" : output: input : clobber */
	__asm__ __volatile__("mrrc	p15, 1, %0, %1, c2"
						 : "=r" (ttbr1_low), "=r" (ttbr1_high)
		                 : /* no input, no clobber */ );

	ttbr = ((_Uint64t) ttbr1_high) << 32 | ttbr1_low;
	return (ttbr);
}

/*
 * Set TTBCR register
 */
static __inline__ void
arm_ttbcr_set(_Uint32t ttbcr)
{
	__asm__ __volatile__("mcr	p15, 0, %0, c2, c0, 2" : : "r" (ttbcr));
}


/*
 * Get TTBCR register
 */
static __inline__ _Uint32t
arm_ttbcr_get()
{
	unsigned	ttbcr;

	__asm__ __volatile__("mrc	p15, 0, %0, c2, c0, 2" :  "=r" (ttbcr));
	return ttbcr;
}



#define ARM_LPAE_XLAT_PRIV 1
#define ARM_LPAE_XLAT_UNPRIV 0

/* Perform LPAE address translation */
static __inline__ _Uint64t
arm_lpae_translate(_Uint32t va, int priv)
{
	_Uint32t out_low;
	_Uint32t out_high;
	_Uint64t output;

    if (priv) {
        // ATS1CPR Stage 1 Current state PL1 read opc1=0, opc2=0
        __asm__ __volatile__("mcr p15, 0, %0, c7, c8, 0" : /* no output */ : "r" (va) );  // ATS1CPR
    } else { 
        // ATS1CUR Stage 1 Current state unprivileged read opc1=0, opc2=2
        __asm__ __volatile__("mcr p15, 0, %0, c7, c8, 2" : /* no output */ : "r" (va) );  // ATS1CUR
    }

	__asm__ __volatile__("isb");  // Ensure instruction is completed
	
    // MRRC p15, 0, <Rt>, <Rt2>, c7  ; Read 64-bit PAR into Rt (low word) and Rt2 (high word)
	__asm__ __volatile__("mrrc	p15, 0, %0, %1, c7"
						 : "=r" (out_low), "=r" (out_high)
		                 : /* no input, no clobber */ );

	output = ((_Uint64t) out_high) << 32 | out_low;
	
	return (output);
}



/* Read/Write MAIR0/1 registers */
static __inline__ _Uint32t
arm_lpae_mair_get(_Uint32t mair)
{
	_Uint32t val;
	if (mair == 0) {
		__asm__ __volatile__("mrc	p15, 0, %0, c10, c2, 0" : "=r" (val) );
		__asm__ __volatile("mov r0,r0");
	} else {
		__asm__ __volatile__("mrc	p15, 0, %0, c10, c2, 1" : "=r" (val) );
		__asm__ __volatile("mov r0,r0");
	}
	return val;
}

static __inline__ void
arm_lpae_mair_set(_Uint32t mair, _Uint32t val)
{
	if (mair == 0) {
		__asm__ __volatile__("mcr	p15, 0, %0, c10, c2, 0" : /* no output */ : "r" (val) );
		__asm__ __volatile("mov r0,r0");
	} else {
		__asm__ __volatile__("mcr	p15, 0, %0, c10, c2, 1" : /* no output */ : "r" (val) );
		__asm__ __volatile("mov r0,r0");
	}
	return;
}


static __inline__ void
arm_cache_clean(_Uintptrt vaddr)
{
	// DCCMVAC "Data Cache Clean MVA to point of coherency" - E.G. entire system
	// This uses the current asid (as defined by TTBCR and TTBR0/1; p B1284)
	//__asm__ __volatile__("mcr p15, 0, %0, c7, c10, 1" : /* no output */ : "r" (vaddr) );

	// DCCMVAU "Data Cache Clean MVA to point of unification" - within the shareability domain
	// This uses the current asid (as defined by TTBCR and TTBR0/1; p B1284)
    // According to the docs, if the MVA is defined as non-sharable, this will be the local cpu 
    // if the MVA is inner or outer shareable, the effect will be on all CPUs in the Inner Sharability domain
	__asm__ __volatile__("mcr p15, 0, %0, c7, c11, 1" : /* no output */ : "r" (vaddr) );

	__asm__ __volatile__("dsb");

	return;
}


static __inline__ void
arm_icache_invalidate(void)
{
	// ICCALLUIS "Instruction cache clean to PoU - inner shareable"
	__asm__ __volatile__("mcr p15, 0, r0, c7, c1, 0");
	__asm__ __volatile__("isb");

    // ICCALLUIS flushes branch predictors, so separate BPIALLIS not required
    //__asm__ __volatile__("mcr p15, 0, r0, c7, c1, 6" : : ); // BPIALLIS
    
	return;
}

static __inline__ void
arm_v7_dsb(void)
{
    // DSB takes arguments!
	__asm__ __volatile__("dsb");
}

static __inline__ void
arm_v7_dmb(void)
{
	__asm__ __volatile__("dmb");
}




#endif	/* __ARM_MMU_H_INCLUDED */


#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/branches/6.6.0/trunk/services/system/public/arm/mmu.h $ $Rev: 761639 $")
#endif
