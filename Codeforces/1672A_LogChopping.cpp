#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	int cnt=0;
	while(n--){
		int x;cin>>x;
		cnt+=(x/2);
	}
	if (cnt/2==0)
	{
		cout<<"maomao90"<<endl;
	}
	else{
		cout<<"errorgorn"<<endl;

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