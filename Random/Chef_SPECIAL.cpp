#include <bits/stdc++.h>
using namespace std;

long long power(long long num, long long n){
 	if(n == 0)return 1;
  	long long tmp = power(num, n / 2);
  	tmp = (tmp * tmp)%1000000007;
  	if(n % 2 == 0)return tmp%1000000007;
  	return (tmp * num)%1000000007;
}


void solve(){
	long long n;cin>>n;
	long long f = 5;
	long long res = power(5,n)%1000000007;
	cout<<res<<endl;
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}