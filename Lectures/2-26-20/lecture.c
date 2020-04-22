#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define LEN 100

void arrayInit (int *a, int len) {
    for (int i = 0; i < len; i ++) {
        a[i] = rand()%100;
    }
}

void arrayPrint( int *a, int len) {
    for (int i = 0; i < len; i ++ ) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble(int *a, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < len; j++) { // len - i
            if (a[j-1] > a[j]) {
                int t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
        }
    }
}

int8_t comp1(int a, int b) {
    return a < b;
} 

int8_t comp2(int a, int b) {
    return a > b;
}

void insertion(int *a, int len, int8_t (*comp)(int, int)) {
    for (int i = 0; i < len; i++) {
        for (int j = i - 1; j >= 0; j--) {

            if (comp(a[j], a[j+1])) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void qsortHelp(int *a, int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot = a[high];
    int i = low-1;
    for (int j = low; j <= high - 1; j++) {
        if(a[j] < pivot) {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    i++;
    int t = a[i];
    a[i] = pivot;
    a[high] = t;
    qsortHelp(a, low, i - 1);
    qsortHelp(a, i + 1, high);
}

void quickSort(int *a, int len) {
    qsortHelp(a, 0, len-1);
}

int main (void) {
    int a[LEN];
    arrayInit(a, LEN);

    /*clock_t b = clock();
    bubble(a, LEN);
    clock_t e = clock();*/
    clock_t b = clock();
    insertion(a, LEN, &comp1);
    //insertion(a, LEN, &comp2);
    clock_t e = clock();
    double dur = 1000.0 * (e - b) / CLOCKS_PER_SEC; // Clock gives us how many clock cycles it takes, so to determine how many seconds it takes we divide by clocks_per_sec, multiply by 1000 to get milliseconds

    arrayPrint(a, LEN);
    printf("%g\n", dur);

    return 0;
}