#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <ncurses.h>

#include "type_text.h"
#include "fuzzy.h"

int main(int argc, char **argv) {
    initscr();

    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    scrollok(stdscr, TRUE);

    if (argc != 2) {
        printf("Usage: %s <Number of Questions>\n", argv[0]);
        return -1;
    }

    int num_questions = atoi(argv[1]);

    if (num_questions <= 0) {
        printf("Please give a positive, non-zero integer for the number of questions to play for!\n");
        return -1;
    }

    printf("<Insert %d Good Question(s) about Women in Stem Here>\n", num_questions);

    display_question("What is the name of the first programmer?\n", 10.0f);

    char* base = "Ada Lovelace\0";
    char* comp = "Lovelace\0";

    printf("The difference between %s and %s is %d\n", base, comp, levenshtein(base, comp));
    return 0;
}
