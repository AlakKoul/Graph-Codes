#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    int adjMatrix[nodes+1][nodes+1]={0}; //1-based Indexing
    for(int i=0;i<edges;i++){
        int n, m;
        cin>>n>>m;
        adjMatrix[n][m]=1;
        adjMatrix[m][n]=1; // Not in case of directed graph
    }
    return 0;
}

/*
Drawback: In case of Large Number of nodes let's say 10^5, a matrix of 10^5*10^5 is not an efficient method, i.e. why we uses adjacency list

*/