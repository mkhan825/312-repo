#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int** allocMatrix( int n, int m) {
    int **matrix = malloc (n *sizeof(int*)); // m will point to the entire array of n
    // Every element in our array will be a pointer
    // So far we have initialized all the rows in our matrix but now we want to intialize the columns
    for ( int i = 0; i < n; i ++) {
        *(matrix + i) = malloc (m*sizeof(int)); // matrix[i] = malloc(m*sizeof(int));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10; // *(m[i]+j)
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** extendMatrix(int **matrix, int n, int m) {
    matrix = realloc(matrix, (n+1) *sizeof(int\*));
    matrix[n] = malloc(m *sizeof(int));
    // initialize elements after allocating space for it
    return matrix; // Need to return the new pointer in the case that the old memory is not being used anymore
}

void freeMatrix(int **matrix, int n) {
    for (int i = 0; i < ,; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main (void) {

    int **m = allocMatrix[DIM, DIM];
    printMatrix(m, DIM, DIM);
    // use matrix any way you want

    //calloc initializes memory space in the heap to 0 
    //malloc just allocates space in the heap
    //Ragged matrix: not every row has the same amount of columns
    int m[3][3]; // This creates a matrix with 3 rows and 3 columns
    // C uses row major order, so row by row the items go into memory. First row, second row, etc.
    // m is a pointer to the first element 0,0 in the matrix
    // m[0] is a pointer to the first element in the first row
    // m[1] is a pointer to the first element in the second row
    // A matrix is a pointer of a pointer (int**)

    int *p = m[1];

    int a[3]; // int*

    int e1;
    int *p1 = &e1;
    int **p2 = &p1; // You need to tell the compiler how many indirections there are to get what you want
    int ***p3 = &p2; // You can do make how many indirections you want

    e1 = 100;
    *p1 = 99;
    **p2 = 88;

    m = extendMatrix(m, DIM, DIM);


    freeMatrix(m, DIM+1); // need to free memory in the opposite order that it was created

    return 0;
}
