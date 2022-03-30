#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	n-=10;
	if (n<=0)
	{
		cout<<0;
		return 0;
	}
	else if (n>=1 && n<10)
	{
		cout<<4;
		return 0;
	}
	else if (n==10)
	{
		cout<<15;
		return 0;
	}
	else if(n==11){
		cout<<4;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}


	return 0;
}