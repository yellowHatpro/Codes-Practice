#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxi = 0;
        int n = arr.size();
        for (int i = 1; i < n-1;)
        {
        	if (arr[i]>arr[i-1] && arr[i]>arr[i+1]){
        		int peak = i;
        		int cnt1 = 1;
        		while(peak>=1 && arr[peak]>arr[peak-1]){
        			cnt1++;
        			peak--;
        		}
        		while(i<n-1 && arr[i+1]<arr[i]){
        			cnt1++;
        			i++;
        		}
        		maxi = max(maxi,cnt1);

        	} else {
        		i++;
        	}
        }
        return maxi;
    }
};