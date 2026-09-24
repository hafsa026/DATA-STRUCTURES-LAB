#include <iostream>
using namespace std;

struct Nodetype {
    int data;
    Nodetype *next;
};

Nodetype *first = NULL, *last = NULL;

void insert_end() {
    Nodetype *p = new Nodetype;
    cout << "Enter the data in node: ";
    cin >> p->data;
    p->next = NULL;
    
    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        last = p;
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
    insert_end();
    insert_end();
    insert_end();
    display();
    return 0;
}