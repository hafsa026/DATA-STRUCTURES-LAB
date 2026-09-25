#include <iostream>
using namespace std;

struct Nodetype {
    int data;
    Nodetype *next;
    Nodetype *prev;
};

Nodetype *first = NULL, *last = NULL;

void insert_end(int val) {
    Nodetype *p = new Nodetype;
    p->data = val;
    p->next = NULL;
    p->prev = NULL;
    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        p->prev = last;
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

void delete_node(int key) {
    Nodetype *p = search(key);
    if (p == NULL) {
        cout << "Value not found" << endl;
        return;
    }
    
    if (first == p && last == p) {
        // Single node
        first = last = NULL;
    } else if (p == first) {
        // Delete first
        first = first->next;
        first->prev = NULL;
    } else if (p == last) {
        // Delete last
        last = last->prev;
        last->next = NULL;
    } else {
        // Inner node
        p->next->prev = p->prev;
        p->prev->next = p->next;
    }
    delete p;
    cout << "Node deleted" << endl;
}

void display() {
    Nodetype *p = first;
    while (p != NULL) {
        cout << p->data << " <-> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    display();
    
    delete_node(20);
    display();
    
    return 0;
}