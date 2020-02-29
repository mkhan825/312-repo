/*
 * Name: Masaad Khan
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "String.h"

#define SIGNATURE (~0xdeadbeef)

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    uint32_t length = 0;
    for (int i = 0; *(s->string+i) != '\0' ; i++) {
        length++;
    }
    return (length-4);
}

/* 
 * Allocate a utstring on the heap. 
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    //find length/capacity of string
    int capacity = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        capacity++;
    }
    UTString *ptr = (UTString*) malloc(sizeof(UTString)*1);
    for (int i = 0 ; i < capacity ; i++ ) {
        *(ptr->string) = src[i];
        *(ptr->string) = '\0';
    }
	return ptr;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s. 
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) { // im confused
    int capacity = 0;
    for (int i = 0; i < *(s->string) ; i++) {
        capacity++;
    }
    for (int i = 0; i < capacity; i++) {

    }
	return NULL;
}

/* 
 * Copy src into dst.
 *  dst must be a valid UTString. 
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst. 
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    int capacity = 0;
    for (int i = 0; src[i]!= '\0' ; i++) {
        capacity++;
    }
    for (int i = 0; (i < capacity)||(*dst->string+i)=='\0' ; i++) {
        *(dst->string+i) = src[i];
    }
    dst->length = capacity-4;
	return dst;
}

/*
 * Free all memory associated with the given UTString. 
 */
void utstrfree(UTString* self) {

}

/* 
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity, 
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata. 
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    //find capacity
	if (new_capacity > (*s).capacity) {
	    int *ptr = (int*)malloc(sizeof(char)*new_capacity);

	}
    return NULL;
}
