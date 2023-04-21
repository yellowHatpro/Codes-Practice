#include <bits/stdc++.h>
using namespace std;

int f(vector<int> v, int i){
	if (i>=v.size()-1){
		return v[v.size()-1];
	}
	return v[i]*f(v,i+1);
}

int p(vector<int> v, int i, int sum){
	if (i==v.size()){
		return sum;
	}
	return p(v,i+1,sum*v[i]);
}

int main(){
	vector<int> v{1,2,3,4,5};
	cout<<f(v,0)<<endl;
	cout<<p(v,0,1);
	return 0;
}