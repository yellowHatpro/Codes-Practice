#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> &v, int k){
	int st = 0;
	int en = k;
	vector<int> res;
	for (int i = 0; i < en; ++i)
	{
		if (v[i]<0) {
			res.push_back(v[i]);
			break;
		}
	}
	st++;
	while(en<v.size()){
		
	}


}

int main(){
	 vector<int> v = {12,-1,-7,8,-15,30,13,28};
	 int k = 3;
	 vector<int> vi = f(v,k);
	 for(auto i: vi){
	 	cout<<i<<" ";
	 }
	return 0;
}