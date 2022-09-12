/*
basically the main crux behind this question is that we have to identify this
 as a MCM variation . As given in problem statement : nums[i - 1] * nums[i] * nums[i + 1] ,
  this indicates the same cost when we multiply a 2 matrices . so we will create an array 
  where same as sums , but here we will put the first and last index =1 , as given clearly
   in the question "If i - 1 or i + 1 goes out of bounds of the array, then treat it as if
    there is a balloon with a 1 painted on it." , this will be the slight variation from
     MCM , and solve this recursively by partitioning the array
*/
class Solution {
public:
    int t[401][401];
    int solve(vector<int>& nums, int i, int j){
        if(i>=j)
            return 0;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        int res=INT_MIN;
        for(int k=i;k<=j-1;k++){
            int ans=solve(nums,i,k)+solve(nums,k+1,j)+(nums[i-1]*nums[k]*nums[j]);
            res=max(res,ans);
        }
        
        return t[i][j]=res;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+2);
        arr[0]=1;
        arr[n+1]=1;
        
        for(int i = 1;i<=nums.size();i++){
            arr[i]=nums[i-1];   
        }
        
        memset(t,-1,sizeof(t));
        return solve(arr,1,n+1);
    }
};