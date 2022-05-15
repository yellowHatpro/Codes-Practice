#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int cnt=0;
	vector<int> v(n);
	int kcheck = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	kcheck = v[k-1];

	for (int i = 0; i < n; ++i)
	{
		if (v[i]>=kcheck && v[i]!=0)
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}