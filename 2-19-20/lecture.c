#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct vector {
    int cap; 
    int size;
    int *elems;
} Vector;

Vector* vectorAlloc(void) {
    Vector *v = malloc(1 * sizeof(Vector));
    v->cap = N;
    v->size = 0;
    v->elems = malloc(N);
    return v;
}    
// We have the capacity so that we can double the size of the vector once we hit the initial capacity. It is a lot better to do this than to reallocate everytime we need to add something. It takes more time to reallocate.

void vectorAdd (Vector *v, int el) {
    // check the capacity
    if (v->size >= v->cap) {
        v-> cap *= 2;
        v->elems = realloc(v->elems, v->cap * sizeof(int));
        //Check for NULL
    }

    v->elems[v->size] = el;
    (v->size)++;
}

struct name {
    char first[50];
    char last[50];
};

struct person {
    int id;
    struct name fullname;
    int age;
};

void person canDrink(struct person *p) { // Everything in C is passed by value not by reference. It is very very inefficient to pass by value because we have to copy over and over again values
    if (p.age > 21) { // depends on the country (this is for USA); for Serbia it would be p.age > 0
        printf("Yes\n");
    } else {
        printf("No\n");
        //return p; // If we wanted to reflect a change in an instance we can return the value in order to do this
    }
    p->age = 66; // Same to reflect a change to an instance
}
int main (void) {
    //struct person dean; // struct person dean = {.id = 1, .age = idk} Techncially this could work however probably not for the characters
    struct person *dean = malloc(1*sizeof(struct person));

    (*dean).id = 1; // dean->id = 1; Same thing as the line. Uses pointer

    //dean.id = 1; Once we change dean into a pointer, we cannot use the same method in order to access these values
    strcpy(dean->fullname.first, "Dean");    
    dean->age = 40;

    printf("%d %s %d\n", dean->id, dean->fullname.first, dean->age);
    canDrink(dean);

    free(dean);

    Vector *v = vectorAlloc();
    for (int i = 0; i < 100; i++) {
        vecotrAdd(v, i);
    }
    return 0;
}

/*
struct point {
    int x, y;
} a, b, c;

//Creates int x and y for each different list thingy: a, b, c.

struct rectanble {
    struct point( south_west, north_east);
};

//You can nest structs to create complex structs

struct circle {
    double r;
    struct point center;
};

//Can nest different types within the same struct, double and int for example

to make a database:
struct person {
    int age;
    int height;
    etc...
};*/