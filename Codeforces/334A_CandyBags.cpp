#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	for ( int i=1; i <= (n*n)/2; i+=(n/2))
	{ 
		int j=n/2;
		int cnt = i;
		while(j--){
			cout<<cnt<<" "<<(n*n)-cnt+1<<" ";
			cnt++;
		}
		cout<<endl;
	}
	return 0;
}