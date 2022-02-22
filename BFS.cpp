#include<bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int n, vector<int>& adj[]){
    vector<int> bfs; 
    vector<int> visited(n+1,0);
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int temp = q.front();
                bfs.push_back(temp);
                q.pop();
                for(int& j: adj[temp]){
                    if(!vis[j]){
                        q.push(j);
                        vis[j]=1;
                    }
                }
            }
        }
    }
    return bfs;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i =1 ;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //only in undirected graph
    }

    vector<int> res = bfsOfGraph(n,adj);
    cout<<"BFS of the Graph is: ";
    for(int &i: res)
        cout<<i<<" ";
    return 0;
}