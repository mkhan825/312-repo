
using namespace std;
#include <string>

// class string {
// private:
//     char *data;
// public:
//     string(char *d) {
//         data = ...;
//         // data <= d
//     }

//     ~string() {
//         delete [] data;
//     }

//     string(string &other);

//     bool operator==(string &other);
//     bool operator<(string &other);
// };

class Node {
public:
    string val;
    Node *next;
};

class LL {
private:
    int len;
    Node *head;

public:
    LL(void) : len(0), head(NULL) {}

    ~LL() {
        // todo
    }

    // assignment
    // copy constructor

    void add(string el) {
        Node *node = new Node();
        node->val = el;
        node->next = head;
        head = node;
        len++;
    }

    bool find(string el) {
        Node *current = head;
        while (current != NULL) {
            if (current->val == el) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    LL rotate(LL given, LL third) {
        Node *current = given.head;
        Node *current2 = given.head;
        string last;
        while (current != NULL) {
            third.add(current->val);
            last = current->val;
            current = current->next;
        }
        third.add(last);
        current2 = current2->next;
        while(current2 != NULL) {
            third.add(current2->val);
            current2 = current2->next;
        }
        return third;
    }

    LL combine(LL first, LL second, LL third) {
        Node *current = first.head;
        Node *current2 = second.head;
        while (current != NULL) {
            third.add(current->val);
            current = current->next;
        }
        while (current2 != NULL) {
            third.add(current2->val);
            current2 = current2->next;
        }
        return third;
    }

    LL operator+(LL newer, LL third) {
        LL *newer = new LL();
        Node *newer = this->head;
        while(acurrent != 0) {
            a.add(newer->val);
            newer = newer->next;
        }
    }

    bool remove(string el) {
        Node *current = head;
        Node *prev = NULL;
        while (current != NULL) {
            if (current->val == el) {
                break;
            }
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            return false;
        }
        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current; // free(current);
        len--;
        return true;
    }
};
