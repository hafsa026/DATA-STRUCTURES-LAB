#include <iostream>
using namespace std;

void modifyValue(int &x) {
  
    // Modifies the original variable
    x = 20;  
}

int main() {
    int a = 10;
  
    // Pass a by reference
    modifyValue(a);
    
    cout << a;
    return 0;
}