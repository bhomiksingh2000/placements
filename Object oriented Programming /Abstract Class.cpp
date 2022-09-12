#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class person{
    public:
    int age;
    string name;
    string address;
    
    virtual void total_account_money() = 0;
};

class student: public person{
    public:
    int roll_no;
    char section;
    void total_account_money(){
        return ;
    }
    student(int age, int roll_no, char section){
        this -> age = age;
        this -> roll_no = roll_no;
        this -> section = section;
    }
};

class faculty: public person{
    public:
    int salary;
    int savings;
    
    void total_account_money(){
        cout<<"the total money held by the faculty is: "<<this -> salary + this -> savings<<endl;
    }
    
    faculty(int age, int salary){
        this -> age = age;
        this -> salary = salary;
    }
};
int main() {
    student bhomik(18, 13, 'E');
    faculty manisha(45, 50000);
    
    return 0;
}