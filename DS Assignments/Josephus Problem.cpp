// Circular_Josephus.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

int main() {
    int n, m;
    cout << "Enter N (total persons): ";
    cin >> n;
    cout << "Enter M (skip count): ";
    cin >> m;

    // Build circular list 1..n
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= n; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    temp->next = head;   // make circular

    Node* curr = head;
    Node* prev = temp;

    cout << "Elimination order: ";
    while (curr->next != curr) {
        // Skip m-1 persons
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }
        cout << curr->data << " ";
        prev->next = curr->next;
        Node* del = curr;
        curr = curr->next;
        delete del;
    }

    cout << "\nSurvivor: " << curr->data << endl;
    delete curr;

    return 0;
}