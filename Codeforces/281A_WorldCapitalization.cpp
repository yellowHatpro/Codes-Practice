#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	if (s[0]>=97)
	{
		s[0]-=32;
	}
	for (int i = 0; i < s.length(); ++i)
	{
		cout<<s[i];
	}
cout<<endl;
	return 0;
}