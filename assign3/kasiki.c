#include <stdlib.h>
#include <stdio.h>

#define NUMCHARS 256

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Wrong number of args.  Usage: index string minkeylength maxkeylength\n");
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

    printf("Total number of chars: %d", i);

    for (int keylength = atoi(argv[2]); keylength <= atoi(argv[3]); keylength++) {
        printf("\nKey length = %d, ics:", keylength);
        float mean = 0.0f;
        for (int keypos = 0; keypos < keylength; keypos++) {
            int ic_numerator = 0;
            int col_length = 0;
            for (int i = 0; i < length/keylength + 1; i++) {
                if (i * keylength + keypos < length) {
                    col_length++;
                }
                for (int j = 0; j < length/keylength + 1; j++) {
                    if (i * keylength + keypos < length && j * keylength + keypos < length) {
                        if (argv[1][i * keylength + keypos] == argv[1][j * keylength + keypos] && i != j) {
                            ic_numerator++;
                        }
                    }
                }
            }
            float ic = (float)ic_numerator / (col_length * (col_length - 1));
            printf("\t%f", ic);
            mean += ic;
        }
        mean = mean / keylength;
        printf("Mean: %f", mean);
    }

    printf("\n");
    return 0;

}
