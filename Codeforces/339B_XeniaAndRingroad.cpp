#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,m; cin>>n>>m;
	vector<ll> v(m);
	for (int i = 0; i < m; ++i)
	{
		cin>>v[i];
	}
	ll ans = v[0]-1;
	for (ll i = 1; i < m; ++i)
	{
		if (v[i]<v[i-1]){
			ans += n-(v[i-1] - v[i]);
		}
		else if (v[i]>v[i-1]){
			ans+=(v[i]-v[i-1]);
		}
	}
	cout<<ans;
	return 0;
}