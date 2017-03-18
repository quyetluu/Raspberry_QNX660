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

enum bcm2835_fsel {
	BCM2835_FSEL_GPIO_IN = 0,
	BCM2835_FSEL_GPIO_OUT = 1,
	BCM2835_FSEL_ALT0 = 4,
	BCM2835_FSEL_ALT1 = 5,
	BCM2835_FSEL_ALT2 = 6,
	BCM2835_FSEL_ALT3 = 7,
	BCM2835_FSEL_ALT4 = 3,
	BCM2835_FSEL_ALT5 = 2,
	BCM2835_FSEL_COUNT = 8,
	BCM2835_FSEL_MASK = 0x7,
};



static inline void bcm2835_gpio_write(uint32_t reg,  uint32_t val ){
	out32(BCM2835_GPIO_BASE + reg, val);
}

static inline uint32_t bcm2835_gpio_read(uint32_t reg){
	return in32(BCM2835_GPIO_BASE + reg);
}

static inline int bcm2835_gpio_get_bit( uint32_t reg,
		uint32_t bit)
{
	reg += GPIO_REG_OFFSET(bit) * 4;
	return (bcm2835_gpio_read( reg) >> GPIO_REG_SHIFT(bit)) & 1;
}

static inline void bcm2835_gpio_set_bit(uint32_t reg, uint32_t bit)
{
	reg += GPIO_REG_OFFSET(bit) * 4;
	bcm2835_gpio_write(reg, BIT(GPIO_REG_SHIFT(bit)));
}

void bcm2835_pin_set(unsigned pin, enum bcm2835_fsel fsel){

	uint32_t val = bcm2835_gpio_read(FSEL_REG(pin));
	enum bcm2835_fsel cur = (val >> FSEL_SHIFT(pin)) & BCM2835_FSEL_MASK;

	if (cur == fsel)
		return;

	if (cur != BCM2835_FSEL_GPIO_IN && fsel != BCM2835_FSEL_GPIO_IN) {
		/* always transition through GPIO_IN */
		val &= ~(BCM2835_FSEL_MASK << FSEL_SHIFT(pin));
		val |= BCM2835_FSEL_GPIO_IN << FSEL_SHIFT(pin);

		bcm2835_gpio_write(FSEL_REG(pin), val);
	}

	val &= ~(BCM2835_FSEL_MASK << FSEL_SHIFT(pin));
	val |= fsel << FSEL_SHIFT(pin);

	bcm2835_gpio_write(FSEL_REG(pin), val);
}
  
void init_serial(){
	// bcm2835_pin_set(32,BCM2835_FSEL_ALT3);
	// bcm2835_pin_set(33,BCM2835_FSEL_ALT3);
	// bcm2835_gpio_write(BCM2835_GPIO_GPSET1, bcm2835_gpio_read(BCM2835_GPIO_GPSET1) | 0x3);

	bcm2835_pin_set(14,BCM2835_FSEL_ALT0);
	bcm2835_pin_set(15,BCM2835_FSEL_ALT0);
	bcm2835_gpio_write(BCM2835_GPIO_GPSET0, 0x3 << 14);
	bcm2835_gpio_write(BCM2835_GPIO_GPLEV0, ~(3 << 14));

}


void init_board()
{
	init_serial();
}


#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL$ $Rev$")
#endif
