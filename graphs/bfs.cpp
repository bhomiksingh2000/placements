class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector<int> res;
        vector<int>vis(v,0);
        
        queue<int> q;
        q.push(0);
        vis[0]=1;
                
        while(!q.empty()){
                int x=q.front();
                q.pop();
                res.push_back(x);
                    
                for(auto j:adj[x]){
                    
                    if(!vis[j]){
                        q.push(j);
                        vis[j]=1;
                    }
                        
                }
            
        }
        return res;
    }
};