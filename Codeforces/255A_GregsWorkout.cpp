#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> v(3);
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		v[i%3]+=x;
	}
	int max =v[0];
	if (v[1]>max)
	{
		max=v[1];
	}
	if (v[2]>max)
	{
		max=v[2];
	}
	if (max==v[0])
	{
		cout<<"chest"<<endl;
	}
	else if (max==v[1]) cout<<"biceps"<<endl;
	else cout<<"back"<<endl;
	return 0;
}