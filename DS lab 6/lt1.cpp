#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class LinkedQueue {
    Node* front;
    Node* rear;

public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    ~LinkedQueue() {
        while (front) {
            Node* t = front;
            front = front->next;
            delete t;
        }
    }

    bool isEmpty() { return (front == nullptr); }

    void enqueue(int v) {
        Node* n = new Node(v);
        if (isEmpty()) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
        cout << "\nEnqueued: " << v;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is empty (Underflow)";
            return -1;
        }
        Node* t = front;
        int v = t->data;
        front = front->next;
        if (front == nullptr) rear = nullptr;   // queue became empty
        delete t;
        return v;
    }

    void display() {
        if (isEmpty()) { cout << "\nQueue is empty"; return; }
        cout << "\nQueue: ";
        for (Node* p = front; p; p = p->next)
            cout << p->data << " ";
    }
};

int main() {
    LinkedQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "\nDequeued: " << q.dequeue();
    cout << "\nDequeued: " << q.dequeue();
    q.display();

    q.enqueue(40);
    q.display();

    return 0;
}