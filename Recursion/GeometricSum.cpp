#include <bits/stdc++.h>
using namespace std;

double geometricSum(int n){
	if (n==0)
	{
		return 1;
	}
	return  1/pow(2,n) + geometricSum(n-1);
}

int main(){
	int k;cin>>k;
	cout<<geometricSum(k)<<endl;
	return 0;
}