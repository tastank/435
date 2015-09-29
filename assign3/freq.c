#include <stdlib.h>
#include <stdio.h>

#define NUMCHARS 256

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Wrong number of args.  Usage: freq string\n");
        return -1;
    }

    printf("%s", argv[1]);
    return 0;

    int freqs[NUMCHARS];

    for (int i = 0; i < NUMCHARS; i++) {
        freqs[i] = 0;
    }

    char c = argv[1][0];
    while (c != '\0') {

    }

}
