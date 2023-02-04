#include "db.h"

struct db_response* get_response(sqlite3 * db) {
    int val = rand() % DB_LENGTH;
    char st[50];
    sprintf(st, "SELECT * FROM data WHERE id = %d;", val);
    sqlite3_stmt * stmt; 
    sqlite3_prepare_v2(db, 
                       st,
                       50, 
                       &stmt,
                       NULL);

    sqlite3_step(stmt); 
    struct db_response* re = malloc(sizeof(struct db_response));
    re->answer = sqlite3_column_text(stmt, 1);
    re->question = sqlite3_column_text(stmt, 2);
    re->hint = sqlite3_column_text(stmt, 3);
    return re;
}

sqlite3 * init_database(char* filename) {
    srand(time(NULL));
    sqlite3 * db_ptr;
    sqlite3_open_v2(filename, &db_ptr, SQLITE_OPEN_READONLY, NULL);
    return db_ptr;
}

int main() {
    sqlite3 * d = init_database("data.db");
    struct db_response* re = get_response(d);
    printf("%s\n%s\n%s\n", re->answer, re->question, re->hint);
    free(re);

    sqlite3_close_v2(d);
    free(d);
}
    
