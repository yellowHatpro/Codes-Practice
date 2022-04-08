#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	double x=0;
	for (int i = 0; i < n; ++i)
	{
		int y;cin>>y;
		x+=y;
	}
	cout<<double(x/n);

cout<<endl;
	return 0;
}