#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	string res;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i]=='.')
		{
			res+="0";
		}
		else if(s[i]=='-'){
			if (s[i+1]=='.')
			{
				res+="1";
				i++;
			}
			else if(s[i+1]=='-'){
				res+="2";
				i++;
			}
		}

	}
	cout<<res;
cout<<endl;
	return 0;
}