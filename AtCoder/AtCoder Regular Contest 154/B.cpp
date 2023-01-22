#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	string s;cin>>s;
	string t;cin>>t;
	int res=0;
	int targetIndex = 0;
	int rew = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i]!=t[i]){
			res+=1+rew;
			rew=0;

		} else {
			targetIndex++;
			rew++;
		}
	}
	cout<<res;
	return 0;
}