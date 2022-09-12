class Solution {
public:
    // first find out the length of LCS of both the strings , 
    
    int minDistance(string S1, string S2) {
        int n=S1.size();
        int m=S2.size();
         int t[n+1][m+1];
       
       for(int i=0;i<n+1;i++){
           for(int j=0;j<m+1;j++){
               if(i==0 || j==0)
                 t[i][j]=0;
           }
       }
       for(int i=1;i<n+1;i++){
           for(int j=1;j<m+1;j++){
               if(S1[i-1]==S2[j-1])
                 t[i][j]=1+t[i-1][j-1];
                 
               else
                 t[i][j]=max(t[i-1][j],t[i][j-1]);
               
           }
       }
      
       int LCS=t[n][m];
       // then x will denote the no of characters to be deleted from s1 to form lcs with s2 and y will denote  the no of characters to be added 
       int x=n-LCS;
       int y=m-LCS;
        
      return x+y;
      
    }
};