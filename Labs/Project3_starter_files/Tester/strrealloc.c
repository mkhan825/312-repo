 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef
struct UTString {
    uint32_t length;	// number of characters before the null terminator
    uint32_t capacity;	// length of the longest string that can be stored
    char* string;		// pointer to the actual string (contains signature after string)
} UTString;

UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    int s_capacity = 0;
    for (int i = 0; s->string[i] != '\0'; i++) {
        s_capacity++;
        printf("%d\n", s_capacity);
    }
    s_capacity += 5;
    printf("%d\n", s_capacity);
    if (new_capacity > s_capacity) {
        //create a buffer with new_capacity capacity
        char* newptr = (char*) malloc(sizeof(char) * new_capacity);
        //copy elements
        for (int i = 0; s->string[i] != '\0'; i++) {
            newptr[i] = s->string[i];
        }
        //deallocate old buffer
        for(int j = s_capacity; j >= 0; j--) {
            free(s->string[j]);
        }
        s->string = newptr;
    }
    return s;
}

int main(void) {
    int capacity = 8;
    UTString* ptr = (UTString*) malloc(sizeof(UTString));
    ptr->string = malloc(8*sizeof(char));
    strcpy(ptr->string, "WOW");
    printf("UTString: %s\n", ptr->string);
    utstrrealloc(ptr, 10);
    printf("UTString: %s\n", ptr->string);
}
