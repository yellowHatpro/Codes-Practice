#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,t;cin>>n>>t;
	string s;cin>>s;
	while(t--){
		for (int i = n-1; i>= 1; --i)
	{
		if (s[i]=='G' && s[i-1]=='B')
		{
			char temp = s[i];
			s[i] = s[i-1];
			s[i-1] = temp;
			i--;
		}

	}
	}
	cout<<s<<endl;
	return 0;
}