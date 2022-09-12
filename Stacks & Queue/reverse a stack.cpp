class Solution{
public:
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
    
    void reverse(stack<int> &st){
        if(st.empty()){
            return ;
        }
        
        else{
            int x = st.top();
            st.pop();
            
            reverse(st);
            
            insertAtBottom(st, x);
            
        }
    }
    stack<int> Reverse(stack<int> st){
        reverse(st);
        
        return st;
    }