#include <iostream>
using namespace std;

#define SIZE 10

class dequeue {
    int a[20], f, r;

public:
    dequeue() { f = -1; r = -1; }

    void insert_at_beg(int i) {
        if (f == -1) {
            f = 0;
            a[++r] = i;
            cout << "\nInserted element is: " << i;
        } else if (f != 0) {
            a[--f] = i;
            cout << "\nInserted element is: " << i;
        } else {
            cout << "\nInsertion is not possible, overflow!!!!";
        }
    }

    void insert_at_end(int i) {
        if (r >= SIZE - 1) {
            cout << "\nInsertion is not possible, overflow!!!!";
        } else {
            if (f == -1) { f++; r++; }
            else r = r + 1;
            a[r] = i;
            cout << "\nInserted item is " << a[r];
        }
    }

    void delete_fr_front() {
        if (f == -1) {
            cout << "Deletion is not possible::dequeue is empty";
            return;
        } else {
            cout << "The deleted element is: " << a[f];
            if (f == r) { f = r = -1; return; }
            else f = f + 1;
        }
    }

    void delete_fr_rear() {
        if (f == -1) {
            cout << "Deletion is not possible::dequeue is empty";
            return;
        } else {
            cout << "The deleted element is: " << a[r];
            if (f == r) { f = r = -1; }
            else r = r - 1;
        }
    }

    void show() {
        if (f == -1) {
            cout << "Dequeue is empty";
        } else {
            for (int i = f; i <= r; i++) cout << a[i] << " ";
        }
    }
};

int main() {
    int c, i;
    dequeue d;
    do {
        cout << "\n1.insert at beginning";
        cout << "\n2.insert at end";
        cout << "\n3.show";
        cout << "\n4.deletion from front";
        cout << "\n5.deletion from rear";
        cout << "\n6.exit";
        cout << "\nEnter your choice: ";
        cin >> c;

        switch (c) {
            case 1: cout << "Enter the element to be inserted: "; cin >> i; d.insert_at_beg(i); break;
            case 2: cout << "Enter the element to be inserted: "; cin >> i; d.insert_at_end(i); break;
            case 3: d.show(); break;
            case 4: d.delete_fr_front(); break;
            case 5: d.delete_fr_rear(); break;
            case 6: exit(1);
            default: cout << "Invalid choice"; break;
        }
    } while (c != 7);
    return 0;
}