/* Project2.cpp
 * Masaad Khan
 * EE312H, Spring 2020
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(
    double *a,
    const uint32_t a_rows,
    const uint32_t a_cols,
    double *b,
    const uint32_t b_cols,
    double *c) {
    int indexofc = 0;
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;
    double sum = 0;
    double first_number;
    double second_number;
    while (i < a_rows) {
        while (j < b_cols) {
            while (k < a_cols) {
                first_number = a[i*a_cols+k];
                second_number = b[k*b_cols+j];
                sum = first_number*second_number + sum;
                k++;
            }
            c[indexofc] = sum;
            indexofc++;
            sum = 0;
            k = 0;
            j++;
        }
        i++;
        j = 0;
    }
}

double** multiplyMatricesPtr(
    double** a,
    const uint32_t a_rows,
    const uint32_t a_cols,
    double** b,
    const uint32_t b_cols) {
    double** fMatrix = (double**) malloc(a_rows*sizeof(double*));
    for (uint32_t l = 0; l < a_rows ; l++) {
        *(fMatrix + l) = (double*) malloc (b_cols * sizeof(double));
    }
    double first_number;
    double second_number;
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;
    uint32_t x = 0;
    uint32_t y = 0;
    double sum = 0;
    uint32_t sumindex = 0;
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


// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
    double** a,
    const uint32_t a_rows,
    const uint32_t a_cols) {

    double **b = (double**) malloc(a_cols * sizeof(double*));
    for (uint32_t i = 0; i < a_cols; i++) {
        *(b + i) = (double*) malloc(a_rows * sizeof(double));
    }
    for (uint32_t i = 0; i < a_cols; i++) {
        for (uint32_t j = 0; j < a_rows; j++) {
            b[i][j] = a[j][i];
        }
    }
    return b;
}
