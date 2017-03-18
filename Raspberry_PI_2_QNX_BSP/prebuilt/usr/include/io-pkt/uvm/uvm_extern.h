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

#ifndef _UVM_UVM_EXTERN_H_
#define _UVM_UVM_EXTERN_H_

#include <uvm/uvm_param.h>

struct proc;

struct vmspace {
	struct proc	*vm_proc;
	int		vm_flags;
};
#define VM_USERSPACE    1
#define VM_SYSSPACE     2
/* Hints to copyin / copyout */
#define VM_OUTFORCE	4
#define VM_NOCTXT	8
#ifdef __QNXNTO__
#define VM_MSGLENCHECK  0x10
#endif
#endif

__SRCVERSION( "$URL: http://svn/product/tags/services/bsp/nto650/freescale-mx6q-sabrelite/1.0.0/latest/io-pkt/sys/uvm/uvm_extern.h $ $Rev: 688026 $" )
