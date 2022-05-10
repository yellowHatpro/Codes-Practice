#include <bits/stdc++.h>
using namespace std;

int cntdiff(string x, string y, int n){
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		sum+=abs(x[i]-y[i]);	
	}
	return sum;
}

void solve(){
	int a,b;
	cin>>a;cin>>b;
	vector<string> v;
	for (int i = 0; i < a; ++i)
	{
		string str;cin>>str;
		v.push_back(str);
	}
	vector<int> sum;
	for (int i = 0; i < a; ++i)
	{
		for (int j = i+1; j < a; ++j)
			{
				sum.push_back(cntdiff(v[i],v[j],b));		
			}	
	}
	sort(sum.begin(), sum.end());
	cout<<sum[0]<<endl;
	return;
}
int main(){
	int t;cin>>t;
	while(t--){
	solve();
	}
	return 0;
}