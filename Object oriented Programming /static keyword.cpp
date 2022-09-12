#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class student{
    public:
    int age;
    char section;
    
    static int x;
};

int student :: x = 5;
int main() {
    student p;
    // p.x = 5;
    cout<<student :: x;
}