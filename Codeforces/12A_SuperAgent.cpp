// yellowhatpro
#include <bits/stdc++.h>
using namespace std;

//Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<char>> v(3,vector<char>(3));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin>>v[i][j];
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (v[i][j]!=v[2-i][2-j]){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES\n";
	return 0;
}