class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string str){
        int i=0;
        int j=str.size()-1;
        
        while(i<j){
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    void solve(string s, int i, int j,vector<string> temp){
        if(i>j){
            res.push_back(temp);
            return ;
        }

        for(int k=i;k<=j;k++){
            
            if(isPalindrome(s.substr(i,k-i+1))){
                
                temp.push_back(s.substr(i,k-i+1));
                solve(s,k+1,j,temp);
                temp.pop_back();
                
            }
        }
        
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s,0,s.size()-1,temp);
        return res;
    }
};