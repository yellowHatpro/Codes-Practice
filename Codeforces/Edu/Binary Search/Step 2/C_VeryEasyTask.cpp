#include <bits/stdc++.h>
using namespace std;
#define int long long int

int n,x,y;

bool good(int m){
	if (m<0) return false;
	return (((m/x)+(m/y)) >=(n-1));
}

int32_t main(){
	cin>>n>>x>>y;
	int l = 0;
	int r = max(x,y)*(n);
	while(r>l+1){
		int m = (l+r)/2;
		if (good(m-min(x,y))) r = m;
		else l = m;
	}
	cout<<r<<endl;
	return 0;
}