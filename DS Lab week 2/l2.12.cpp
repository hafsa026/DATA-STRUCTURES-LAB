#include <iostream>
using namespace std;

int& getMax(int &a, int &b) {
  
    // Return the larger of the two numbers
    return (a > b) ? a : b;  
}

int main() {
    int x = 10, y = 20;
    int &maxVal = getMax(x, y);
  
    // Modify the value of the larger number
    maxVal = 30;  
    cout << "x = " << x << ", y = " << y;
    return 0;
}