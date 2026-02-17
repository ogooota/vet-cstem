#include "utils.h"

FILE* sopen(const char* name, const char* mode) {
  if(!name || !mode)
    return NULL;
  
  FILE* file = fopen(name, mode);
  if(!file)
    return NULL;
  return file;
}

void getcsize(int* outwidth, int* outheight) {
  WINSIZE w;
  if(ioctl(STDIN_FILENO, TIOCGWINSZ, &w) == -1) {
    perror("ioctl error");
    return;
  }
  *outwidth = w.ws_col;
  *outheight = w.ws_row;
  return;
}
