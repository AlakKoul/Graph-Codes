#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> adj[n]; //0 based indexed graph
    for(int i =0 ;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> dist(n,INT_MAX);
    int src;
    cout<<"Enter the source Node: ";
    cin>>src;
    cout<<"Shortest distances are: "<<endl;
    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        int node = q.front();
        int d = dist[node]+1;
        q.pop();
        for(auto &i: adj[node]){
            if(d<dist[i]){
                dist[i]=d;
                q.push(i);
            }
        }
    }
    for(int& i: dist) cout<<i<<" "; 
    return 0;
}