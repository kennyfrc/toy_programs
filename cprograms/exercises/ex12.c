// !STUDY-CLANG: BYTES

// c treats strings as an array of bytes
#include <stdio.h>

// the thing that you need to focus on in C is the $size_of_stuff <- this is what you need to be obsessed about
int main(int argc, char *argv[]){
  int areas[] = { 10, 12, 13, 14, 20 };
  double double_blah = 234.234f;
  float float_blah = 23.23f;
  long long_blah = 23423L;
  char name[] = "Kenn";
  char full_name[] = { 'K', 'e', 'n', 'n', ' ', 'R', ' ', 'C', 'o', 's', 't', 'a', 'l', 'e', 's', '\0'};

  // sizeof returns the number of byes necessary to store this type or a varriable (or the object representation of this type)
  // it's preferable to use the type
  // array is a fixed block of memory
  // when you make an array... you're making a chunk of memory and you cut it up into little sections
  // it's one cohesive memory that's split up
  // in python, it's multiple chunks that are linked
  // if you get teh size of something which look like this: ['K' | 'e' | 'n' | 'n' | '\0' | | |], it checks teh size of EVERYTHING.
  // if you use the splat operator to define an array, like char *another = 'Kenn', it will give you the $size of the $pointer
  // C is all about the size and the location of pieces of memory, and what you do with them
  printf("The size of an int: %ld\n", sizeof(int)); // 4
  printf("The size of the areas (int[]): %ld\n", sizeof(areas)); // 20 = takes the number of elements in that array, multiplied by int (which is 4)
  printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
  printf("The first area is %d, the 2nd is %d\n", areas[0], areas[1]);

  
  printf("The size of a double: %ld\n", sizeof(double));
  printf("The size of a float: %ld\n", sizeof(float));
  printf("The size of a long: %ld\n", sizeof(long));

  printf("The size of a double blah: %ld\n", sizeof(double_blah));
  printf("The size of a float blah: %ld\n", sizeof(float_blah));
  printf("The size of a long blah: %ld\n", sizeof(long_blah));

  printf("The size of a char: %ld\n", sizeof(char));
  printf("The size of name (char[]): %ld\n", sizeof(name));
  printf("The size of chars: %ld\n", sizeof(name) / sizeof(char));

  printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
  printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));

  printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

  return 0;
}