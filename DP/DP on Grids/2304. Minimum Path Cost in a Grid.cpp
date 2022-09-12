class Solution {
public:
    int dp[51][51];
    int solve(vector<vector<int>>& grid, int n, int m, int i,int j, vector<vector<int>>& moveCost){
        
        if(i==n-1)
            return grid[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int tempAns=INT_MAX;
        for(int k=0;k<m;k++){
            tempAns=min( tempAns, grid[i][j] + moveCost[grid[i][j]][k] + solve(grid,n,m,i+1,k,moveCost));
        }
        
        return dp[i][j]=tempAns;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        
        for(int i=0;i<m;i++)
            ans=min(ans,solve(grid,n,m,0,i,moveCost));
        
        return ans;
    }
};