#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void dfs(int node, vector<int>& vis, stack<int>& s, vector<int> adj[]){
        vis[node]=1;
        for(int& i: adj[node]){
            if(!vis[i]){
                dfs(i,vis,s,adj);
            }
        }
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    vector<int> res;
	    stack<int> s;
	    for(int i = 0;i<V;i++){
	       if(!vis[i]){
	           dfs(i,vis,s,adj);
	       }
	    }
	    while(!s.empty()){
	        res.push_back(s.top());
	        s.pop();
	    }
	    return res;
	}
}

int main()
{
    return 0;
}