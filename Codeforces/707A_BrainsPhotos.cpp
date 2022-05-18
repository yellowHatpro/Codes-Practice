#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	while(n--){
		for (int i = 0; i < m; ++i)
		{
			char test;cin >>test;
			if (test!='W'&&test!='G'&&test!='B')
			{
				cout<<"#Color"<<endl;
				return 0;
			}
		}
	}
	cout<<"#Black&White"<<endl;
	return 0;
}