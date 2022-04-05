#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	for (int i = 2; i <=pow(n,0.5); ++i)
	{	
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}

int main(){
	int n;int m;
	cin>>n;
	cin>>m;
	int x=n+1;
	while(x<=m){
		if (isPrime(x))
		{
			if (x==m)
			{
				cout<<"YES";
			}
			else{
				cout<<"NO";
			}
			return 0;
		}
		x++;
	}
	cout<<"NO";
cout<<endl;
	return 0;
}