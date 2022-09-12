/*
we will try out all possibilities through recursion 
base condition will be where we would have 
traversed through the whole string , 
this is the point where we will check whether
our 2 subsequences are palindromic , and 
if yes , then we will compare the product 
of the lengths of 2 strings with our ans


recurrence realation will contain three recursive calls , 
first for not inlcuding s[i] in both the strings 
second for inlcuding s[i] in the string s1
third for inlcuding s[i] in the string s2

and we will get our ans recursively

*/
class Solution {
public:
    bool ispalindrome(string s){
    int i = 0,j = s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    
    void solve(string &s , string &s1 , string &s2 , int i , int &ans){
        if(i>=s.size()){
            if(ispalindrome(s1) && ispalindrome(s2)){
                int x=s1.size()*s2.size();
                ans=max(ans,x);
                
            }
            return ;
        }
        
//*******************************************************************************  
        
        // here we have not used backtracking , 
        //but here we will not able to use &s1/&s2  ,
        //ie reference based addressing , and 
        //therefore a new copy of s1 and s2 will be made each time
        //, resulting in TLE
        
//         // we dont add in either of the strings
//         solve(s,s1,s2,i+1,ans);
        
//         // adding in s1;
//         solve(s,s1+s[i],s2,i+1,ans);
        
//         // adding in s2
//         solve(s,s1,s2+s[i],i+1,ans);
//*******************************************************************************     

           // we dont add in either of the strings
            solve(s,s1,s2,i+1,ans);
    
            //pic in first string s1
            s1.push_back(s[i]);
            solve(s,s1,s2,i+1,ans);
            s1.pop_back();

            //pic in second string s2
            s2.push_back(s[i]);
            solve(s,s1,s2,i+1,ans);
            s2.pop_back();
    
    }

    int maxProduct(string s) {
        string s1="";
        string s2="";
        int ans=0;
        solve(s,s1,s2,0,ans);
        return ans;
    }
};