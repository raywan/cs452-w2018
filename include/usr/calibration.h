#ifndef __CALIBRATION_H__
#define __CALIBRATION_H__

#include <train.h>

void init_stopping(int train_num, int stopping_dist[15]);

int get_init_cali_vel_10(int train_num); // mm/s

void attach_short_move_func(int train_num, int (*fp)(int));

#endif
