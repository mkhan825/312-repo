#include <stdint.h>

#define STEP 10

typedef struct {
    int32_t size;
    int32_t len;
    int32_t *elems;
} Vector;

Vector* vecInit();

void vecDestroy(Vector *vec);

int32_t veclen(Vector *vec);

void vecAdd(Vector *vec, int32_t el);

void vecPrint(Vector *vec);