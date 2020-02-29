#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//Should i assume that the struct information is filled out for me in the tests?
typedef
struct UTString {
    uint32_t length;	// number of characters before the null terminator
    uint32_t capacity;	// length of the longest string that can be stored
    char* string;		// pointer to the actual string (contains signature after string)
} UTString;

UTString* utstrcat(UTString* s, const char* suffix) { // Should i assume the test cases has deadbeef at the end of them?
    int length = 0; // Find the length
    //printf("UTString: %s", s->string);
    for (int i = 0; *(s->string+i) !='\0' ; i++) {
        length++; // get length
    }
    int i = 0;
    for (; i < length ; i++) {
        //printf("s->string+1");
        s->string[length+i] = suffix[i];
    }
    *(s->string+i+length) = '\0';
    printf("EndString: %s", s->string);
}
int main(void) {
    char array[] = "ADD";
    UTString* ptr = (UTString*) malloc(sizeof(UTString));
    ptr->string = malloc(100*sizeof(char));
    strcpy(ptr->string, "WOW");
    printf("UTString: %s\n", ptr->string);
    utstrcat(ptr, array);
}
