#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	bool odd = true;
	int o=0;
	int e=0;
	for (int i = 0; i < 3; ++i)
	{
		if (v[i]%2==0)
		{
			e++;
		}
		else{
			o++;
		}
	}
	if (o<e)
	{
		odd = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if (odd && v[i]%2==0)
		{
			cout<<i+1<<endl;
			return 0;
		}
		else if(!odd && v[i]%2!=0){
			cout<<i+1<<endl;
			return 0;
		}
	}
	return 0;
}