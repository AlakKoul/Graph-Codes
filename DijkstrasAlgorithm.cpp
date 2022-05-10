#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1];

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back({b,wt});
		g[b].push_back({a,wt});
	}	
	cin >> source;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	vector<int> distTo(n+1,INT_MAX);
	
	distTo[source] = 0;
	pq.push({0,source});
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
	
		for( auto it: g[prev]){
			int next = it.second;
			int nextDist = it.first;
			if( distTo[next] > dist + nextDist){
				distTo[next] = dist + nextDist;
				pq.push({distTo[next], next});
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}


/*
Why Priority Queue?
 It will end up taking a lot more time, as you will not get the shorter distance at first instance, will have to do a lot of rounds.
Example:
1 2 10
2 3 15 
1 4 1
4 5 1 
3 6 10
5 6 1 
In this queue, you will necessary travel some nodes, you reach the node 6 twice, which will be avoided in case of PQ, so in larger cases, this becomes more costlier..
*/