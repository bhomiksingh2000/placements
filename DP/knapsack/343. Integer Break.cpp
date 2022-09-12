class Solution {
public:
// easy coin change variation.
   int t[101][10001];
   int solve(vector<int>& coins, int amount, int i,int k){
        if(i<0 || amount<0)
            return 0;
        
        if(amount==0){
            if(k<2)
                return 0;
            return 1;
        }
               
        if(t[i][amount]!=-1)
            return t[i][amount];
        
        if(coins[i]<=amount)
            return t[i][amount]=max(coins[i]*solve(coins,amount-coins[i],i,k+1),solve(coins,amount,i-1,k));
        
        else
            return t[i][amount]=solve(coins,amount,i-1,k);
            
    }
   
    int integerBreak(int n) {
        vector<int> numbers;
        for(int i=1;i<n;i++){
            numbers.push_back(i);
        }
        
        memset(t,-1,sizeof(t));
        return solve(numbers,n,numbers.size()-1,0);
    }
};