#include <iostream>
using namespace std;

// Singly linked list node
struct SNode {
    int data;
    SNode *next;
};

// Doubly linked list node
struct DNode {
    int data;
    DNode *next;
    DNode *prev;
};

SNode *sFirst = NULL, *sLast = NULL;
DNode *dFirst = NULL, *dLast = NULL;

void insert_singly(int val) {
    SNode *p = new SNode;
    p->data = val;
    p->next = NULL;
    if (sFirst == NULL) {
        sFirst = sLast = p;
    } else {
        sLast->next = p;
        sLast = p;
    }
}

void convertToDoubly() {
    SNode *p = sFirst;
    while (p != NULL) {
        DNode *d = new DNode;
        d->data = p->data;
        d->next = NULL;
        d->prev = NULL;
        
        if (dFirst == NULL) {
            dFirst = dLast = d;
        } else {
            dLast->next = d;
            d->prev = dLast;
            dLast = d;
        }
        p = p->next;
    }
    cout << "Converted to doubly linked list" << endl;
}

void displaySingly() {
    SNode *p = sFirst;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void displayDoubly() {
    DNode *p = dFirst;
    while (p != NULL) {
        cout << p->data << " <-> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insert_singly(10);
    insert_singly(20);
    insert_singly(30);
    
    cout << "Singly Linked List: ";
    displaySingly();
    
    convertToDoubly();
    
    cout << "Doubly Linked List: ";
    displayDoubly();
    
    return 0;
}