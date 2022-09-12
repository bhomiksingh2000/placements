#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class A{
    int a;
    int b;
    
    public:
    int c;
    void setVal(int x){
        this -> a = x;
    }
    
    void getVal(){
        cout<< " The Value of a is: "<<this -> a<<endl;
    }
};
int main() {
    
    A obj;
    obj.c = 5;
    cout<<" The Value of c is: "<<obj.c<<endl;
    obj.setVal(10);
    obj.getVal();
}

/*
o/p:

 The Value of c is: 5
 The Value of a is: 10

 
*/