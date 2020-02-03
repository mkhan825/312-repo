//Arrays, Pointers, and Strings
#include <stdio.h>
#include <stdint.h>

int main(void) {
    int32_t a = 0;  // Depending on what compiler you have, the order in which variables are saved in memory locations may differ (upwards vs downwards) 
    int32_t b = 0;
    int32_t array[2] = {0};

    //array[0] // Equivalent to *(array + 0)
    *(array+0) = 1;
    *(array+1) = 2; // Go to second value in array, dereference, assign 2

    //array = pa; Cannot do this despite types being the same. Arrays are a constant pointer given their data type

    int32_t *pa = &a; //This asks for the address of the symbolic name "a" and saves it in the variable pa. "pa" is a POINTER to an integer. 
                      // This "*" represents that it is a pointer and "&" asks for memory address
    int32_t *pt = pa; // pt will have the same value as pa. They are the same pointer. Pointer does not have to be 32 bit, but it will be pointing to one
    
    double d = 0.0;
    double *pd = &d;

    a = 77;
    *pa = 88; // Similar to LDI/STI. This will put the value of 88 in a's memory location

    *(&b - 1) = 99; // &b is explicitly a pointer, subtract one to that pointer and put 99 in that location

    printf("%d %d %d %p\n", pa, b, array[0]); // %p is used to print pointers
    //printf("%p %p \n", &a, &b); // We can use this to see how the compiler lays out memory
    return 0;
}