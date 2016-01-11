#include <stdio.h>
#include <assert.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>


struct Address {
  int id;
  int set;
  char *name;
  char *email;
};

struct Connection *Database_open(const char ) {
  struct Connection *conn = malloc(sizeof(struct Address));

if(!conn)
  printf("Failure: Memory Error\n");

}

int main(int argc, char *argv[]){ // you cant pass numbers immediately as the first arguments given function limitations
  if(argc != 3)
    printf("Need name email id set as arguments\n");

  char *filename = argv[1];
  char action = argv[2][0];

  struct Connection *conn = Database_open(filename, action);

  char *id = argv[1]; // set teh value ~> why if *id is id instead, there's a segfault? no allocation in RAM...
  char *set = argv[2]; // set the value ~> without the asterisk, it's just a sing value assingment
  char *name = argv[3]; // set the address
  char *email = argv[4]; // set the address

  struct Address who = { id, set, name, email };

  printf("\tId: %s\n", who.id);
  printf("\tSet: %s\n", who.set);
  printf("\tName: %s\n", who.name);
  printf("\tEmail: %s\n", who.email);

  return 0;
}