#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	map<int,int> mapp;
	mapp[1] = 0;
	mapp[2] = 0;
	for (int i = 0; i < n; ++i)
	{
		string temp;cin>>temp;
		if (temp=="For"){
			mapp[1]++;
		} else mapp[2]++;
	}
	if (mapp[1]>mapp[2]){
		cout<<"Yes"<<endl;
	}
	 else cout<<"No"<<endl;
	return 0;
}	