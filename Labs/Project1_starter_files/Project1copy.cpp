/*
 * Project1.cpp
 * 
 * Name: Masaad Khan
 * EE312H Spring 2020
 * SpellCheck
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types]
#include <string.h>
//#include "header.c"

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I *insist* that you indent
 * reasonably and consistently in your code. I strongly encourage you to avoid big functions
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */

int i = 0;
int correctwords = 0;

void extract_words (char *word, char *array) { //This function extracts words out of the arrays
    int encountered_letter = 0;
    int encountered_index = 0;
    int array_len = strlen(array);
    for (i; i < array_len ; i++) {
        if ((array[i] >= 'a' && array[i] <= 'z') ||
            (array[i] >= 'A' && array[i] <= 'Z')) { // This checks if the character is a letter
            if (encountered_letter == 0) {
                encountered_index = i;              // Set value to i when we reach a letter
                encountered_letter = 1;
            }
            if ( ( array[i+1] > 'z' || array[i+1] < 'A' ) || ( array[i+1] >= 91 && array[i+1] <= 96 ) ) {      // If the word length is greater than 1 and the next character encountered is not a letter
                encountered_letter = 0;
                if ( (i-encountered_index) >= 1 ) {
                    int k=0;
                    correctwords++;
                    for ( ; encountered_index <= i ; encountered_index++) {
                        word[k] = array[encountered_index]; // Extract the characters
                        k++;
                    }
                    word[k] = '\0';
                    break;
                }
            }
        }
    }
}


int checkifin (char *str1, char *str2) { // This checks if str1 is in str2, also the input str1 can only have letters
    int str2len = strlen(str2);
    int j = 0;
    for (int m = 0; m < str2len; m++) {
        if (str1[j] == str2[m] || (str1[j] == str2[m] + 32) || (str1[j] == str2[m] - 32)) { //+-32 signifies upper/lower case characters
            if (str1[j + 1] == '\0' && ((str2[m + 1] == '\0') || (str2[m + 1] == '\n'))) {
                break;
            }
            j = j + 1;
        } else {
            j = 0;
            if (m == (str2len - 1)) {
                printf ("%s\n", str1);
                break;
            }
        }
    }
}


void spellCheck(char article[], char dictionary[]) {
    i = 0;
    correctwords = 0;
    char words[50] = "";
    int array_len = strlen(article);
    for (; i < array_len - correctwords ;) {
        extract_words(words, article);
        checkifin(words, dictionary);
    }
}

