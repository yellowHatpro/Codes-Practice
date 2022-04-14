#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;cin>>n;
	vector<pair<int,int>> v;
	for (int i = 0; i < n; ++i)
	{
		int a;cin>>a;
		int b;cin>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size()-1; ++i)
	{
		if (v[i].second>v[i+1].second)
		{
			cout<<"Happy Alex"<<endl;
			return 0;
		}
	}
cout<<"Poor Alex"<<endl;
	return 0;
}