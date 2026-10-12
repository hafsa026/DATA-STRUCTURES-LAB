#include <iostream>
using namespace std;

#define SIZE 8

class Que {
    int q[SIZE];
    int front, rear;

    void shift_left(int f, int r) {
        for (int x = f; x < r; x++)
            q[x] = q[x + 1];
    }

public:
    Que() { front = rear = -1; }

    bool isEmpty() { return (front == -1); }
    bool isFull()  { return (rear == SIZE - 1); }

    void enQueue(int v) {
        if (isFull()) { cout << "\nQueue is Full"; return; }
        if (isEmpty()) front = rear = 0;
        else rear++;
        q[rear] = v;
    }

    int deQueue() {
        int temp;
        if (!isEmpty()) {
            temp = q[front];
            if (front == rear) {
                front = rear = -1;      // queue becomes empty
            } else {
                shift_left(front, rear); // shift elements left
                rear--;
            }
        } else {
            cout << "\nSorry Q is Empty ";
            temp = -1;
        }
        return temp;
    }

    void display() {
        if (isEmpty()) { cout << "\nQueue is empty"; return; }
        cout << "\nQueue: ";
        for (int i = front; i <= rear; i++) cout << q[i] << " ";
    }
};

int main() {
    Que q;
    for (int i = 1; i <= 5; i++) q.enQueue(i * 10);
    q.display();

    cout << "\nDequeued: " << q.deQueue();
    cout << "\nDequeued: " << q.deQueue();
    q.display();

    q.enQueue(60);
    q.enQueue(70);
    q.display();
    return 0;
}