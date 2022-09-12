#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class A{
    public:
    int x;
    int y;
};

class B: public A{
    public:
    int z;
};

int main() {
    B obj;
    cout<<sizeof(obj);
}