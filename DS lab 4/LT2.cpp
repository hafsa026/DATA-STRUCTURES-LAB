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

// Josephus problem: n people, every k-th person is eliminated
int josephus(int n, int k) {
    // Build circular linked list with 1..n
    last = NULL;
    for (int i = 1; i <= n; i++)
        insertEnd(i);

    Node* ptr = last->next;  // start from first node
    Node* prev = last;

    cout << "Elimination order: ";
    while (ptr->next != ptr) {
        // Move k-1 steps
        for (int count = 1; count < k; count++) {
            prev = ptr;
            ptr = ptr->next;
        }
        // Eliminate ptr
        cout << ptr->data << " ";
        prev->next = ptr->next;
        if (ptr == last) last = prev;
        delete ptr;
        ptr = prev->next;
    }

    int survivor = ptr->data;
    cout << "\nSurvivor: " << survivor << endl;
    delete ptr;
    last = NULL;
    return survivor;
}

int main() {
    int n = 7, k = 3;
    cout << "Josephus Problem: n = " << n << ", k = " << k << endl;
    int result = josephus(n, k);
    cout << "The safe position is: " << result << endl;
    return 0;
}