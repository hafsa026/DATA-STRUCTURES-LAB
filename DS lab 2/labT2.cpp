#include <iostream>
using namespace std;

struct Nodetype {
    int data;
    Nodetype *next;
};

Nodetype *first1 = NULL, *last1 = NULL;
Nodetype *first2 = NULL, *last2 = NULL;

void insert_end(Nodetype *&first, Nodetype *&last, int val) {
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

Nodetype* mergeLists(Nodetype *f1, Nodetype *f2) {
    Nodetype *newFirst = NULL, *newLast = NULL;
    
    Nodetype *p = f1;
    while (p != NULL) {
        Nodetype *temp = new Nodetype;
        temp->data = p->data;
        temp->next = NULL;
        if (newFirst == NULL) {
            newFirst = newLast = temp;
        } else {
            newLast->next = temp;
            newLast = temp;
        }
        p = p->next;
    }
    
    p = f2;
    while (p != NULL) {
        Nodetype *temp = new Nodetype;
        temp->data = p->data;
        temp->next = NULL;
        if (newFirst == NULL) {
            newFirst = newLast = temp;
        } else {
            newLast->next = temp;
            newLast = temp;
        }
        p = p->next;
    }
    
    return newFirst;
}

void display(Nodetype *first) {
    Nodetype *p = first;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insert_end(first1, last1, 1);
    insert_end(first1, last1, 3);
    insert_end(first1, last1, 5);
    
    insert_end(first2, last2, 2);
    insert_end(first2, last2, 4);
    insert_end(first2, last2, 6);
    
    cout << "List 1: ";
    display(first1);
    cout << "List 2: ";
    display(first2);
    
    Nodetype *merged = mergeLists(first1, first2);
    cout << "Merged List: ";
    display(merged);
    
    return 0;
}