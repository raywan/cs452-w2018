#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

#include <kernel.h>

void interrupt_clock(KernelState *ks);
void interrupt_uart1(KernelState *ks);
void interrupt_uart2(KernelState *ks);

#endif
