#ifndef __SCHEDULING_H__
#define __SCHEDULING_H__

void scheduler_insert(KernelState *ks, TD *td);
TD *schedule(KernelState *ks);
void reschedule(KernelState *ks);

#endif
