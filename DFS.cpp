#include<bits/stdc++.h>
using namespace std;
class Dfs{
private:
    void(int node, vector<int>& res, vector<int>& vis, vector<int> adj[]){
        res.push_back(node);
        vis[node]=1;
        for(int& i: adj[node]){
            if(!vis[i]){
                dfs(i,res,vis,adj);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<int> vis(n,0);
        dfs(0,res,vis,adj); //zero based indexing
        return res;
    }
};

int main(){
    //Graph Creation Code
    return 0;
}