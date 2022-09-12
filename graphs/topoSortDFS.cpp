class Solution{
    public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int> adj[],vector<int> &vis,stack<int> &st,int i){
	    
	    vis[i]=1;
	    
	    for(auto j:adj[i]){
	        if(!vis[j]){
	            dfs(adj,vis,st,j);
	        }

            // this is wrong because saara loop nhi chlega iski vjh se
	       // else{
	       //     return ;
	       // }
	    }
	    st.push(i);
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{  
	   vector<int> vis(v,0);
	   stack<int> st;
	   
	   for(int i=0;i<v;i++){
	       if(!vis[i])
	           dfs(adj,vis,st,i);
	   }
	   
	   vector<int> res;
	   while(!st.empty()){
	       res.push_back(st.top());
	       st.pop();
	   }
	   
	   return res;
	}
};


// 2nd method 😂😂😂 just a slight modification:
class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int> adj[],vector<int> &vis,stack<int> &st,int i){
	    for(auto j:adj[i]){
	        if(!vis[j]){
	            vis[j]=1;
	            dfs(adj,vis,st,j);
	        }
	    }
	    st.push(i);
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{  
	   vector<int> vis(v,0);
	   stack<int> st;
	   
	   for(int i=0;i<v;i++){
	       if(!vis[i]){
	            vis[i]=1;
	            dfs(adj,vis,st,i);
	       }
	           
	   }
	   
	   vector<int> res;
	   while(!st.empty()){
	       res.push_back(st.top());
	       st.pop();
	   }
	   
	   return res;
	}

};