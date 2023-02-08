#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	vector<int> a(n);
	vector<int> b(m);
	vector<int> res;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	int j = 0;
	for (int i = 0; i < m; ++i)
	{
		while(j<n && a[j]<b[i]){
			j++;	
		}
		res.push_back(j);
	}
	for (int itr: res){
		cout<<itr<<" ";
	}
	cout<<endl;
	return 0;
}