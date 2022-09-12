// shortest distance in undirected graph with unit weights

void BFS(vector<int> adj[], int v, int src){
    vector<int> dist(v,INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src]=0;

    while(!q.empty()){

        int node=q.front();
        q.pop();

        for(auto i:adj[node]){
            if(dist[i]>dist[node]+1){
                dist[i]=dist[node]+1;
                q.push(i);
            }
        }
    }

    // dist[i] will contain , the shortest distance for each node:
    // means for eg , if we want calculate shortest distance bw any two nodes
    // it can be calculated by dist[y]-dist[x]:
    for(int i=0;i<v;i++){
        cout<<dist[i]<<endl;
    }
}

