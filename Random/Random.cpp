#include <bits/stdc++.h>
using namespace std;

int MinimumFairness(int* arr, int n, int k){
	sort(arr,arr+n);
	vector<int> ans(k);
	int maxi = INT_MIN;
	int mini = INT_MAX;
	for (int i = 0; i < k; ++i)
	{
		maxi = max(maxi, arr[i]);
		mini = min(mini, arr[i]);

	}

	return maxi - mini;
}
int main(){
	int arr[7] = {10,100,300,200,1000,20,30};
	int n = 7;
	int k = 3;
	cout<<MinimumFairness(arr,n,k);
	return 0;
}