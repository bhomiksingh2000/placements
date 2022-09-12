#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// method overloading , i.e Compile Time Polymorphism
// it can only be achived by changing the arguments of the fuction:
// i.e either the no of parameteres, parameters data types, order of parameteres
class A{
    public:
    void f(){
        cout<<"f A"<<endl;
    }
    
    void f(int x){
        cout<<x<<endl;
    }
};

int main() {
    A obj1;
    
    obj1.f();
    obj1.f(5);
}