#include "type_text.h"

int kbhit() {
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

int display_question(char* text, double seconds) {
    int length = strlen(text);
    int clocks_per_char = ( seconds / length ) * CLOCKS_PER_SEC;

    int beginning = clock();

    int elapsed;
    for (int i = 0, last = clock(); i < length; elapsed = clock() - last) {
        //if (kbhit()) {
        //    printf("Enter key was pressed\n");
        //    refresh();
        //    return (clock() - beginning);
        //}
        //refresh();
        if (clocks_per_char <= elapsed) {
            putchar(text[i]);
            fflush(stdout);
            last = clock();
            i++;
        }
    }

    return (clock() - beginning);
}

