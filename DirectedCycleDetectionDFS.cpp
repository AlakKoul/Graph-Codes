#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
  bool checkCycleDFS(int node, vector<int>& vis, vector<int>& dfsVis, vector<int> adj[]){
      vis[node]=1;
      dfsVis[node]=1;
      for(int& i: adj[node]){
          if(!vis[i]){
              if(checkCycleDFS(i,vis,dfsVis,adj)) return true;
          }
          else if(dfsVis[i]) return true;
      }
      dfsVis[node]=0;
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> dfsVis(V,0);
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(checkCycleDFS(i,vis,dfsVis,adj)) return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}
