#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // Gives us the random function

#define MAX 200

int main(void) {

    int32_t line = 0;

   /* for(;;) {
       How to create infinite loop with for loop
    }*/

    while(1) {
        line++;

        for(int32_t i = 0; i < line; i++) {
            for (int32_t j = 0; j < MAX; j++) {
                //todo: print chars
                char c = 32 + (rand() % 94); //32 is the ASCII conversion and there are 94 different printable characters
                printf("%c", c);
            }
            printf("\n"); //new line
        }
    }
}