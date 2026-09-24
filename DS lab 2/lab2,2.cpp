#include <iostream>
using namespace std;

struct Nodetype {
    int data;
    Nodetype *next;
};

Nodetype *first = NULL, *last = NULL;

void insert_start() {
    Nodetype *p = new Nodetype;
    cout << "Enter the data in node: ";
    cin >> p->data;
    p->next = NULL;
    
    if (first == NULL) {
        first = last = p;
    } else {
        p->next = first;
        first = p;
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
    insert_start();
    insert_start();
    insert_start();
    display();
    return 0;
}