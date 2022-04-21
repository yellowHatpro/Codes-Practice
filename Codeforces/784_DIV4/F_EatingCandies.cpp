#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int> v;
	int res=0;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
	}
	int cnt=0;
	int lw=0;
	int rw=0;
	int i=0;
	int j=n-1;
	while(i<j){
		if(lw==0&&rw==0){
			lw+=v[i];
			rw+=v[j];
			i++;
			j--;
			cnt+=2;
		}
		else if (lw<rw)
		{
			lw+=v[i];
			i++;
			cnt++;
		}
		else if(rw<lw){
			rw+=v[j];
			j--;
			cnt++;
		}
	
		else if(rw==lw){
			if (cnt>res)
			{
				res=cnt;
			}
		}
	}
	cout<<res<<endl;
	return;
}
int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
}