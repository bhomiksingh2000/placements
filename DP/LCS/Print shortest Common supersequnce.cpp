class Solution {
public:
    string printSCS(string str1, string str2, int n, int m, vector<vector<int>> &t){
        int i=n;
        int j=m;
        string res="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                res+=str1[i-1];
                i--;
                j--;
            }
            
            else{
                if(t[i-1][j]>t[i][j-1]){
                    res+=str1[i-1];
                    i--;
                }
                
                else{
                    res+=str2[j-1];
                    j--;
                }
            }
        }
        
        while(i>0){
            res+=str1[i-1];
            i--;
        }
        
        while(j>0){
            res+=str2[j-1];
            j--;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        
        vector<vector<int>> t(n+1,vector<int>(m+1));
        for(int i=0;i<n+1;i++)
            t[i][0]=0;
        for(int i=0;i<m+1;i++)
            t[0][i]=0;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1]==str2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        
        return printSCS(str1,str2,n,m,t);
    }
};