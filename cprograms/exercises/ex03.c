// include standard input / output functions $HEADER_FILE (one of which is print f)
#include <stdio.h>

// this main funciton should return an $int, with argc count of arguments and an array of char strings for the arguments
int main(int argc, char *argv[])
{
  // set some integers
  int age = 10;
  int height = 72;

  // print the values using a format strings (ie. strings with placeholders)
  printf("My age is %d\n", age);
  printf("My height is %d cm tall\n", height);

  return 0;
}