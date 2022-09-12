class Solution {
public:
    int dp[201][201][201];
    bool solve(string s1, string s2, string s3, int i, int j, int k){
        if(k>=s3.size())
            return true;
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        if(i<s1.size() && j<s2.size() && s1[i]==s3[k] && s2[j]==s3[k])
            return dp[i][j][k]=solve(s1,s2,s3,i+1,j,k+1) || solve(s1,s2,s3,i,j+1,k+1);
        
        if(i<s1.size() && s1[i]==s3[k])
            return dp[i][j][k]=solve(s1,s2,s3,i+1,j,k+1);
        
        if(j<s2.size()&& s2[j]==s3[k])
            return dp[i][j][k]=solve(s1,s2,s3,i,j+1,k+1);
        
        return dp[i][j][k]=false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        if(n+m!=k)
            return false;
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,0,0,0);
    }
};