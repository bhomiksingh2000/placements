class Solution {
public:
    int dp[1001];
    int solve(vector<int>& arr, int i, int d, int n){
        
        if(dp[i]!=-1)
            return dp[i];
        
        // ans is kept 1 because if there will be 0 jumps , means out of index hoga , then we would not be returning INT_MIN, but 1 jump to hoga hi .
        int ans=1;
        
        // for forward jump:
        for(int k=i+1;k<=min(n-1,i+d) && arr[i] > arr[k];k++){
            ans=max(ans,1+solve(arr,k,d,n));
        }
        
        // for backward jump:
        for(int k=i-1;k>=max(0,i-d) && arr[i] > arr[k];k--){
            ans=max(ans,1+solve(arr,k,d,n));
        }
        
        return dp[i]=ans;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
            ans=max(ans,solve(arr,i,d,n));
        
        return ans;
        
    }
};