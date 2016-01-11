// !STUDY-CLANG: POINTERS

#include <stdio.h>

int main(int argc, char *argv[]){

  // create two arrays that we care about
  int ages[] = { 23, 43, 12, 89, 2}; // a container which has a bunch of things in it || container == 1 solid block of memory
  // what is a pointer? so it's not a container like above. rather, it's a block of memory, which each $element containing $addressses
  // that point to another block of memory which contains the names
  // it's *almost* like a hash map of 0,1,2,3 to strings || it's a block of ram that points to more ram
  // this does not have the size of all the strings concatenated together. it's wrong. 
  char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
  };

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way using indexing
  for (i = 0; i < count; i++){
    printf("%s has %d years alive.\n", names[i], ages[i]);
  }

  printf("-----\n");

  // set up the pointers to the start of the line
  // ages = [] | <- cur_age pointer
  int *cur_age = ages;
  // string names <- names pointer = [] | <- cur_name pointer1 and pointer2 (you need 2 stars to point first at names then to the strings)
  char **cur_name = names;

  // second way using pointers
  for(i = 0; i < count; i++){
  // below points to an address (address in names) and (the actual content in age)
  // however, this is generally bad syntax.. it is equivalent to the 3rd wway, which is...
    printf("%s is %d years old\n", *(cur_name + i), *(cur_age + i));
  }

  printf("-----\n");

  // third way, pointers are just arrays
  for(i = 0; i < count; i++){
  // pointers are just arrays! jump by i amount, then lookup the value or address
  // this is the slowest IF the $complier can't #optimize it or the $complier optimizes it wrong
    printf("%s is %d years old again\n", cur_name[i], cur_age[i]);
  }

  printf("-----\n");

  // fourth way with pointers in a stupid complex
  for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_age++, cur_name++) {
    printf("%s lived %d years so far\n", *cur_name, *cur_age);
  }

  return 0;
}

// 1) type *ptr || A pointer of type named ptr ||this is a reference
//  int *cur_age = ages; // i want a pointer of type integer, and point it at the beginning of ages
//  char **cur_name = names;
// the $computer is just a gigantic array of $bytes... the $RAM parks in it and it has a bunch of addresses which contain data types (eg. int height) [the variable declartion is the $actual_piece_of_ram]
// the $pointer_declaration is the array index / address of where that piece of ram is / grabbing an indirection
// you're essentially pointing to an address

// 2) *ptr || The value of whatever ptr is pointed at || this gets the value of
// if it's just (cur_Name +i ) == you get the address itself
// if it's *(cur_name +i) == you get the actual value

// 3) *(ptr + i) || The value of (whatever ptr is pointed at plus i)
// => the better way is to use it like an array... cur_name[i]

// 4) &thing || address of a thing
// int height = 100;
// int *cur_height = &height; (you can only do 'without' & if the object pointed at is an array) || so it's the opposite of *ptr

// 5) ptr++ increment where pointer points (the address)


// an array is pretty much a pointer | you can treat them like pointers. you can treat arrays as pointers and pointers as arrays | C strings are pointers to an array of characters. names is an array of character pointers (strings) it is not an array of cahracters. that's WHY if you remove the nul_byte, or if you access an address beyond that, it will #blow past the $RAM until it dies