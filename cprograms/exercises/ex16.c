// !STUDY-CLANG: STRUCTS && POINTERS

// ptr->elem || Use ptr to struct/union to get element

// basic functionality -> initialize a struct, then call a set of functions on it 
// drawing out the struct -> 
// [ (pointer of name) (stuff to store age) (stuff to store math)]

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name; // c tries to pack these vars in into 1 piece of RAM. it's like an array but you don't index it with integers. rather, you index it by name.
  int age; // note that these things are addresses to the actual value / actual data stored
  int height; // you can then reference them via kenn->weight
  int weight;
};

// to get access to the stuff, you use dot (like a method)... like when struct Person kenn => kenn.name => to get the name

// function Person_create
struct Person *Person_create(char *name, int age, int height, int weight)
{
  struct Person *who = malloc(sizeof(struct Person)); // malloc == pls give me a new piece of memory
  // pass to malloc the sizeof(struct Person)which calcs the total size of the structure
  // what malloc does || you work with pointers because you want to use this new X called malloc. what malloc does is that it's a memory allocator || i want a $chunk of $RAM that i can store and  keep around that's the $sizeof(struct Person) => the size of every individual component and adds it up
  // a Person structure
  // then malloc returns a pointer (*who)
  // malloc just knows a chunk of RAM and it has X chunk of size
  // this tells the operating system to give me a chunk of RAM
  // when it checks the sizeof the STruct, it checks every individual component and adds it up
  assert(who != NULL); // assert to make sure that you have a valid piece of memory back from malloc
  // assert basically aborts if the condition is false (ie. i want to #assert that this is $true)

  // you cannot do who.name because *who is a pointer. you can only do that kind of reference for structs
  // instead, what you should do is who->name
  // what is strdup? it copies the string in the same malloc stype and assigns its address (will probably help if the arg is some pointer)
  // what does it mean to malloc something? we're #making a $chunk_of_RAM... so now we can #free the $chunk_of_RAM. the reason why
  // we want to free it is that the oeprating system has limited memroy. if you are #creating a bunch of $ram objects, eventually you'll need to delete them
  // in a programming language like python / ruby, you don't need to 'free' it beccause there's something called a $garbage_collector. 
  // freeing the $ram is what person_destroy does
  // initialization below
  who->name = strdup(name); // use strdup to make sure that this structure actually owns it
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
};

void Person_destroy(struct Person *who) {
  assert(who != NULL); // this asserts that X is true
  free(who->name); // yo uare trying to access ram here. if who is $NULL, then it just blows up
  free(who); // if you do not free memory, then you have a $memory_leak

  // why do you need to 'free memory?' malloc takes up dynamic memory so you need to free it to allow other vars to use it
  // so when we destroy a var, you need to free up memory manually
  // EXC_BAD_ACCESS = memory mismanagement
}

// what causes segfaults? this happens whenever you are trying to read or write an illegal memory location
// || occurs when a reference to a variable falls outside teh segment where the variable resides
// || when a write is attempted to a location that is in read-only segment
// program memory is divided into multiple parts:
// 1) text segment for program instructions
// 2) data segment for variables and arrays defined at compile time
// 3) stack segment for temporary (or automatic variables) defined in subroutines and functions
// 4) heap segment for variables allocated durign runtime by functions such as malloc()

// \t is an escape character that moves indents a line by a tab
void Person_print(struct Person *who) {
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[]) {
  // make two people structures
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);

  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  // print them out and where they are in memory
  // %p prints out where it is in memory or the address
  printf("Joe is at memory location %p:\n", joe);
  // what happens if you pass NULL? it's a segfault because the error doesn't exist
  Person_print(joe);

  printf("Frank is memory location %p\n", frank);
  Person_print(frank);

  // make everyone age 20 years and print them again
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);

  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  // destroy them both so we clean up
  // what happens if we forget to destroy the struct? there will be a memory leak
  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}