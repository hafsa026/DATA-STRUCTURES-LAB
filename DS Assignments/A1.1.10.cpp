// Task10_SwapPairs.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) { head = newNode; return; }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void swapPairs() {
    if (head == NULL || head->next == NULL) return;

    Node* prev = NULL;
    Node* curr = head;
    head = head->next;   // new head will be second node

    while (curr != NULL && curr->next != NULL) {
        Node* first = curr;
        Node* second = curr->next;

        first->next = second->next;
        second->next = first;

        if (prev != NULL) prev->next = second;

        prev = first;
        curr = first->next;
    }
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    for (int i = 1; i <= 6; i++) insert(i);

    cout << "Input:  ";
    display();

    swapPairs();

    cout << "Output: ";
    display();

    return 0;
}