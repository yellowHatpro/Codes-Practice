#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		map<char,int>mp;
		vector<int> v;
		bool isDed = false;
		for (int i = 0; i < s.length(); ++i)
		{
			mp[s[i]]++;
		}
		for (int i = 0; i < s.length(); ++i)
		{	
			if(mp[s[i]]>1){
				v.push_back(-1);
				mp[s[i]]--;
			}
			else if(mp[s[i]]==1){
				for (int j = i; j < s.length(); ++j)
				{
					cout<<s[j];
				}
				cout<<endl;
				isDed = true;
				break;
			}
			else{
				v.push_back(0);
			}
		}
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i]!=-1 && !isDed)
			{
				cout<<s[i];
			}
					}
					cout<<endl;
	}

	return 0;
}