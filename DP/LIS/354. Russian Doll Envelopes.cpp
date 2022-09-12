// recursion + meoization => TLE:
class Solution {
public:
    // int t[100001][100001];
    int LIS(vector<vector<int>>& envelopes,int i,int prevInd){
        if(i>=envelopes.size())
            return 0;
        
        // if(t[i][prevInd])
        //     return t[i][prevInd];
        
        // not take
        int ans= 0 + LIS(envelopes,i+1,prevInd);
        
        // take if condition satisfied
        if(prevInd==-1  || (envelopes[prevInd][0]<envelopes[i][0] 
                             && envelopes[prevInd][1]<envelopes[i][1]))
            ans=max(ans,1+LIS(envelopes,i+1,i));
        
        // return t[i][prevInd]=ans;
        return ans;
        
    }   
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        // memset(t,-1,sizeof(t));
        return LIS(envelopes,0,-1);
    }
};

// 2nd approach also TLE:
class Solution {
public:
   
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(envelopes.size(),1);
        int ans=INT_MIN;
        
        for(int i=0;i<envelopes.size();i++){
            for(int prevInd=0;prevInd<i;prevInd++){
                if(envelopes[prevInd][0]<envelopes[i][0] && envelopes[prevInd][1]<envelopes[i][1])
                    dp[i]=max(dp[i],1+dp[prevInd]);
                
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};


// 3rd approach: BINARY SEARCH with MODIFICATION: