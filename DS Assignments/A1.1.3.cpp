// Task3_RemoveDuplicates.cpp
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

void removeDuplicates() {
    Node* curr = head;
    while (curr != NULL) {
        Node* runner = curr;
        while (runner->next != NULL) {
            if (runner->next->data == curr->data) {
                Node* dup = runner->next;
                runner->next = dup->next;
                delete dup;
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
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
    insert(10);
    insert(20);
    insert(10);
    insert(30);
    insert(20);
    insert(40);
    insert(10);

    cout << "Original: ";
    display();

    removeDuplicates();

    cout << "After removing duplicates: ";
    display();

    return 0;
}