#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    bool cycleDFS(int node, int par, vector<int> adj[], vector<int>& vis){
        vis[node]=1;
        for(int&i: adj[node]){
            if(!vis[i]){
                if(cycleDFS(i,node,adj,vis)) return true;
            }
            else if(i!=par) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(cycleDFS(i,-1,adj,vis)) return true; 
            }
        }
        return false;
    }
};
int main()
{
    return 0;
}