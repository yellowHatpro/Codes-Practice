#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n] ;
		for (int i = 0; i < n; ++i)
		{	cin>>a[i];
		}
		int b[n];
		for (int i = 0; i < n; ++i)
		{	cin>>b[i];
		}
		int tarA=a[0];
		int tarB = b[0];
		int ansA=INT_MAX;
		int ansB=INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			if(a[i] < tarB){
				ansA=i;
				break;
			}
			}
			for (int i = 0; i < n; ++i)
			{
				if (b[i]>tarA)
				{
					ansB=i;
					break;
				}
			}
			cout<<min(ansA,ansB);
		cout<<endl;

	}
	return 0;
}