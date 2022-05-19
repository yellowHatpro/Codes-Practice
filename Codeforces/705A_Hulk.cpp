#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	string hate = "I hate ";
	string love = "I love ";
	string res = "";
	int i = 1;
	while(i!=n && n-1>0){
		if (i%2!=0)
		{
			res+=hate;
		}
		else{
			res+=love;
		}
		res+="that ";
		i++;
	}
	if (n%2==1)
	{
		res+="I hate it";
	}
	else{
		res+="I love it";
	}
	cout<<res<<endl;
	return 0;
}