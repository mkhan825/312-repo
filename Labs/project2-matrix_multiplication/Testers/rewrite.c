#include <stdio.h>
#include <stdint.h>

void multiplyMatrices(
    double a[],
    const uint32_t a_rows,
    const uint32_t a_cols,
    double b[],
    const uint32_t b_cols,
    const uint32_t b_rows,
    double c[]) {
        int indexofc = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        int sum = 0;
        int first_number;
        int second_number;
        while (i < a_rows) {
            while (j < b_cols) {
                while (k < a_cols) {
                    first_number = a[i*a_cols+k];
                    second_number = b[k*b_cols+j];
                    sum = first_number*second_number + sum;
                    c[indexofc] = sum;
                    k++;
                }
                indexofc++;
                sum = 0;
                k = 0;
                j++;
            }
        i++;
        j = 0;
        }
}

int main () {
    double firstMatrix[] = {1,2,3,4,5,6,7,8,9};
    double secondMatrix[] = {1,2,3,4,5,6,7,8,9};
    double Final_Matrix[9];
    multiplyMatrices(firstMatrix, 3, 3, secondMatrix, 3, 3, Final_Matrix);
    for (int l = 0; l < 9 ; l++) {
        printf("Final_Matrix[%d]: %f\n", l, *(Final_Matrix+l));
    }
}