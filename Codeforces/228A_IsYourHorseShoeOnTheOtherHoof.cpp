#include <bits/stdc++.h>
using namespace std;

int main(){
	set<int> s;
	int n = 4;
	while(n--){
		int x;cin>>x;
		s.insert(x);
	}
	cout<<4-s.size();
}