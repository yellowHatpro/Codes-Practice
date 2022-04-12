#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int cnt=0;
	vector<pair<int,int>> v;
	for (int i = 0; i < n; ++i)
	{
		int a;cin>>a;
		int b;cin>>b;
		v.push_back(make_pair(a,b));
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i].first==v[j].second)
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}