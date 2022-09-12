class Solution {
public:
    unordered_map<string,int>mp;
    int util(vector<int> &nums,int i,int prev_ind, int d){
        if(i>=nums.size())
            return 0;
        
        string temp=to_string(i);
        temp.push_back(' ');
        temp.append(to_string(prev_ind));
        temp.push_back(' ');
        temp.append(to_string(d));
        
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        
        // not take
        int l1=0+util(nums,i+1,prev_ind,d);
        
        // take
        int l2=0; 
        if(prev_ind==-1)
            l2= 1+util(nums,i+1,i,501);
    
        if(prev_ind!=-1 && d==501)
            l2= 1+util(nums,i+1,i,nums[i]-nums[prev_ind]);
        
        else if(prev_ind!=-1 && d == nums[i] - nums[prev_ind])
            l2=1+util(nums,i+1,i,d);
        
        return  mp[temp]=max(l1,l2);
    }
    
    int longestArithSeqLength(vector<int>& nums) {
         return util(nums,0,-1,501);
    }
};


// but recursion + memoization is also giving TLE:

/*
In Normal LIS solutions we just check if it's arr[i]>arr[j] then we update the result and
 dp, now suppose I tell you find LIS with difference 2, you will just put the condition 
 if(arr[i]-arr[j]==2)then update the dp and res, its the same questions with different 
 differences, so whatever our difference may come, we go to that difference and update 
 its new dp length simple as that!
*/
int longestArithSeqLength(vector<int>& nums) {
         // return util(nums,0,-1,501);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2001,1));
        int maxs=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j]+510;
                dp[i][diff]=max(dp[i][diff],1+dp[j][diff]);
                maxs=max(dp[i][diff],maxs);
            }
        }
        
        return maxs;
    }
};

