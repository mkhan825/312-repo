/*
 * Copy the contents of header.txt (filled out) and paste here
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"

/*
 * Several of the required functions have been written already
 * You may use these functions as-is or you may modify them in any way.
 * Please NOTE, you are responsible for ensuring that the functions work correctly in
 * your project solution. Just because the function works correctly in my solution does
 * NOT mean that the function will work correctly in yours.
 */

/*
 * Design NOTES:
 *
 * The design provided in this starter kit assumes
 * (1) empty sets will be represented with length == 0 and elements == nullptr (i.e., address 0)
 * (2) amortized doubling is not used, and capacity is ignored/unused. Functions should assume that
 * the amount of storage available in the elements[] array is equal to length
 */


/* done for you already */
void destroySet(Set* self) {
    free(self->elements);
}

/* done for you already */
void createEmptySet(Set* self) {
    self->len = 0;
    self->elements = nullptr;
}

/* done for you already */
void createSingletonSet(Set* self, int x) {
    self->elements = (int*) malloc(sizeof(int));
    self->elements[0] = x;
    self->len = 1;
}

/* done for you already */
void createCopySet(Set* self, const Set* other) {
    self->elements = (int*) malloc(other->len * sizeof(int));
    for (int k = 0; k < other->len; k += 1) {
        self->elements[k] = other->elements[k];
    }
    self->len = other->len;
}

/* done for you already */
void assignSet(Set* self, const Set* other) {
    if (self == other) { return; }

    destroySet(self);
    createCopySet(self, other);
}

/* return true if x is an element of self */
bool isMemberSet(const Set* self, int x) {
    /*Set* dup = (Set*) malloc(sizeof(Set));
    if(self->len == 0) {
        return false;
    }
    if(self->len == 1) {
        return self->elements[self->len] == x;
    }
    if(self->elements[self->len/2] > x) {
        createCopySet(dup, self);
        dup->len = dup->len/2;
        dup->elements += sizeof(int)*dup->len/2;
        isMemberSet(dup, x);
        destroySet(dup);
    } else {
        if(self->elements[self->len/2] < x) {
            createCopySet(dup, self);
            dup->len = dup->len/2;
            isMemberSet(dup, x);
            destroySet(dup);
        } else {
            if(self->elements[dup->len/2] == x) {
                destroySet(dup);
                return true;
            }
        }
    }*/
    if (self->len == 0) {
        return false;
    }
    int beginning = 0;
    int end = self->len;
    while (beginning <= end) {
        int middle = (beginning + end)/2;
        if (self->elements[middle] == x) {
            return true;
        }
        if (self->elements[middle] < x) {
            if(beginning == end) {
                return false;
            }
            beginning = middle + 1;
        } else {
            end = middle - 1;
        }

    }
    return false;
}


/*
 * add x as a new member to this set.
 * If x is already a member, then self should not be changed
 * Be sure to restore the design invariant property that elemnts[] remains sorted
 * (yes, you can assume it is sorted when the function is called, that's what an invariant is all about)
 */
void insertSet(Set* self, int x) {
    if (isMemberSet(self, x)) {
        return;
    }
    self->len++;
    if(self->len == 1) {
        self->elements = (int*) malloc(sizeof(int));
        self->elements[0] = x;
        return;
    } else {
        self->elements = (int*) realloc(self->elements, sizeof(int) * self->len);
        self->elements[self->len - 1] = x;
        int tmp;
        for(int i = self->len-1; i > 0; i--) {
            if (self->elements[i-1] > self->elements[i]) {
                tmp = self->elements[i];
                self->elements[i] = self->elements[i-1];
                self->elements[i-1] = tmp;
            }
        }
    }
}


/*
 * don't forget: it is OK to try to remove an element
 * that is NOT in the set.
 * If 'x' is not in the set 'self', then
 * removeSet should do nothing (it's not an error)
 * Otherwise, ('x' IS in the set), remove x. Be sure to update self->length
 * It is not necessary (nor recommended) to call malloc -- if removing an element means the
 * array on the heap is "too big", that's almost certainly OK, and reallocating a smaller array
 * is almost definitely NOT worth the trouble
 */
void removeSet(Set* self, int x) {
    if (!isMemberSet(self, x)) {
        return;
    }
    int i = 0;
    for(; i < self->len; i++) {
        if(self->elements[i] == x) {
            break;
        }
    }
    for(int j = i; j < self->len-1; j++) {
        self->elements[j] = self->elements[j+1];
    }
    self->len--; // Check what if the thing is at the last elements will it still work
}

/* done for you already */
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

/* return true if self and other have exactly the same elements */
bool isEqualToSet(const Set* self, const Set* other) {
    if(self->len != other->len) {
        return false;
    }
    for(int i = 0; i < self->len; i++) {
        if(self->elements[i] != other->elements[i]) {
            return false;
        }
    }
    return true;
}

/* return true if every element of self is also an element of other */
bool isSubsetOf(const Set* self, const Set* other) {
    int count = 0;
    int i = 0;
    int j = 0;
    if(self->len == other->len) {
        if(isEqualToSet(self, other)) {
            return true;
        };
    }
    //Set* inter = (Set*) malloc(sizeof(Set));
    //createCopySet(inter, self);
    if(self->len == 0 && other->len == 0) {
        return true;
    } else if(self->len == 0) {
        return true;
    } else if(other->len == 0) {
        return false;
    }
    if(self->len > other->len) {
        return false;
    }
    /*intersectFromSet(inter, other);
    if(isEqualToSet(self, inter)) {
        return true;
    } else {
        return false;
    }*/
    while((i < self->len) && (j < other->len)) {
        if(self->elements[i] > other->elements[j]) {
            j++;
        } else {
            if(self->elements[i] < other->elements[j]) {
                i++;
            } else {
                if(self->elements[i] == other->elements[j]) {
                    count++;
                    i++;
                    j++;
                }
            }
        }
    }
    //destroySet(inter);
    return count == self->len;
}

/* done for you */
bool isEmptySet(const Set* self) {
    return self->len == 0;
}

/* remove all elements from self that are not also elements of other */
void intersectFromSet(Set* self, const Set* other) {
    int i = 0;
    int j = 0;
    int count = 0;
    Set* inter = (Set*) malloc(sizeof(Set));
    createEmptySet(inter);
    inter->len = other->len + self->len;
    inter->elements = (int*) malloc(sizeof(int)*inter->len);
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
    inter->len = count;
    assignSet(self, inter);
    destroySet(inter);
}

/* remove all elements from self that are also elements of other */
void subtractFromSet(Set* self, const Set* other) {
    if(self->len == 0 || other->len == 0) {
        return;
    }
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
                //save number
                inter->elements[count] = self->elements[i];
                count++;
                i++;
            } else {
                if(self->elements[i] == other->elements[j]) {
                    // don't save elements
                    i++;
                    j++;
                }
            }
        }
    }
    while(i < self->len) {
        inter->elements[count] = self->elements[i];
        i++;
        count++;
    }
    for(int k = 0; k < count; k++) {
        self->elements[k] = inter->elements[k];
    }
    self->len = count;
    destroySet(inter);
}

/* add all elements of other to self (obviously, without creating duplicate elements) */
void unionInSet(Set* self, const Set* other) {
    int i = 0;
    int j = 0;
    int count = 0;
    Set* inter = (Set*) malloc(sizeof(Set));
    createEmptySet(inter);
    inter->len = self->len + other->len;
    inter->elements = (int*) malloc(sizeof(int)*inter->len);
    while( (i < self->len) && (j < other->len) ) {
        if(self->elements[i] > other->elements[j]) {
            //check the next element, undetermined
            inter->elements[count] = other->elements[j];
            count++;
            j++;
        } else {
            if (self->elements[i] < other->elements[j]) {
                inter->elements[count] = self->elements[i];
                count++;
                i++;
            } else {
                if(self->elements[i] == other->elements[j]) {
                    // save elements
                    inter->elements[count] = self->elements[i];
                    count++;
                    i++;
                    j++;
                }
            }
        }
    }
    while(i < self->len) {
        inter->elements[count] = self->elements[i];
        count++;
        i++;
    }
    while(j < other->len) {
        inter->elements[count] = other->elements[j];
        count++;
        j++;
    }
    inter->len = count;
    assignSet(self, inter);
    destroySet(inter);
}
