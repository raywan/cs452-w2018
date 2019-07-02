#ifndef __TIMER_H__
#define __TIMER_H__

#define NOTIFIER_REQUEST 0
#define TIME_REQUEST 1
#define DELAY_REQUEST 2
#define DELAYUNTIL_REQUEST 3

typedef struct ClockMessage {
  int type;
  int tid;
  int data;
  struct ClockMessage *next;
} ClockMessage;

int Time(void);
int Delay(int ticks);
int DelayUntil(int ticks);

#endif
