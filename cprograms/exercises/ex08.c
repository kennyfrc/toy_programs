#include <stdio.h>

// return an integer via the main function, which has argc and argv[] arguments
// declare 2 variables for the main function
// one of them is $how_many_arugments_we_have and the other is an $array_of_character_strings
int main(int argc, char *argv[])
{
  int i = 0;

  // only ./ex8
  if (argc == 1){
    printf("You only have one variable. You suck.\n");
  } else if (argc > 1 && argc < 4) {
    printf("Here are your arguments:\n");

    for(i = 0; i < argc; i++) {
      printf("%s ", argv[i]);
    }
    printf("\n");
  } else {
    printf("You have too many arguments. You suck.\n");
  } 

  return 0;
}