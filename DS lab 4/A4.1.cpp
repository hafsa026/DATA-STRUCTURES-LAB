#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* pNode = NULL;  // points to LAST node

// Insert at end
void insert_end(int value) {
    Node* p = new Node;
    p->data = value;
    
    if (pNode == NULL) {
        // Empty list — first node
        pNode = p;
        p->next = pNode;   // last->next = first (itself)
    } else {
        // List has nodes
        p->next = pNode->next;   // new node points to first node
        pNode->next = p;         // old last points to new node
        pNode = p;               // pNode becomes new last
    }
}

// Display the list
void display() {
    if (pNode == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* p = pNode->next;  // start from first node
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != pNode->next);
    cout << endl;
}

// Main
int main() {
    cout << "=== Circular Linked List: Insert at End ===" << endl;
    
    
    cout<< insert_end(10);
    display();
    
    insert_end(20);
    cout << "After insert 20: ";
    display();
    
    insert_end(30);
    cout << "After insert 30: ";
    display();
    
    insert_end(40);
    cout << "After insert 40: ";
    display();
    
    return 0;
}