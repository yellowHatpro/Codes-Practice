#include <bits/stdc++.h>
using namespace std;
int main(){
int n;cin>>n;
int sum = 0;
int max_sum=INT_MIN;
vector<pair<int,int>> v;
for (int i = 0; i < n; ++i)
{	int a;cin>>a;
	int b;cin>>b;
	v.push_back(make_pair(a,b));
	sum-=a;
	sum+=b;
	if (max_sum<sum)
	{
		max_sum=sum;
	}
}
cout<<max_sum;

	return 0;
}