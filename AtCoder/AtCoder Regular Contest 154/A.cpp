#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main(){
	int n;
	ll a,b;
	cin>>n>>a>>b;
	ostringstream A;
	A<<a;
	string big = A.str();

	ostringstream B;
	B<<b;
	string small = B.str();

	for (int i = 0; i < n; ++i)
	{
		if (big[i] - '0' <small[i] - '0'){
			char temp = small[i];
			small[i] = big[i];
			big[i] = temp;
		}	
	}
	ll newbig = stoull(big,nullptr,10)%998244353;
	ll newsmall = stoull(small,nullptr,10)%998244353;
	cout<<(newbig*newsmall)%998244353;
	return 0;
}