#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

double** transposeMatrix(
    double** a,
    const uint32_t a_rows,
    const uint32_t a_cols){


    double** b = (double **) malloc(a_cols * sizeof(double*));

    for (int i = 0; i < a_cols; i++) {
        *(b+i) = (double *) malloc(a_rows * sizeof(double));
    }
    for (int i = 0; i < a_cols; i++) {
        for (int j = 0; j < a_rows; j++) {
            b[i][j] = a[j][i];
            printf("b[%d][%d] = %f\n", i, j, b[i][j]);
        }
    }
}

int main(void) {
    double firstMatrix1[] = {1, 2, 3};
    double firstMatrix2[] = {4, 5, 6};
    //double firstMatrix3[] = {7, 8, 9};
    double *pointerArray1[] = {&firstMatrix1, &firstMatrix2, /*&firstMatrix3*/};
    double **ptr1 = pointerArray1;
    double **ptr2 = transposeMatrix(ptr1, 2, 3);
}