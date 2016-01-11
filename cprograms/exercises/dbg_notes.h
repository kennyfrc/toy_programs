// defend against accientally using the file twice
#ifndef __dbg_h__ // IF YOU DIDN'T DEFINE THIS in the prgram... 
#define __dbg_h__ // .. then define this


#include <stdio.h>
#include <errno.h>
#include <string.h>

// an ifdef that enables you to recompile your program so that all of the debug log messsage are moved
#ifdef NDEBUG // IF YOU DEFINED NDEBUG in the program... i don't want debugging, therefore the below stuff gets disabled
#define debug(M, ...) // if you defined NDEBUG, then you execute this..
#else
// an alternative #define_debug that translates ANY use of $debug(format, arg1, arg2) into an $fprint_call to $stderror
// some compilers don't support this, but the ones that matter do.
// the magic here is the use of ##__VA_ARGS__ that says "put whatever they had for extra arguments here"
// __FILE__ and __LINE__ is for the debug message
// stderr as part of FILE I/O
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n" ,\
        __FILE__, __LINE__, ##__VA_ARGS__) 
#endif
// ELSE IF NOT.. then you have a nicely defined printf


// get a safe, readable version of errno
#define clean_errno() (errno == 0 ? "None" : strerror(errno))


// these logs are $macros for $logging_messages that are meant for teh enduser. they work like debug but can be compiled out.
// this is more for users themselves...
#define log_err(M, ...) fprintf(stderr,\
        "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__,\
        clean_errno(), ##__VA_ARGS__) // variatic print f

#define log_warn(M, ...) fprintf(stderr,\
        "[WARN] (%s:%d: errno: %s) " M "\n",\
        __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n",\
        __FILE__, __LINE__, ##__VA_ARGS__)

// asserts if A is false, then logs the error M (with variable arguments for log_err), then jumps to error: for cleanup
#define check(A, M, ...) if(!(A)) {\ // it's an assert // tests A if it becomes false and if so, then logs an error and goes t the error handler 
    log_err(M, ##__VA_ARGS__); errno=0; goto error; } // sets 0 to errno (if your error handler needs to set errno, then yo ushould), and goes to the error
// the check macro replaces this code in the original ex19.c
    // open and read a file and assign it to input
    // input = fopen(file_name, "r")
    // if(input == NULL) {
    //   printf("Failed to open %s\n", file_name);
    // // goto error
    //   goto error;
    // }  
//     int test_check(char *file_name)
// {
//       // assign null into the file pointer
//     FILE *input = NULL;
//       // assign null into a char pointer
//     char *block = NULL;

//     block = malloc(100);
//     check_mem(block);   // should work

//   // assign a read file name into input
//   // call check() with an input and a string
//     input = fopen(file_name, "r");
//     check(input, "Failed to open %s.", file_name);

//     free(block);
//     fclose(input);
//     return 0;

// error:
//     if (block) free(block);
//     if (input) fclose(input);
//     return -1;
// }

// #mark a $chunk_of_code that shouldn't happen, if it does, jump to an error label
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__);\
    errno=0; goto error; } // log an error and #goto the $error

// int test_sentinel(int code)
// {
//     char *temp = malloc(100);
//     check_mem(temp);

//     switch (code) { // if you get a code input that you didn't anticipate, then it shows a message that you shouldn't pass X input
//         case 1:
//             log_info("It worked.");
//             break;
//         default:
//             sentinel("I shouldn't run.");
//     }

//     free(temp);
//     return 0;

// error:
//     if (temp)
//         free(temp);
//     return -1;
// }

// check if the memory is there after malloc. if not, shoot a message that says out of memory.
#define check_mem(A) check((A), "Out of memory.")

// a version of check. where you don't want to log the message in production... just want to clean up.. just a soft error and try something ELSE. you won't see a debugging message unless you have $debug on
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__);\
    errno=0; goto error; }

#endif
