*
 see this soln:  VVIMP

https://leetcode.com/problems/cherry-pickup/discuss/1678016/Recursion-%2B-memoization-or-3-Approaches-or-C%2B%2B-fully-memoized-code-or-O(N4)-to-O(N3)




So here we have not used backtracking because it is a very intuitive case,,  both of the person will start from the top left corner and can't take either  right or down direction through valid path cells (cells with value 0 or 1). 

so here if we see that We will solve this problem previously we have done in all DP grids problems ,  in this problem where we explore all the parts and take out the maximum answer if you remember we do not use backtracking in it because we explore every part and here  also we have use this and he will explore  every path  and backtracking will not be used (remember dp on grids) and in the second method if you see in the solution of  discussion the backktracking is used because two different persons are going because first you'll start from top left and then when we reach to the right most cell then we will again go from right most cell to the top one cause we want to find out the maximum and there we will use the backtracking because the first person coming in the direction of the right most cell will pick the cherries and at that cell cherries will be 0 , and the second person will not be able to pick up any cherry , thereofore  we will have to use backtracking there


*/
class Solution {
public:
    int dp[50][50][50][50];
    int solve(vector<vector<int>>& grid,int n, int i1,int j1 , int i2, int j2){
       
        if( i1>=n || j1>=n ||  i2>=n || j2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1 )return INT_MIN;
        
        
        if(i1==n-1 && j1==n-1)
            return grid[i1][j1];
        
        if(i2==n-1 && j2==n-1)
            return grid[i2][j2];
        
       if(dp[i1][j1][i2][j2]!=-1)return dp[i1][j1][i2][j2];
        
       int pickedCherries = 0;
    
       int dd,dr,rd,rr;
       
        dd =  solve(grid,n,i1+1,j1,i2+1,j2);
        dr =  solve(grid,n,i1+1,j1,i2,j2+1);
        rd =  solve(grid,n,i1,j1+1,i2+1,j2);
        rr=   solve(grid,n,i1,j1+1,i2,j2+1);
        
        
        pickedCherries=max( max(dd,dr) , max(rd,rr) ); 
        
        if(i1==i2 && j1==j2){
            pickedCherries+=grid[i1][j1];
        }
        else{
            pickedCherries+= grid[i1][j1]+grid[i2][j2];
        }
        
         dp[i1][j1][i2][j2]=pickedCherries;
        return pickedCherries;
         
    }   
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        int ans= solve(grid,n,0,0,0,0);
        
        
        if(ans<0)
            return 0;
        
        return ans;
    }
};


/*
 see this soln:  VVIMP

https://leetcode.com/problems/cherry-pickup/discuss/1678016/Recursion-%2B-memoization-or-3-Approaches-or-C%2B%2B-fully-memoized-code-or-O(N4)-to-O(N3)

*/