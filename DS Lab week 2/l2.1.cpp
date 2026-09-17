#include <iostream>
using namespace std;

int main() {
    int var = 10;
   int v=7;
  int* ptr= &v;
  cout<<*ptr<<endl;
     int* ptr1= &var;
        cout << ptr<<endl;
        *ptr=33;
         cout<<*ptr<<endl;
         cout<<v;
        
   // return 0;
}