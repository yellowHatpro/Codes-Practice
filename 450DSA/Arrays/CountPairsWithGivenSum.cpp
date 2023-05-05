#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
	//Most optimal
    int getPairsCount(int arr[], int n, int k) {
        map<int, int> m;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
        	if (m.find(k-arr[i])!= m.end()){
        		ans+=m[k-arr[i]];
        	}
        	m[arr[i]]++;
        	
        }
        return ans;
    }
};