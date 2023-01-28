#include <bits/stdc++.h>
using namespace std;




int main(){
	int n,m;cin>>n>>m;
	vector<vector<int>> edges(n);
	for (int i = 0; i < m; ++i)
	{
		int u,v;cin>>u>>v;
		u-=1;
		v-=1;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	//For checking if no. of edges is vertices - 1
	//Cyclicity check
	if (m!=n-1){
		cout <<"No"<<endl;
		return 0;
	}
	// Checking if the degree of each node is <=2
	for (int i = 0; i < n; ++i)
	{
		if (edges[i].size()>2){
			cout<<"No"<<endl;
			return 0;
		}
	}

	// Checking the graph is connected
	vector<bool> visited(n);
	queue<int> q;
	visited[0] = true;
	q.push(0);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (auto v: edges[u]){
			if (!visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (!visited[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}