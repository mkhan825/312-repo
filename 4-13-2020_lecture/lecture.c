#include <stdio.h>
#include <stdlib.h>
#include <iostream> // C++ library for input/output. Replaces printf, scanf.

public:
    class Iterator {
    private:
        int *current;
    public:
        Iterator(int *c) : current(c) {}
        void operator++ (int unused) { current++; }
        bool operator!=(Iterator other) { current != other.current; }
        int32_t operator*(void) { *current; }
    };

    Iterator begin(void) {
        return Iterator(elems);
    }
    Iterator end(void) {
        return Iterator(elems + len);
    }
    
void destroy(void) {
    delete [] elems;
}
Vector& operator =(Vector &other) {
    //Need to delete the previous array
    destroy();
    copy(other);
    return *this;
}


int main() {
    Vector v3 = v1; // Copy constructor called 

    v3 = v1; // Copy constructor is not called, this ends up becoming a memory leak because v3 elems will now be pointing to v1 elems. 
    //Will also become a double delete cause they point to same area.
    //To fix this we need to overload the equal sign a new function so that it performs the actions we want
    
    //Deep copy: When you have items on the heap/free store in which you have to reinitialize and then copy the whole data

    //Can use all C functions, however, if it is a C++ file you should probably use C++ functionalities
    std::cout << "copy" << std::endl; // writes copy and puts a new line
    std::cout << "Vector len =" << len << ", size=" << size << std::endl;
    for(int32_t i = 0; i < len; i++) {
        std::cout << elems[i] " ";
    }
    std::cout << std::endl;
    int d;
    std::cin >> d; // equivalent to scanf

    //for(inr i = 0; i < v1.size(); i++) {
        //std::cout << v1.get(i); 
    //}
    //This way iterates from beginning to end, it's just that people will not know the implementation of your class
    for(Vector:: Iterator iter = v1.begin(); iter != v1.end(); iter++) {
        std::cout << *iter;
    }
}