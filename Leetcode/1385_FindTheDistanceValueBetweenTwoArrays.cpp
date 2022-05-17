#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
		int ans = 0;
		for (int i = 0; i < arr1.size(); ++i)
		        {
		        	int lo = 0;
		        	int hi = arr2.size() - 1;
		        	while(lo<=hi){
		        		int mid = hi - (hi-lo)/2;
		        		if (arr2[mid]<=arr1[i]+d && arr2[mid]>=arr1[i]-d)
		        		{
		        			ans++;
		        			break;
		        		}
		        		else if (arr2[mid]>arr1[i]+d){
		        			hi= mid-1;
		        		}
		        		else{
		        			lo = mid+1;
		        		}
		        	}
		        }        
		        return arr1.size() -ans;
    }
};