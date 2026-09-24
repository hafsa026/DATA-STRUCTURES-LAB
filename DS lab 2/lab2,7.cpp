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

void delete_node(int key) {
    Nodetype *q = first, *q1 = NULL;
    
    while (q != NULL && q->data != key) {
        q1 = q;
        q = q->next;
    }
    
    if (q == NULL) {
        cout << "Value not found" << endl;
        return;
    }
    
    if (q == first && q == last) {
        // only node
        first = last = NULL;
    } else if (q == first) {
        first = first->next;
    } else if (q == last) {
        q1->next = NULL;
        last = q1;
    } else {
        q1->next = q->next;
    }
    delete q;
    cout << "Node deleted" << endl;
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
    
    delete_node(20);
    display();
    
    return 0;
}