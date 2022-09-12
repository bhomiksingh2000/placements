class Solution{
  public:
    // Function to detect cycle in an undirected graph.
    bool check(vector<int> &vis, vector<int> adj[],int i){
        queue<pair<int,int>> q;
        q.push({i,-1});
        vis[i]=1;
        while(!q.empty()){
            int node=q.front().first;
            int prev=q.front().second;
            q.pop();
            for(auto i :adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,node});
                    
                }
                else {
                    if(prev!=i){
                        return true;
                        
                    }
                    
                }
                
            }
            
        }
        return false;
        
    }
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> vis(v,0);
        queue<pair<int,int>> q;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(check(vis,adj,i))
                  return true;
            }
        }
        
        return false;
    }

};