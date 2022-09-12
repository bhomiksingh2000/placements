class Solution {
public:
    int t[201][201];
    int solve(vector<vector<int>>& dungeon,int n, int m, int i , int j){
        if(i>=n  ||  j>=m )
            return INT_MAX;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        int d=solve(dungeon,n,m,i+1,j);
        int r=solve(dungeon,n,m,i,j+1);
        
        int health =min(r,d);
        int res=0;
        
        if(health==INT_MAX)
            health=1;
        
        if(health-dungeon[i][j]>0)
            res=health-dungeon[i][j];
        
        else
            res=1;
    
        return t[i][j]=res;
            
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        
        memset(t,-1,sizeof(t));
        return solve(dungeon,n,m,0,0);
        
        
        
    }
};