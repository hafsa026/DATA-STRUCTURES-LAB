// DoublyTask1_SwapDesks.cpp
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
    Node(string d) : data(d), next(NULL), prev(NULL) {}
};

Node* head = NULL;
Node* tail = NULL;

void insert(string val) {
    Node* newNode = new Node(val);
    if (head == NULL) { head = tail = newNode; return; }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void swapEndsTowardCenter() {
    Node* left = head;
    Node* right = tail;

    while (left != right && left->prev != right) {
        swap(left->data, right->data);
        left = left->next;
        right = right->prev;
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
    insert("Alice");
    insert("Bob");
    insert("Charlie");
    insert("Dana");
    insert("Eva");
    insert("Frank");

    cout << "Original: ";
    display();

    swapEndsTowardCenter();

    cout << "After swap: ";
    display();

    return 0;
}