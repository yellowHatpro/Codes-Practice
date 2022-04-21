#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<string> v;
		string  s;
		cin>>s;
		int fnd=false;
		int bp=0;
		string str="";
		for (int i = 0; i < n; ++i)
		{	
			if (s[i]=='W'&&str!="")
			{
				v.push_back(str);
				str="";
			}
			else{
				if (s[i]!='W')
				{
					str+=s[i];
				}
				
			}
		}
		if (str!="")
		{
			v.push_back(str);
		}
	

		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i]==std::string(v[i].length(),'B')||v[i]==std::string(v[i].length(),'R'))
			{
				cout<<"NO"<<endl;
				fnd=true;
			}
		}
		if (fnd==false)
		{
			cout<<"YES"<<endl;
		}
	}
}