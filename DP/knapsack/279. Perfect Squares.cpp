class Solution {
public:
// easy coin change.
   int t[101][10001];
   int solve(vector<int>& coins, int amount, int i){
        if(i<0 || amount<0)
            return INT_MAX-1;
        
        if(amount==0)
            return 0;
        
        if(t[i][amount]!=-1)
            return t[i][amount];
        
        if(coins[i]<=amount)
            return t[i][amount]=min(1+solve(coins,amount-coins[i],i),solve(coins,amount,i-1));
        
        else
            return t[i][amount]=solve(coins,amount,i-1);
            
    }
    int numSquares(int n) {
        
        vector<int>perfectSquares;
         int p =1, curr = 1;
        
        while(curr<=n){
            curr = pow(p++,2);
            perfectSquares.push_back(curr);
        }
        
        memset(t,-1,sizeof(t));
        return solve(perfectSquares,n,perfectSquares.size()-1);
    }
};