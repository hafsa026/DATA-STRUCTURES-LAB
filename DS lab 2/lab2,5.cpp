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

void delete_first() {
    if (first == NULL) {
        cout << "Linked List is empty" << endl;
    } else {
        Nodetype *p = first;
        first = first->next;
        delete p;
        if (first == NULL) last = NULL;
        cout << "First node deleted" << endl;
    }
}

void display() {
    Nodetype *p = first;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    display();
    
    delete_first();
    display();
    
    return 0;
}