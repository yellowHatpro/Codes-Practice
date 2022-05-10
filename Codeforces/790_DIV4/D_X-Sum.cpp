#include <bits/stdc++.h>
using namespace std;

void solveBoard(int i, int j, vector<vector<int>> v, vector<vector<int>> &res){

}

void solve(){
	int n,m;
	cin>>n;cin>>m;
	vector<vector<int>> v;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int x;cin>>x;
			v[i].push_back(x);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++i)
		{
			vector<vector<int>> res;
			solveBoard(i,j,v, res);
		}
	}

	return;
}
int main(){
	int t;cin>>t;
	while(t--){
	solve();
	}
	return 0;
}