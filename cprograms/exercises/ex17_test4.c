// this is supposed to crash
// just want to see how sucky strncpy is

#include <stdio.h>
#include <string.h>
#define MAX_DATA 700

int main(int argc, char *argv[]){
  char src[] = "hello, world";
  char dst[MAX_DATA];
  // strcpy(dst, src);
  strcpy(dst, src); // strcpy sucks becuase there's no nul termination
  printf("%c\n", src[700]); // you'll get random data OR a segfault
  return 0;
}