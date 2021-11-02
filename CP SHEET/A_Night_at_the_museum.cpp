#include<bits/stdc++.h>
using namespace std;
int main()
{	string s;
	cin>>s;
	int current = 'a';
	int cnt=0;
	for (int i = 0; i < s.length(); ++i)
	{
		int clk=abs(current-(int)s[i]);
		int aclk=abs(-26+abs(current-(int)s[i]));

		if (clk<aclk)
		{
			cnt+=clk;
		}
		else{
			cnt+=aclk;
		}
		current = s[i];

	}
	cout<<cnt; 
    cout<<endl;
    return 0;
}