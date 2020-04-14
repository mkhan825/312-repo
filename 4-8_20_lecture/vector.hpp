
#include <cstdint>

#define STEP 10

class Vector {
private:
    int32_t size;
    int32_t len;
    int32_t *elems;

public:

    Vector(int init);

    Vector(Vector &other) {
        print("copy\n");
        this->size = other.size;
        this->len = other.len;
        this->elems = new int32_t[other.size];
        for(int i = 0; i < size; i++) {
            this->elems[i] = other.elems[i];
        }
    }

    ~Vector();

    int32_t getLen();

    int32_t get(int ix) {
        return elems[ix];
    }

    int32_t getSize() {
        return this->size;
    }

    void add(int32_t el) {
        if (len == size) {
            size *= 2;
            //            elems = (int32_t*) realloc(elems, sizeof(int32_t) * size);
            int32_t *nelems = new int32_t[size];
            for (int i = 0; i < len; i++) {
                nelems[i] = elems[i];
            }
            delete [] elems;
            elems = nelems;
        }
        elems[len] = el;
        len++;
    }

    void operator+=(int el) {
        add(el);
    }

    void operator--() {
        if (len >  0) {
            len--;
        }
    }

    void print() {
        printf("Vector len=%d, size=%d\n", len, size);
        for (int32_t i = 0; i < len; i++) {
            printf("%d ", elems[i]);
        }
        printf("\n");
    }
};
