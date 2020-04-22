
#include <iostream>
#include "vector.hpp"

Vector::Vector(int init) {
    printf("constructor\n");
    this->size = init;
    this->len = 0;
    this->elems = new int32_t[size]; // (int32_t*) malloc(sizeof(int32_t) * size);
}

Vector::~Vector() {
    printf("destructor\n");
    delete [] elems;
    // free(elems);
}

int32_t Vector::getLen() {
    return this->len;
}

int sumVal(Vector v) {
    int sum = 0;
    for (int i = 0; i < v.getSize(); i++){
        sum += v.get(i); //v.elems[i]
    }
}

int sumPtr(Vector *v) {
    int sum = 0;
    for (int i = 0; i < v->getSize(); i++){
        sum += v->get(i); //v.elems[i]
    }
} //Doing sum with pointers

int sumRef(Vector &v){
    int sum = 0;
    for (int i = 0; i < v.getSize(); i++){
        sum += v.get(i); //v.elems[i]
    }
} //Trying to implement sum with pointers but without pointers

int main(void) {
    Vector v1(10);
    Vector v2(20);

    Vector v3 = v1;
    //Vector *v3 = new Vector(30);

    printf("%d\n", v1.getLen());
    printf("%d\n", v2.getLen());

    for (int i = 0; i < 77; i++) {
        v1 += i; // === v1.add(i);
    }

    int sum = sumVal(v1);
    sum = sumPtr(&v1);
    sum = sumRef(v1);

    printf("%d\n", sum);
    

    //--v1;

    v1.print();
    //v2.print();

    //delete v3;

    return 0;
}
