#ifndef __EVENT_H__
#define __EVENT_H__

#define NUM_EVENTS 5

#define EVENT_TYPE_CLOCK 0
#define EVENT_TYPE_UART1_RX 1
#define EVENT_TYPE_UART1_TX 2
#define EVENT_TYPE_UART2_RX 3
#define EVENT_TYPE_UART2_TX 4

typedef struct Event {
  int tid;
  int type; // event type
  void *data;
  int len;
  int result; // "return" of the interrupt
  struct Event *next;
} Event;

typedef struct E_Q {
  struct Event *head;
  struct Event *tail;
} E_Q;

void eq_push(struct E_Q *e_q, struct Event *e);
struct Event *eq_pop(struct E_Q *e_q);

#endif
