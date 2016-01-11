// exercise to covnert the program to not user pointers and malloc

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name; 
  int age; 
  int height; 
  int weight;
};

void Person_print(struct Person who) {
  printf("Name: %s\n", who.name);
  printf("\tAge: %d\n", who.age);
  printf("\tHeight: %d\n", who.height);
  printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[]) {
  // struct structName NAME = {blah, ...};
  struct Person joe = {"Joe Alex", 32, 64, 140};

  struct Person frank = {"Frank Blank", 20, 72, 180};

  Person_print(joe);
  Person_print(frank);

  joe.height -= 2;
  joe.weight += 40;
  Person_print(joe);

  frank.age += 20;
  frank.weight += 20;
  Person_print(frank);


  return 0;
}