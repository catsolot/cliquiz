#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Usage: %s <Number of Questions>\n", argv[0]);
        return -1;
    }

    int num_questions = atoi(argv[1]);

    if (num_questions <= 0) {
        printf("Please give a positive, non-zero integer for the number of questions to play for!\n");
        return -1;
    }


    printf("<Insert %d Good Question(s) about Women in Stem Here>\n", num_questions);

    return 0;

}
