// !STUDY-CLANG: FORWARD-DECLARATIONS

#include <stdio.h>
#include <ctype.h>

// forward declarations
// the C compiler is designed to read line by line. int he old days, there wasn't enough CPU memory to load whole files
// so you had to #tell C what functions are coming up later.. you #declare that you will do X function later 
// and you will define it later on
// instead of doing forawrd declartions, it may be easier to just do a header file...
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[]) {

  int i = 0;

  for(i = 0; i < argc; i++){
    print_letters(argv[i]);
  }
}

// how does strlen work? usually works by counting the characters in a string until a \0 character is found. 
void print_letters(char arg[]){

  int i = 0;

  for (i = 0; arg[i] != '\0'; i++){
    char ch = arg[i];

    if (can_print_it(ch)) {
      printf("'%c' == %d \n", ch, ch ); // %d here prints the ASCII equivalent of the number
    }
  }

  printf("\n");
}

int can_print_it(char ch) {
  return isalpha(ch) || isblank(ch);
}

// the main is calling a lot of thigns
// it calls print_arugments, print_letters, and can_print_it
int main(int argc, char *argv[]){
  print_arguments(argc, argv);
  return 0;
}