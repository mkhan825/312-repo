#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Setlist {
    int* elements;
    int len;
    // int capacity; // NOTE: amortized doubling does not improve the time complexity for these problems
    /* in fact, you can safely ignore capacity entirely. I'm including it here just in case some
     * students feel more comfortable tracking the array size and the number of elements independently
     * REPEATNG: You do not need to to implement amortized doubling in order to achieve the time-complexity
     * bounds for this problem. You can achieve all the time complexity bounds even when
     * capacity is ignored (i.e., your design can assume capacity == len).
     */
} Set;

void createEmptySet(Set* self) {
    self->len = 0;
    self->elements = 0;
}

void destroySet(Set* self) {
    free(self->elements);
}

int array1[] = {3,4,5,6,7};
int array2[] = {1,3,6,7,8,9,10};

void intersectFromSet(Set* self, const Set* other) {
    int i = 0;
    int j = 0;
    int count = 0;
    Set* inter = (Set*) malloc(sizeof(Set));
    createEmptySet(inter);
    inter->elements = (int*) malloc(sizeof(int)*100);
    while( (i < self->len) && (j < other->len) ) {
        if(self->elements[i] > other->elements[j]) {
            //check the next element, undetermined
            j++;
        } else {
            if (self->elements[i] < other->elements[j]) {
                //get rid of number in the list 1
                i++;
            } else {
                if(self->elements[i] == other->elements[j]) {
                    // keep elements
                    inter->elements[count] = self->elements[i];
                    count++;
                    i++;
                    j++;
                }
            }
        }
    }
    for(int k = 0; k < count; k++) {
        self->elements[k] = inter->elements[k];
    }
    self->len = count;
    destroySet(inter);
}

void subtractFromSet(Set* self, const Set* other) {
    int i = 0;
    int j = 0;
    int count = 0;
    Set* inter = (Set*) malloc(sizeof(Set));
    createEmptySet(inter);
    inter->elements = (int*) malloc(sizeof(int)*100);
    while( (i < self->len) && (j < other->len) ) {
        if(self->elements[i] > other->elements[j]) {
            //check the next element, undetermined
            j++;
            if((i == self->len - 1) && (j == other->len)) {
                inter->elements[count] = self->elements[i];
                count++;
                i++;
            }
        } else {
            if (self->elements[i] < other->elements[j]) {
                //save number
                inter->elements[count] = self->elements[i];
                count++;
                i++;
            } else {
                if(self->elements[i] == other->elements[j]) {
                    // don't save elements
                    i++;
                }
            }
        }
    }
    for(int k = 0; k < count; k++) {
        self->elements[k] = inter->elements[k];
    }
    self->len = count;
    destroySet(inter);
}

void unionInSet(Set* self, const Set* other) {
    int i = 0;
    int j = 0;
    int count = 0;
    Set* inter = (Set*) malloc(sizeof(Set));
    createEmptySet(inter);
    inter->elements = (int*) malloc(sizeof(int)*100);
    while( (i < self->len) && (j < other->len) ) {
        if(self->elements[i] > other->elements[j]) {
            //check the next element, undetermined
            j++;
        } else {
            if (self->elements[i] < other->elements[j]) {
                i++;
            } else {
                if(self->elements[i] == other->elements[j]) {
                    // save elements
                    i++;
                    j++;
                    inter->elements[count] = self->elements[i];
                    count++;
                }
            }
        }
    }
    for(int k = 0; k < count; k++) {
        self->elements[k] = inter->elements[k];
    }
    self->len = count;
    destroySet(inter);
}

void displaySet(const Set* self) {
    int k;
    printf("{");
    if (self->len == 0) {
        printf("}");
    }
    else {
        for (k = 0; k < self->len; k += 1) {
            if (k < self->len - 1) {
                printf("%d,", self->elements[k]);
            } else {
                printf("%d}", self->elements[k]);
            }
        }
    }
}

int main(void) {
    Set* setone = (Set*) malloc(sizeof(Set));
    Set* settwo = (Set*) malloc(sizeof(Set));
    createEmptySet(setone);
    createEmptySet(settwo);
    setone->elements = (int*) malloc(sizeof(int) * 5);
    settwo->elements = (int*) malloc(sizeof(int) * 3);
    setone->len = 5;
    settwo->len = 7;
    for(int i = 0; i < 5; i++) {
        setone->elements[i] = array1[i];
    }
    for(int i = 0; i < 7; i++) {
        settwo->elements[i] = array2[i];
    }
    displaySet(setone);
    displaySet(settwo);
    unionInSet(setone, settwo);
    displaySet(setone);
    free(setone);
    free(settwo);
}