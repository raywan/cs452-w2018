#ifndef __ACTIONS_H__
#define __ACTIONS_H__

#include <track_node.h>

#define SUB_SENSORS 0
#define SUB_SWITCHES 1
#define SUB_TRACK_ACQUIRE 2
#define SUB_TRACK_RELEASE 3
#define SUB_TRAIN_SPEED 4
#define SUB_TRAIN_REVERSE 5
#define SUB_TRAIN_IDLE 6
#define SUB_FIRST SUB_SENSORS
#define SUB_LAST SUB_TRAIN_IDLE

#define ANN_SENSORS 10
#define ANN_SWITCHES 11
#define ANN_TRACK_ACQUIRE 12
#define ANN_TRACK_RELEASE 13
#define ANN_TRAIN_SPEED 14
#define ANN_TRAIN_REVERSE 15
#define ANN_TRAIN_IDLE 16
#define ANN_FIRST ANN_SENSORS
#define ANN_LAST ANN_TRAIN_IDLE

#define ACT_ACQUIRE_TRACK 20
#define ACT_RELEASE_TRACK 21
#define ACT_GET_TRACK_PTR 22

#define ACT_SET_SWITCH 23
#define ACT_SET_TRAIN_SPEED 24
#define ACT_REVERSE_TRAIN 25
#define ACT_DUMP_SENSORS 26
#define ACT_TRACK_GO 27
#define ACT_EMERGENCY_STOP 28
#define ACT_TRAIN_PLACEMENT 29
#define ACT_TRAIN_GOTO 30

#define SWITCH_POP 31 // Notifier to Switches
#define TRAIN_SET_PLACEMENT 32 // Conductor to Train
#define TRAIN_GOTO 33 // Conductor to Train

#define ACT_GET_TRACK_PATH 34
#define ACT_PRINT_RES 35
#define ACT_USE_TRACK 36

#include <track.h>

typedef struct Request {
  unsigned int type;
  int data1;
  int data2;
  int data3;
} Request;

// Subscriptions
void subscribe_sensors(int dispatch_tid);
void subscribe_switches(int dispatch_tid);
void subscribe_track_acquire(int dispatch_tid);
void subscribe_track_release(int dispatch_tid);
void subscribe_train_speed(int dispatch_tid);
void subscribe_train_reverse(int dispatch_tid);
void subscribe_train_idle(int dispatch_tid);

// Annoucements
void announce_sensors(int dispatch_tid, int track_idx); // For sensor server only
void announce_switches(int dispatch_tid, int switch_num, char switch_direction);
void announce_track_acquire(int dispatch_tid, int track_idx); // For track server only
void announce_track_release(int dispatch_tid, int track_idx); // For track server only
void announce_train_speed(int dispatch_tid, int train_num, int train_speed);
void announce_train_reverse(int dispatch_tid, int train_num);
void announce_train_idle(int dispatch_tid, int train_num);

// Actions
void use_track(int track_tid, int track_num);
int acquire_track(int track_tid, int train_num, int track_idx, int edge_num); // 0=success, 1=fail
int release_track(int track_tid, int train_num, int track_idx, int edge_num); // 0=success, 1=fail, 2=donotown
void set_switch(int conductor_tid, int switch_num, char switch_direction);
void set_train_speed(int conductor_tid, int train_num, int train_speed);
void reverse_train(int conductor_tid, int train_num);
void dump_sensors(int conductor_tid);
void track_go(int conductor_tid);
void emergency_stop(int conductor_tid);
void train_placement(int conductor_tid, int train_num, int next_sensor_track_idx);
void train_goto(int conductor_tid, int train_num, int target_sensor_idx);
track_node *get_track_ptr(int track_tid);
void get_path(int track_tid, Path *p, int train_num, int source_sensor_idx);
void print_res(int track_tid, int train_num);

#endif
