#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int m;cin>>m;
	if (m>n)
	{
		cout<<-1;
		return 0;
	}
	
	int minCoins = n/2;
	int extra = minCoins%m;
	if (extra==0&&n%2==1)
	{
		extra+=m;
	}
	else if (extra!=0)
	{
		extra = m - extra;
	}
	

	cout<<minCoins+extra;
	return 0;
}