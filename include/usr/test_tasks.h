#ifndef __TASKS_H__
#define __TASKS_H__

/**
 * List of user tasks that can be created and scheduled
 */

void k1_first_task(void);
void k1_second_task(void);

void msg_first_task(void);
void test_sender_task(void);
void test_receiver_task(void);

void perf_first_task(void);
void perf_send_task(void);
void perf_recv_task(void);

void ns_first_task(void);
void ns_register_task1(void);
void ns_register_task2(void);
void ns_register_task3(void);
void ns_register_task4(void);
void ns_whois_task(void);

void hw_ext_int_test(void);

void dispatch_test(void);

#endif
