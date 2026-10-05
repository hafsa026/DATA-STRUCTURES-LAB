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

// Delete the entire circular linked list
void deleteList() {
    if (last == NULL) {
        cout << "List is already empty.\n";
        return;
    }

    Node* p = last->next;   // start from first node
    Node* p1;

    do {
        p1 = p;
        p = p->next;
        delete p1;
    } while (p != last->next);

    last = NULL;
    cout << "Entire circular linked list deleted.\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    cout << "Deleting list...\n";
    deleteList();

    deleteList();  // try deleting again
    return 0;
}