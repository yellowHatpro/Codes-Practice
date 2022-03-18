#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;int r;
	cin>>k;
	cin>>r;
	int val = k%10;
	for (int i = 1; i <= 10; ++i)
	{	if (val%10==0||val==r)
		{	cout<<i;
			return 0;
		}
		val+=(k%10);
		val%=10;
		
	}
	cout<<10<<endl;
	return 0;
}