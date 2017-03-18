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
 * R-CarE2 specific WDT support.
 * RWDT is used.
 */

#include "startup.h"
#include <arm/bcm2836.h>

void wdt_enable()
{
    uint32_t cur;

    // out32(BCM2835_WDOG_PHYSADDR + BCM2835_WDOG_WDOG, BCM2835_WDOG_PASSWORD | (SECS_TO_WDOG_TICKS(0x000fffff) & BCM2835_WDOG_WDOG_TIME_SET) );
    // out32(BCM2835_WDOG_PHYSADDR + BCM2835_WDOG_WDOG, BCM2835_WDOG_PASSWORD | (0x80 & BCM2835_WDOG_WDOG_TIME_SET) );
    out32(BCM2835_WDOG_PHYSADDR + BCM2835_WDOG_WDOG, BCM2835_WDOG_PASSWORD | (0xffff & BCM2835_WDOG_WDOG_TIME_SET) );

    cur = in32(BCM2835_WDOG_PHYSADDR + BCM2835_WDOG_RSTC);
    out32(BCM2835_WDOG_PHYSADDR + BCM2835_WDOG_RSTC, BCM2835_WDOG_PASSWORD | (cur & BCM2835_WDOG_RSTC_WRCFG_CLR) | BCM2835_WDOG_RSTC_WRCFG_FULL_RESET);

}

void wdt_disable()
{
    out32(BCM2835_WDOG_PHYSADDR + BCM2835_WDOG_RSTC, BCM2835_WDOG_PASSWORD | BCM2835_WDOG_RSTC_RESET);
}



#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL$ $Rev$")
#endif
