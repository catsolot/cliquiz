#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <ncurses.h>
#include "db.h"

#include "type_text.h"
#include "fuzzy.h"

int main(int argc, char **argv) {
    //initscr();

    //cbreak();
    //noecho();
    //nodelay(stdscr, TRUE);

    //scrollok(stdscr, TRUE);

    if (argc != 2) {
        printf("Usage: %s <Number of Questions>\n", argv[0]);
        return -1;
    }

    int num_questions = atoi(argv[1]);

    if (num_questions <= 0) {
        printf("Please give a positive, non-zero integer for the number of questions to play for!\n");
        return -1;
    }

    // Score keeping
    int correct = 0;
    double percentage;

    // Connect to database
    sqlite3* database = init_database("data.db");

    char buf[50];
    struct db_response * response;
    printf("Welcome to CLIQuiz!\n");
    for (int i = 0; i < num_questions; i++) {
        // get a thing
        response = get_response(database);

        // print the thingy
        display_question(response->question, 2.0);

        // get input
        printf("\nAnswer? ");
        scanf("%[^\n]%*c", buf);

        // compare 
        printf("You answered: %s\n", buf);
        printf("The answer actually is: %s\n", response->answer);
        unsigned int di = levenshtein(buf, response->answer);
        printf("The difference from your answer is: %d\n", di);
        if (di < 2) {
            printf("YAYYYY YOU'RE SO SMART O.o\n");
            correct++;
        }
        else {
            printf("bruh\n");
        }

    }

    printf("You're final score was %d/%d, or %3.2f%% correct.\n", correct, num_questions, 100 * (double) correct / (double) num_questions);
    return 0;
}
