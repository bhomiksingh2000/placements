class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i<s.size(); i++){
            
            // if opening bracket , then simply push:
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            
            
            // closing bracket :
            // if we will not find any valid opening braket for the closing brakcet , then it will be not valid Parentheses
            else{
                
                if(st.empty())
                    return false;
                
                else{
                    if((s[i] == ')' && st.top() == '(' ) || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[' ))
                        st.pop();
                    
                    else
                        return false;
                }
            }
            
            
        }
        
        if(st.empty())
            return true;
        
        return false;
    }
};