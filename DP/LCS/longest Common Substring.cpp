// recursive code:
int lcs(int i, int j, int count)
{

	if (i == 0 || j == 0)
		return count;

	if (X[i - 1] == Y[j - 1]) {
		count = lcs(i - 1, j - 1, count + 1);
	}
	count = max(count,
				max(lcs(i, j - 1, 0),
					lcs(i - 1, j, 0)));
	return count;
}

// here tabulation is more easy becuase recursion m tagda intuition h
//tabulation

int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++)
            dp[i][0]=0;
        
        
        for(int i=0;i<m+1;i++)
            dp[0][i]=0;
        
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                
                
                else{
                    dp[i][j]=0;
                }
            }
        }
        
        // max can occur at any cell, therefore iterating over the dp 
        // to calculate maximum.
        
        int maxs=-1;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                maxs=max(maxs,dp[i][j]);
            }
        }
        return maxs;
    }