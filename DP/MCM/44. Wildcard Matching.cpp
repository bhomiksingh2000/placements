class Solution {
public:
//     int t[2004][2004];
//     int solve(string &s, string &p, int i, int j){
        
//         if(i<0 && j<0)
//             return true;
        
//         if(i<0 && j>=0){
//             for(int k=0;k<=j;k++){
//                 if(p[k]!='*')
//                     return false;
//             }
            
//             return true;
//         }
        
//         if(j<0 && i>=0)
//             return false;
        
        
//         if(t[i+1][j+1]!=-1)
//             return t[i+1][j+1];
//         if(s[i]==p[j] || p[j]=='?')
//             return  t[i+1][j+1]=solve(s,p,i-1,j-1);
        
        
//         if(p[j]=='*'){
        
//             int match,add_to_sequence;
           
//             if(t[i+1][j]!=-1)
//                 match=t[i+1][j];
            
//             else{
//                 match=solve(s,p,i,j-1);
//                 t[i+1][j]=match;
//             }
            
//             if(t[i][j+1]!=-1)
//                 add_to_sequence=t[i][j+1];
            
//             else{
//                 add_to_sequence=solve(s,p,i-1,j);
//                 t[i][j+1]=add_to_sequence;
//             }
            
            
//             return  t[i+1][j+1]=add_to_sequence || match;
//         }
    
//             return  t[i+1][j+1]=false;
//     }
    // bool isMatch(string s, string p) {
    //     int n=s.size();
    //     int m=p.size();
        // memset(t,-1,sizeof(t));
        // return solve( s,  p,n-1,m-1);
        
bool isMatch(string s, string p) {
		int height = s.size();
		int width = p.size();

		bool result[height + 1][width + 1];
		memset(result, 0, sizeof(result));
		result[0][0] = true;

		for(int i = 0; i < height + 1; i ++)
		{
			for(int j = 1; j < width + 1; j ++)
			{
				if(p[j - 1] == '*')
				{
					result[i][j] = result[i][j - 1];
					if(i > 0)
						result[i][j] = result[i][j] || result[i - 1][j];
				}
				else if(p[j - 1] == '?' && i > 0)
						result[i][j] = result[i - 1][j - 1];
				else if(i > 0)
						result[i][j] = result[i - 1][j - 1] && p[j - 1] == s[i - 1];
			}
		}
		return result[height][width];
	
        }
};