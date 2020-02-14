#include <stdio.h>

char String1[] = "then";
char String2[] = "abccdoep";
int String1len = sizeof(String1)/sizeof(String1[0]);

int main() {
    for (int i = 0; i < String1len ; i++) {
        if ((String1[i] != String2[i]) && (String1[i] != String2[i]+32) && (String1[i] != String2[i]-32)) {
            printf("Strings are not the same\n");
            return 0;
        } else { 
            if (i == (String1len-1)) {
                printf("Strings are the same\n");
                return 0;
            }
        }
    }
}