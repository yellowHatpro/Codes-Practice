#include <bits/stdc++.h>
using namespace std;

vector<int> x;
vector<int> v;
int n;
bool good(double t){
	auto maxi = (double)INT_MIN;
	auto mini = (double)INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		maxi = max(maxi,x[i] - v[i]*t);
		mini = min(mini, x[i]+ v[i]*t);
	}
	return maxi<=mini;
}

int main(){
	cin>>n;
	x.resize(n);
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int xi,vi;cin>>x[i]>>v[i];
	}
	double l = 0;
	double r = 1e10;
	for (int i = 0; i < 100; ++i)
	{
		double m = (l+r)/2;
		if (good(m)) r = m;
		else l = m;
	}
	cout<< l<< '\n';
	return 0;
}