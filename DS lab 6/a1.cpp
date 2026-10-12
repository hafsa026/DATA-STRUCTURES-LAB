#include <iostream>
using namespace std;

class Que {
    int size;
    int *q;
    int front;
    int rear;

public:
    Que() {                 // default constructor
        size = 10;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    Que(int x) {            // overloaded constructor
        size = x;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    ~Que() { delete[] q; }

    bool is_empty() { return (rear == -1); }

    bool is_full() { return (rear == size - 1); }

    void display() {
        if (is_empty()) {
            cout << "\nQueue is empty....";
        } else {
            for (int i = front; i <= rear; i++)
                cout << "\nValue at index " << i << " is: " << q[i];
        }
    }

    void Enqueue(int x) {
        if (is_full()) {
            cout << "\nNo space (Overflow)";
        } else {
            if (is_empty()) {
                front = rear = 0;
            } else {
                rear++;
            }
            q[rear] = x;
        }
    }

    int Dequeue() {
        if (is_empty()) {
            cout << "\nQueue is already empty";
            return -1;
        } else {
            int x = q[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
            return x;
        }
    }
};

int main() {
    Que q1;        // default size 10
    Que q2(5);     // size 5
    Que q3(15);    // size 15

    q1.Enqueue(5);
    q2.Enqueue(7);
    q3.Enqueue(6);

    int x = q2.Dequeue();
    cout << "Dequeued element from q2 is: " << x << endl;
    return 0;
}