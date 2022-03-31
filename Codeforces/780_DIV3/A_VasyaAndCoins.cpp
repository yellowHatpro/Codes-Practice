#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int a;cin>>a;
		int b;cin>>b;
		if (a==0)
		{
			cout<<"1"<<endl;
			continue;
		}
		int res = a + 2*b +1;
		cout<<res<<endl;

	}

	return 0;
}