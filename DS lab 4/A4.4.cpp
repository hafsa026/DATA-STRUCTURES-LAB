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

// Delete a node with given key
void deleteNode(int givenKey) {
    if (last == NULL) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }

    Node* q = last->next;  // first node
    Node* q1 = last;       // previous node

    do {
        if (q->data == givenKey) break;
        q1 = q;
        q = q->next;
    } while (q != last->next);

    if (q->data != givenKey) {
        cout << "Key " << givenKey << " not found.\n";
        return;
    }

    // Case 1: Only one node
    if (q == q->next) {
        delete q;
        last = NULL;
        cout << "Deleted " << givenKey << ". List is now empty.\n";
        return;
    }

    // Case 2: Deleting the first node (but not last)
    if (q == last->next) {
        last->next = q->next;
        if (q == last) last = q1;  // safety
    }
    // Case 3: Deleting the last node
    else if (q == last) {
        q1->next = q->next;
        last = q1;
    }
    // Case 4: Deleting a middle node
    else {
        q1->next = q->next;
    }

    delete q;
    cout << "Deleted " << givenKey << ".\n";
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
    insertEnd(50);
    display();

    deleteNode(30);
    display();

    deleteNode(10);
    display();

    deleteNode(50);
    display();

    deleteNode(20);
    display();

    deleteNode(40);
    display();

    return 0;
}