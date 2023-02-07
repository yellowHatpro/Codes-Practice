#include <bits/stdc++.h>
using namespace std;
class SolutionLinear {
public:

	//O (n) solution
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 ;
        int j = 0;
        vector<int> v;
        int n = nums1.size();
        int m = nums2.size();
        while(i<n && j<m){
        	if (nums1[i]<nums2[j]){
        		v.push_back(nums1[i++]);
        	} else {
        		v.push_back(nums2[j++]);
        	}
        }
        while(i<n){
        	v.push_back(nums1[i++]);
        }
        while(j<m){
        	v.push_back(nums2[j++]);
        }
        if ((n+m)%2==0){
        	int x = (n+m)/2;
        	return (v[x] + v[x-1])/2.0;
        } else {
        	int x = floor((n+m)/2);
        	return v[x];
        }
    }
};


class Solution {
public:
	double findMedianSortedArrays(vector<int> &v1, vector<int>&v2){
		//Lets keep v1 the larger vector
		if (v1.size()<v2.size()){
			v1.swap(v2);
		}
		int n = v1.size();
		int m = v2.size();
		int partition_size = (n+m)/2;
		int l = 0;
		int r = n;
		while(l<=r){
			int cut1 = (l+r)/2;
			int cut2 = partition_size-cut1;
			int l1 = (cut1==0) ? INT_MIN : v1[cut1-1];
			int l2 = (cut2==0) ? INT_MIN : v2[cut2-1];
			int r1 = (cut1==n) ? INT_MAX : v1[cut1+1];
			int r2 = (cut2==n) ? INT_MAX : v1[cut2+1];
			if (l1<=r2 && l2<=r1){
				if ((n+m)%2==0){
					int res = max(l1,l2) + min(r1,r2);
					return res/2.0; 
				} else {
					return min(r1,r2);
				}
			} else {
				if (l1>r2){
					r = cut1-1;
				} else  {
					l = cut1+1;
				}
			}
		}
		return 0.0;
}
};