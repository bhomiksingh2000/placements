/*
So it is a very good question because here you have to intuitively think that how to apply the recursive relation and also to apply backtracking or not but here we do not have any use of backtracking because backtracking is applied then we have to move to similar cells again and again but here we will not move to similar cells because if you see the robot one is starting from the top left corner and robot two is starting from the top right corner therefore either they can go down or they can move digonally  left or digonally right therefore if you will think if you will see surely you will understand that the path of robot1 to  robot2 will be unique to each other and they will meet at only some points where the cell value is same  therefore at that cell we  will only add cherry once and for other cells We add cherry twice
*/
class Solution {
public:
    int t[71][71][71];
    int solve(vector<vector<int>>& grid,int i,int j, int y){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || y<0 ||  y>=grid[0].size())
            return INT_MIN;
        
        if(i==grid.size() && j==grid[0].size())
            return grid[i][j];
        
        if(i==grid.size() && y==grid[0].size())
            return grid[i][y];
      
        if(t[i][j][y]!=-1)
            return t[i][j][y];
        
        int cherry1=grid[i][j];
        int cherry2=grid[i][y];
        int ans=0;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                ans=max(ans,solve(grid,i+1,j+a,y+b));
            }
        }
        
        if( j==y)
            return t[i][j][y]=cherry1+ans;
        
        return t[i][j][y]=cherry1+cherry2+ans;
        
//         int dldl=solve(grid,i+1,j-1,x+1,y-1);
//         int dldr=solve(grid,i+1,j-1,x+1,y+1);
//         int dld=solve(grid,i+1,j-1,x+1,y);
        
//         int drdl=solve(grid,i+1,j+1,x+1,y-1);
//         int drdr=solve(grid,i+1,j+1,x+1,y+1);
//         int drd=solve(grid,i+1,j+1,x+1,y);
        
//         int ddl=solve(grid,i+1,j,x+1,y-1);
//         int ddr=solve(grid,i+1,j,x+1,y+1);
//         int dd=solve(grid,i+1,j,x+1,y);
        
//         int c1=max(dldl,max(dldr,dld));
//         int c2=max(drdl,max(drdr,drd));
//         int c3=max(ddl,max(ddr,dd));
        
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        return solve(grid,0,0,grid[0].size()-1);
    }
};