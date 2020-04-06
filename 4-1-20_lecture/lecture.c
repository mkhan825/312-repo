#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Vector* vecInit() {
    Vector *vec = malloc(sizeof(Vector));
    vec->size = STEP;
    vec->len = 0;
    vec->elems = malloc
}