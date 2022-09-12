class Solution {
public:
   
    int solve(vector<int>& prices, int index , bool canBuy , int cap,vector<vector<vector<int>>> &t){
        if(index>=prices.size() || cap==0)
            return 0;
        
         if(t[index][canBuy][cap]!=-1)
            return t[index][canBuy][cap];
        
        int profit=0;
        if(canBuy){
            int buy= - prices[index] + solve(prices,index+1,false,cap,t);
            int notBuy= 0 + solve(prices,index+1,true,cap,t);
            profit=max(buy,notBuy);
        }
        
        else{
            int sell= prices[index] + solve(prices,index+1,true,cap-1,t);
            int notSell= 0 +solve(prices,index+1,false,cap,t);
            profit=max(sell,notSell);
        }
        
        return t[index][canBuy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
       vector<vector<vector<int>>>t(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
       
        return solve(prices,0,true,k,t);
    
    }
};