#ifndef __KERNEL_H__
#define __KERNEL_H__

#include <td.h>
#include <message.h>
#include <event.h>
#include <buffers.h>

#define NULL 0
#define TRUE 1
#define FALSE 0

// Should probably find a way to do this programmatically
// NOTE(rwan): Function addresses are fucked if we don't offset by this
#define PROGRAM_ENTRY 0x00218000

#define KERNEL_STACK_BASE 0x01500000
#define KERNEL_STACK_SIZE 0x00400000
#define USER_STACK_BASE (KERNEL_STACK_BASE - KERNEL_STACK_SIZE)
//#define USER_STACK_SIZE 0x00010000
#define USER_STACK_SIZE 0x000493E0


typedef struct KernelRequest {
  int syscall_code;
  int result;
  int priority;
  void (*code)(); // (used for the Create syscall)
  M_Q_Entry *msg_entry;
  M_Q_Entry *msg_reply_entry;
  Event *event;
} KernelRequest;

// Used to hold the state of the kernel
typedef struct KernelState {
  int irq_flag;
  TD *cur_task;
  int next_free_td;
  KernelRequest *cur_req;
  TD tds[MAX_TASKS]; // List of task descriptors
  int cur_highest_priority;
  TD_Q td_pq[NUM_PRIORITIES+1]; // Don't want the stupid off-by-one errors
  TD *td_free_list[MAX_TASKS]; // Used for deciding which TD to use
  E_Q awaiting_tasks[NUM_EVENTS];
  int task_total_run_time[MAX_TASKS];
  int shutdown;
  int txfe_flag;
  int cts_on_flag;
  char_rb rx_q;
} KernelState;

// Assembly functions
KernelRequest *kernel_exit(TD *active_task, int *irq_flag);
void kernel_enter(KernelRequest *kr);
void hw_kernel_enter();

#endif
