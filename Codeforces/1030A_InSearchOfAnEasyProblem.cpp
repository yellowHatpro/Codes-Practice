#include <bits/stdc++.h>
using namespace std;

void solve(){
		int n;cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		if (x==1)
		{
			cout<<"HARD";
			return;
		}
	}
	cout<<"EASY";
	return;
}
int main(){
	solve();
	return 0;
}