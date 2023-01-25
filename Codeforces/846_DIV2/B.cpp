#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
	if (a==0){
		return b;
	}
	return gcd(b%a,a);
}


void solve(){
	ll n;cin>>n;
	vector<ll> v(n);
	ll right = 0;
	for (ll i = 0; i < n; ++i)
	{
		ll x;cin>>x;
		v[i] = x;
		right+=x;
	}
	ll maxi = 0;
	ll left = 0;
	for (ll i = 0; i < n-1; ++i)
	{
		right-=v[i];
		left+=v[i];
		maxi = max(maxi,gcd(right,left));	
	}
	cout<<maxi<<endl;
	return;

}
int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}