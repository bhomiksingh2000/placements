// SHALLOW COPYING:

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class student{
    public:
    int age;
    char section;
    
    
    student(){
        cout<<"constructor Called"<<endl;
    }
    
    student(int x, char y){
        cout<<"paramterised constructor Called"<<endl;
        this -> age = x;
        this -> section = y;
    }
    // student (student & temp){
    //     this -> age = temp.age;
    //     this -> section = temp.section;
    // }
    void print(){
        cout<< "age of student is: "<<this -> age <<endl;
        cout<< "section of student is: "<<this -> section <<endl;
    }
   
};
int main() {
    student victor (18, 'e');
  
    student &kento=victor;   // copy constructor called.
    cout<<"kento:  "<<endl;
    kento.print();
    cout<<endl;
    victor.age = 19;
    
    cout<<"victor:  "<<endl;
    victor.print();
    cout<<endl;
    
    cout<<"kento:  "<<endl;
    kento.print();
   
}


/*
o/p:

paramterised constructor Called
kento:  
age of student is: 18
section of student is: e

victor:  
age of student is: 19
section of student is: e

kento:  
age of student is: 19
section of student is: e

*/