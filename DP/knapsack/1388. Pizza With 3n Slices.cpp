  class Solution {
public:
    int solve(vector<int>& slices, int i, int n, int k, vector<vector<int>> &dp){
        // if we have reached out of bounds, or we have taken n/3 elements , this will be base case
        if(i>=n || k==0)
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        // not take:
        int notTake=solve(slices,i+1,n,k,dp);
        
        // take:
        int take=slices[i]+solve(slices,i+2,n,k-1,dp);
        
        return dp[i][k]=max(notTake,take);
    }
    int maxSizeSlices(vector<int>& slices) {
        // as we know that the size of pizza is 3n , therefore Alice, Bob, and and you can pick 3 slices each , thereofore this is simple knapsack problem , but with some trick 
        int n=slices.size();
        
        // first will be starting from 0 , and last index will not be taken
        vector<vector<int>> dp1(n+1,vector<int>(n/3+1,-1));
        int ans1=solve(slices,0,n-1,n/3,dp1);
        
        // second  will be starting from 1 , and first index will not be taken
        vector<vector<int>> dp2(n+1,vector<int>(n/3+1,-1));
        int ans2=solve(slices,1,n,n/3,dp2);
        
        return max(ans1,ans2);
        
    }
};