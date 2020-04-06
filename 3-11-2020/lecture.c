#include <stdio.h>
#include <stdlib.h>

int factorial(int n ) {
    if(n <= 1) {
        return;
    }
    return n*factorial(n-1);
}
int main(void) {
    factorial(0);
    factorial(1);
    factorial(10);
}

/*
void printstars(int n) {
    if(n == 0) {
        return;
    }
    printstars(n-1);
    printf("*");
}

int power(int a, int b) {
    if(b == 0) {
        return 1;
    }
    return a*power(a, b-1);

}
*/