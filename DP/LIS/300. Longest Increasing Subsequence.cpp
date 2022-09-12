/*
Approach 1) Recursive + Memoization

Time Complexity : O(n^2)
Space Complexity : O(n^2) + Recursion Stack Space O(n)

*/
class Solution {
public:
    int dp[2501][2502];
    int solve(vector<int>& nums, int n, int i, int prev){
        if(i>=n)
            return 0;
        
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        
        // not take:
        int ans=solve(nums,n,i+1,prev);
        
        // take if condition valid:
        if(prev==-1 || nums[i]>nums[prev])
            ans=max(ans,1+solve(nums,n,i+1,i));
        
        return dp[i][prev+1]=ans;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,n,0,-1);
    }
};

/*
Approach 2) Tabulation Method (more space optimized than recursive approach)

Time Complexity : O(n^2)
Space Complexity : O(n^2)
*/
class Solution {                    
public:
	 
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
		
		// Tabulation
        dp = vector<vector<int>> (n+1, vector<int> (n+1, 0));
		
        for(int i=n-1; i>=0; i--)
            for(int prev = i-1; prev>=-1; prev--)
            {
                int not_take = dp[i+1][prev+1];
                
                int take = 0;
                if(prev == -1 || nums[i]>nums[prev])
                take = 1 + dp[i+1][i+1];
                
                dp[i][prev+1] = max(take,not_take);
            }
        
          return dp[0][0];
		}
	};

/*
Approach 3) More Space optimized than Tabulation Method

Time Complexity : O(n^2)
Space Complexity : O(n)
SC: O(N)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,1);
        int LIS=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    dp[i]=max(dp[i],1+dp[j]);
            }
            
            LIS=max(LIS,dp[i]);
        }
        
        return LIS;
    }
};


/*
METHOD-4
BINARY SEARCH:
Time Complexity : O(nlog(n))
Space Complexity : O(n)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        int n=nums.size();
        LIS.push_back(nums[0]);
        
        for(int i=0;i<n;i++){
            if(LIS.back()<nums[i])
                LIS.push_back(nums[i]);
            
            else{
                int ind=lower_bound(LIS.begin(),LIS.end(),nums[i]) - LIS.begin();
                LIS[ind]=nums[i];
            }
        }
        
        return LIS.size();
    }
};

// printing LIS:
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