// Task6_SeparateEvenOdd.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

Node* head = NULL;
Node* evenHead = NULL;
Node* oddHead = NULL;

void insert(Node*& h, int val) {
    Node* newNode = new Node(val);
    if (h == NULL) { h = newNode; return; }
    Node* temp = h;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void separate() {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0)
            insert(evenHead, temp->data);
        else
            insert(oddHead, temp->data);
        temp = temp->next;
    }
}

void display(Node* h) {
    Node* temp = h;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insert(head, 10);
    insert(head, 15);
    insert(head, 20);
    insert(head, 25);
    insert(head, 30);
    insert(head, 35);
    insert(head, 40);

    cout << "Original: ";
    display(head);

    separate();

    cout << "Even Prices: ";
    display(evenHead);

    cout << "Odd Prices: ";
    display(oddHead);

    return 0;
}