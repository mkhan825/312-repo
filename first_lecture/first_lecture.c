#include <stdio.h> 
//defines the function which are important to read from keyboard to output devices/terminals
//.h represents a header file

int main(void) {
    int a = 1; //local variable 
    int b = 3;

//printf("d\n", a);
//__asm__("movl   $20, -8(%rbp)");
//printf("%d\n", a);

    while(a > 0) {
        a++; // a = a + 1;
    }
    printf("put a string");
    printf("something %d %d \n", a, b); 
    //print has 2 arguments, first is what you want to print to the screen, and
    //% means that you are trying to print a specific type of number such as integer, etc
    //the second argument is the value that you want to print here
    //for every variable to be printed you need to have one percent
    return 0;
}