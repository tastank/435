
#include <cstdlib>
#include <cstdio>


void sort(char *, float *);

int main() {
    float freqs[26] = {
        .1202,
        .091,
        .0812,
        .0768,
        .0731,
        .0695,
        .0628,
        .0602,
        .0592,
        .0432,
        .0398,
        .0288,
        .0271,
        .0261,
        .023,
        .0211,
        .0209,
        .0203,
        .0182,
        .0149,
        .0111,
        .0069,
        .0017,
        .0011,
        .001,
        .0007
    };
    float cipherFreqs[26];
    char letters[27] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'r', 'h', 'd', 'l', 'u', 'c', 'm', 'f', 'y', 'w', 'g', 'p', 'b', 'v', 'k', 'x', 'q', 'j', 'z', '\0'};

    char *string = "mcifgsqfshwggotskwhvaspsqoigshvsfswgoqvobqswkogbchzwghsbwbu";
  //char *string = "eeeeeeetttttaaaaoooiiinnnsssrrrhhhddlluuccmmffyywwgpbvkxqjz";

    sort(letters, freqs);

    printf("%s\n", letters);

    float min = 1.0f;
    float max = 0.0f;
    int min_shift;
    int max_shift;

    for (int i = 0; i < 26; i++) {
        printf("%c %f\n", letters[i], freqs[i]);
    }

    for (int i = 0; i < 26; i++) {
        int string2[59];
        for (int j = 0; j < 59; j++) {
            string2[j] = (int) string[j] + i;
            if (string2[j] > (int) 'z') {
                string2[j] -= 26;
            }
            string2[j] -= (int)'a';
            printf("%c", (char)string2[j] + 'a');
        }
        float deviation = 0.0f;
        for (char j = 0; j < 26; j++) {
            int count = 0;
            for (int k = 0; k < 59; k++) {
                if (string2[k] == (char) j) {
                    count++;
                }
            }
            float freq = (float)count / 59.0f;
            deviation += (freq - freqs[(int)j]) * (freq - freqs[(int)j]);
        }
        if (deviation < min) {
            min = deviation;
            min_shift = i;
        } else if (deviation > max) {
            max = deviation;
            max_shift = i;
        }
        printf("Shifted %d positions; deviation = %f\n", i, deviation);

    }

    printf("Min deviation: %f; shift: %d\n", min, min_shift);
    printf("Max deviation: %f; shift: %d\n", max, max_shift);

}

void sort(char * ar, float * freq) {
   for (int i = (25); i >= 0; i--) {
      for (int j = 1; j <= i; j++) {
         if (ar[j-1] > ar[j]) {
              char temp = ar[j-1];
              float tempFreq = freq[j-1];
              ar[j-1] = ar[j];
              freq[j-1] = freq[j];
              ar[j] = temp;
              freq[j] = tempFreq;
         }
      }
   }
}

