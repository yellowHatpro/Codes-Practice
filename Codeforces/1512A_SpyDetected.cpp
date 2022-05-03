#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
	}
		int a = 0;
		if (v[0]==v[1])
		{
			a=v[0];
		}
		else{
			if (v[0]==v[2])
			{
				a=v[0];
			}
			else{
				a=v[1];
			}
		}
	
		for (int i = 0; i < n; ++i)
		{
			if (v[i]!=a)
			{
				cout<<i+1<<endl;
				return;
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
