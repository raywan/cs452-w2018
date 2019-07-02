#ifndef __TRACK_H__
#define __TRACK_H__

#include <track_data.h>

typedef struct {
  int prev[144];
  int dist[144];
  int node_st[144];
  int cmd[144];
  int st_pt;
  int sensor_idx_before_path; // For predictions
  int last_st_idx; // For predictions
} Path;

typedef struct Prediction {
  int idx[5];
  int dist[5];
  int time[5];
} Prediction;

void track_server(void);

int convert_sensor_to_track_idx(const unsigned char *cmd_buf);
const char* convert_sensor_track_idx_to_name(int track_idx, track_node *track);
void get_next_sensors(track_node track[144], int node_idx, Prediction *p);
void predict_reverse(track_node track[144], Prediction *p);
void make_path(Path *p, int target_idx);
void print_path(track_node *track, Path *p, int target_idx);
void print_reservations(track_node *track, int reservations[TRACK_MAX][2], int train_num);
void path_to_commands(track_node *track, Path *p);

#endif
