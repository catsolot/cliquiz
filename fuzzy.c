#include "fuzzy.h"

static int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= c && b <= a) {
        return b;
    } else if (c <= b && c <= a) {
        return c;
    }
}

/**
 * C implementation of Levenshtein's Distance Algorithm for fuzzy string matching.
 * Lifted from WikiBooks:
 * https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C
 */
int levenshtein(char *s1, char *s2) {
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++) {
        matrix[x][0] = matrix[x-1][0] + 1;
    }
    for (y = 1; y <= s1len; y++) {
        matrix[0][y] = matrix[0][y-1] + 1;
    }
    for (x = 1; x <= s2len; x++) {
        for (y = 1; y <= s1len; y++) {
            matrix[x][y] = min(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));
        }
    }

    return(matrix[s2len][s1len]);
}
