#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int fact = v[0];
	int sum=0;
	for (int i = 1; i < n; ++i)
	{
		sum+=(v[i]-fact);
	}
	cout<<sum<<endl;
	return;
}
int main(){
	int t;cin>>t;
	while(t--){
	solve();
	}
	return 0;
}