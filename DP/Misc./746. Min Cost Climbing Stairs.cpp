
class Solution {
public:
    int util(vector<int>& cost,vector<int>& t,int i){
        if(i>=cost.size())
            return 0;
        if(t[i]!=-1)
            return t[i];
        
        int l=cost[i]+util(cost,t,i+1);
        int r=cost[i]+util(cost,t,i+2);
        
        t[i]=min(l,r);
        return t[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> t(cost.size()+1,-1);
        int x1= util(cost,t,0);
        
        vector<int> t2(cost.size()+1,-1);
        int x2=util(cost,t2,1);
        
        return min(x1,x2);
    }
};