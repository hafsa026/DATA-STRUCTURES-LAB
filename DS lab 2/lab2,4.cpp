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

Nodetype* search(int key) {
    Nodetype *p = first;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    return p;
}

void insert_after(int key) {
    Nodetype *p = search(key);
    if (p == NULL) {
        cout << "Value not found" << endl;
        return;
    }
    
    Nodetype *Newnode = new Nodetype;
    cout << "Enter data for new node: ";
    cin >> Newnode->data;
    
    if (p == last) {
        Newnode->next = NULL;
        last->next = Newnode;
        last = Newnode;
    } else {
        Newnode->next = p->next;
        p->next = Newnode;
    }
    cout << "New node linked successfully" << endl;
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
    
    insert_after(20);
    display();
    
    return 0;
}