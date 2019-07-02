#ifndef __IO_H__
#define __IO_H__

int Getc(int server_tid, int channel);
int Putc(int server_tid, int channel, char c);
void Printf(int server_tid, char *format, ... );
void nPrintf(int server_tid, int r, int c, char *format, ... );
int Puts(int server_tid, int channel, char *c);

#endif
