// !STUDY-CLANG: CASES

#include <stdio.h>

int main(int argc, char *argv[])
{
  // if argc is NOT 2, then it fails
  if (argc != 2){
    printf("ERROR: You need one argument\n");
  // to abort a program, use return 1;
  return 1;
  }

  // initialize an integer called i and assign it to 0
  int i = 0;

  // for i = 0, while each character in name is NOT a nul byte, execute Y code and increment by 1
  // argv[1][i] is about taking the 2nd argument and then taking each letter of it
  // argv[1][i] means you should process each character until you #hit the $nul_byte at the end of the string
  for (i = 0; argv[1][i] != '\0'; i++) {

    // assign each letter as a char named letter
    char letter = argv[1][i];

    // switch statements... work by calculating integers.. it then takes that number and looks at the set of constants, and if it's equal to the constant, then it #jumps to the code.. .then it runs until it meets a break, afterwhich it leave the switch statement
    // example.. you start with A, then it gets translated into some ascii number and it will jump ahead to X many bytes to its letter
    // it's a controlled goto based on an integer
    // you can't 'case' expressions in C.. you can only do constants
    // switch statements in C are different vs other languages in teh sense that it's like a jump table... instead of boolean values, u can only put 
    // expressions that result in integers
    switch(letter){
      case 'a':
      case 'A':
        printf("%d: 'A'\n", i);
        break;

      case 'e':
      case 'E':
        printf("%d: 'E'\n", i);
        break;

      case 'i':
      case 'I':
        printf("%d: 'I'\n", i);
        break;
      case 'o':
      case 'O':
        printf("%d: 'O'\n", i);
        break;
      case 'u':
      case 'U':
        printf("%d: 'U'\n", i);
        break;
      case 'y':
      case 'Y':
        if (i > 2){
          printf("%d: 'Y'\n", i);
        }
        break;

      default:
        printf("%d: %c is not a vowel\n", i, letter);
    }
  }


}