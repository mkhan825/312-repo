#include <stdio.h>
#include <stdlib.h>

int fsolutions[100];

int Fibbonacci(int n) {
    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return 1;
    }

    if (fsolutions[n] != 0) {
        return fsolutions[n];
    }

    int result = Fibbonacci(n-1) + Fibbonacci(n-2);
    fsolutions[n] = result;
    return result;
}

int main(void) {

    // Assume we cannot use global variables for when we use recursion
    // Fibbonacci, Maze example, Subset sum example, Unterminated recursion, Stack overflow
    // Chapter 17 Patt book
    
    printf("%d %d\n", 5, Fibbonacci(5));
    printf("%d %d\n", 10, Fibbonacci(10));

    return 0;
}

/*
int main(void) {
    int n = ?;
    int fibbonacci = 0;
    if (n == 0) {
        fibbonacci = 0;
    }
    if (n == 1) {
        fibbonacci = 1;
    }
    for (int i = 2; i < n; i++) {
        fibbonacci = fibbonacci + n;
    }
    // Check what I did wrong for fibbonacci
}

*/