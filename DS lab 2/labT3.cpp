#include <iostream>
using namespace std;

struct Nodetype {
    int data;
    Nodetype *next;
};

Nodetype *first = NULL, *last = NULL;

void insert_end(int val) {
    Nodetype *p = new Nodetype;
    p->data = val;
    p->next = NULL;
    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        last = p;
    }
}

void findOccurrences(int key) {
    Nodetype *p = first;
    int count = 0;
    int position = 1;
    
    cout << "Occurrences of " << key << " at positions: ";
    while (p != NULL) {
        if (p->data == key) {
            cout << position << " ";
            count++;
        }
        p = p->next;
        position++;
    }
    
    if (count == 0)
        cout << "None";
    cout << "\nTotal occurrences: " << count << endl;
}

void display() {
    Nodetype *p = first;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(10);
    insert_end(30);
    insert_end(10);
    insert_end(40);
    
    cout << "List: ";
    display();
    
    findOccurrences(10);
    
    return 0;
}