class Solution {
public:
    int t[100001][2];
    int solve(vector<int>& prices,int index,bool canBuy){
        if(index>=prices.size())
            return 0;
        
        int profit=0;
       if(t[index][canBuy]!=-1)
            return t[index][canBuy];
        if(canBuy){
            int buy= -prices[index] + solve(prices,index+1,false);
            int notBuy= 0 + solve(prices,index+1,true);
            profit=max(buy,notBuy);
        }
        else{
            int sell= prices[index] + solve(prices,index+2,true);
            int notSell= 0 + solve(prices,index+1,false);
            profit=max(sell,notSell);
        }
        
         return t[index][canBuy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(prices,0,true);
    }
};