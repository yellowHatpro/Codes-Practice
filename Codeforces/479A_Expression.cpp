#include <bits/stdc++.h>
using namespace std;
int main(){
	int a;cin>>a;
	int b;cin>>b;
	int c;cin>>c;
	int w = a+b+c;
	int x = a*(b+c);
	int y = a*b*c;
	int z = (a+b)*c;
	cout<<max({w,x,y,z});

	return 0;
}