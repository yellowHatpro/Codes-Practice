#include <bits/stdc++.h>
using namespace std;
int main(){
	std::string::size_type sz; 
string a;cin>>a;
string b;cin>>b;
string c ="";
for (int i = 0; i < a.length(); ++i)
{	string x1;x1+=a[i];
	string y1;y1+=b[i];
	
	int x = stoi(x1);
	int y = stoi(y1);
	string z;
	z+=to_string(x^y);
	c+=z;
}
cout<<c;
	return 0;
}