#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	vector<int> v;
	for (int i = 0; i < s.length(); i+=2)
	{
		string c;
		c+=s[i];
		v.push_back(stoi(c));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size()-1; ++i)
	{
		cout<<v[i]<<"+";
	}
	cout<<v[v.size()-1];
cout<<endl;
	return 0;
}