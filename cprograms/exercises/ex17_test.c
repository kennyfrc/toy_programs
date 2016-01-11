#include <stdio.h>
#include <assert.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
  char name[MAX_DATA];
  char email[MAX_ROWS];
  int id;
  int set;
};

int main(int argc, char *argv[]){
  if(argc != 5)
    printf("Need name email id set as arguments\n");
  struct Address *details = ()

  return 0;
}