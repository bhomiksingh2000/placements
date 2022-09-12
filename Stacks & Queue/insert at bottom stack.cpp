#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void insertAtBottom(stack<int> &st, int x){
    if(st.empty()){
        st.push(x);
        return ;
    }
    
    else{
        int y = st.top();
        st.pop();
        
        insertAtBottom(st, x);
        st.push(y);
    }
}

void print(stack<int> &st){
    
    while(!st.empty()){
        cout<< st.top()<<" ";
        st.pop();
    }
    
    cout<<endl;
}
int main() {
    stack<int> st;
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(11);
    
    print(st);
    
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(11);
    
    insertAtBottom(st, 3);
    
    print(st);
    
    return 0;
    
}