class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        
        //base cases
        if(i < 0 || j < 0
          || i >= grid.size()
          || j >= grid[0].size())
            return 0;
        
        if(grid[i][j])
             return 0;
        
        
        if(i == grid.size() - 1 && j == grid[0].size() - 1)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = dfs(grid, i + 1, j, dp) + dfs(grid, i, j + 1, dp);
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size()+1, vector<int>(obstacleGrid[0].size()+1, -1));
        
        return dfs(obstacleGrid, 0, 0, dp);
    }
};