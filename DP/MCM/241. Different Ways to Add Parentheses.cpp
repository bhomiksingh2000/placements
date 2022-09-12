class Solution {
public:
     unordered_map<string, vector<int>> dp;
    vector<int>  solve(string s, int i , int j){
        if(i>j)
        {
            return { };
        }
        string key = to_string(i) + "," + to_string(j);
        
        if(dp.count(key))
        {
            return dp[key];
        }
        if(j-i<=1)
        {
             string num = s.substr(i, j + 1);
            
            return dp[key] = {stoi(num)};
        }
        
        vector<int>  ans;
       
        for(int k=i;k<=j-1;k++){
              if(s[k] == '+' || s[k] == '-' || s[k] == '*')
              {
                vector<int>  left=solve(s,i,k-1);
                vector<int>  right=solve(s,k+1,j);

                  char ch = s[k];
                for (auto l : left) {
                    for (auto r : right) {
                        switch (ch) {
                            case '+':
                                ans.push_back(l + r);
                                break;
                            case '-':
                                ans.push_back(l - r);
                                break;
                            case '*':
                                ans.push_back(l * r);
                                break;
                            case '/':
                                ans.push_back(l / r);
                                break;
                        }
                    }
                }
              }
            
        }
       
      return dp[key] = ans;
        
    }
    vector<int> diffWaysToCompute(string expression) {
          return solve(expression, 0 , expression.size()-1);
    }
};

