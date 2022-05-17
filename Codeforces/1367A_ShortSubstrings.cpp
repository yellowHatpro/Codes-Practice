#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;cin>>s;
	string res="";
	for (int i = 0; i < s.length(); i+=2)
	{
		res+=s[i];
	}
	res+=s[s.length()-1];
	cout<<res<<endl;
	return;
}
int main(){
	int t;cin>>t;
	while(t--){
	solve();
	}
	return 0;
}