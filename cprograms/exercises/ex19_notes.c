#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>


void test_debug() {
  // you don't need the \n anymore
  debug("I have brown hair.\n");

  // you don't need to pass arguments like printf
  // debug() provides a log msg when debugging 
  debug("I am %d years old", 37);
}

void test_log_err() {
  log_err("I believe everything is broken.");
  log_err("There are %d problems in %s", 0, "space");
}

void test_log_info() {
  log_info("Well, I did something mundane.");
  log_info("It happened %f times today", 1.3f);
}

int test_check(char *file_name) {
  // assign null into the file pointer
  FILE *input = NULL;
  // assign null into a char pointer
  char *block = NULL;

  block = malloc(100);
  check_mem(block);

  // assign a read file name into input
  input = fopen(file_name, "r");
  // call check() with an input and a string
  check(input, "failed to call %s", file_name);

  // free the malloc'd memory
  free(block);
  // close the file
  fclose(input);
  // terminate the function
  return 0;

  // error keyword
  error:
  // if block address is strue then free the block
  if(block) free(block);
  // if file is stil there then close it
  if(input) fclose(input);
  // make sure that the program exits with an error
  return -1;
}

// call test_sentinel function with an integer called code
int test_sentinel(int code){
  // allocate a hundred bytes to a char called temp
  char *temp = malloc(100);
  // check the memory of temp
  check_mem(temp);

  // check code... if it's true then print a log that it worked then break it
  // as a default, call sentinel with "i shouldn't run" string
  switch(code) {
    case 1:
      log_info("It worked");
      break;
    default:
      sentinel("I shoudn't run");
  }
  // free the memory in temp
  free(temp);

  // error if temp still exists, free it. 
  error:
    if(temp)
      free(temp);
    return -1;
}

// call a test_check_mem function that returns an int
int test_check_mem() {
  // assign a NULL address to a test character pointer
  char *test = NULL;
  // check the memory of test
  check_mem(test);

  // free the memory allocated to test
  free(test);
  // terminate the program IF it runs successfuly
  return 1;

  // else, call an error if it doesn't
error:
  return -1;
}

// create a check_test_debug function that returns an int
int check_test_debug(){
  int i = 0;
  // call check_debug with a condition and input and a string input
  check_debug(i != 0, "Oops I was 0");

  // terminate the program successfully
  return 0;
error:
  return -1;
}

int main(int argc, char *argv[]) {
  // call a check functionw ith condition and string arguments
  // the check macro runs each test function
  check(argc == 2, "Need an argument");

  // call test debug, test log error, test log warn, test log info
  test_debug();
  test_log_err();
  test_log_warn();
  test_log_info();

  // asserts that it's true 
  // check is a version of asserts that #combines the practice of assertion && #printing the messsage when it's not && recording the lien where it happened && jump to clean up
  // these have results
    // assert == check
  check(test_check("ex19.c") == 0, "failed with ex19.c");
  check(test_check(argv[1]) == -1, "failed with argv");
  check(test_sentinel(100) == 0, "test sentinel failed");
  check(test_sentinel(1) == 0, "test sentinel failed");
  check(test_check_mem() == -1, "test_check_mem failed");
  check(test_check_debug() == -1, "test_check_debug failed.");

  return 0;

error:
  return 1;
}