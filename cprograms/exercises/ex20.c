#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb) (int a, int b);

/**
 * A classic bubble sort function that uses the 
 * compare_cb to do the sorting. 
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if (!target)
        die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/** 
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);

    if (!sorted)
        die("Failed to sort as requested.");

    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);
}


void dump(compare_cb cmp)
{
    int i = 0;

    check(cmp != NULL, "Invalid function ptr to dump.");
    unsigned char *data = (unsigned char *)cmp;

    for(i = 0; i < 25; i++) {
        printf("%02x:", data[i]);
    }

    printf("\n");

error:
    printf("\n");
}

//use the cmp as an argument tot he desetroy function
void destroy(compare_cb cmp) {
  int i = 0;
  // convert the $function to a $string. and then for each address in that string, you overwrite 
  unsigned char *data = (unsigned char *)cmp; // dump is going to #cast the $fucntion_pointer to an $unsigned_character_pointer (changing the data type)
  // you then try to overwrite the address' address with i // just something to F up the data
  for(i = 0; i < 25; i++){ // then go through the first 25 bytes and print it out (data[ii)
    data[i] = i; // we're using the data pointer to overrite the code for whatever compare function we havee and replace it iwth numbers
  } // lots of operating systems are not protected from code || some have protection of executable code and you can't just overwrite functiosn
  // significance: one of the major hacks / C is to take a pointer, re-point it to a function, and overwrite it to add malicious stuff
  // find a spot in RAM and you make a way to point a function pointer at that code

  printf("\n");
}


int main(int argc, char *argv[])
{
    if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error.");

    for (i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);

  printf("SORTED:\n");
  dump(sorted_order);
  destroy(sorted_order); // bus error: 
  printf("REVERSED:\n");
  dump(reverse_order);

    return 0;
}
