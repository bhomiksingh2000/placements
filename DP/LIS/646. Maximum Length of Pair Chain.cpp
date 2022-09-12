// method-2 
// TC: O(N^2);
// SC: O(N);
class Solution {
public:
    int t[1001][1002];
    int util( vector<vector<int>>& pairs , int curr , int prev){
        if(curr>=pairs.size())
            return 0;
        
        if(t[curr][prev+1]!=-1)
            return t[curr][prev+1];
        
        int len=util(pairs,curr+1,prev);
        if(prev==-1 || pairs[curr][0]>pairs[prev][1])
            len=max(len,1+util(pairs,curr+1,curr));
        
        return t[curr][prev+1]=len;
    }
  
    int findLongestChain(vector<vector<int>>& pairs) {
       
        sort(pairs.begin(),pairs.end());
        memset(t,-1,sizeof(t));
        return util(pairs,0,-1);
        
    }
};

// method-2 
// TC: O(N^2);
// SC: ;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int> dp(n+1,1);
        int maxs=INT_MIN;
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1])
                    dp[i]=max(dp[i],1+dp[j]);
            }
            
            maxs=max(maxs,dp[i]);
        }
        
        return maxs;
    }
};