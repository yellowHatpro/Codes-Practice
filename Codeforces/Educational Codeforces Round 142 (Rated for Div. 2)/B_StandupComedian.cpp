#include <bits/stdc++.h>
using namespace std;
//Upsolved
void solve(){
	vector<int> v;
	for (int i = 0; i < 4; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
	}
	if (v[0]==0){
		cout<<1<<endl;
	} else {
		cout<<v[0] + 2*(min(v[1],v[2])) + min(v[0]+1,abs(v[1]-v[2]) + v[3])<<endl; 
	}

	return;
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}