#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	int k;cin>>k;
	for (int i = 0; i < k; ++i)
	{
		int L,R;cin>>L>>R;
		int l = -1;
		int r = n;
		while(r>l+1){
			int m = (l+r)/2;
			if (v[m]<L) l = m;
			else r = m;
		}
		int a = r;
		l = -1;
		r = n;
		while(r>l+1){
			int m = (l+r)/2;
			if (v[m]<=R) l = m;
			else r = m;
		}
		cout<<l-a+1<<" ";
	}
	cout<<endl;
	return 0;
}