#ifndef __SYSCALLS_H__
#define __SYSCALLS_H__

#include <kernel.h>

void syscall_create(KernelState *ks);
void syscall_tid(KernelState *ks);
void syscall_ptid(KernelState *ks);
void syscall_pass(KernelState *ks);
void syscall_exit(KernelState *ks);

void syscall_send(KernelState *ks);
void syscall_receive(KernelState *ks);
void syscall_reply(KernelState *ks);

void syscall_awaitevent(KernelState *ks);
void syscall_mytotalruntimeptr(KernelState *ks);
void syscall_totalruntimeptr(KernelState *ks);

void syscall_shutdown(KernelState *ks);

int Create(int priority, void (*code)(void));
int MyTid(void);
int MyParentTid(void);
void Pass(void);
void Exit(void);

int Send(int tid, void *msg, int msg_len, void *reply, int reply_len);
int Receive(int *tid, void *msg, int msg_len);
int Reply(int tid, void *reply, int reply_len);

int AwaitEvent(int event_type, void *data, int len);

int *MyTotalRunTimePtr();
int *TotalRunTimePtr(int tid);

int Shutdown();

#endif
