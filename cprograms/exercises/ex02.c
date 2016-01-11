// makefiles = it has *implied dependencies* and *ancient lore*
// make is a rules engine where given a target by a NAME,
// look any number of similar files with the name but a different extension
// there is a specifier that tells WHEN a file is under X name THEN run Y command
// make file = manually specificies IMPLIED DEPENDENCIES (ex1 -> ex1.c)

// make file = a RULES ENGINE  / PRODUCTION RULEconsisting of a SET OF VALIDATIONS / SET OF CONDITIONAL TESTS that $raise an ERROR if the validation is false

// you can also use make to set options TO the makefile (ie. add some extra flags). in other words, you can create implied dependencies (if-thens) || 
/*

clean: // this identifier depends on
  rm -f ex1
*/

// overall, makefiles are for:
// 1) setting options (via .... CFLAG of sorts???)
// 2) implied dependencis / creating dependencies
// 3) ancient lore (it knows general utility scripts for C)

// what do you do when you execute make? like in...
// make ex1
// "i am telling make that i want a file named ex1 to be created"
// 1) is there a file that's called ex1? 
// 2) no, is there another file that starts with ex1?
// 3) yes, does this make file know how to build executable files? 
// 4) yes, it's cc ex1.c -o ex1

// what are CFLAGS?
// these are ENVIRONMENT VARIABLES (dynamic named [fixed] values || constants ) that enable you to specify %additional_switches to to be passed to the %compiler in the process of building computer software
// as you run the process, the program PICKS UP these $environment_variables that %modifies their behavior

// how do you %pass modifiers into thte MAKEFILE? via CFLAGS="-Wall" for examlple