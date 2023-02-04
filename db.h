#ifndef DB
#define DB
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include <time.h>
#include <stdlib.h>
#define DB_LENGTH 2

struct db_response {
    const char* answer;
    const char* question;
    const char* hint;
};

struct db_response* get_response(sqlite3 * db);
sqlite3 * init_database(char* filename);
#endif
