#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class A{
    public:
    int a;
    int b;
    
    virtual void f(){
        cout<<"in f of class A"<<endl; 
    }
};

class B : public A{
    public:
    int x;
    int y;
    
    void f(){
        cout<<"in f of class B"<<endl; 
    }
};

class C: public B{
    void f(){
        cout<<"in f of class C"<<endl; 
    }
};

int main() {
    A *ptr;   // pointer of A type
    C obj;
    
    ptr = &obj;   
    
    ptr -> f();
    
}

