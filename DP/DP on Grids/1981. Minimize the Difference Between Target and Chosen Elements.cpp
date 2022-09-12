class Solution {
public:
    int t[71][5041];
    int solve(vector<vector<int>>& mat, int target, int sum, int n, int m, int i){
        if(i==n)
            return abs(sum-target);
        
        if(t[i][sum]!=-1)
            return t[i][sum];
          
        int ans=INT_MAX;
        for(int j=0;j<m;j++)
            ans=min(ans,solve(mat,target,sum+mat[i][j],n,m,i+1));
        
        
        return t[i][sum]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        memset(t,-1,sizeof(t));
        return solve(mat,target,0,n,m,0);
    }
};