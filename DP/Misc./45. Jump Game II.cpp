class Solution {
public:
    int dp[10001];
    int solve(vector<int>& nums, int i){
        if(i>=nums.size()-1)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        if(nums[i]==0)
            return 1000;
        
        int ans=INT_MAX;
        for(int k=1;k<=nums[i];k++){
            ans=min(ans,1+solve(nums,i+k));
        }
        
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};