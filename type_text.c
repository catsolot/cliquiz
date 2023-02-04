#include "type_text.h"

void display_text(char* text, double seconds) {
    int length = strlen(text);
    int clocks_per_char = ( seconds / length ) * CLOCKS_PER_SEC;

    int elapsed;
    for (int i = 0, last = clock(); i < length; elapsed = clock() - last) {
        if (clocks_per_char <= elapsed) {
            putchar(text[i]);
            fflush(stdout);
            last = clock();
            i++;
        }
    }
}

