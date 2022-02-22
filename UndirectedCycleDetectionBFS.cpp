#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool cycleBFS(int s, vector<int> adj[], vector<int>& vis){
        queue<pair<int,int>> q;
        q.push({s,-1});
        vis[s]=1;
        while(!q.empty()){
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for(int& i: adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,node});
                }
                else if(prev!=i) return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(cycleBFS(i,adj,vis)) return true; 
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}