// Task7_ReverseHalves.cpp
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

Node* reverseList(Node* node) {
    Node* prev = NULL;
    Node* curr = node;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reverseHalves() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) { count++; temp = temp->next; }

    int half = count / 2;

    Node* firstEnd = head;
    for (int i = 1; i < half; i++) firstEnd = firstEnd->next;

    Node* secondStart = firstEnd->next;
    firstEnd->next = NULL;

    head = reverseList(head);
    secondStart = reverseList(secondStart);

    temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = secondStart;
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
    for (int i = 1; i <= 8; i++) insert(i);

    cout << "Original: ";
    display();

    reverseHalves();

    cout << "After: ";
    display();

    return 0;
}