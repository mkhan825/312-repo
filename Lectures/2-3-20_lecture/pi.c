#include <stdio.h> // Standard input/output library
#include <stdint.h> // including this to know how many bits our integers are

int main(void) {
    double pi = 4.0; // need .0 because double
    int32_t n;
    printf("Enter ther nth term value: ");
    scanf("%d", &n); // Comes from stdio. Scan formative. What is the type that user should enter?
    // &n is the ADDRESS of n. &n points to the data in n.
    // scanf: read keyboard for input. &n: place value from keyboard into this part of memory

    for (int32_t i = 1; i <= n; i++) { // While an int i is less than n, do this action
        double t = (4.0/(2*i+1)); // We make t this because it makes the code more readable
        if (i%2 == 0) { //do you need the parentheses around i? = is used for assigning values. == is used for comparing values. != not equal. >= Greater than or equal.
            pi = pi + t; // We're subtracting because when i is even, the equation makes it negative
        } else {
            pi = pi - t;
        }
    }

    printf("%g\n", pi);
    return 0;
}