#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	map<int,int> v;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		v[x]++;
	}
	if (v[1]==1){
		sum+=1;
	} else if (v[1]>=2){
		float f = ((float)v[1]/(float)2);
		sum+=ceil(f);
	}
	for(auto itr: v){
		if (itr.first!=1){
			sum+=itr.second;
		}
	}
	cout<<sum<<endl;
	return ;
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}