class Solution{
  public:
    int t[1001][1001];
    int solve(int price[],vector<int> &len, int n, int i){
        if(n==0){
            return 0;
        }
        
        if(n<0 || i<0){
            return -1000;
        }
       
        if(t[i][n]!=-1){
            return t[i][n];
        }
        if(len[i]<=n){
            return t[i][n]=max(price[i]+solve(price,len,n-len[i],i),solve(price,len,n,i-1));
        }
        
        else{
            return t[i][n]=solve(price,len,n,i-1);
        }
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int> len(n);
        for(int i=0;i<n;i++){
            len[i]=i+1;
        }
        // memset(t,-1,sizeof(t));
        // return solve(price,len,n,n-1);
        
        
        // by TABULATION
        int dp[n+1][n+1];
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                
                if(len[i-1]<=j)
                    dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
                
                else
                    dp[i][j]=dp[i-1][j];
                
            }
        }
        
        return dp[n][n];
    }
};
