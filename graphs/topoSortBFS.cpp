// kahn's algo:
class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
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
	    
	    vector<int> topo;
	    
	    while(!q.empty()){
	        
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto i:adj[node]){
	            indegree[i]--;
	            if(indegree[i]==0){
	                q.push(i);
	            }
	        }
	    }
	    
        
	    return topo;
	    
	}
};