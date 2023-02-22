#include <bits/stdc++.h>
using namespace std;

int f(string s,string t){
	if (s.size()==0) return 0;
	if (t.size()==0) return 0;
	if (s[0]==t[0]){
		return 1+ f(s.substr(1), t.substr(1));
	} else {
		return max(f(s, t.substr(1)), f(s.substr(1), t));
	}
}

int lcs(string s, string t)
{	int n = max(s.size(), t.size());
	return f(s,t);
}
int main(){
	cout<<lcs("ashu", "ads");
	return 0;
}