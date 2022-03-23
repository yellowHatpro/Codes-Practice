#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin>>s;
	string res="";
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i]<=91)
		{
			s[i]+=32;
		}
	 if(s[i]!='a' && s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='y'){
			res+='.';
			res+=s[i];
		}
	}
	cout<<res;
cout<<endl;
	return 0;
}