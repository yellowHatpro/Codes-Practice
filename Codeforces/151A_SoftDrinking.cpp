#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int k;cin>>k;
	int l;cin>>l;
	int c;cin>>c;
	int d;cin>>d;
	int p;cin>>p;
	int nl;cin>>nl;
	int np;cin>>np;
	int kxl = k*l;
	int enuf = kxl/nl;
	int enuflime = c*d;
	int salt = p/np;
	int res = min({enuf,enuflime,salt})/n;
	cout<<res;
cout<<endl;
	return 0;
}