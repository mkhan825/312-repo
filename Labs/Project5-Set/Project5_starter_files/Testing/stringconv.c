#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
} set;

int array1[] = {1,2,3,6,7};
int array2[] = {1,3,6};
int array3[] = {1,2,4,6,7};
int array4[] = {1,2,3,6};

char* convits (set* a) {
    char* conv = malloc(sizeof(char)*5000);
    int check = 0;
    for(int i = 0; i < a->len*2; i++) {
        if(check == 0) {
            conv[i] = (char) (a->elements[i/2]+48);
            check = 1;
        } else {
            if(i != a->len*2-1) {
                conv[i] = ',';
                check = 0;
            }
        }
    }
    return conv;
}

set* arraytoset (int array[], int len){
    set* a = malloc(sizeof(set));
    a->len = len;
    a->elements = malloc(sizeof(int)*a->len);
    for(int i = 0; i < len; i++) {
        a->elements[i] = array[i];
    }
    return a;
}

int findint(char* a, int index) {
    int num = 0;
    int count = 0;
    int numarr[5000] = {0};
    for(int i = 0; i < 5000; i++) {
        numarr[i] = -1;
    }
    for(int i = index; i < strlen(a); i++) {
        if(a[i] != ',') {
            numarr[i] = (int) (a[i] - 48);
        } else {
            break;
        }
    }
    for(int i = 0; i < 5000; i++) {
        if(numarr[i] != -1) {
            count++;
        }
    }
    for(int i = count; i >= 0; i--) {
        num = num + numarr[count]*10^(count);
    }
    return num;
}

/* remove all elements from self that are not also elements of other */
void intersectFromSet(set* self, const set* other) {
    /*for(int i = 0; i < other->len; i ++) {
        int check = 0;
        check = isMemberSet(self, other->elements[i]);
        if (check == 0) {
            removeSet(self, other->elements[i]);
        }
    }*/
    int i = 0;
    int j = 0;
    char* convert1 = convits(self);
    char* convert2 = convits(other);
    while( (i < strlen(convert1)) && (j < strlen(convert2)) ) {
        if(findint(convert1, i) > findint(convert2, j)) {
            //check the next element, undetermined
            j++;
        } else {
            if (findint(convert1, i) < findint(convert2, j)) {
                //get rid of number in the list 1
                removeSet(self, self->elements[i]);
                i++;
            } else {
                if(findint(convert1, i) == findint(convert2, j)) {
                    // keep elements
                    i++;
                    j++;
                }
            }
        }
    }
}

int main(void) {
    set* set1 = arraytoset(array1, 5);
    set* set2 = arraytoset(array2, 3);
    set* set3 = arraytoset(array3, 5);
    set* set4 = arraytoset(array4, 4);

}