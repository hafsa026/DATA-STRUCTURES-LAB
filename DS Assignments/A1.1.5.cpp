// Task5_FindMiddle.cpp
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

int findMiddle() {
    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    cout << "Odd List (1..5) Middle: " << findMiddle() << endl;

    // Reset for even list
    head = NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);

    cout << "Even List (1..6) Middle (left): " << findMiddle() << endl;

    return 0;
}