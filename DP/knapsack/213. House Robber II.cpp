/* method-1:
just call the solve func two times , setting appropriate first and last indices, and 
then return maximum of them:
*/
class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int> &dp){
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int take=nums[i]+solve(nums,i+2,n,dp);
        int notTake=0+solve(nums,i+1,n,dp);
        
        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n+1,-1);
        int ans1=solve(nums,0,n-1,dp);
        vector<int> dp2(n+1,-1);
        int ans2=solve(nums,1,n,dp2);
        
        return max(ans1,ans2);
    }
};

//************************************************************************************************************

/* method-2:
create 2 arrrays , in first do not include the last element ,and 
in the second do not include the first element , and perform dp on both
*/
class Solution {
public:
    int util(vector<int> nums,vector<int> &t,int i){
        if(i>=nums.size())
            return 0;
        
        if(t[i]!=-1)
            return t[i];
        
        return t[i]= max( nums[i] + util(nums,t,i+2) , util(nums,t,i+1));
    }
    
    int rob(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;
        int n=nums.size();
        if(n==1)
            return nums[0];
       
        
        for(int i=0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            
            if(i!=n-1) nums2.push_back(nums[i]);
        }
         vector<int>t(nums1.size(),-1);
        int x=util(nums1,t,0);
        vector<int> t2(nums2.size(), -1);  
        int y = util(nums2 , t2, 0);
       
        
        return max(x,y);
        
    }
};