#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

typedef struct winsize WINSIZE;

FILE* sopen(const char* name, const char* mode);
void getcsize(int* outwidth, int* outheight);

#endif