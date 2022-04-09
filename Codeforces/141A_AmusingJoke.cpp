#include <bits/stdc++.h>
using namespace std;
int main(){
string name;
cin>>name;
string host;
cin>>host;
string jumbled;
cin>>jumbled;

map<char,int> m;
for (int i = 0; i < jumbled.length(); ++i)
{
	m[jumbled[i]]++;
}
for (int i = 0; i < host.length(); ++i)
{
	if (m[host[i]]<=0)
	{
		cout<<"NO";
		return 0;
	}
	else{
		m[host[i]]--;
	}
}
for (int i = 0; i < name.length(); ++i)
{
	if (m[name[i]]<=0)
	{
		cout<<"NO";
		return 0;
	}
	else{
		m[name[i]]--;
	}
}
if (jumbled.length()==name.length()+host.length())
{
	cout<<"YES";
}else{
	cout<<"NO";
}
return 0;
}