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

// This swaps the DATA inside the nodes (Safe and easy)
void swapNodes(int val1, int val2) {
    if (val1 == val2) return;
    
    Nodetype *n1 = search(val1);
    Nodetype *n2 = search(val2);
    
    if (n1 == NULL || n2 == NULL) {
        cout << "One or both values not found" << endl;
        return;
    }
    
    int temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
    
    cout << "Nodes swapped successfully" << endl;
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
    insert_end(40);
    
    cout << "Original: ";
    display();
    
    swapNodes(20, 30);
    cout << "After swap: ";
    display();
    
    return 0;
}