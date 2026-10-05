#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* last = NULL;

void insertEnd(int value) {
    Node* p = new Node;
    p->data = value;
    if (last == NULL) {
        last = p;
        last->next = last;
    } else {
        p->next = last->next;
        last->next = p;
        last = p;
    }
}

void display() {
    if (last == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = last->next;
    cout << "Circular List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}

// Delete all nodes whose data value is even
void deleteEven() {
    if (last == NULL) return;

    Node* q = last->next;
    Node* q1 = last;
    bool deletedAny = false;

    do {
        Node* nextNode = q->next;

        if (q->data % 2 == 0) {
            // Delete q
            if (q == q->next) {
                // Only one node
                delete q;
                last = NULL;
                cout << "Deleted even node. List is now empty.\n";
                return;
            }

            if (q == last->next) {
                // first node
                last->next = q->next;
            } else if (q == last) {
                // last node
                q1->next = q->next;
                last = q1;
            } else {
                // middle
                q1->next = q->next;
            }
            delete q;
            deletedAny = true;
            q = nextNode;
        } else {
            q1 = q;
            q = q->next;
        }
    } while (q != last->next);

    if (deletedAny)
        cout << "All even-valued nodes deleted.\n";
    else
        cout << "No even-valued nodes found.\n";
}

// Delete all nodes whose data value is odd
void deleteOdd() {
    if (last == NULL) return;

    Node* q = last->next;
    Node* q1 = last;
    bool deletedAny = false;

    do {
        Node* nextNode = q->next;

        if (q->data % 2 != 0) {
            if (q == q->next) {
                delete q;
                last = NULL;
                cout << "Deleted odd node. List is now empty.\n";
                return;
            }

            if (q == last->next) {
                last->next = q->next;
            } else if (q == last) {
                q1->next = q->next;
                last = q1;
            } else {
                q1->next = q->next;
            }
            delete q;
            deletedAny = true;
            q = nextNode;
        } else {
            q1 = q;
            q = q->next;
        }
    } while (q != last->next);

    if (deletedAny)
        cout << "All odd-valued nodes deleted.\n";
    else
        cout << "No odd-valued nodes found.\n";
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    insertEnd(6);
    display();

    deleteEven();
    display();

    // Rebuild list
    insertEnd(7);
    insertEnd(8);
    insertEnd(9);
    display();

    deleteOdd();
    display();

    return 0;
}