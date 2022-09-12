class Solution {
public:
    int t[13][10001];
    int solve(vector<int>& coins, int amount, int i){
        if(i<0 || amount<0)
            return INT_MAX-1;
        
        if(amount==0)
            return 0;
        
        if(t[i][amount]!=-1)
            return t[i][amount];
        
       // if(coins[i]<=amount)
            return t[i][amount]=min(1+solve(coins,amount-coins[i],i),solve(coins,amount,i-1));
        
        // else
        //     return t[i][amount]=solve(coins,amount,i-1);
            
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int ans= solve(coins,amount,coins.size()-1);
        if(ans==INT_MAX-1)
            return -1;
        
        return ans;
    }
};


//TABULATION:
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
          int m=coins.size();
        long long t[m+1][amount+1];
        
        for(int i=0;i<m+1;i++)
           t[i][0]=0;
        for(int j=0;j<amount+1;j++)
           t[0][j]=INT_MAX-1;
        
        for(int j=1;j<amount+1;j++){
            
            // coins[0] se islie divide kia h kyonki abhi i=1 , this means only 1 element is there in coins 
            if(j%coins[0]==0)
                t[1][j]=j/coins[0];
            
            else
                t[1][j]=INT_MAX-1;
        }
       
           
        for(int i=2;i<m+1;i++){
            for(int j=1;j<amount+1;j++){
                
                if(coins[i-1]<=j)
                t[i][j]=min(1+t[i][j-coins[i-1]],t[i- 1][j]);
                
                else
                 t[i][j]=t[i- 1][j];
            }
        }
       if(t[m][amount]>amount )
           return -1;
       return t[m][amount];
       

  
    }
};
