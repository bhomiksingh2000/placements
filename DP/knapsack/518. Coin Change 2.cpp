class Solution {
public:
    int t[301][5001];
    int solve(int amount, vector<int>& coins, int i){
        if(amount==0)
            return 1;
        
        if(amount<0 || i<0)
            return 0;
        
        if(t[i][amount]!=-1)
            return t[i][amount];
            
        if(coins[i]<=amount)
            return t[i][amount]=solve(amount-coins[i],coins,i)+solve(amount,coins,i-1);
        
        else
            return t[i][amount]=solve(amount,coins,i-1);
                       
            
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve( amount,coins,coins.size()-1);
    }
};


// TABULATION:
int change(int amount, vector<int>& coins) {
        int m=coins.size();
        long long t[m+1][amount+1];
        
        for(int i=0;i<m+1;i++)
           t[i][0]=1;
        for(int j=1;j<amount+1;j++)
           t[0][j]=0;
           
        for(int i=1;i<m+1;i++){
            for(int j=1;j<amount+1;j++){
                
                if(coins[i-1]<=j)
                t[i][j]=t[i][j-coins[i-1]]+t[i- 1][j];
                
                else
                 t[i][j]=t[i- 1][j];
            }
        }
       
       return t[m][amount];
    }