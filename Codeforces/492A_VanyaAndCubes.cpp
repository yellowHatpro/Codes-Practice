#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int cnt=0;
	int itr=0;
	int sum = 0;
	int total=0;

	for (int i = 1; i <= n; i+=1)
	{
		sum+=i;
		total+=sum;
		if (total>n)
		{
			cout<<cnt--<<endl;
			return 0;
		}
		cnt++;
		if (total==n)
		{
			cout<<cnt<<endl;
			return 0;
		}
		

	}

	return 0;
}