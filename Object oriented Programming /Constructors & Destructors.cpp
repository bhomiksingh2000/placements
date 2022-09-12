#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class student{
    public:
    int age;
    char section;
    
    // our own default constructor:
    student(){
        cout<<"constructor Called"<<endl;
    }
    
    // parametrised constructor:
    student(int x, char y){
        cout<<"paramterised constructor Called"<<endl;
        this -> age = x;
        this -> section = y;
    }
    
    // copy constructor:
    student (student & temp){
        this -> age = temp.age;
        this -> section = temp.section;
    }
    
    // destructor:
    ~ student (){
        cout<<"destructor called "<<endl;
    }
    
    void print(){
        cout<< "age of student is: "<<this -> age <<endl;
        cout<< "section of student is: "<<this -> section <<endl;
    }
   
};
int main() {
    student victor ;
    student kento ;
    
   
}

/*
o/p:
constructor Called
constructor Called
destructor called 
destructor called 

*/


/* but  when we will do dynamic allocation , if we will not call delete explicitly, then 
 destructor will not be called.

 o/p:
constructor Called
constructor Called
destructor called 

 */

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class student{
    public:
    int age;
    char section;
    
    // our own default constructor:
    student(){
        cout<<"constructor Called"<<endl;
    }
    
    // parametrised constructor:
    student(int x, char y){
        cout<<"paramterised constructor Called"<<endl;
        this -> age = x;
        this -> section = y;
    }
    
    // copy constructor:
    student (student & temp){
        this -> age = temp.age;
        this -> section = temp.section;
    }
    
    // destructor:
    ~ student (){
        cout<<"destructor called "<<endl;
    }
    
    void print(){
        cout<< "age of student is: "<<this -> age <<endl;
        cout<< "section of student is: "<<this -> section <<endl;
    }
   
};
int main() {
    student victor ;
    student *kento  = new student();
    delete(kento);
    
}

/*
o/p:

constructor Called
constructor Called
destructor called 
destructor called 
*/

