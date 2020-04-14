#include <stdlib.h>
#include <stdio.h>

int sumHelp(int sum, int **matrix, int rows, int cols, int row, int col) {
    if(col == cols) {
        row++;
        col = 0;
    }
    if(row == rows) {
        return sum;
    }
    sumHelp(sum+matrix[row][col], matrix, rows, cols, row,col+1);
}

int sumRec(int **matrix, int rows, int cols) {
    int sum = 0;
    if(rows == 0 || cols == 0) {
        //Idk prolly return
    }
    sum = sumHelp(sum, matrix, rows, cols, 0, 0);
    return sum;
}

void PrintMatrix(int **matrix) {
    for(int i = 0; i < 3; i ++) {
        printf("\n");
        for(int j = 0; j < 3; j++) {
            printf("%d, ", matrix[i][j]);
        }
    }
}

int main(void) {
    int **matrix = malloc(sizeof(int)*3);
    int **matrix2 = malloc(sizeof(int)*3);
    int **matrix3 = malloc(sizeof(int)*3);
    for(int i = 0; i < 3; i++) {
        matrix[i] = malloc(sizeof(int)*3);
        matrix2[i] = malloc(sizeof(int)*3);
        matrix3[i] = malloc(sizeof(int)*3);
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matrix[i][j] = 1;
        }
    }
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j++) {
            matrix2[i][j] = rand() % 9;
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matrix3[i][j] = 9;
        }
    }
    printf("Matrix1:\n");
    PrintMatrix(matrix);
    printf("Sum: %d\n", sumRec(matrix, 3, 3));
    printf("Matrix2:\n");
    PrintMatrix(matrix2);
    printf("Sum: %d\n", sumRec(matrix2, 3, 3));
    printf("Matrix3:\n");
    PrintMatrix(matrix3);
    printf("Sum: %d\n", sumRec(matrix3, 3, 3));
    for(int i = 0; i < 3; i++) {
        free(matrix[i]);
        free(matrix2[i]);
        free(matrix3[i]);
    }
    free(matrix);
    free(matrix2);
    free(matrix3);
}