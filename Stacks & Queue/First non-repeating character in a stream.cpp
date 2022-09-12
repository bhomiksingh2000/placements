string FirstNonRepeating(string s){
		    // Code here
		    unordered_map<char,int> mp;
            queue<char> q;
            string res = "";
            for(auto it: s){
                mp[it]++;
                q.push(it);
                
                while(!q.empty() && mp[q.front()]>1){
                    q.pop();
                }
                
                if(q.empty()){
                    res+='#';
                }
                
                else{
                    res+=q.front();
                }
            }
            
            return res;
		}