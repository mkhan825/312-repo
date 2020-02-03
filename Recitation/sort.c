#include <stdint.h>
#include <stdio.h>

/*
 * This file contains an implementation of insertion sort. The
 * implementation is likely to contain errors (i.e. bugs) and probably
 * won't actually sort things correctly. Your job is to determine what
 * errors (if any) exist and fix them.
 */
void main() {
    // Create an array
    int32_t a[] = { 1, 6, 2, 3, 9, 4, 8, 7, 5, 0 };
    int n = sizeof(a)/sizeof(a[0]);

    // Do insertion sort
 /*   for (uint32_t i = 1; i < n; i++) {
        int32_t tmp = a[i];
        uint32_t j = i;
        for (; j > 0; j--) {
            if (a[j - 1] > tmp) {
                tmp = a[j-1];
                a[j-1] = a[j];
            }
        }
        a[j] = tmp;
    }*/
    for (int32_t i = 1; i < (n); i++) {
        int32_t tmp = a[i];
        int32_t j = i;
        for (; j > 0; j-- ) {
            if(a[i] < a[i-1]) {
                a[i] = a[i-1];
                a[i-1] = tmp;
            }
        }
            
    }

    // Print the sorted array
    const char* prefix = "";
    for (uint32_t k = 0; k < n; k += 1) {
        printf("%s%d", prefix, a[k]);
        prefix = ", ";
    }
    printf("\n");
}
