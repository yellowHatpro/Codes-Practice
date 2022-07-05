#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
	if (n<=10)
	{
		return n;
	}
	return n%10+ sumOfDigits(n/10);
	}
int main(){
	int i = 1234;
	cout<<sumOfDigits(i)<<endl;
	return 0;
}