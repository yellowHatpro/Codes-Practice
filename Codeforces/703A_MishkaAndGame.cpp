#include <bits/stdc++.h>
using namespace std;
int cntm=0;
int cntc=0;
void solve(){
	int m;cin>>m;
	int c;cin>>c;
	if (m<c)
	{
		cntc++;
	}
	else if (m>c){
		cntm++;
	}
	return;
}
int main(){
	int t;cin>>t;
	while(t--){
	solve();
	}
	if (cntm>cntc)
	{
		cout<<"Mishka"<<endl;
	}
	else if (cntm<cntc){
		cout<<"Chris"<<endl;
	}
	else {
		cout<<"Friendship is magic!^^"<<endl;
	}
	return 0;
}