class A{
    public:
    void f(){
        cout<<"f A"<<endl;
    }
};

class B{
    public:
    void f(){
        cout<<"f B"<<endl;
    }
};


class C : public A, public B{
    public:
    int k;
};


int main() {
    C obj;
    /*
    obj.f();
           if we do this, inheritance ambiguity will be there , therefore 
           we will use scope resolution operator
    */
    
    obj.A::f();
    obj.B::f();
    
}