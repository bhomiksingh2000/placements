#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Stack{
    public:
    int stack[100], n = 100, top = -1;
    
    void push(int val) {
       if(top >= n - 1)
           cout<<"Stack Overflow"<<endl;
        
       else {
          top++;
          stack[top] = val;
       }
    }
    
    void pop() {
       if(top <= -1)
           cout<<" Stack Underflow "<<endl;
       else {
          cout<<" The popped element is "<< stack[top] <<endl;
          top--;
       }
    }
    
    void Top() {
       if(top <= -1)
           cout<<" Stack is Empty "<<endl;
       else 
          cout<<" The top element is "<< stack[top] <<endl;
       
    }
    
    void display() {
       if(top >= 0) {
          cout<<" Stack elements are: ";
           
          for(int i = top; i >= 0; i--)
              cout<<stack[i]<<" ";

          cout<<endl;
       } 
        else
            cout<<"Stack is empty";
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
    st.Top();
    st.pop();
    st.Top();
    st.display();
    

}