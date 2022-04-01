#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int skip;cin>>skip;
	int start=1;
	int res=0;
	while(n--){
		int l;cin>>l;
		int r;cin>>r;
		int sex= (l-start)/skip;
		start+=sex*skip;
		res+=r-start+1;

		start = r+1;
	}
	cout<<res<<endl;
	return 0;
}