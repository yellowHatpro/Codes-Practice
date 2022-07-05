#include <bits/stdc++.h>
using namespace std;

int countZeros(int n) {
	if (n==0)
	{
		return 1;
	}
	if (n<10)
	{
		return 0;
	}
	if (n%10==0)
	{
		return 1+countZeros(n/10);
	}
	else {
		return countZeros(n/10);
	}
}

int main(){
	int i = 1000001;
	cout<<countZeros(i)<<endl;
	return 0;
}