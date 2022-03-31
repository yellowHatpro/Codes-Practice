#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
	int n;cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{	int inp;cin>>inp;
		v.push_back(inp);
	}
	if (v.size()==1&&v[0]>1)
	{
		cout<<"NO"<<endl;
		continue;
	}
	
	sort(v.begin(), v.end(),greater<int>());
	if (v[0]-v[1]>1)
	{
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
	}
	return 0;
}