//Given array, find 2 elements in array that add ups to a sum.

//Brute O (n2) iterate over each element and find the complement.
//O(nlog n) Sort, and for each element find commplement using binary search


//Best solution using map O (N)
#include <bits/stdc++.h>
using namespace std;
int main(){
	map<int, int> m;
	vector<int> v = {10,5,2,3,-6,9,11};
	int target = 4;
	for (int i = 0; i < v.size(); ++i)
	{
		if (m[target-v[i]]==0)
		{
			m[v[i]]++;
		}
		else {
			cout<<v[i]<<" "<<target-v[i];
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}