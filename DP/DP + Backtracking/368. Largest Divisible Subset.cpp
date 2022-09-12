class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int> hash;
        int lastIndex;
        int maxs=INT_MIN;
        
        for(int i=0;i<n;i++)
            hash.push_back(i);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            
            if(dp[i]>maxs){
                maxs=dp[i];
                lastIndex=i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            ans.push_back(nums[lastIndex]);
            
        }
        
        reverse(ans.begin(),ans.end());
      
        return ans;
    }
};