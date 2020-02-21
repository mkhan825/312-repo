#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 100
int32_t HEAP[SIZE];
int32_t is_init = 0;

void mminit(void) {
    if (!is_init) {
        HEAP[0] = SIZE-2;
        HEAP[SIZE-1] = SIZE - 2;
        is_init = 1;
    }
}

void mmprint(void) {
    mminit();
    for (int i = SIZE-1; i >= 0; i--) {
        printf("========\n");
        printf("| %5d | %d\n", HEAP[i], i);
    }
}

void* mmalloc(int32_t size_in_bytes) {
    mminit();
    int32_t one_size = sizeof(int32_t);
    int32_t num_of_locations = (size_in_bytes + one_size -1) / one_size;

    int32_t chunK_i = 0;
    while (chunK_i < SIZE && HEAP[chunK_i] < num_of_locations) {
        if (HEAP[chunK_i > 0]) {
            chunK_i += HEAP[chunK_i] + 2;
        } else {
            chunK_i += -HEAP[chunK_i] + 2;
        }
    }

    if (SIZE <= chunK_i) {
        return NULL;
    }

    int32_t my_size = HEAP[chunK_i] - 2;
    int32_t resid_size = HEAP[chunK_i]-num_of_locations - 2;
    if (resid_size > 0) {
        // todo split
        my_size = num_of_locations;
        HEAP[chunK_i + my_size + 2] = resid_size;
        HEAP[chunK_i + my_size + 2 + resid_size + 1] = resid_size;
    }
    HEAP[chunK_i] = -my_size;
    HEAP[chunK_i + my_size + 1] = -my_size;

    return &(HEAP[chunK_i]) + 1;
}

int main (void) {

    // int *p = malloc (5*sizeof(int));
    // Tells heap that we want to allocate 20 bytes, asks heap to look for chunks in which there is space to be used
    
    mmprint();
    int *p = mmalloc(4);
    *p = 77;
    mmprint();

    return 0;
}