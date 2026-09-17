#include <iostream>
using namespace std;

int* getPointer(int x) {
    x = 10;
    
    // returning address of local variable
    return &x; 
}

int main() {
    int y=10;
    // ptr becomes dangling here
    int* ptr = getPointer(y); 
    
    // Undefined behavior
     cout << *ptr; 
    return 0;
}