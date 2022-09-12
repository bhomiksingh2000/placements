class Solution
{
    public:
    // Find LCS of two strings and then subtract it from their combine length, that's it ….
    // bcoz we have to find the length of the smallest string which 
    //has both, X and Y as its sub-sequences.
    
    int t[101][101];
    int solve(string str1, string str2, int i, int j){
        if(i<0 || j<0){
            return 0;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        if(str1[i]==str2[j]){
            return t[i][j]=1+solve(str1,str2,i-1,j-1);
        }
        
        else{
            return t[i][j]=max(solve(str1,str2,i,j-1),solve(str1,str2,i-1,j));
        }
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        memset(t,-1,sizeof(t));
        int LCS=solve(X,Y,m-1,n-1);
        
        int sx=m-LCS;
        int sy=n-LCS;
 
        return LCS+sx+sy;
    }
};