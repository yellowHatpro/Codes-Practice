#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int> v;
	int totalSum=0;
	int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
		totalSum+=x;
	}
	sort(v.begin(), v.end(), greater<int>());
	int twinAMone=0;
	for (int i = 0; i < n; ++i)
	{	if (totalSum<twinAMone)
		{	
			break;
		}
		totalSum-=v[i];
		twinAMone+=v[i];
		cnt++;
	}
	cout<<cnt;
	return 0;


}