#include <stdio.h>
#include <stdint.h>

int main(void) {
    int32_t n;

    scanf("%d", &n);

    if (n < 2 || n > 100) {
        return 33;
    }

    for (int32_t i = 2; i <= n; i++) { // Outer loop, will iterate to n
        int8_t prime = 1;
        for (int32_t j = 2; j<= 10; j++) { // Check if divisible 
            if (i%j == 0 && i!=j) {
                prime = 0;
            }
        }
        if (prime) {
            printf("%d\n", i);
        }
    }

    /* Same thing with a while loop
        int32_t j = 2;
        while (j <= 10) {
            if ((i%j) == 0 && i!=j) {
                prime = 0;
            }
            j++;
        }

        Whenever we have a counter it is preferred to use a for loop rather 
        than a while loop
    */
   
    return 0;
}