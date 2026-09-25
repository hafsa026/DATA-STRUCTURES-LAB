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

void insert_after(int key, int val) {
    Nodetype *q = search(key);
    if (q == NULL) {
        cout << "Value not found" << endl;
        return;
    }
    
    Nodetype *p = new Nodetype;
    p->data = val;
    
    p->prev = q;
    p->next = q->next;
    
    if (q->next != NULL)
        q->next->prev = p;
    q->next = p;
    
    if (last == q)
        last = p;
    
    cout << "Node inserted after " << key << endl;
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
    
    insert_after(20, 25);
    display();
    
    return 0;
}