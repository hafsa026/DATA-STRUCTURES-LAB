// DoublyTask4_SpecialSeating.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) : data(d), next(NULL), prev(NULL) {}
};

Node* head = NULL;
Node* tail = NULL;

void insert(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) { head = tail = newNode; return; }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Input:  1 2 3 4 5 6 7 8 9
// Output: 1 8 3 6 5 4 7 2 9
void specialPattern() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) { count++; temp = temp->next; }

    int* arr = new int[count];
    temp = head;
    for (int i = 0; i < count; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    // Swap even positions from both ends
    int left = 1;
    int right = count - 2;
    while (left < right) {
        swap(arr[left], arr[right]);
        left += 2;
        right -= 2;
    }

    temp = head;
    for (int i = 0; i < count; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    delete[] arr;
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
    for (int i = 1; i <= 9; i++) insert(i);

    cout << "Input:  ";
    display();

    specialPattern();

    cout << "Output: ";
    display();

    return 0;
}