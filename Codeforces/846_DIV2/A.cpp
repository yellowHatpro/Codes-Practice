#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> odd;
	vector<int> even;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		if (x%2==0){
			even.push_back(i+1);
		} else {
			odd.push_back(i+1);
		}

	}
			if (odd.size()+even.size()>=3){
			if (odd.size()>=1 && even.size()>=2){
				cout<<"YES"<<endl;
				cout<<even[0]<<" "<<even[1]<<" "<<odd[0]<<endl;
				return;
			}
			else if (odd.size()>=3){
				cout<<"YES"<<endl;
				cout<<odd[0]<<" "<<odd[1]<<" "<<odd[2]<<endl;
				return;
			}   else {
				cout<<"NO"<<endl;
	return;
			}
		}
	

}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}