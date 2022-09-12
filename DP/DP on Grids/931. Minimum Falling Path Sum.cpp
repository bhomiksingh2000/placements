class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& matrix, int i, int j, int n, int m){
        
        if(i>=n || j>=m || i<0 || j<0)
            return 10000;
        
        if(i==n-1)
            return matrix[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int op1=solve(matrix,i+1,j-1,n,m);
        int op2=solve(matrix,i+1,j,n,m);
        int op3=solve(matrix,i+1,j+1,n,m);
        
        
        return dp[i][j] = matrix[i][j] + min(op1,min(op2,op3));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix.size();
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<m;i++)
            ans=min(ans,solve(matrix,0,i,n,m));
        
        return ans;
        
    }
};