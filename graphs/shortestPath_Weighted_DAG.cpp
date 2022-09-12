// shortest path in directed , weighted directed acyclic Graph (DAG)


void shortestPath(vector<pair<int,int>> adj[], int v, int src){

    vector<int> dist(v,INT_MAX);
    stack<int> st;
    vector<int> vis(v,0);

    for(int i=0;i<v;i++){
        if(!vis[i]){
            toposort(v,adj,st,vis);
        }
    }

    // topoSort order is in stack
    // now we will use BFS, for finding shortest distance,
    dist[src]=0;
    
    while(!st.empty()){

        int node=st.top();
        st.pop();
        
        // if the node has not been reached previously:
        if(dist[node]!=INT_MAX){
           for(auto j:adj[node]){
            if(dist[node]+j.second<dist[j.first]){
                dist[j.first]=dist[node]+j.second;
                }
            }
        }
    }
}

void dfs(vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &st,int i){
	    
	    vis[i]=1;
	    
	    for(auto j:adj[i]){
	        if(!vis[j.first]){
	            dfs(adj,vis,st,j.first);
	        }

            // this is wrong because saara loop nhi chlega iski vjh se
	       // else{
	       //     return ;
	       // }
	    }
	    st.push(i);
	}
	vector<int> topoSort(int v, vector<pair<int,int>> adj[],stack<int> &st, vector<int> &vis) 
	{  
	   for(int i=0;i<v;i++){
	       if(!vis[i])
	           dfs(adj,vis,st,i);
	   }

    }

       /*
This problem, can be solved through BFS too.But there will be too many redundancies in it.
We start from source=0, it relaxes its adjacents, and pushes these adjacent nodes along with 
their distances into the queue.
Then these adjacent nodes will further relax their adjacent nodes and push the relaxed nodes.

Consider this graph: first of pair is the adjacent node and second of pair is the edge weight 

1->[(2,2), (3,1)]
2->(4,2)
3->(5,1)
5->(4,1)
4->(6,1)

Final queue will be like - (first of pair is the node and second of pair is the distance
 from source to this node)
(1,0)(2,2)(3,1)(4,4)(5 2)(6 5)(4 3)(6 4)
These all will be popped out when they relax their adjacent nodes.
For ex, (1,0) will be popped out before (2,2)(3,1) are pushed into queue and so on.

As we can see, there is redundancy, node 4 first came in the queue with a 
distance of 4 from source, and then again
node 4 came with a distance of 3 from the source, which increases time 
complexity, because, now (4,3) will have to again relax its adjacent nodes
to reduce the distances of its adjacent nodes.

So, if the pre-requisites of any node(say, cur) are relaxed as minimum
 as possible before the relaxation of node cur.Then redundancy will never occur.
Taking the same example as above, if 1 2 3 5 are relaxed as minimum 
as possible before the relaxation of node 4. Then redundancy will never occur.

The solution to the above observation is Topological sort.
If we have Topo sort sequence, then we will take the source node first and relax its adjacent nodes.After that, we take next node
in the topo sort, and will do the same.

TC - O(N+E)
SC-O(N)
*/