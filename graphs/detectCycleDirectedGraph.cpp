// METHOD_1 => DFS:

class Solution{
public:
    // Function to detect cycle in a directed graph.
    int dfs(vector<int> adj[], vector<int> &vis, vector<int> &dfsVis, int i){
        dfsVis[i]=1;
        vis[i]=1;
        
        for(auto j:adj[i]){
            
            if(!vis[j]){
                if(dfs(adj,vis,dfsVis,j))
                    return true;
            }
            else{
                if(dfsVis[j])
                    return true;
            }
        }
        
        dfsVis[i]=0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> vis(v,0);
        vector<int> dfsVis(v,0);
       
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(adj,vis,dfsVis,i))
                    return true;
            }
            
        }
        
          
        return false;
    }

};


// METHOD-2 =>BFS (using kahn's algo)
class Solution{
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
         vector<int> indegree(v,0);
	    
	    for(int i=0;i<v;i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<v;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        } 
	    }
	    
	    int count=0;
	    
	    while(!q.empty()){
	        
	        int node=q.front();
	        q.pop();
	        count++;
	        
	        for(auto i:adj[node]){
	            indegree[i]--;
	            if(indegree[i]==0){
	                q.push(i);
	            }
	        }
	    }
	    
        // means no cycle
	    if(count==v)
	      return false;
	      
        // cycle is present
	    return true;
    }
};