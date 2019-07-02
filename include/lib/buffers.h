#ifndef __BUFFERS_H__
#define __BUFFERS_H__

#define SMALL_CHAR_RB_SIZE 8
#define SMALL_CHAR_RB_MASK (SMALL_CHAR_RB_SIZE-1)

#define SENSOR_RB_SIZE 8
#define SENSOR_RB_MASK (SENSOR_RB_SIZE-1)

#define CHAR_RB_SIZE 128
#define CHAR_RB_MASK (CHAR_RB_SIZE-1)

#define INT_RB_SIZE 64
#define INT_RB_MASK (INT_RB_SIZE-1)

typedef struct small_char_rb {
  unsigned char buf[SMALL_CHAR_RB_SIZE];
  unsigned int s;
  unsigned int e;
} small_char_rb;

void small_char_rb_init(struct small_char_rb *rb);
int is_small_char_rb_full(struct small_char_rb *rb);
int small_char_rb_empty(struct small_char_rb *rb);
void small_char_rb_insert(struct small_char_rb *rb, char data);
int small_char_rb_pop(struct small_char_rb *rb, char *data);
int small_char_rb_peek(struct small_char_rb *rb, char *data);

typedef struct char_rb {
  unsigned char buf[CHAR_RB_SIZE];
  unsigned int s;
  unsigned int e;
} char_rb;

void char_rb_init(struct char_rb *rb);
int is_char_rb_full(struct char_rb *rb);
int char_rb_empty(struct char_rb *rb);
void char_rb_insert(struct char_rb *rb, char data);
int char_rb_pop(struct char_rb *rb, char *data);
int char_rb_peek(struct char_rb *rb, char *data);

typedef struct int_rb {
  unsigned int buf[INT_RB_SIZE];
  unsigned int s;
  unsigned int e;
} int_rb;

void int_rb_init(struct int_rb *rb);
int is_int_rb_full(struct int_rb *rb);
int int_rb_empty(struct int_rb *rb);
void int_rb_insert(struct int_rb *rb, int data);
int int_rb_pop(struct int_rb *rb, int *data);
int int_rb_peek(struct int_rb *rb, int *data);
///////////////////////////////////////////////////////////////////////////////

typedef struct sensor_rb {
  unsigned char buf[SENSOR_RB_SIZE][4];
  int s;
  int e;
  int count;
} sensor_rb;

void sensor_rb_init(struct sensor_rb *rb);
void sensor_rb_insert(struct sensor_rb *rb, const char *data);

#endif

