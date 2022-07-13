#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;cin>>n;
	int res;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
	}
	int one;
	int last;
	for (int i = 0; i < n; ++i)
	{
		if (v[i]==1)
		{
			one = i;
			break;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (v[i]==n)
		{
			last = i;
			break;
		}
	}
	if (one<last)
	{
		cout<< one + n-1-last<<endl;
	}else{
		cout<< one+ n-2-last<<endl;
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