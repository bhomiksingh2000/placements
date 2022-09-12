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


class C : public A{
    public:
    int k;
};

class D : public B, public C{
    public:
    int g;
};
int main() {
    D obj;
    cout<<sizeof(obj);
}