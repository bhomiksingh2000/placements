// time complexity: O(nlogn)
// space complexity: O(n) + O(n)
vector <int> dijkstra(int v, vector<pair<int,int> >adj[], int s)
    {
        vector<int> dist(v,INT_MAX);
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

         // min heap will be sorted according to dist
         pq.push({0,s});
         dist[s]=0;
         while(!pq.empty()){
             
             int node=pq.top().second;
             int distance=pq.top().first;
             pq.pop();
             
             for(auto i:adj[node]){
                 
                 int nextNode=i.first;
                 int nextNodeDist=i.second;
                 
                 
                 if(distance+nextNodeDist<dist[nextNode]){
                     dist[nextNode]=distance+nextNodeDist;
                     pq.push({dist[nextNode],nextNode});
                 }
                 
                 /*
                 this is also same :
                 if(dist[node]+nextNodeDist<dist[nextNode]){
                     dist[nextNode]=dist[node]+nextNodeDist;
                     pq.push({dist[nextNode],nextNode});
                 }
                 */
             }
         }
        return dist;
    }