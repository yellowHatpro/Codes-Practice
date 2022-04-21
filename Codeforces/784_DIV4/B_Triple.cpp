#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> v;
		int cnt=0;
		for (int i = 0; i < n; ++i)
		{
			int x;cin>>x;
			v.push_back(x);
		}
		map<int,int> m;
		bool isPrinted=false;
		for (int i = 0; i < n; ++i)
		{
			m[v[i]]++;
			if (m[v[i]]>=3)
			{
				cout<<v[i]<<endl;
				isPrinted=true;
				break;
			}
		}
		if (!isPrinted)
		{
			cout<<-1<<endl;
			isPrinted=false;
		}
		
		continue;

	}
}