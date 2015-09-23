
#include <cstdlib>
#include <cstdio>


void sort(char *, float *);

int main() {
    float freqs[26] = {.1202, .091, .0812, .0768, .0731, .0695, .0628, .0602, .0592, .0432, .0398, .0288, .0271, .0261, .023, .0182, .0149, .0111, .0069, .0017, .0011, .001, .0007};
    char letters[27] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'r', 'h', 'd', 'l', 'u', 'c', 'm', 'f', 'y', 'w', 'g', 'p', 'b', 'v', 'k', 'x', 'q', 'j', 'z', '\0'};

    char *string = "mcifgsqfshwggotskwhvaspsqoigshvsfswgoqvobqswkogbchzwghsbwbu";

    sort(letters, freqs);

    printf("%s", letters);

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

