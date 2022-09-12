class Solution {
  public:
  
    bool dfs(vector<int> &vis, vector<int> adj[],int i,int parent){
        vis[i]=1;
        
        for(auto j:adj[i]){
            if(!vis[j]){
                if(dfs(vis,adj,j,i)){
                    return true;
                }
            }
            
            else{
                if(parent!=j){
                    return true;
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
                if(dfs(vis,adj,i,-1))
                  return true;
            }
        }
        
        return false;
    }
};