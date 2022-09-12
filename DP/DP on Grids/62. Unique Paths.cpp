class Solution {
public:
    int t[101][101];
    int solve(int m, int n, int i, int j){
        if(i==m-1 && j==n-1)
            return 1;
        
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        int d=solve(m,n,i+1,j);
        int r=solve(m,n,i,j+1);
        
        return t[i][j]=d+r;
    }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(m,n,0,0);
    }
};