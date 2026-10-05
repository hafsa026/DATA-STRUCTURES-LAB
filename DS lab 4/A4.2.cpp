#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* last = NULL;

void insertEnd(int value) {
    Node* p = new Node;
    p->data = value;
    if (last == NULL) {
        last = p;
        last->next = last;
    } else {
        p->next = last->next;
        last->next = p;
        last = p;
    }
}

// Search for a key in the circular linked list
Node* search(int givenKey) {
    if (last == NULL) return NULL;  // empty list

    Node* p = last->next;  // start from first node
    do {
        if (p->data == givenKey) {
            return p;  // key found
        }
        p = p->next;
    } while (p != last->next);

    return NULL;  // not found
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    int key = 30;
    Node* result = search(key);
    if (result != NULL)
        cout << "Element " << key << " found at address: " << result << endl;
    else
        cout << "Element " << key << " not found.\n";

    key = 99;
    result = search(key);
    if (result != NULL)
        cout << "Element " << key << " found.\n";
    else
        cout << "Element " << key << " not found.\n";

    return 0;
}