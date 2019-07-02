#ifndef __TD_H__
#define __TD_H__

#include <message.h>

#define MAX_TASKS 50
#define NUM_PRIORITIES 10

#define TASK_STATE_READY 0
#define TASK_STATE_ACTIVE 1
#define TASK_STATE_ZOMBIE 2
#define TASK_STATE_SEND_BLOCKED 3
#define TASK_STATE_RECV_BLOCKED 4
#define TASK_STATE_REPLY_BLOCKED 5
#define TASK_STATE_AWAIT_BLOCKED 6

typedef struct TaskDescriptor {
  // DON'T MOVE THESE WITHOUT CHANGING THE ASSEMBLY (src/kfunc.asm)
  // ASSEMBLY CODE DEPENDS ON THE POSITION OF THE FIELDS
  int *sp;
  int *lr;
  int spsr;
  // ---------------------------------------------------------------------------
  int id;
  int parent_id;
  int priority;
  int rv;
  int *sp_base; // Used for resetting the stack pointer to the base value
  int state; // ACTIVE, READY, ZOMBIE etc.
  struct TaskDescriptor *next; // Used for scheduling
  // Messaging related
  M_Q_Entry *msg_recv_entry;
  M_Q_Entry *msg_reply_entry;
  M_Q send_q; // send_queue
} TD;

// Next task is at the head, appending happens at the tail
typedef struct TD_Q {
  struct TaskDescriptor *head;
  struct TaskDescriptor *tail;
} TD_Q;

void td_init(TD *td, int id, int parent_id, int priority, void (*code)());

#endif
