#include<bits/stdc++.h>
#define ll long long int
using namespace std;
    
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++;
    int child = 0; 
    for(auto adjacent: adj[node]) {
        if(adjacent == parent) continue;
        
        if(!vis[adjacent]) {
            dfs(adjacent, node, vis, tin, low, timer, adj, isArticulation); 
            low[node] = min(low[node], low[adjacent]); 
	    child++; 
            if(low[adjacent] >= tin[node] && parent != -1) {
                isArticulation[node] = 1; 
            }
        } else {
            low[node] = min(low[node], tin[adjacent]); 
        }
    }
    
    if(parent == -1 && child > 1) {
        isArticulation[node] = 1; 
    }
}

int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj, isArticulation); 
	    }
	}
	
	for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) cout << i << endl;
	}
	
	return 0;
}