#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(int node, int parent, vector<int>& tin, vector<int>& low, vector<int>& vis, vector<int>& adj, int& timer){
    timer+=1;
    vis[node]=1;
    tin[node] = low[node] = timer;
    for(auto& adjacent: adj[node]){
        if(adjacent == parent) continue;

        if(!vis[adjacent]){
            dfs(adjacent, node, tin, low, vis, adj, timer);
            low[node] = min(low[adjacent],low[node]);
            if(low[adjacent]>tin[node]){
                cout<<node<<"<->"<<it<<endl;
            }
        }
        else{
            low[node] = min(low[adjacent],low[node]);
        }
    }       
}
    
int main(){
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}

    vector<int> tin(n,-1);
    vector<int> low(n,-1);
    vector<int> vis(n,0);
    int timer = 0;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,tin,low,vis,adj,timer);
        }
    }
return 0;
}