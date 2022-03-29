#include <bits/stdc++.h>
using namespace std;
int main(){
	int sizezz;cin>>sizezz;
	string s;cin>>s;
	set<char> s_cnt;
	
	for (int i = 0; i < s.length(); ++i)
	{	int x = s[i];
		if (x<97)
	{
			x+=32;
		}
		char y = x;	
		s_cnt.insert(y);
	}
	if (s_cnt.size()<26)
	{
		cout<<"NO";
	}else{
		cout<<"YES";
	}
	return 0;
}