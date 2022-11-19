#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	for (int i = 0; i < n; ++i)
	{
		if (s[i]=='_'){
			s[i]=s[n-1-i];
		}
	}
	for(int i = 0;i<(n)/2;i++){
		if (s[i]!=s[n-1-i]){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
	return;
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}