#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    vector<int> adjList[nodes+1];

    for(int i = 0; i<edges; i++){
        int n,m;
        cin>>n>>m;
        adjList[n].push_back(m);
        adjList[m].push_back(n); //Not in case of directed graph
    }
    return 0;
}