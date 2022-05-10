#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;cin>>s;
	int sum1 = 0;
	int sum2=0;
	for (int i = 0; i < 3; ++i)
	{
		int a = (int) s[i];
		int b = (int) s[3+i];
		sum1+=a;
		sum2+=b;
	}
	if (sum1==sum2)
	{
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
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