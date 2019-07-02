#ifndef __MESSAGE_H__
#define __MESSAGE_H__

typedef struct Message {
  int send_tid;
  int recv_tid;
  char *msg;
  int msg_len;
} Message;

typedef struct M_Q_Entry {
  int send_tid;
  int recv_tid;
  void *msg;
  int msg_len;
  struct M_Q_Entry *next;
} M_Q_Entry;

typedef struct M_Q {
  struct M_Q_Entry *head;
  struct M_Q_Entry *tail;
} M_Q;

void mq_push(struct M_Q *td, struct M_Q_Entry *msg);
struct M_Q_Entry *mq_pop(struct M_Q *td);

#endif
