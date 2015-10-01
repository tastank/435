#include <stdlib.h>
#include <stdio.h>

#define NUMCHARS 256

int main(int argc, char **argv) {
    for (int i = 1; i <= 10; i++) {
        float index;
        index = 1.0f/i * 0.066 + (i-1.0f)/i*0.038;
        printf("E_%d(IC)\t= %f\n", i, index);
    }
}
