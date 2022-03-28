#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	std::getline(std::cin, s);
	if (s=="{}")	
	{
		cout<<0;
		return 0;
	}
	set<char> sett;
	for (int i = 1; i <= s.length(); i+=3)
	{	
		sett.insert(s[i]);
	}
	 cout<<sett.size();
cout<<endl;
	return 0;
}