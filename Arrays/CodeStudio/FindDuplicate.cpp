#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	for (int i = 0; i < n; ++i)
	{
		int index = abs(arr[i]-1);
		if (arr[index]<0)
		{
			return index;
		} else {
			arr[index] *=-1;
		}
	}
	return -1;
}
