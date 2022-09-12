class Solution{
   public:
		int LongestRepeatingSubsequence(string str1){
		    // Code here
		    string str2=str1;
		    int n=str1.size();
		    int t[n+1][n+1];
		    for(int i=0;i<n+1;i++)
		        for(int j=0;j<n+1;j++)
		            if(i==0 || j==0)
		                t[i][j]=0;
		  
		    for(int i=1;i<n+1;i++){
		        for(int j=1;j<n+1;j++){
		            if(str1[i-1]==str2[j-1] && i!=j)
		                t[i][j]=1+t[i-1][j-1];
		          
		            else
		                t[i][j]=max(t[i][j-1],t[i-1][j]);
		            
		        }
		    }
		    
		    return t[n][n];
		}
};