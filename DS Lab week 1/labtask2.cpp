#include <iostream>
using namespace std;

struct ArrayList {
    int arr[100];
    int size = 0;

    void insertEnd(int x) {
        arr[size] = x;
        size++;
    }

    void insertStart(int x) {
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = x;
        size++;
    }

    void insertAfter(int after, int x) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == after) {
                for (int j = size; j > i+1; j--) {
                    arr[j] = arr[j-1];
                }
                arr[i+1] = x;
                size++;
                return;
            }
        }
    }

    void insertBefore(int before, int x) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == before) {
                for (int j = size; j > i; j--) {
                    arr[j] = arr[j-1];
                }
                arr[i] = x;
                size++;
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteEnd() {
        if (size > 0) size--;
    }

    void deleteStart() {
        if (size > 0) {
            for (int i = 0; i < size-1; i++) {
                arr[i] = arr[i+1];
            }
            size--;
        }
    }

    void deleteSpecific(int x) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == x) {
                for (int j = i; j < size-1; j++) {
                    arr[j] = arr[j+1];
                }
                size--;
                return;
            }
        }
    }
};

int main() {
    ArrayList a;

    // Testing all functions
    a.insertEnd(10);
    a.insertEnd(20);
    a.insertStart(5);
    a.insertAfter(10, 15);
    a.insertBefore(20, 18);
    
    cout << "After insertions: ";
    a.display();  // 5 10 15 18 20

    a.deleteEnd();
    a.deleteStart();
    a.deleteSpecific(15);

    cout << "After deletions: ";
    a.display();  // 10 18

    return 0;
}