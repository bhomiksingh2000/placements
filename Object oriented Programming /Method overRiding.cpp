// method overRiding i.e RUNTIME POLYMORPHISM:
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class A{
    public:
    void f(){
        cout<<"f A"<<endl;
    }
};

class B{
    public:
    void f(){
        cout<<"f B"<<endl;
    }
};



int main() {
    A obj1;
    B obj2;
    
    obj1.f();
    obj2.f();
}