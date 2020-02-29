#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t get_length(char a[]) { // What defines as a noncharacter?
    uint32_t length = 0;
    for (int i = 0; a[i] != '\0' ; i++) {
        length++;
    }
    return length;
}

int main(void) { // What's stored in an empty char array
    char array[] = "Wow";
    int length = get_length(array);
}