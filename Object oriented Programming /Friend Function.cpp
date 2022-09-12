// friend fucntion is not a member function of any class.
// it can be used to access objects of different classes at same time.
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class B;  // forward declaration for friend fucntion.
class A{
    public:
    int x;
   
    friend void func(A, B);
    
};

class B {
    public:
    int y;
    
    friend void func(A, B);
    
};

void f(A obj1, B obj2){
    cout<<" Sum is: "<<obj1.x + obj2.y<<endl;
}
int main() {
    A obj1;
    B obj2;
    
    obj1.x = 5;
    obj2.y = 7;
    
    f(obj1, obj2);
}

