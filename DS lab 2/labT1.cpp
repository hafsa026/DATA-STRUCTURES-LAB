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

// Iterative reverse display
void displayReverseIterative() {
    // Count nodes
    int count = 0;
    Nodetype *p = first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    
    // Print from end
    for (int i = count - 1; i >= 0; i--) {
        p = first;
        for (int j = 0; j < i; j++) {
            p = p->next;
        }
        cout << p->data << " -> ";
    }
    cout << "NULL" << endl;
}

// Recursive reverse display
void displayReverseRecursive(Nodetype *p) {
    if (p == NULL) return;
    displayReverseRecursive(p->next);
    cout << p->data << " -> ";
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
    insert_end(40);
    
    cout << "Original: ";
    display();
    
    cout << "Reverse (Iterative): ";
    displayReverseIterative();
    
    cout << "Reverse (Recursive): ";
    displayReverseRecursive(first);
    cout << "NULL" << endl;
    
    return 0;
}