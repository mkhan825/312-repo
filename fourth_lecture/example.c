#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//Write a function to count 0s and 1s in an array

#define LEN 10

void count(int32_t a[], int32_t len, int32_t *z, int32_t *o) {
    int32_t *z = 0;
    int32_t *o = 0;
    for (int32_t i = 0; i < len; i++) {
        if (a[i] == 0) {
            *z = *z + 1; // *z gets the value from that address
        } else if (a[i] == 1) {
            *o = *o + 1;
        } // else ...
    }
}

int main(void) {
    int32_t array[LEN] = {0};

    for(int32_t i = 0; i < LEN; i++) {
        *(array+i) = rand() % 10; // array[i] = rand() % 10;
    }

    int32_t zeros = 0;
    int32_t ones = 0;
    count(array, LEN, &zeros, &ones); // "array" only passes the address of the array
                                      // count(1000, 10, 0, 0)
    for (int32_t i = 0; i < LEN; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    printf("%d %d\n", zeros, ones);

    return 0;
}