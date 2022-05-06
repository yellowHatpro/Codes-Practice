#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a,b,n;
	cin>>a;cin>>b;cin>>n;
	int max=0;
	int min=0;
	if (a>b)
	{
		max=a;
		min=b;
	}else{
		max=b;
		min=a;
	}
	int cn=0;
	while(min<=n){
		min+=max;
		int temp = min;
		min = max;
		max = temp;
		cn++;
	}
	cout<<cn-1<<endl;
	return;
}
int main(){
	int t;cin>>t;
	while(t--){
	solve();
	}
	return 0;
}