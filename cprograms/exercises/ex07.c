// !STUDY-CLANG: PRINTING
// include the header file called stdio (standard input / output), which contains a set of functions, including printf
#include <stdio.h>

// return an integer via the main function, using argc and argv arguments
int main (int argc, char *argv[])
{

  // integer called distance assign 100
  int distance = 100;
  // floate called power where you assign 2.345
  float power = 2.345f;
  // double (big float) called super_power where you assign 5... (no need for f)
  double super_power = 56789.4532;
  // char called initial where you assign R
  char initial = 'R';
  // char called first_name[] which is an array, where you assign "Kenn"
  char first_name[] = "Kenn";
  // char called last_name[] which is an array, where you assign "Costales"
  char last_name[]= "Costales";

  // go past the end of the array to make the initial disappear
  // using the pointer of the first name... move right past th eindex of of it and reset into something else
  // if you set it to someting within the arrya, the
  // C terminates its strings with a nul_byte...
  // if you use an index within the array, then that will remove the nul_byte and the print functions will #trample over the $ram and #print whatever's there
  // in general, assume the computer will cause bad things... to forecast how these bad things will happen, and how can u cause them to happen
  // ALL SORTS OF THINGS CAN HAPPEN WITH STRINGS.. change indexes and stuff || craft bad srings & mess with pointers (+100 after variable calls)
  // messing with pointers with small added values make the var disappear. if it's a very big positive number, you get a segmentation fault
  // subtractin gives ??? (searches in RAM??)... also gives a segfault if big enough
  // on bad strings, if it's big enough, it segfaults. if just 1 right after the length of the string, it replaces it
  // if it's exactly at the end of the string, the print will #trample over $ram and #pritn whatever's there
  //first_name[5] = 'Z';

  // print You are X miles away, where X is a format sequence with distance as its value
  printf("You are %d miles away\n", distance);
  // print You are F miles away, where F is a format sequence with power as it value
  printf("You have %f levels of power\n", power);
  // print You are F awesome super powers away, where F is a format sequence with super_power as its value
  printf("You have %f awesome super powers\n", super_power);
  // print I have a C initial, where C is a char format sequence with inital as its value
  printf("I have a %c initial\n", initial);
  // print I have C first name, where S is a string format sequence with first_name as its valeu
  printf("I have %s first name\n", first_name); 
  // print I have C last name, where S is a string format sequence with last_name as its value
  printf("I have %s last name\n", last_name);
  // print My whoel name is S C S, where S are string format sequences and C is a char format sequence
  printf("My full name is %s %c %s \n", first_name, initial, last_name);

  // initialize an integer called bugs where you assign value 100
  int bugs = 100;
  // initialize a double called bug rate where you assign value 1.2
  double bug_rate = 1.2;  

  // print You have %d bugs with th eimaginary growth rate of %f
  printf("You have %d bugs with the imaginary growth rate of %f \n", bugs, bug_rate);
  // initialize a long variable called universe_of_defects where you assign the value of the product of 1, 1024, 1024, nad 1024
  // if it's too big, then it says "it's too large to be represented in any data type"
  long universe_of_defects = 1L * 1024L * 1024L * 1024L;
  // print The entire universe has %ld bugs, where %ld is a LONG DIGIT WITH of value of blah
  printf("The entire universe has %ld bugs\n", universe_of_defects);
  // initialize a double where its value is assigned to %f bugs
  double expected_bugs = bugs * bug_rate;
  // print You are expected to have %f bugs, where %f is a float format sequence with expected_bugs as its value
  printf("You are expected to have %f bugs\n", expected_bugs);
  double part_of_universe = expected_bugs / universe_of_defects;
  printf("That is only an %e portion of the universe\n", part_of_universe);
  
  // demo of something weird
  // this usually means 0 => converted a nul_byte to 0
  char nul_byte = '\0';
  int care_percentage = bugs * nul_byte;

  printf("Therefore you should care %d%%.\n", care_percentage);

  return 0;
}