#include <cstdlib>
#include <cstdio>


#define NUM_STRINGS 20
#define STR_LENGTH  256

bool is_hex_digit(char);

int main(int argc, char *argv[]) {
    //xor infilename outfilename
    if (argc != 3) {
        printf("Wrong number of args.\n");
        return -1;
    }

    //open the input file to read it
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Couldn't open file; wrong filename?\n");
        return -1;
    }

    //allocate memory for the input strings
    char **input = new char*[NUM_STRINGS];
    bool *useful = new bool[NUM_STRINGS];

    //get the input strings
    for (int i = 0; i < NUM_STRINGS; i++) {
        input[i] = new char[STR_LENGTH];
        //assume there's no error here, because this isn't for anyone else to use
        fgets(input[i], STR_LENGTH, fp);
        if (is_hex_digit(input[i][0])) {
            useful[i] = false;
        } else {
            useful[i] = true;
        }
    }

    //I could do this above, but for clarity
    //
    for (int i = 0; i < NUM_STRINGS; i++) {
        if (useful[i]) {
            printf("Useful %d\n", i);
        }
    }

    //close the input file
    fclose(fp);
    return 0;
}


bool is_hex_digit(char input) {
    return  (!(input >= 'a' && input <= 'f') && 
             !(input >= 'A' && input <= 'F') &&
             !(input >= '0' && input <= '9'));
}
