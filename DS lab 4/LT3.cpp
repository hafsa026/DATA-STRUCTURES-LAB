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

// Delete all even-positioned nodes (1-based indexing)
void deleteEvenPositions() {
    if (last == NULL) return;

    Node* ptr = last->next;  // first node
    Node* prev = last;
    int pos = 1;

    // If list has only one node, its position is 1 (odd) - keep it
    if (ptr->next == ptr) {
        cout << "Only one node at position 1 (odd). Nothing deleted.\n";
        return;
    }

    do {
        Node* nextNode = ptr->next;

        if (pos % 2 == 0) {
            // Delete ptr
            if (ptr == last) {
                last = prev;
            }
            prev->next = ptr->next;
            delete ptr;
            ptr = nextNode;
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
        pos++;
    } while (ptr != last->next && last != NULL);

    cout << "All even-positioned nodes deleted.\n";
}

int main() {
    // Test with odd number of nodes
    cout << "Test 1: Odd number of nodes (5)\n";
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    display();
    deleteEvenPositions();
    display();

    // Test with even number of nodes
    cout << "\nTest 2: Even number of nodes (6)\n";
    last = NULL;
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    insertEnd(6);
    display();
    deleteEvenPositions();
    display();

    // Test with single node
    cout << "\nTest 3: Single node\n";
    last = NULL;
    insertEnd(100);
    display();
    deleteEvenPositions();
    display();

    return 0;
}