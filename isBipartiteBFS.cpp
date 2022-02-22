#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    bool checkBipartiteBFS(int node, vector<int> adj[], vector<int>& color){
        queue<int> q;
        q.push(node);
        color[node]=1; //starting from color 1
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int &i: adj[t]){
                if(color[i]==-1){
                    color[i] = (color[t]==0?1:0);
                    q.push(i);
                }
                else{
                    if(color[i]==color[t]) return false;
                }
            }
        }
        return true;
    }
    public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    for(int i = 0;i<V;i++){
	        if(color[i]==-1){
	            if(!checkBipartiteBFS(i,adj, color)) return false;
	        }
	    }
	    return true;
	}

};
int main()
{
    return 0;
}