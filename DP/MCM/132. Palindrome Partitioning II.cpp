class Solution {
public:
    
    int t[2001][2001];
    bool isPalindrome(string &s,int i,int j){
    while(i<j){
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
        return 1;
    }
    int solve(string s,int i,int j){
        if(i==s.size())
            return 0;
        
        if(isPalindrome(s, i, j))
            return 0;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int l=solve(s,i,k);
            int r=solve(s,k+1,j);
        
            ans=min(ans,l+r+1);
        }
        
        return t[i][j]=ans;
    }
    int minCut(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,s.size()-1);
    }
};


// optimised:
// jab left m palindrome hi nhi h then there is no  need to check .
class Solution {
public:
    int t[2001][2001];
    bool isPalindrome(string &str, int i, int j){
        while(i<j){
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    int solve(string &s, int i, int j){
        if(i>=j)
            return 0;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        // as it is a palindrome , thereofore cuts required will be zero
        if(isPalindrome(s,i,j))
            return 0;
        
        int res=INT_MAX;
        for(int k=i;k<=j;k++){
            if(isPalindrome(s,i,k)){
                int r=solve(s,k+1,j);
                res=min(r+1,res);
            }
        }
        
        return t[i][j]=res;
    }
    int minCut(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,s.size()-1);
    }
};