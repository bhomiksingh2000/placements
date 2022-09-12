#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class A{
    public:
    int a;
    void f1(){
        
    };
    
     virtual ~A(){
        // destructor.
        cout<< "memory occupied by object of class A deleted "<<endl;
    }
};

class B : public A{
    public:
    int b;
    void f2(){
        
    };
    
    ~B(){
        // destructor.
        cout<< "memory occupied by object of class B deleted "<<endl;
    }
};
int main() {
    A * ptr = new B;
    ptr -> f1();
    delete ptr;
}


/*
output of programme:

Finished in 0 ms    (no destructor will be called when we dont put "delete ptr")



Finished in 4 ms   (child class's  destructor will not be called when we dont add virtual in front of destructor)
memory occupied by object of class A deleted  



Finished in 0 ms (first the destructor of child class will be called , then parent's)
memory occupied by object of class B deleted 
memory occupied by object of class A deleted 

*/