class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        // this is the longest bitonic subsequence:
        int n=nums.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    dp1[i]=max(dp1[i],1+dp1[j]);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j])
                    dp2[i]=max(dp2[i],1+dp2[j]);
            }
        }
        
        for(int i=0;i<n;i++){
           cout<<dp1[i];
       }
        cout<<endl;
        cout<<endl;
        for(int i=0;i<n;i++){
           cout<<dp2[i];
       }
        
        int LongestBitonicSequence=0;
        for(int i=0;i<n;i++){
            if(dp1[i]!=1 && dp2[i]!=1)
                LongestBitonicSequence=max(LongestBitonicSequence,dp1[i]+dp2[i]);
        }
            
        
        return n-(LongestBitonicSequence-1);
         
    }
};