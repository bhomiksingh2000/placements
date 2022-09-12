void sortedInsert(stack<int> &st, int x){
    if(st.empty() || st.top() < x){
        st.push(x);
        return ;
    }
    
    else{
        int y = st.top();
        st.pop();
        
        sortedInsert(st, x);
        
        st.push(y);
    }
}

void sortStack(stack<int> &st){
    if(st.empty()){
        return ;
    }
    
    else{
        int x = st.top();
        st.pop();
        
        sortStack(st);
        
        sortedInsert(st, x);
        
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
    st.push(55);
    st.push(7);
    st.push(4);
    st.push(143);
    
    print(st);
    
    st.push(55);
    st.push(7);
    st.push(4);
    st.push(143);
    
    sortStack(st);
    
    print(st);
    
    return 0;
    
}