// Task4_DetectLoop.cpp
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

void createLoop(int pos) {
    Node* last = head;
    while (last->next != NULL) last = last->next;

    Node* target = head;
    for (int i = 0; i < pos; i++) target = target->next;

    last->next = target;
}

bool detectLoop() {
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    if (detectLoop())
        cout << "Loop Detected" << endl;
    else
        cout << "No Loop" << endl;

    createLoop(2);   // create a loop

    if (detectLoop())
        cout << "Loop Detected" << endl;
    else
        cout << "No Loop" << endl;

    return 0;
}