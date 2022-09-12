// take , 2*take, not take
class Solution {
public:
    int ans=INT_MIN;
    int minDiff=INT_MAX;
    void solve(vector<int>& toppingCosts,int cost, int target, int i){
        if(abs(target-cost)<minDiff ){
            minDiff=abs(target-cost);
            ans=cost;
        }
        
        if(abs(target-cost)==minDiff )
            ans=min(ans,cost);
        
        
        if(i>=toppingCosts.size())
            return ;
        
        // not Take:
        solve(toppingCosts, cost, target, i+1);
        
        // take
        solve(toppingCosts, cost+toppingCosts[i], target, i+1);
        
        // take the topping 2 times, bec we can take  at most two of each type of topping.
        solve(toppingCosts, cost+2*toppingCosts[i], target, i+1);
        
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
   
        // as There must be exactly one ice cream base., trying for each , and compare with minDiff , if the diff bw the current cost and target is smalller than minDiff, then change the ans to the current cost.
        
        for(int i=0;i<baseCosts.size();i++){
            solve(toppingCosts,baseCosts[i],target,0);
        }
        
        return ans;
    }
};