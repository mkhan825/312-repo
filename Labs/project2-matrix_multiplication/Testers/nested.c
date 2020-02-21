#include <stdio.h>
#include <stdint.h>
#include "MatrixMultiply.h"

/*void multiplyMatrices(
    double a[],
    const uint32_t a_rows,
    const uint32_t a_cols,
    double b[],
    const uint32_t b_cols,
    const uint32_t b_rows,
    double c[],
    const uint32_t c_rows,
    const uint32_t c_cols) {
        
        int first_number;
        int second_number;
        int sum = 0;
        for ( int i = 0; i < a_rows ; i++ ) {
            first_number = a[i];
            for ( int j = 0; j < ; j++ ) {
                second_number = b[j*b_rows]; 
                for ( int k = 0; k < (a_cols*b_rows); k++ ) {
                    sum = first_number*second_number + sum;
                    c[k] = sum;
                }
            }
        }


}*/

int nested() {
    int first_number = 1;
    int second_number = 2;
    int c;
    int sum = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < 3) {
        while (j < 3) {
            while (k < 3) {
                first_number++;
                printf("First_number: %d\n", first_number);
                second_number++;
                printf("Second_number: %d\n", second_number);
                sum = sum + first_number*second_number;
                printf("Sum: %d\n", sum);
                k++;
                i++;
                j++;
            }
        }
    }
    return sum;
}

int main (void) {
    int sum;
    sum = nested();
    printf("sum = %d\n", sum);
}