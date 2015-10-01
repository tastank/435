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

    int length = i;
    int distinct = 0;
    float index_of_coincidence;
    int index_of_coincidence_numerator = 0;

    printf("Total number of chars: %d\n", i);

    for (int i = 0; i < NUMCHARS; i++) {
        if (0 != freqs[i]) {
            printf("%c -- %d\t%f\n", (char)i, freqs[i], (float)freqs[i]/length);
            index_of_coincidence_numerator += freqs[i] * (freqs[i] - 1);
            distinct++;
        }
    }

    index_of_coincidence = (float)index_of_coincidence_numerator / (length*(length - 1));
    printf("Index of coincidence: %f\n", index_of_coincidence);



}
