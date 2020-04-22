#include <stdlib.h> // This is a standard input/output library to including printf
#include <stdint.h> // This library allows you to see how many bits int takes. int8_t, int16, etc. Important if you need to know how many bits you have.
#include "second_lecture.h" // Quotation marks needed for user files
// Global variables are mentioned outside of functions

// #define WEIGHT 60 // To avoid copy pasting we can create a macro, whenever we see WEIGHT we will assign 60
// This is done by pre-processor. **No memory is taken in order to do this**
// It will check your file for WEIGHT and will just replace it with 60 
// If you can avoid macros you should because it could create problems with debugging

int global = 44; // This is a global variable
// Global variables are stored in different places in memory (Global Data Storage)
// Global variables are ALWAYS intialized to 0 unlike local variables

int main(void) { //This is where the code starts
    //In assembly language the program will jump to this part of memory
    
    int a = WEIGHT; //a is a variable with int data type and will take a space in memory (It will go to the stack)
    int _a1 = WEIGHT;
    int _a2 = WEIGHT; 
    // a will become a symbolic name for a space in memory, a is also a local variable because it is mentioned inside the curly braces
    // Will things that get called outside of the braces be able to be made?
    // The initial value of the local variable cannot be nothing, it has to have something even if it is junk (that junk can also get printed)
    // ALL symbolic names have to follow some rules: cannot start a variable with a number, do not use underscore at the beginning of the name
    
    int array[] = {0, 1, 2, 3}; // int array[10] = {0, 1, 2, 3}; This is an array named "array" with 10 elements. 10 memory locations will be taken for this array.
    // If a part of an array is not defined it will be set to 0 
    char carray[] = { 'a', 'b', 'c'}; // Creates a character array, undefined parts are initialized to 0
    // char carray[10] = "abc"; this is equivalent to the last line
    // char carray[] = {'a', 'b', 'c'} if you do not define the length of the array, it will just take the length that you define, however, with an added '\0'.
    // This array takes 4 spaces

    int b = a + global;
    // b is a symbolic name for another memory location
    // In the computation we first go to the symbolic name of a instead of the character "a", take the value, add them together and put it in the symbolic name b
    // When it comes to compiling "a + global" it checks if the correct operators are being used on certain data types to check if it is allowed 
    // int is usually represented in 2's compliment
    // float (floating point number) frequently takes one word (32 bits), we use floating point when we have to use something like pi
    // double is like floating point, it's just that ***
    // long is *16 or 32 bits* long 
    // _Bool ***
    // Data Type tells you how much memory you will take from memory
    // Data Type also tells you what kinds of operations that you can be used

    char c = 'a';
    // char type used for one character at a time, but it is an integer so you can do math with it
    
    double d = 5.3;

    printf("%d %c %g\n", a, c, d); // To print integer print d, c does char, g does double, s does string

    return 0; //We keep this in order to check if there was an error or not in this program 0 is arbitrary
}