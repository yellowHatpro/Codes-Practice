#include <bits/stdc++.h>
using namespace std;

int main(){
	int k,l,m,n,d;
	cin>>k>>l>>m>>n>>d;
	int cnt=0;
	if ((d<k)&&(d<l)&&(d<m)&&(d<n))
	{
		cout<<0<<endl;
		return 0;
	}
	for (int i = 1; i <= d; ++i)
	{
		if (i%k==0||i%l==0||i%m==0||i%n==0)
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}