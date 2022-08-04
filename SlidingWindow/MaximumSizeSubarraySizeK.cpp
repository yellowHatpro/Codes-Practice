#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &v, int k){
	int st = 0;
	int en = k ;
	int maxi = 0;

	for (int i = 0; i < en; ++i)
	{
		maxi+=v[i];
	}
	int curr = maxi;
	for (int i = en; i < v.size(); ++i)
	{
		curr+=v[i];
		curr-=v[st++];
		maxi = max(maxi,curr);
		
	}
	return maxi ;
}

int main(){
	vector<int> v = {2,5,1,8,2,9,1};
	int k = 3;
	cout<<f(v,k);
	return 0;
}