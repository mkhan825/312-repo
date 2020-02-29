#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) {
    char array[] = "WOW";
    char array2[3];
    printf("%s\n", array);
    printf("Array2: %s\n", array2);
    int length = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < length-1; i ++) {
        array2[i] = array[i];
        printf("array2[i]= %c\n", array2[i]);
        printf("array[i]= %c\n", array[i]);
    }
    printf("Array: %s\n", array);
    printf("Array2: %s\n", array2);
}
