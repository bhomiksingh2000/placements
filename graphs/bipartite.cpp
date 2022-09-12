// BFS:

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> vis(v,0);
        vector<int> colour(v);
        
        for(int i=0;i<v;i++){
            
            if(!vis[i]){
                
                colour[i]=1;
                vis[i]=1;
                queue<int> q;
                q.push(i);
                
                while(!q.empty()){
                    
                    int node=q.front();
                    q.pop();
                    
                    for(auto j:graph[node]){
                        
                        if(!vis[j]){
                            vis[j]=1;
                            colour[j]=!(colour[node]);
                            q.push(j);
                        }
                        
                        else{
                            if(colour[j]==colour[node])
                                return false;
                        }
                    }
                    
                }
                
                
            }
        }
        
        return true;
    }
};

// DFS:
public:
    bool dfs(vector<int> &vis,vector<int> &colour,vector<int> adj[],int i){
	    vis[i]=1;
	   // colour[i]=1;
	    
	    for(auto j:adj[i]){
	        if(!vis[j]){
	           // vis[j]=1;
	            colour[j]=!(colour[i]);
	            if(!dfs(vis,colour,adj,j))
	                return false;
	        }
	        
	        else{
	            if(colour[j]==colour[i])
	                return false;
	        }
	    }
	    
	    return true;
    }
	bool isBipartite(int v, vector<int>adj[]){
	    vector<int> vis(v,0);
	    vector<int> colour(v,0);
	    
	    for(int i=0;i<v;i++)
	        if(!vis[i])
	            if(!dfs(vis,colour,adj,i))
	                return false;
	            
	        
	    return true;
	}
