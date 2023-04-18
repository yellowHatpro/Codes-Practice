#include <bits/stdc++.h>
using namespace std;
int w,h,n;
#define int long long int

bool good(int x){
	return ((x/w)*(x/h)>=n);
}
int32_t main(){
	cin>>w>>h>>n;
	//Finding invariants
	int l = 0;
	int r = 1;
	while(!good(r)) r*=2;
	while(r>l+1){
		int m = (l+r)/2;
		if (good(m)) r = m;
		else l = m;
	}
	cout<<r<<endl;

	return 0;
}