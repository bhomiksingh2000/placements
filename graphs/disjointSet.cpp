// here we will have 2 functions: 

int parent[10000];
int rank[10000];
int n=100;
void makeSet(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findPar(int node){

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

void union (int u, int v){
    
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

void main{
    makeSet();
    int m;
    cin>>m;

    while(m--){
        int u,v;
        cin>>u;
        cin>>v;
        
        union(u,v);
    }

    // we want to check whtheer nodes 2 & 3 belong to same compnent or not
    if(findPar(u)!=findPar(v)){
        cout<<"diff component"<<endl;
    }

    else{
        cout<<"same compmonet"<<endl;
    }
}