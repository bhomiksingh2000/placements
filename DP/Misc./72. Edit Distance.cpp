class Solution {
public:
    int dp[501][501];
    int solve(string word1, string word2, int i, int j){
        if(i<0)
            return j+1;
        
        if(j<0)
            return i+1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(word1[i]==word2[j])
            return 0 + solve(word1,word2,i-1,j-1);
        
        // insertion:
        int op1= 1 + solve(word1,word2,i,j-1);
        
        // deletion:
        int op2= 1 + solve(word1,word2,i-1,j);
        
        //replace:
        int op3= 1 + solve(word1,word2,i-1,j-1);
        
        return dp[i][j]=min(op1,min(op2,op3));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,n-1,m-1);
    }
};