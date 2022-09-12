int findPar(int node, int parent[]){

    // means we have reached at the super daddy, 
    // it will be its own parent
    if(node==parent[node]){
        return node;
    }

    // return findPar(parent[node]);

    // this will decrease the depth of the tree, and 
    // also decrease the time complexity of finding parent again and again:
    // this is Path Compression:
    return parent[node]=findPar(parent[node]);
}

void union (int u, int v,int parent[], int rank[]){
    
    // finding the parent of both nodes u & v;
    u=findPar(u);
    v=findPar(v);
    
    if(rank[u]>rank[v]){
        // thereofore u will be the daddy of v
        // and as ranks are differnt therefore no change in rank[u] & rank[v]
        parent [v]=u;
    }

    else if(rank[u]<rank[v]){
        // thereofore u will be the daddy of v
        parent [u]=v;
    }

    else{
        // as both have same rank , thereofre kisi ko bhi banado daddy
        // lets say u ko banadia daddy
        parent [v]=u;
        rank[u]++;
    }

    // if parent of u & v will be same , then they belong to same component ,
    // then there will be no need of union.
}

struct node{
    int u,v,wt;
     node(int first,int second, int weight){
        u=first;
        v=second;
        wt=weight;
     }
};

// sort according to weights:
bool comp(node a, node b){
    return a.wt<b.wt;
}
int main(){
    int N=5,m=6;
	vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));

    // sorted by weights:
	sort(edges.begin(), edges.end(), comp); 

    int parent[N];
    int rank[N];

    for(int i=0;i<N;i++){
        parent[i]=i;
        rank[i]=0;
    }

    int cost=0;
    // this will store all the pair (u,v) if u & v form an edge in MST 
    vector<pair<int,int>> mst;

    for(auto it:edges){
        // if they do not have same parent, ie they dont belong to same component
        // then we can create an edge:
        if(findPar(it.v,parent)!=findPar(it.v,parent)){
            cost+=it.wt;
            // thats a valid edge 
            mst.push_back({it.u,it.v});

            // now as they will be connected , thereofre connect them 
            union(it.u,it.v,parent,rank)
        }
    }

    cout<<"total cost of MST is"<<cost<<endl;

    for(auto it:mst){
        cout<<it.first<<"-"<<it.second<<endl;
    }
	return 0;
}