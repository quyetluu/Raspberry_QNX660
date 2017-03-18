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
 * APE6 system reboot
 */

#include "callout.ah"
#include <arm/bcm2836.h>

/*
 * -----------------------------------------------------------------------
 * Routine to patch callout code
 *
 * On entry:
 *  r0 - physical address of syspage
 *  r1 - virtual  address of syspage
 *  r2 - offset from start of syspage to start of the callout routine
 *  r3 - offset from start of syspage to read/write data used by callout
 * -----------------------------------------------------------------------
 */
patch_reboot:
    stmdb   sp!,{r4,lr}
    add     r4, r0, r2

    /*
     * Map reset control registers
     */
    mov     r0, #0x100
    ldr     r1, Lpaddr
    bl      callout_io_map32

    /*
     * Patch the callout routine
     */
    CALLOUT_PATCH   r4, r0, r1, r2, ip
    ldmia   sp!,{r4,pc}

Lpaddr:    .word    BCM2835_WDOG_PHYSADDR


CALLOUT_START(reboot_bcm2836, 0, patch_reboot)
    /*
     * Get the Watchdog Timer base address (patched)
     */
    mov     ip,   #0x000000ff
    orr     ip, ip, #0x0000ff00
    orr     ip, ip, #0x00ff0000
    orr     ip, ip, #0xff000000

    teq	    r1, #0      // r1 = abnormal parameter flag
    beq	    _do_reboot

    ldrh	r2, [r0, #SYSPAGE_SYSTEM_PRIVATE] // offset to system_private
    add	    r0, r0, r2  // system_private address
    ldr	    r2, [r0, #SP_PRIVATE_FLAGS]
    tst	    r2, #SYSTEM_PRIVATE_FLAG_ABNORMAL_REBOOT
    beq	    0f          // spin if ABNORMAL_REBOOT is NOT set

_do_reboot:

    movw    r2, #0x000A
    movt    r2, #0x5A5A
    str     r2, [ip, #BCM2835_WDOG_WDOG]

    movw    r2, #0x0102
    movt    r2, #0x5a00
    str     r2, [ip, #BCM2835_WDOG_RSTC]

0:  b       0b
CALLOUT_END(reboot_bcm2836)

#ifdef __QNXNTO__
#ifdef __USESRCVERSION
.section .ident, "SM",%progbits,1;
.asciz "$URL: http://svn.ott.qnx.com/product/branches/6.6.0/trunk/hardware/startup/boards/rcar_e2/callout_reboot_rcare2.S $ $Rev: 788077 $";
.previous
#endif
#endif
