#include <stdio.h>
#include <string.h>

int main (void) { //void extract_words(char word, char array);
    char array[] = "This is ee36a56e75t 5e6c56 7b75f6string12";
    int encountered_letter = 0;
    int encountered_index = 0;
    char word[50] = "";
    int word_len = sizeof(word)/sizeof(word[0]);
    int array_len = (sizeof(array)/sizeof(array[0]))-1;
    for (int i = 0; i < array_len ; i++) {
        if ((array[i] >= 'a' && array[i] <= 'z') ||
            (array[i] >= 'A' && array[i] <= 'Z')) { // This checks if the character is a letter
            if (encountered_letter == 0) {
                encountered_index = i;
                encountered_letter = 1;
            }
            if ( ( array[i+1] > 'z' || array[i+1] < 'A' ) || ( array[i+1] >= 91 && array[i+1] <= 96 ) ) {      // If the word length is greater than 1 and the next character encountered is not a letter
                encountered_letter = 0;
                if ( (i-encountered_index) >= 1 ) {
                    int k=0;
                    for ( ; encountered_index <= i ; encountered_index++) {
                        //strcat(word, (array+encountered_index)); // array[encountered_index]
                        word[k] = array[encountered_index];
                        k++;
                    }
                    word[k] = '\0';
                }
            }
        }
    }
}
