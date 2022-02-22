// Disjoint set Union By Rank and find parent by path compression
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int parent[1e5];
int rank[1e5];

void makeSet(){
    for(int i = 1; i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findPar(int node){
    if(parent[node]==node) return node;
    
    return parent[node] = findPar(parent[node]); // path compression
}

void union(int u, int v){
    u = findPar(u);
    v = findPar(v);
    if(rank[u]<rank[v])
        parent[u]=v;
    else if(rank[v]<rank[u])
        parent[v]=u;
    else{
        parent[v]=u;
        rank[u]++;
    }
}
    
int main(){
    makeSet();
    int t;
    while(t--){
        int u,v;
        cim>>u>>v;
        union(u,v);
    }
    //Check for same set or not
    if(findPar(2)!=findPar(3)) cout<<"Different Component"<<endl;
    else cout<<"Same component"<<endl;
return 0;
}

/* Time complexity:
    without path compression: O(N)
    with compression: O(logN)
*/