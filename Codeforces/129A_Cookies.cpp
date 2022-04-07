#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int cnt=0;
	vector<int> v;
	int x;
	int res=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		v.push_back(x);
		cnt+=x;
	}
	for (int i = 0; i < n; ++i)
	{
		if (cnt%2==0)
		{
			if (v[i]%2==0)
			{
				res++;
			}
		}
		else{
			if (v[i]%2!=0)
			{
				res++;
			}
		}
	}

cout<<res<<endl;
	return 0;
}