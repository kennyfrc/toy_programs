// !STUDY-CLANG: PRINTING

// include = way to *import* the #contents of ONE FILE into this SOURCE FILE
// stdio.h = C has a convention of using #(.h extensions) for header files (standard IO library)
// header files = contains lists of functions to use in your program
#include <stdio.h>

// how it works: the OPERATING_SYSTEM %loads your $program and then
// it runs the $function named $main
// for the function to complete, it needs to %return an $int
// and this function takes 2 paramters: an $int for the argument count which arg
// and an $array of char *strings for the arguments
int main(int argc, char *argv[])
{
  // you need the brackets above to indicate the start of a BLOCK
  // this is a var declaration and an assignment at the same time
  // this is how u create a variable.. syntax is { type name = value;}
  // in C, statements (except for logic) end in a ; (semicolon) character
  int distance = 100;
  int agent_number = 25;

  // function call printf. but this is weird in that it can take multiple args
  // the %d format is a PLACEHOLDER where u instruct the %compiler that there is a || it's called a format string
  // integer that you want to give for TRANSLATION
  printf("Agent %d,\nYou are %d miles away.\n", agent_number, distance);

  // a $return form the MAIN function that gives the $OS your $exit_value
  // UNIX software returns codes btw
  return 0;
}