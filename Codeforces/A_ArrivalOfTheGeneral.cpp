#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int max=INT_MIN;
	int min=INT_MAX;
	int max_idx;int min_idx;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i]>max)
			{
				max=arr[i];
				max_idx=i;
			}	
		if (arr[i]<=min)
			{
				min=arr[i];
				min_idx=i;
			}	
	
	}
		if(min_idx<max_idx) {
			cout<<n-min_idx-2+max_idx;
		}	
		else{
			cout<<n-min_idx-1+max_idx;
		}
cout<<endl;
	return 0;
}