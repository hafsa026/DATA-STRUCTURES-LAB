#include <iostream>
using namespace std;

struct ArrayList {
    int arr[100], size=0;
    void insertEnd(int x) { arr[size++]=x; }
    void display() { for(int i=0;i<size;i++) cout<<arr[i]<<" "; cout<<endl; }
};

int main() {
    ArrayList a;
    a.insertEnd(10); a.insertEnd(25); a.insertEnd(30); 
    a.insertEnd(45); a.insertEnd(60);
    
    cout<<"List: "; a.display();
    
    int target, i=0, found=-1;
    cout<<"Enter number: "; cin>>target;
    
    while(i<a.size) {
        if(a.arr[i]==target) { found=i; break; }
        i++;
    }
    
    if(found!=-1) cout<<"Found at index "<<found;
    else cout<<"Not found";
}