#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = nums[0];
        for (int i =1; i<nums.size();i++){
            x^=nums[i];
        }
        return x;
    }
};

class SolutionLogn{
public:
	int singleNonDuplicate(vector<int>& nums){
		int n = nums.size();
		int l = 0;
		int r = n-1;
        if (n==1) return nums[0];
		while(l<r){
			int mid = (l+r)/2;
            if (mid==0 && nums[mid]!=nums[mid+1]) return nums[mid];
            if (mid)
			if (nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
			if (mid%2==0){
				if (nums[mid]==nums[mid-1]){
					r = mid-1;
				} else {
					l = mid+1;
				}
			}
			if (mid%2!=0){
				if (nums[mid]!=nums[mid-1]){
					r = mid -1;
				} else {
					l = mid+1;
				}
			}
		}
        return nums[l];
	}
};