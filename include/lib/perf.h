#ifndef __PERF_H__
#define __PERF_H__

#define MAX_TICKS 0xFFFFFFFF
#define TICKS_PER_PERIOD 0x1FC // 508 ticks = 1ms on a 508kHZ clock

void init_timer();
void init_debug_timer();
void reset_debug_timer();
unsigned int get_ticks();
unsigned int get_cur_ms();

#endif
