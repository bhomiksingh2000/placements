class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> valid;  
        valid.push(-1);
        int ans = 0;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(')
                valid.push(i);
            
            else{
                valid.pop();
                
                if(valid.empty())
                    valid.push();
                
                else
                    ans = max(ans, i - valid.top());
            }
        }
        return ans;
    }
};