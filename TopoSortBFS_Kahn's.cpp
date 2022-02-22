#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    queue<int> q;
	    vector<int> topo;
	    for(int i=0;i<V;i++){
	        for(int& it: adj[i])
	            indegree[it]++;
	    }
	    
	    for(int i=0; i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(int i: adj[node]){
	            indegree[i]--;
	            if(!indegree[i]) q.push(i);
	        }
	    }
	    return topo;
	}
};
int main()
{
    return 0;
}