// !STUDY-CLANG: BUBBLE-SORT ALGORITHMS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

// a typedef creates a fake type. in this case, for a function pointer
// #creates a $new_Type, which is a poitner to a fucntion => compare_cb // compare callback

// process:
// find a function where you want to put pointers to
// 1) int reverse_order(int a, int b) || you start here
// 2) typedef int (*reverse_order)(int a, int b);
// 3) typedef int (*comapre_cb)(int a, int b); || now it's a function pointer

// another type:
// 1) char *say_my_name(char *name);
// 2) char *(*say_my_name)(char *name);
// note char * == return value type of the $function
// 3) typdef *(*say_cb)(char *name); || function pointer
typedef int (*compare_cb) (int a, int b);


// classic bubble sort function that uses compare_cb to do the sorting
int *bubble_sort(int *numbers, int count, compare_cb cmp){ // a function pointer allows you to pass a function by nameto another function 
// this makes the bubble_sort to become generic
// however, this is an inefficient way to sort integers
// initialize some base vars
  int temp = 0;
  int i = 0;
  int j = 0;
  int *target = malloc(count * sizeof(int)); //new array of integers on the $heap using $malloc [count the size of integers here]

  if (!target)
    die("Memory Error");

  memcpy(target, numbers, count * sizeof(int));

  // for each i in i.count, do X
  for (i = 0; i < count; i++) { // you need 5 counts to get the all the cycles completed (there are COUNT elements)
    printf("i: %d\n", i);
    printf("-------\n");
    // for each j in i.count - 1, do Y
    for (j = 0; j < count - 1; j++) { // this is to move the numbers from left to right (there are [count - 1] GAPS)
      printf("j: %d\n", j);
      printf("compare: target[j] of %d && target[j + 1] of %d \n", target[j], target[j + 1]);
      printf("-------\n");
      // call the sort instruction and check if it's in order (< 0) or if it's not in order (> 0)
      if (cmp(target[j], target[j + 1]) > 0) { // because if it's less than 0, it's OK an dit's in the right order
        printf("target[j] now: %d\n", target[j]);
        // just cycle the between target[j] and target[j + 1]
        // printf("target[j] %d\n", target[j]);
        // printf("target[j + 1] %d\n", target[j + 1]);
        // printf("=================base\n");
        // if you take the target address and the next address and apply the sort and you check that it's indeed 0...
        temp = target[j + 1];
        // printf("temp is now: %d\n", temp);
        // you apply the next target to temp
        target[j + 1] = target[j];
        // printf("target[j + 1] is now: %d\n", target[j + 1]);
        // you you apply the base target to the origin target
        target[j] = temp;
        // printf("target[j] is now: %d\n", target[j]);
        // printf("=================sorted\n");
        // printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("target[j] FIXED: %d\n", target[j]);
      }
    }
  }

  return target;
}

int sorted_order(int a, int b){
  // if((a - b) < 0) {
  //   printf("a - b: %d NOT OK!\n", a - b);
  // } else {
  //   printf("a - b: %d OK!\n", a - b);
  // }
  return a - b;
}

int reverse_order(int a, int b){
  // if((b - a) < 0) {
  //   printf("b - a: %d NOT OK!\n", a - b);
  // } else {
  //   printf("b - a: %d OK!\n", a - b);
  // }
  return b - a;
}

int strange_order(int a, int b){
  if (a == 0 || b == 0) {
    return 0;
  } else {
    return a % b;
  }
}

// what is a function callback? it's a way for you to #pass a function to another function

// used to test that we are sorting things correctly
// by doing the sort and printing it out

void test_sorting(int *numbers, int count, compare_cb cmp) { // pass the comparator to
  int i = 0;
  // calls bubble sort and sets that call into a sorted pointer
  int *sorted = bubble_sort(numbers, count, cmp); // calls bubble sort

  if (!sorted)
  // check if sorted pointer is NULL then you return a die function
    die("Failed to sort as requested"); // make sure it works

  for(i = 0; i < count; i++) {
  // for each i in count, you print the $value of the bubble sort
    printf("%d ", sorted[i]);
  }
  // add a new line
  printf("\n");
  // free the data after the sorted *sort
  free(sorted);
}

void dump(compare_cb cmp) {
  int i = 0;
  unsigned char *data = (unsigned char *)cmp; // dump is going to #cast the $fucntion_pointer to an $unsigned_character_pointer

  for(i = 0; i < 25; i++){ // then go through the first 25 bytes and print it out (data[i])
    printf("%02x:", data[i]); // puts the executable RAM in character data 
  }

  printf("\n");
}
// use the cmp as an argument tot he desetroy function
// void destroy(compare_cb cmp) {
//   int i = 0;
//   // convert the $function to a $string. and then for each address in that string, you overwrite 
//   unsigned char *data = (unsigned char *)cmp; // dump is going to #cast the $fucntion_pointer to an $unsigned_character_pointer (changing the data type)
//   // you then try to overwrite the address' address with i // just something to F up the data
//   for(i = 0; i < 25; i++){ // then go through the first 25 bytes and print it out (data[ii)
//     data[i] = i; // we're using the data pointer to overrite the code for whatever compare function we havee and replace it iwth numbers
//   } // lots of operating systems are not protected from code || some have protection of executable code and you can't just overwrite functiosn
//   // significance: one of the major hacks / C is to take a pointer, re-point it to a function, and overwrite it to add malicious stuff
//   // find a spot in RAM and you make a way to point a function pointer at that code

//   printf("\n");
// }

int main(int argc, char *argv[]) {
  if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;

  int *numbers = malloc(count * sizeof(int));
  if (!numbers) die("Memory Error");

  for (i = 0; i < count; i++) {
    numbers[i] = atoi(inputs[i]);
  }

  printf("SORTED ORDER!!!!\n");
  test_sorting(numbers, count, sorted_order);
  printf("REVERSE ORDER!!!!\n");
  test_sorting(numbers, count, reverse_order);
  printf("STRANGE ORDER!!!!\n");
  test_sorting(numbers, count, strange_order);

  free(numbers);

  // printf("SORTED:");
  // dump(sorted_order);
  // destroy(sorted_order); // bus error: 
  // printf("REVERSED:");
  // dump(reverse_order);

  return 0;
}