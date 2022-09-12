class Solution{
public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n=nums.size();
	    vector<int> dp1(n,1);
	    vector<int> dp2(n,1);
	    
	    // aage se check karenge, max LIS size
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j]){
	                dp1[i]=max(dp1[i],1+dp1[j]);
	            }
	        }
	    }
	    
	    // peeche se check karenge, max LIS size
	    // or longest decreasing subsequnce
	    for(int i=n-1;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(nums[i]>nums[j]){
	                dp2[i]=max(dp2[i],1+dp2[j]);
	            }
	        }
	    }
	    
	    int ans=INT_MIN;
	    for(int i=0;i<n;i++){
	        ans=max(ans,dp1[i]+dp2[i]);
	    }
	    
	    return ans-1;
    }
};