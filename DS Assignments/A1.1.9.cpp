// Task9_DeleteAllInstances.cpp
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

void deleteAll(int val) {
    while (head != NULL && head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == NULL) return;

    Node* curr = head;
    while (curr->next != NULL) {
        if (curr->next->data == val) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
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
    insert(5);
    insert(10);
    insert(5);
    insert(20);
    insert(5);
    insert(30);
    insert(5);

    cout << "Original: ";
    display();

    deleteAll(5);

    cout << "After deleting all 5s: ";
    display();

    return 0;
}