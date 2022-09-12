#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class A{
    public:
    int a;
    int b;
    
    void f(){
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

int main() {
    A *ptr;   // pointer of A type
    B obj;
    
    ptr = &obj;    // pointer of parent class storing the address of object of child class
    
    ptr -> f();
    
}

/*
o/p: 

    Finished in 0 ms
    in f of class A

problem:
 although we wanted that the object of class we would have been called but due to 
 early binding or compiled time binding the  compiler sees that the pointer is of
 child class, therefore it binds it to the function of parent class but we wanted 
 the function of child class should have been called

 soln:
 Therefore to solve this problem so that the function of B to be called 
 We do runtime binding or late binding , so that by adding virtual so that the compiler
 sees the content of the pointer that means what type of object is stored in the pointer
*/


/*
thereofre just add virtual in front of f() in paremnt class , so that all functions inside
parent class will also be virtual , and ensure late binding.

o/p:
    Finished in 4 ms
    in f of class B
*/


