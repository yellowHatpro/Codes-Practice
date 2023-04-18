#include <bits/stdc++.h>
using namespace std;

int n,k;

bool good(vector<int> v, double x){
	int s=0;
	for (auto itr: v){
		s+=floor (itr/x);
	}
	return s>=k;
}

int main(){
	cin>>n>>k;
	vector<int>v(n);
	double l = 0; //good
	double r = 1; //bad
	int sz = 100;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		r = max(r,(double)(v[i]));
	}
	while(sz--){
		double m = (l+r)/2;
		if (good(v,m)) l = m;
		else r = m; 
	}
	cout<< setprecision(20) << l <<endl ;
	return 0;
}