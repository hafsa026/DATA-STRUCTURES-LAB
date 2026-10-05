#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* last = NULL;

void insertEnd(int value) {
    Node* p = new Node;
    p->data = value;
    if (last == NULL) {
        last = p;
        last->next = last;
    } else {
        p->next = last->next;
        last->next = p;
        last = p;
    }
}

// Insert a new node before the node with key = givenKey
void insertBefore(int givenKey, int newValue) {
    if (last == NULL) {
        cout << "List is empty. Cannot insert before.\n";
        return;
    }

    Node* q = last->next;  // start from first node
    Node* q1 = last;       // previous node (last initially)

    do {
        if (q->data == givenKey) break;
        q1 = q;
        q = q->next;
    } while (q != last->next);

    if (q->data != givenKey) {
        cout << "Key " << givenKey << " not found.\n";
        return;
    }

    Node* p = new Node;
    p->data = newValue;

    if (q == last->next) {
        // Inserting before the first node
        p->next = q;
        q1->next = p;    // q1 is last
        // last remains same
    } else if (q == last) {
        // Inserting before the last node
        q1->next = p;
        p->next = q;
    } else {
        // Inserting in the middle
        q1->next = p;
        p->next = q;
    }
    cout << "Inserted " << newValue << " before " << givenKey << ".\n";
}

void display() {
    if (last == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = last->next;
    cout << "Circular List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    display();

    insertBefore(30, 25);
    display();

    insertBefore(10, 5);
    display();

    insertBefore(40, 35);
    display();

    return 0;
}