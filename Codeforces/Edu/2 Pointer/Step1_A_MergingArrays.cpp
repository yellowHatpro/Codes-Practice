#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	vector<int> a(n);
	vector<int> b(m);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	a.push_back(INT_MAX);
	b.push_back(INT_MAX);
	int i = 0;
	int j = 0;
	vector<int> res;
	while(i<n || j <m){
		if (a[i]<b[j]){
			res.push_back(a[i++]);

		} else {
			res.push_back(b[j++]);
		}
	}
	for (int itr: res){
		cout<<itr<<" ";
	}
	
	return 0;
}