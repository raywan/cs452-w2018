/*
 * bwio.h
 */

typedef char *va_list;

#define __va_argsiz(t)	\
		(((sizeof(t) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

#define va_start(ap, pN) ((ap) = ((va_list) __builtin_next_arg(pN)))

#define va_end(ap)	((void)0)

#define va_arg(ap, t)	\
		 (((ap) = (ap) + __va_argsiz(t)), *((t*) (void*) ((ap) - __va_argsiz(t))))

#define COM1	0
#define COM2	1

#define ON	1
#define	OFF	0

#define RING_BUFFER_SIZE 512
#define RB_MASK (RING_BUFFER_SIZE-1)

typedef struct ring_buffer {
  unsigned char buf[RING_BUFFER_SIZE];
  unsigned int s;
  unsigned int e;
} ring_buffer;

int bwsetfifo( int channel, int state );

int bwsetspeed( int channel, int speed );

int bwputc( int channel, char c );

int bwgetc( int channel );
//int getc( struct ring_buffer *rb , char c);

int bwputx( int channel, char c );
//int putx( struct ring_buffer *rb, char c );

int bwputstr( int channel, char *str );
//int putstr( struct ring_buffer *rb, char *str );

int bwputr( int channel, unsigned int reg );
//int putr( int channel, unsigned int reg );

void bwputw( int channel, int n, char fc, char *bf );
//void putw( int channel, int n, char fc, char *bf );

void bwprintf( int channel, char *format, ... );

void rprintf( struct ring_buffer *rb, char *format, ... );
