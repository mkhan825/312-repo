
#include "linked_list.hpp"

int main(void) {
    // Vector v1;
    // ...

    LL list1;
    LL list2;
    LL list3;
    list1.add("44");
    list2.add("55");
    list3.add("0");
    list3 = list1 + list2;
    list1.remove("44");

    return 0;
}
