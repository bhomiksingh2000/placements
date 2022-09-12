#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Stack{
    vector<int> v;
    public:
    void push(int val){
        v.push_back(val);
    }
    
    bool isEmpty(){
        return v.size() == 0;
    }
    
    void pop(){
        if(!isEmpty())
            v.pop_back();
    }
    int top(){
        return v.back();
    }
    
    void display(){
        for(int i = v.size()-1; i>=0; i--)
            cout<<v[i]<<" ";
        
        cout<<endl;
    }
};
int main() {

    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.display();
    
    st.pop();
    cout<<"the top of Stack is "<<st.top()<<endl;
    st.pop();
    cout<<"the top of Stack is "<<st.top()<<endl;
    st.display();
    

}