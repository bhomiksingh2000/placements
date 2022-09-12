class Solution {
public:
    int t[1001][1001];
    int solve(string &text1, string &text2, int i, int j){
        
        if(i<0 || j<0)
            return 0;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        if(text1[i]==text2[j])
            return t[i][j]=1+solve(text1,text2,i-1,j-1);
        else
            return t[i][j]=max(solve(text1,text2,i-1,j),solve(text1,text2,i,j-1));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
         
        memset(t,-1,sizeof(t));
        return solve(text1,text2,n-1,m-1);
       /*
       TABULATION:
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                
            }
        }
        
        return t[n][m];
        */
    }
};