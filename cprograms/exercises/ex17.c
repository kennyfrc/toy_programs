// !STUDY-CLANG: DATABASE-FILE

#include <stdio.h> // standard input / output
#include <assert.h> // condtionally complied macro that compares its argument to zero
#include <stdlib.h> // general utilities: memory management, program utilities, string conversions, random numberes
#include <errno.h> // macros reporting error conditions
#include <string.h> // string handline 

// one of the ways to type code...
// just do a little bit at a time
// first, do structures and make sure they compile + a fake main function
// second, play with low dependency functions + then use the main to run them

#define MAX_DATA 512
#define MAX_ROWS 100

// heap vs stack: anytime you call malloc, that's heap. everything else is a stack. (easiest way to descibe it)
// just worry about the heap || everything else is going to be a static allocaiton / stack

// create a struct with id, set, name, email
struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database {
  struct Address rows[MAX_ROWS];
};

struct Connection {
  FILE *file; // FILE == type, capable of holding all information needed to control an I/O stream
  struct Database *db;
};

void die(const char *message) {
  // errno == macro || when you have an $error #return from a $function
  // it will usually #set an $external_variable called $errno to say exactly
  // what happened
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1); // causes "normal program termination".. but why is there a need toa dd this? because this is an error handler
}


void Address_print(struct Address *addr) {
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn) {
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
    die("Failed to load database");
}

struct Connection *Database_open(const char *filename, char mode) {
  struct Connection *conn = malloc(sizeof(struct Connection)); // when do #call $database_open, you are #making a $structure with $malloc. that's a $heap
  // when you do malloc hwere, the structure is composed of a Connection, that has a $pointer to $Address (*db), and the database has NO pointer.. instead
  // it has a full $array of $address_elements
  // it's *just* a pointer therefore we need to malloc it. now once we malloc, we actually malloc the Database and 100 Addresses which has a 512 name and 512 email + 2 ints => this is a full, huge chunk of RAM. it's not malloc.
  if (!conn)
    die("Memory Error");

  conn->db = malloc(sizeof(struct Database));
  if (!conn -> db)
    die("Memory Error");

  if (mode == 'c') {
    conn->file = fopen(filename, "w"); // opens a file and returns a $pointer to the $file_stream associated with that file (inputs: file & mode)
    printf("%p has been generated \n", conn->file);
  } else {
    conn->file = fopen(filename, "r+");
    
    if (conn->file) {
      Database_load(conn);
    }  
  }

  if (!conn -> file)
    die("Failed to open the file");

  return conn;
}

void Database_close(struct Connection *conn) {
  if (conn) {
    if (conn->file)
      fclose(conn->file);
    if (conn->db)
      free(conn->db);
    free(conn);
  }
}

void Database_write(struct Connection *conn) {
  rewind(conn->file); // moves the position indicator to the beginning of the file stream

  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
    die("Failed to write database.");

  rc = fflush(conn->file);
  if (rc == -1)
    die("Cannot flush database.");
}

void Database_create(struct Connection *conn) { 
  int i = 0;

  for (i = 0; i < MAX_ROWS; i++) {
    // make a prototype to initialize it
    struct Address addr = {.id = i, .set = 0}; // this is on the stack because it has no pointer. if i use malloc, it's heap. if i don't use malloc, it's stack
    // stack == funciton itself has a chunk of RAM that's called the stack.. it stores the int and the struct
    // when the function exists, the memory gets #automatically cleaned up... no need to free the memroy

    // then just assign it
    conn->db->rows[i] = addr;
  }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) {
  struct Address *addr = &conn->db->rows[id];
  if (addr->set)
    die("Already set, delete it first");

  addr->set = 1;
  // WARNING: bug, read the "how to break it and fix this"

  char *res = strncpy(addr->name, name, MAX_DATA);

  // demonstrate the strncpy bug
  if (!res)
    die("Name copy failed");

  res = strncpy(addr->email, email, MAX_DATA);
  if (!res)
    die("Email copy failed");
}

void Database_get(struct Connection *conn, int id) {
  struct Address *addr = &conn->db->rows[id]; // & gives you the address... so retrieve the value then get the address of it

  if (addr->set) {
    Address_print(addr);
  } else {
    die("ID is not set");
  }
}

void Database_delete(struct Connection *conn, int id) {
  struct Address addr = {.id = id, .set = 0}; // since you didn't malloc over it, the program just overwrote it
  conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn) { // if you don't use a pointer, you will #pass a full $structure. it will #take over a bunch of the function call stack / takes more space. it will also be copied onto the stack. ||| call by value vs call by reference
  int i = 0;
  struct Database *db = conn->db;

  for (i = 0; i < MAX_ROWS; i++) {
    struct Address *cur = &db->rows[i];

    if (cur->set) {
      Address_print(cur);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3)
    die("USAGE: ex17 <dbfile> <action> [action params]"); // without this, it segfaults (why? because it's trying to read something that doesn't exist)

  char *filename = argv[1];
  char action = argv[2][0];
  struct Connection *conn = Database_open(filename, action);
  int id = 0;

  if (argc > 3) id = atoi(argv[3]);
  if (id >= MAX_ROWS) die("There's not that many records");

  switch(action) {
    case 'c':
      Database_create(conn);
      Database_write(conn);
      break;
    case 'g':
      if (argc != 4)
        die("Need an id to get");

      Database_get(conn, id);
      break;
    case 's':
      if (argc != 6)
        die("Need id, name, email to set");

      Database_set(conn, id, argv[4], argv[5]);
      Database_write(conn);
      break;
    case 'd':
      if (argc != 4)
        die("Need id to delete");

      Database_delete(conn, id);
      Database_write(conn);
      break;
    case 'l':
      Database_list(conn);
      break;
    default:
      die("Invalid action: c=create, g=get, s=set, d=del, l=list");
  }

  Database_close(conn);

  return 0;
}