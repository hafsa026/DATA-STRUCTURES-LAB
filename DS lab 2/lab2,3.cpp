#include <iostream>
using namespace std;

struct Nodetype {
    int data;
    Nodetype *next;
};

Nodetype *first = NULL, *last = NULL;

void insert_end(int val) {
    Nodetype *p = new Nodetype;
    p->data = val;
    p->next = NULL;
    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        last = p;
    }
}

Nodetype* search(int key) {
    Nodetype *p = first;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    return p;
}

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    
    Nodetype *result = search(20);
    if (result != NULL)
        cout << "Value found: " << result->data << endl;
    else
        cout << "Value not found" << endl;
    
    return 0;
}