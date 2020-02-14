#include <stdio.h>
#include <string.h>

int main (void) {
    char str1[] = "Hi";
    char str2[] = "Log\nTop\nHi\nFiretruck";
    int str2len = sizeof(str2) / sizeof(str2[0]);
    int j = 0;
    for (int m = 0; m < str2len; m++) {
        if (str1[j] == str2[m] || (str1[j] == str2[m] + 32) || (str1[j] == str2[m] - 32)) {
            if (str1[j + 1] == '\0' && ((str2[m + 1] == '\0') || (str2[m + 1] == '\n'))) {
                printf("Word was found\n");
                return 1;
            }
            j = j + 1;
        } else {
            j = 0;
            if (m == (str2len - 1)) {
                printf("Could not find word\n");
                return 0;
            }
        }
    }
}