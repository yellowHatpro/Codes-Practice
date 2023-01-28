#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	vector<string> s;
	map<string,int> t;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		string temp;cin>>temp;
		s.push_back(temp.substr(3));
	}
	for (int i = 0; i < m; ++i)
	{
		string temp;cin>>temp;
		t[temp]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if (t[s[i]]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}