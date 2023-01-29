#include <bits/stdc++.h>
using namespace std;


void subArraySumToK(vector<int> plots, int k){
	int i = 0;
	int j = 0;
	int sum = 0;
	vector<pair<int,int>> v;
	while(i<plots.size()){
		sum+=plots[i];
		i++;
		while(sum>k && j<i){
			sum-=plots[j++];
		}
		if (sum==k){
			v.push_back({j,i-1});
		}
		
	}
	for(auto itr: v){
		cout<<itr.first<<" - "<< itr.second<<endl;
	}
	return;
}




int main(){
	vector<int> plots= {1,3,2,1,4,1,3,2,1,1,2};
	int k = 8;
	subArraySumToK(plots, k);
	return 0;
}