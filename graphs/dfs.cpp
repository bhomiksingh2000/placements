// if multiple compnonets then use a loop in dfsOfGraph function

// this is the better approach 
class Solution{
    public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[], vector<int> &vis, vector<int> &res,int i){
        vis[i]=1;
        res.push_back(i);
        for(auto j:adj[i]){
            if(!vis[j]){
                dfs(adj,vis,res,j);
            }
        }
        
        return ;
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> vis(v,0);
        vector<int> res;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(adj,vis,res,i);
            }
        }
        
        return res;
    }
};


// for one component, 
class Solution {
  public:
  
    void dfs(vector<int> adj[],vector<int> &res,vector<int> &vis,int i){
        if(!vis[i]){
            return ;
        }
        
        for(auto j:adj[i]){
            if(!vis[j]){
                vis[j]=1;
                res.push_back(j);
            
                dfs(adj,res,vis,j);
            }
            
        }
        
        
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> res;
        vector<int> vis(v,0);
        vis[0]=1;
        res.push_back(0);
        
        dfs(adj,res,vis,0);
        
        return res;
    }
};


