class Solution {
public:
    int dp[3001][3001];
    long long mod = 1e9 + 7;
    int solve(int startPos, int endPos, int k){
        if(k ==0 && startPos == endPos)
            return 1;
        
        if(k==0)
            return 0;
        
        // startPos can become negative , as infinite number line is given
        
        if(dp[startPos + 1000][k] != -1)
            return dp[startPos + 1000][k];
        
        // move onto left:
        int l = solve(startPos - 1, endPos, k - 1) % mod;
        
        // move onto right:
        int r = solve(startPos + 1, endPos, k - 1) % mod;
        
        return dp[startPos + 1000][k] = (l + r) % mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(startPos, endPos, k);
    }
};