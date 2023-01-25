#include <bits/stdc++.h>
using namespace std;

void solve(){
	vector<int> v;
	for (int i = 0; i < 4; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
	}
	int ans =v[0];
	int a = v[0];
	int b = v[0];
	int checkFirst = min(v[1],v[2])==v[1] ? 0 : 1;
	while(v[1]!=0 || v[2]!=0){
		cout<<"ans"<<ans<<endl;
		if (checkFirst==0){
			if (v[1]>a){
				ans += a;
			
				b+=a;
				v[1]-=a;
				a=0;

			} else {
				ans += v[1];
				b+=(v[1]);
				a-=v[1];
				v[1] =0;
			}
			checkFirst = 1;
		} else {
			if (v[2]>b){
				ans+=b;
				a+=b;
				v[2] -= b;
				b = 0;
			} else {
				ans+=v[2];
				a+=(v[2]);
				b-=v[2];
				v[2] =0;
			}
			checkFirst =0;
		}
		if (v[])
	
	}

	if (v[1]==0 && v[2]==0 && a!=-1 && b!=-1){
		if (v[3]>min(a,b)){
			ans += min(a,b) + 1;
		} else {
			ans += v[3];
		}

	}
	cout<<ans<<endl;
	return;
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}