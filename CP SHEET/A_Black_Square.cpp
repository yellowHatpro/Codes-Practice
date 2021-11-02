#include<bits/stdc++.h>

using namespace std;
int main()
{
	int strips[4];
	for (int i = 0; i < 4; ++i)
	{
		cin>>strips[i];
	}
	string s;
	int one=0;
	int two=0;
	int three=0;
	int four=0;
	cin>>s;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i]=='1'){
			one+=1;
		}
		else if(s[i]=='2'){
			two+=1;
		}
		else if(s[i]=='3'){
			three+=1;
		}
		else {
			four+=1;
		}
	}
	int res = (one*strips[0])+(two*strips[1])+(three*strips[2])+(four*strips[3]);
	cout<<res;
    cout<<endl;
    return 0;
}