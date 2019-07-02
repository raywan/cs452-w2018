/**
 * Credits to https://en.wikibooks.org/wiki/C_Programming/String_manipulation#The_%3Cstring.h%3E_Standard_Header
 */
#ifndef __STRING_H__
#define __STRING_H__

int strlen(const char *s);
char *strncat(char * s1, const char * s2, int n);
int strncmp(const char *s1, const char *s2, int n);
char *strncpy(char * s1, const char * s2, int n);
int streq(const char * s1, const char * s2);
void *memcpy(void *  s1, const void *  s2, int n);
void *memset(void *s, int c, int n);

#endif
