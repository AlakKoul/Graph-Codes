#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    bool checkBipartiteDFS(int node, vector<int> adj[], vector<int>& color){
        for(auto& i: adj[node]){
                if(color[i]==-1){
                    color[i] = (color[node]==0?1:0);
                    if(!checkBipartiteDFS(i,adj,color)) return false;
                }
                else if(color[i]==color[node]) return false;
            }
        return true;
        }
    public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    for(int i = 0;i<V;i++){
	        if(color[i]==-1){
                color[i]==1;
	            if(!checkBipartiteDFS(i,adj, color)) return false;
	        }
	    }
	    return true;
	}

};
int main()
{
    return 0;
}