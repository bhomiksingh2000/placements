class Solution {
public:
     int t[100001][2];
    int solve(vector<int>& prices,int index,bool canBuy,int fee){
        if(index>=prices.size())
            return 0;
        
        int profit=0;
       if(t[index][canBuy]!=-1)
            return t[index][canBuy];
        if(canBuy){
            int buy= -prices[index] + solve(prices,index+1,false,fee);
            int notBuy= 0 + solve(prices,index+1,true,fee);
            profit=max(buy,notBuy);
        }
        else{
            int sell= prices[index] + solve(prices,index+1,true,fee);
            int notSell= 0 + solve(prices,index+1,false,fee);
            profit=max(sell-fee,notSell);
        }
        
         return t[index][canBuy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
         memset(t,-1,sizeof(t));
        return solve(prices,0,true,fee);
        
    }
};