#include <stdio.h>
#include <stdlib.h>

void largeArray() {
    int array[1000];
    printf("%p\n", array);
}


void recursion(int n) {
    if (n > 0) {
        recursion(n-1);
    }
}

void makeArray(int n) {
    // work and initialize
    
    //When you return a local variable the stack frame has already disappeared
    //Therefore whatever you return from this pointer, you are going to get some sort of garbage values
    //int *array = malloc(n * sizeof(int)); // malloc is part of stdlib.h, accepts how many bytes we want to allocated on the heap as an argument
    // takes n, the number, and sizeof(int) tells us how many bytes each int is going to take up
    // it will then give us the address to which the bytes we allocated are located 
    // array is a pointer to heap
    // malloc does not intialize the values in heap to anything

    //if you want to initialize the heap with a certain value:
    int *array = calloc(n, sizeof(int));
    //very similar to malloc
    //calloc is slower than malloc because it sets all the values to 0
    //If you are using too much of the heap it will return back a NULL value
    if (array == NULL) {
        //print/return a value here
    }
    return array;
}

int main (void) {
    //largeArray();
    //recursion(10);

    //int *array[10] = {0};
    //makeArray(array);
    int *array = makeArray(100);
    // do anything with array that we want

    array[0] = 55;
    printf("%d\n", array[0]);

    //memory leak: when heap is still being used from a previous program

    free(array);
    //this basically deactivates the chunk of heap that you previously used in order to write your program
    // if you were to try to use the pointer "array", it would not stop you because free does not get rid of the pointer
    return 0;
}