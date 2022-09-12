class Solution {
public:
     int t[100001][2][5];
    int solve(vector<int>& prices, int index , bool canBuy , int transactions ){
        if(index>=prices.size() || transactions>=4)
            return 0;
        
         if(t[index][canBuy][transactions]!=-1)
            return t[index][canBuy][transactions];
        int profit=0;
        if(canBuy){
            int buy= - prices[index] + solve(prices,index+1,false,transactions+1);
            int notBuy= 0 + solve(prices,index+1,true,transactions);
            profit=max(buy,notBuy);
        }
        
        else{
            int sell= prices[index] + solve(prices,index+1,true,transactions+1);
            int notSell= 0 +solve(prices,index+1,false,transactions);
            profit=max(sell,notSell);
        }
        
        return t[index][canBuy][transactions]=profit;
    }
    int maxProfit(vector<int>& prices) {
         memset(t,-1,sizeof(t));
        return solve(prices,0,true,0);
    }
};