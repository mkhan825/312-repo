#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef
struct UTString {
    uint32_t length;	// number of characters before the null terminator
    uint32_t capacity;	// length of the longest string that can be stored
    char* string;		// pointer to the actual string (contains signature after string)
} UTString;

UTString* utstrdup(const char* src){
    //find length of the string
    int length = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        length++;
    }
    printf("Length of array: %d\n", length);
    //allocate space for the UTString
    UTString* ptr = (UTString*) malloc(sizeof(UTString));
    printf("Size of UTString pointer: %lu bytes\n", sizeof(UTString*));
    //allocate space for the string in UTString
    ptr->string = malloc(sizeof(char)*length);
    printf("Size allocated for String: %lu\n", (sizeof(char)*length)/sizeof(char));
    for (int i = 0; src[i] != '\0' ; i++) {
        ptr->string[i] = src[i];
        printf("This is array[%d]: %c\n", i, src[i]);
        //printf("This is array: %s\n", *(ptr->string+i)); //why did i get a segmentation fault trying to run this?
        //printf("This is array2: %s\n", ptr->string[i]);
    }
    printf("Array2: %s", ptr->string);
    return ptr;
}

int main(void) {
    char array[] = "Wow";
    utstrdup(array);
}
