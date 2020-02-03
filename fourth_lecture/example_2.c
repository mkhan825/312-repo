#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LEN 50

int main(void) {
    char aa[LEN];
    char c;

    char *paa = aa; // &aa[0] // &(aa + 0)
    while((c = getchar()) != '\n') {
        *paa = c;
        paa++;
    }

    *paa = '\0'; // Put 0 at the end of array so it is null terminated

    printf("%s\n", aa);
    return 0;
}