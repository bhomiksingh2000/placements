class Solution {
public:
     int t[366];
    int util(vector<int>& days, vector<int>& costs,int index){
        if(index>=days.size())
            return 0;
        
         if(t[index]!=-1)
            return t[index];
        
        int dollars=INT_MAX;
        
     
        int c1=costs[0]+util(days,costs,index+1);
        
        auto it=lower_bound(days.begin(), days.end(),days[index]+7)-days.begin();
        int c2=costs[1]+util(days,costs,it);
        
        auto it2=lower_bound(days.begin(), days.end(),days[index]+30)-days.begin();
        int c3=costs[2]+util(days,costs,it2);
        
        dollars=min(c1,min(c2,c3));
        
        return t[index]=dollars;
        
    
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        return util(days,costs,0);
    }
};