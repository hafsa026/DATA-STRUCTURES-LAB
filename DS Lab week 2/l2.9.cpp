#include <iostream>
using namespace std;

int main() {
    int x = 10;

    // ref is a reference to x.
    int& ref = x;
 ref = 22;
    // printing value using ref
    cout << ref << endl;
    
    // Changing the value and printing again
   //
    cout << x;

    return 0;
}