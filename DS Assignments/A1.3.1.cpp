// Circular_TaskScheduler.cpp
#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name;
    string status;   // pending, in-progress, completed
    Task* next;
    Task(string n, string s) : name(n), status(s), next(NULL) {}
};

Task* head = NULL;
Task* tail = NULL;

void addTask(string name, string status = "pending") {
    Task* newNode = new Task(name, status);
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
        return;
    }
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

void removeTask(string name) {
    if (head == NULL) { cout << "No tasks\n"; return; }

    // Single node case
    if (head == tail && head->name == name) {
        delete head;
        head = tail = NULL;
        cout << "Task removed\n";
        return;
    }

    Task* curr = head;
    Task* prev = tail;
    do {
        if (curr->name == name) {
            if (curr == head) {
                head = head->next;
                tail->next = head;
            } else if (curr == tail) {
                tail = prev;
                tail->next = head;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Task removed\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    cout << "Task not found\n";
}

void getNextTask() {
    if (head == NULL) { cout << "No tasks\n"; return; }

    Task* curr = head;
    do {
        if (curr->status == "pending") {
            cout << "Next Task: " << curr->name << endl;
            curr->status = "in-progress";
            return;
        }
        curr = curr->next;
    } while (curr != head);

    cout << "No pending tasks\n";
}

void updateStatus(string name, string newStatus) {
    if (head == NULL) { cout << "No tasks\n"; return; }

    Task* curr = head;
    do {
        if (curr->name == name) {
            curr->status = newStatus;
            cout << "Updated\n";
            return;
        }
        curr = curr->next;
    } while (curr != head);

    cout << "Task not found\n";
}

void displayAll() {
    if (head == NULL) { cout << "No tasks\n"; return; }

    Task* curr = head;
    cout << "\n--- All Tasks ---\n";
    do {
        cout << curr->name << " [" << curr->status << "]\n";
        curr = curr->next;
    } while (curr != head);
}

int main() {
    addTask("Task1");
    addTask("Task2");
    addTask("Task3");

    displayAll();

    cout << "\n--- Round Robin ---\n";
    getNextTask();
    getNextTask();
    getNextTask();
    getNextTask();   // no pending

    updateStatus("Task1", "completed");
    displayAll();

    cout << "\n--- Removing Task2 ---\n";
    removeTask("Task2");
    displayAll();

    return 0;
}