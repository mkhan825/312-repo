#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {
    double** fMatrix = malloc(a_rows*sizeof(double));
    for (uint32_t l = 0; l < a_rows ; l++) {
        *(fMatrix+l) = malloc (a_cols * sizeof(double));
    }
    int first_number;
    int second_number;
    int i = 0;
    int j = 0;
    int k = 0;
    int x = 0;
    int y = 0;
    int sumindex = 0;
    int sum = 0;
    if (a_cols == 0|| a_rows == 0|| b_cols == 0) {
        return 0;
    }
    for (; i < a_rows; i++) {
        for (; j < b_cols ; j++) {
            for (; k < a_cols; k++) {
                first_number = a[x][y];
                second_number = b[k][j];
                sum = sum + first_number*second_number;
                y++;
            }
            fMatrix[x][sumindex] = sum;
            sumindex++;
            printf("sum: %d\n", sum);
            sum = 0;
            k = 0;
            y = 0;
        }
        sumindex = 0;
        x++;
        j = 0;
    }
    return fMatrix;
}

int main () {
    double firstMatrix1[] = {1,2,3};
    double firstMatrix2[] = {4,5,6};
    double firstMatrix3[] = {7,8,9};
    double firstMatrix4[] = {10,11,12};
    double firstMatrix5[] = {13,14,15};
    double secondMatrix1[] = {1,2,3,4};
    double secondMatrix2[] = {5,6,7,8};
    double secondMatrix3[] = {9,10,11,12};
    double *pointerArray1[] = {&firstMatrix1,&firstMatrix2,&firstMatrix3,&firstMatrix4,&firstMatrix5};
    double *pointerArray2[] = {&secondMatrix1,&secondMatrix2,&secondMatrix3};
    double **ptr1 = &pointerArray1;
    double **ptr2 = &pointerArray2;
    double **c;
    c = multiplyMatricesPtr(ptr1, 1, 1, ptr2, 1);
    for (int i = 0; i < 5 ; i++) {
        for (int j = 0; j < 4; j++) {
            printf("c[%d][%d] = %f\n", i, j, c[i][j]);
        }
    }
}