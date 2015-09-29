#include <stdlib.h>
#include <stdio.h>

#define NUMCHARS 256

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Wrong number of args.  Usage: freq string\n");
        return -1;
    }

    int freqs[NUMCHARS];

    for (int i = 0; i < NUMCHARS; i++) {
        freqs[i] = 0;
    }

    char c = argv[1][0];
    int i = 0;
    while (c != '\0') {
        freqs[(int)c]++;
        c = argv[1][++i];
    }

    for (int i = 0; i < NUMCHARS; i++) {
        if (0 != freqs[i]) {
            printf("%c -- %d\n", (char)i, freqs[i]);
        }
    }

}
