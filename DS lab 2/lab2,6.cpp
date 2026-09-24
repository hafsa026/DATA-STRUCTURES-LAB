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

void delete_last() {
    Nodetype *q, *q1;
    q1 = NULL;
    q = first;
    
    if (q == NULL) {
        cout << "Linked List is empty" << endl;
    } else {
        while (q != last) {
            q1 = q;
            q = q->next;
        }
        if (q == first) {
            // only one node
            delete q;
            first = last = NULL;
        } else {
            q1->next = NULL;
            last = q1;
            delete q;
        }
        cout << "Last node deleted" << endl;
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
    
    delete_last();
    display();
    
    return 0;
}