#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main(){
	int n;cin>>n;
	vector<int> a(n,0);
	for (int i = 0;i<n;i++) cin>>a[i];
	vector<int> p(n+1,0);
	for(int i = 0; i<n; i++) p[i+1] = p[i]+a[i];
	for (auto itr: p){
		cout<<itr<<" ";
	}
	return 0;
}