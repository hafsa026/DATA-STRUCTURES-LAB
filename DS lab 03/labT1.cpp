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

void reverseList() {
    Nodetype *current = first;
    Nodetype *temp = NULL;
    
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    // Swap first and last
    temp = first;
    first = last;
    last = temp;
    
    cout << "List reversed" << endl;
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
    
    reverseList();
    cout << "Reversed: ";
    display();
    
    return 0;
}