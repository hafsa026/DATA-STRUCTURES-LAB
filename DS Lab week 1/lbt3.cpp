#include <iostream>
using namespace std;

int main() {
    int a[50], n, x, i=0;

    cin >> n;

    for(int j=0; j<n; j++)
        cin >> a[j];

    cout << "Search value: ";
    cin >> x;

    while(i<n) {
        if(a[i] == x) {
            cout << "Value Found";
            return 0;
        }
        i++;
    }

    cout << "Value Not Found";

    return 0;
}