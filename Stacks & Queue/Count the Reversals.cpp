int countRev (string s)
{
    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        
        if(s[i] == '}'){
            if(!st.empty() && st.top() == '{')
                st.pop();
            
            else
                st.push('}');
        }
        
        else
            st.push('{');
        
    }
    
    int open = 0;
    int close = 0;
    while(!st.empty()){
        if(st.top() == '}')
            close++;
        
        else
            open++;
            
        st.pop();
    }
    
    if( (open + close) %2 !=0){
        return -1;
    }
    
    return (open + 1)/2 + (close + 1)/2;
}