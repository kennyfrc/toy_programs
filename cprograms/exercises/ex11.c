// discusses array of things
// like arrays of chars and arrays of integers (and how they're similar)
// strings == byte arrays || only different printing functions can recognize the difference

#include <stdio.h>

int main(int argc, char *argv[]){
  // there are similartieis between arrays and strings in C
  // in modern C, you are able to start off initializing an array using a brace syntax. if it's just 1 value, then C will fill in the rest
  // integer array
  // even if you switch the values between int numbers and char name, it will output the same thing. you'll only get a warning when u try to print a string
  int numbers[4] = { 0 };
  // character array
  // only use this if you need a character buffer and you know the fixed size
  // this fills the first cahracter with a and the rst with 0. this is useful because a lot of $strings depend on things ending by $0
  char name[4] = { 'a' }; // '4' here means 'bytes'??

  // first, print them out raw
  printf("numbers: %d %d %d %d \n", numbers[0], numbers[1], numbers[2], numbers[3]);

  printf("name each: %c %c %c %c  \n", name[0], name[1], name[2], name[3]);

  printf("name: %s\n", name);

  // set up the numbers
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  // set up the name
  // without the nul byte, it will #trample all over $memory
  // C processes each character until it hits that nul terminator
  // if you use *name above, below will create a bus error... because... TBC
  name[0] = 'K';
  name[1] = 'e';
  name[2] = 'n';
  name[3] = '\0';

  // print them out uninitialized
  printf("nubmers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);

  printf("name each: %c %c %c %c \n", name[0], name[1], name[2], name[3]);

  // print name like a string
  printf("name: %s\n", name);

  // another way to use name
  // it's a pointer to an array of characters || character pointer
  char *another = "Ken";

  printf("another: %s\n", another);

  printf("another each: %c %c %c %c \n", another[0], another[1], another[2], another[3]);

  return 0;

}