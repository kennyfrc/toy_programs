#include <stdio.h>

int main(int argc, char *argv[]){

  // makes your code much more reliable
  // it's not "slower". good compilers will default it to 0 and you'll be set.
  int i = 0;

  // go through each string in argv
  // the intializer is code that's set up to run the for loop, which in this case is i = 1
  // intiializer = code that's run to set up the loop
  // by setting the test == 0 (false), then you will SKIP the for loop
  for (i = 1; i < argc; i++){
    printf("arg %d: %s\n", i, argv[i]);
  }

  // let's make our own array of strings
  // you're making an array of strings. you are initializing each string in that array
  // what you're creating here is a 2-dimensional array, where dimension 1 is each element of the array (words), then dimension 2 is each subelement of that element (chars)
  char *states[] = {
    "California", "Oregon",
    "Washington", "Texas"
  };

  int num_states = 4;

  // avoid the off by one error.. what does it do..? it will create an extra state that's empty
  // using a comma in a for loop is equivalent to OR
  // (ie. if you use i < num_states, i < 2), then it wil only evaluate until state 2
  for (i = 0; i < num_states; i++){
    printf("state %d: %s\n", i, states[i]);
  }

  return 0;
}