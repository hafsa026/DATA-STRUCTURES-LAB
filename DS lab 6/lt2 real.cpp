#include <iostream>
using namespace std;

int dq[20];
int front = -1, rear = -1;
int SIZE = 20;

void insertFront(int x) {
    if (front == 0) { cout << "Overflow\n"; return; }
    if (front == -1) front = rear = 0;
    else front--;
    dq[front] = x;
    cout << "Inserted front: " << x << endl;
}

void insertRear(int x) {
    if (rear == SIZE - 1) { cout << "Overflow\n"; return; }
    if (front == -1) front = rear = 0;
    else rear++;
    dq[rear] = x;
    cout << "Inserted rear: " << x << endl;
}

int deleteFront() {
    if (front == -1) { cout << "Empty\n"; return -1; }
    int x = dq[front];
    if (front == rear) front = rear = -1;
    else front++;
    return x;
}

int deleteRear() {
    if (front == -1) { cout << "Empty\n"; return -1; }
    int x = dq[rear];
    if (front == rear) front = rear = -1;
    else rear--;
    return x;
}

void display() {
    if (front == -1) { cout << "Empty\n"; return; }
    cout << "Deque: ";
    for (int i = front; i <= rear; i++) cout << dq[i] << " ";
    cout << endl;
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);
    display();

    cout << "Deleted front: " << deleteFront() << endl;
    cout << "Deleted rear:  " << deleteRear() << endl;
    display();

    return 0;
}