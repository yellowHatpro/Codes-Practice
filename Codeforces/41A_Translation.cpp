#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;cin>>s;
	string s2;cin>>s2;
	string s3;
	for (int i = s.length()-1; i >= 0; i--)
	{
		s3+=s[i];
	}
	if (s3==s2){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
}