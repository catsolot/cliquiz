#ifndef DB
#define DB
#include <stdio.h>
#include <sqlite3.h>

struct db_response {
    char* name;
    char* question;
    char* hints;
};

struct db_response* get_response(sqlite3 * db);

#endif
