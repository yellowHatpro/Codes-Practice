#include <bits/stdc++.h>
using namespace std;

void solve(){
	int k;cin>>k;
	int x=0;
	for (int i = 1; i <= k; ++i)
	{
		if (x%3==0 || x%10==3)
			{
				x++;
				if (x%3==0 || x%10==3)
				{
					x++;
				}
			
			}
			x++;	
	}
	cout<<x-1<<endl;
	return;

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}