class Solution {
public:
    int solve(vector<vector<int>>& grid, int n, int m, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
            return 0;
        
        int gold=grid[i][j];
        grid[i][j]=0;
        
        int u=solve(grid,n,m,i-1,j);
        int d=solve(grid,n,m,i+1,j);
        int l=solve(grid,n,m,i,j-1);
        int r=solve(grid,n,m,i,j+1);
        
        grid[i][j]=gold;
        return gold+max(max(u,d),max(l,r));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxGold=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxGold=max(maxGold,solve(grid,n,m,i,j));
            }
        }
        
        return maxGold;
    }
};