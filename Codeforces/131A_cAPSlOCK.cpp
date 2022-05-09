#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	int size=s.length();
	for (int i = 0; i < size; ++i)
	{
		if (s[i]>=97 && i!=0)
		{
			cout<<s<<endl;
			return 0;
		}
	}
	if (s[0]>=97)
	{
		s[0]-=32;
	}
	else{
		s[0]+=32;
	}
	for (int i = 1; i < size; ++i)
	{
		if (s[i]<97)
	{
		s[i]+=32;
	}
		
	}
	cout<<s<<endl;
	return 0;
}