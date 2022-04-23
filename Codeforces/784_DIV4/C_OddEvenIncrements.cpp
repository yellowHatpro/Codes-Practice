#include <bits/stdc++.h>
using namespace std;

void solve(){
		int n;cin>>n;
		vector<int> v;
		for (int i = 0; i < n; ++i)
		{	
			int x;cin>>x;
			v.push_back(x);
		}

		bool isEvenOnEven= false;
		if (v[1]%2==0)
		{
			isEvenOnEven=true;
		}
		for (int i = 1; i < n; i+=2)
		{
			if (isEvenOnEven)
			{
				if (v[i]%2!=0)
				{
					cout<<"NO"<<endl;
					return;
				}
			}
			else{
				if (v[i]%2==0)
				{
					cout<<"NO"<<endl;
					return;
				}
			}
		}
		bool isOddOnOdd=false;
		if (v[0]%2!=0)
		{
			isOddOnOdd=true;
		}
		for (int i = 0; i < n; i+=2)
		{
			if (isOddOnOdd)
			{
				if (v[i]%2==0)
				{
					cout<<"NO"<<endl;
					return;
				}
			}
			else{
				if (v[i]%2!=0)
				{
					cout<<"NO"<<endl;
					return;
				}
			}
		}
		cout<<"YES"<<endl;
		return;
	
}


int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
}