#include <stdint.h>

class Vector {
//public: //Class elements are initially private in C++, however, to make them all accessible, you must write public to make it like a struct
private: //By writing private right here, you will be able to say that certain things here are ok to be private
    int32_t size;
    int32_t len;
    int32_t *elems;
};

int main(void) {
    Vector v;
    //v.len = 55; Cant access len of a vec class because that part of vec is private

    return 0;
}