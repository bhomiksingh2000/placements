#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// here we have done operator overloading through '+' operator, here we will do subtraction
// through '+' , means we have overloaded the '+' operator according to ourselves 
class A{
    public:
    int a;
    int b;
    
    // paramterised contructor:
    A(int x, int y){
        this -> a = x;
        this -> b = y;
    }
    
    // operator overloading:
    void operator + (A &obj){
        int temp = this -> a;
        
        cout<<temp - obj.a <<endl;
    }
};

int main() {
    A obj1 (5, 7);
    A obj2 (6, 8);
    
    obj2 + obj1;
}