#include <bits/stdc++.h>
using namespace std;

void solveq(int val, vector<int> v){
	int si=0;
	int li=v.size()-1;
	int max=-1;
	while(si<=li){
		int mid = si + (li-si)/2;
		if (v[mid]==val)
		{
			cout<<mid+1<<endl;
			return;
		}
		else if (v[mid]>val)
		{
			max = mid+1;
			li=mid-1;
		}
		else{
			si=mid+1;
		}
	}
	cout<<max<<endl;
	return;

}

void solve(){
	int n,q;
	cin>>n;cin>>q;
	vector<int> nval;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		nval.push_back(x);
	}
	vector<int> qval;
	for (int i = 0; i < q; ++i)
	{
		int x;cin>>x;
		qval.push_back(x);
	}
	sort(nval.begin(), nval.end(), greater<int>());
	for (int i = 1; i < n; ++i)
	{
		nval[i]+=nval[i-1];
	}
	for (int i = 0; i < q; ++i)
	{
		solveq(qval[i],nval);
	}
	return;
}
int main(){
	int t;cin>>t;
	while(t--){
	solve();
	}
	return 0;
}