#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class A{
    public:
    int a;
    void f1(){
        cout<< "f1"<<endl;
    }
};

class B1: public A{
    public:
    int b1;
    void f2(){
        cout<< "f2"<<endl;
    }
};

class B2 : public A{
    public:
    int b2;
    void f3(){
        cout<< "f3"<<endl;
    }
};


class C : public B1, public B2{
    public:
    int c;
    void f4(){
        cout<< "f4"<<endl;
    }
};
int main() {
    
    C obj;
    obj.a = 5;
}

/*
o/p:
Line 40: Char 9: error: non-static member 'a' found in multiple base-class subobjects of type 'A':
    class C -> class B1 -> class A
    class C -> class B2 -> class A
    obj.a = 5;
        ^
Line 7: Char 9: note: member found by ambiguous name lookup
    int a;
        ^
1 error generated.
*/

int main() {
    
    C obj;
    obj.f1();
}

/*
Line 40: Char 9: error: non-static member 'f1' found in multiple base-class subobjects of type 'A':
    class C -> class B1 -> class A
    class C -> class B2 -> class A
    obj.f1();
        ^
Line 8: Char 10: note: member found by ambiguous name lookup
    void f1(){
         ^
1 error generated.
*/

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class A{
    public:
    int a;
    void f1(){
        cout<< "f1"<<endl;
    }
};

class B1: virtual public A{
    public:
    int b1;
    void f2(){
        cout<< "f2"<<endl;
    }
};

class B2 :virtual  public A{
    public:
    int b2;
    void f3(){
        cout<< "f3"<<endl;
    }
};


class C : public B1, public B2{
    public:
    int c;
    void f4(){
        cout<< "f4"<<endl;
    }
};
int main() {
    
    C obj;
    obj.f1();
}

/*
o/p : f1
*/