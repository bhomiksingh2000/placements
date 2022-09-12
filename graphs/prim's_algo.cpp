// brute force: 
// TC > O(n^2)
// SC : O(N)+O(N)+O(N)
class Solution{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> key(v,INT_MAX);
        vector<bool> mst(v,false);
        vector<int> parent(v,-1);
        key[0]=0;
        for(int count=0;count<v-1;count++){
            int mini=INT_MAX, u;
            
            for(int i=0;i<v;i++)
                if(mst[i]==false && key[i]<mini)
                    mini=key[i], u=i;
                
            mst[u]=true;
            
            for(auto it:adj[u]){
                
                // int nextNode=it.first;
                // int weight=it.second;
                
                int nextNode=it[0];
                int weight=it[1];
                if(mst[nextNode]==false && key[nextNode]>weight){
                    key[nextNode]=weight;
                    parent[nextNode]=u;
                }
            }
        }
        
 // from here we can also make mst, but ATQ we have to find out the sum of weights of mst
        int res=0;
        for(int i=0;i<v;i++)
            res+=key[i];
        
        return res;

    }
};


// optimised using MIN HEAP
// TC > O(nlogn)
// SC : O(N)+O(N)+O(N)+O(N)
class Solution{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> key(v,INT_MAX);
        vector<bool> mst(v,false);
        vector<int> parent(v,-1);
        key[0]=0;
        mst[0]=true;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            
            int u=pq.top().second;
            pq.pop();
            mst[u]=true;
            
            for(auto it:adj[u]){
                
                // int nextNode=it.first;
                // int weight=it.second;
                int nextNode=it[0];
                int weight=it[1];
                
                if(mst[nextNode]==false && key[nextNode]>weight){
                    
                    parent[nextNode]=u;
                    key[nextNode]=weight;
                    pq.push({key[nextNode],nextNode});
                    
                }
                
            }
        }
        
        int res=0;
        for(int i=0;i<v;i++)
            res+=key[i];
        
        return res;
    }
};