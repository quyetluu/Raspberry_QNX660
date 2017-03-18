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


#include "startup.h"
#include <arm/bcm2836.h>

extern void init_board(void);
extern void wdt_enable(void);

extern struct callout_rtn   reboot_bcm2836;
const struct callout_slot callouts[] = {
    { CALLOUT_SLOT( reboot, _bcm2836 ) },
};

const struct armv_chip *armv_list[] = {
    &armv_chip_a7
};

const struct debug_device debug_devices[] = {
    {   "bcm2836",
        {   
        "0x3F201000.115200.16",  /* Use whatever boot loader baud rate */
        // "0x3F201000.115200.65000000",  /* Use whatever boot loader baud rate */
        },
        init_bcm2836,
        put_bcm2836,
        {   &display_char_bcm2836,
            &poll_key_bcm2836,
            &break_detect_bcm2836,
        }
    },
};

void 
allocate_codec_memory(paddr_t addr, size_t size)
{
    alloc_ram(addr, size, 1);
    hwi_add_device(HWI_ITEM_BUS_UNKNOWN, HWI_ITEM_DEVCLASS_DMA, "misc", 0);
    hwi_add_location(addr, size, 0, hwi_find_as(addr, 0));
    as_add_containing(addr, addr + size - 1, AS_ATTR_RAM, "codec", "ram");
}

/*
 * main()
 *  Startup program executing out of RAM
 *
 * 1. It gathers information about the system and places it in a structure
 *    called the system page. The kernel references this structure to
 *    determine everything it needs to know about the system. This structure
 *    is also available to user programs (read only if protection is on)
 *    via _syspage->.
 *
 * 2. It (optionally) turns on the MMU and starts the next program
 *    in the image file system.
 */

int main(int argc, char **argv, char **envv)
{
    int     opt;
    char    *p;
    paddr_t codecmem_addr = 0;
    size_t  codecmem_size = 0;

    add_callout_array(callouts, sizeof(callouts));


    while ((opt = getopt(argc, argv, COMMON_OPTIONS_STRING "L:W")) != -1) {
        switch (opt) {
            case 'W':
                /* Enable WDT */
                wdt_enable();
                break;
            case 'L':
                // codecmem_addr = getsize(optarg, &p);
                // if (*p == ',')
                //     codecmem_size = getsize(p + 1, &p);
                // break;
            default:
                handle_common_option(opt);
                break;
        }
    }
    /*
     * Initialize debugging output
     */
    select_debug(debug_devices, sizeof(debug_devices));


    init_board();

    /*
     * Collect information on all free RAM in the system
     */
 
    init_raminfo();

    /*
     * Set CPU frequency
     */
    if (cpu_freq == 0) 
    {
        cpu_freq = 800000000;
    }
    
    /*
     * Remove RAM used by modules in the image
     */
    alloc_ram(shdr->ram_paddr, shdr->ram_size, 1);

    /* Reserve RAM for codec */
    if (codecmem_size != 0)
        allocate_codec_memory(codecmem_addr, codecmem_size);

    /*
    * Initialise SMP
    */
    // TODO

    init_smp();

    if (shdr->flags1 & STARTUP_HDR_FLAGS1_VIRTUAL){
        init_mmu();
    }

    init_intrinfo();
    init_qtime();
    init_cacheattr();
    init_cpuinfo();
    init_hwinfo();

    add_typed_string(_CS_MACHINE, "BCM2836");

    /*
     * Load bootstrap executables in the image file system and Initialise
     * various syspage pointers. This must be the _last_ initialisatnion done
     * before transferring control to the next program.
     */
    init_system_private();

    /*
     * This is handy for debugging a new version of the startup program.
     * Commenting this line out will save a great deal of code.
     */
    print_syspage();

    return 0;
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL$ $Rev$")
#endif
