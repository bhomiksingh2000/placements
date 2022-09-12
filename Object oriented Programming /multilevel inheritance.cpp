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


class C : public B{
    public:
    int k;
};

int main() {
    C obj;
    cout<<sizeof(obj);
}

