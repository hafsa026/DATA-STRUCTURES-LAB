#include <iostream>
using namespace std;

int main() {
    int x = 42;
    char y= 's';
    // void pointer holding address of an int
    void* ptr = &x; 
    void* ptr1=&y;

    // Error: cannot dereference void pointer
    // cout << *ptr; 

    // Typecast before dereferencing
    cout << "Value pointed by void pointer: " << *(static_cast<char*>(ptr1)) << endl;

    return 0;
}