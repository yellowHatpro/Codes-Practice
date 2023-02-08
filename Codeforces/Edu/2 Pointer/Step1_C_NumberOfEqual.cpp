#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	map<int, int> a;
	vector<int> b(m);
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		a[x]++;
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	long long cnt = 0;
	int j = 0;
	for (auto i: a){
		long long newcnt = 0;
		while (j<m && i.first>=b[j]){
			if (i.first == b[j]){
			newcnt++;	
				}
			j++;
		}
		cnt+=(newcnt*i.second);
	}
	cout<<cnt<<endl;

	return 0;
}