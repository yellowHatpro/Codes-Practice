#include <bits/stdc++.h>
using namespace std;

int arr[10] = {12,1,4,5,4,3,7,8,6,2};
vector<vector<int>> res;

void subsetSumToK(int k){
	int sum=0;
	for (int i = 0; i < 10; ++i)
	{	
		res.push_back(arr[i]);
		sum+=arr[i];
		if (sum==k)
		{
			return res;
		}

	}
}
int main(){

cout<<endl;
	return 0;
}