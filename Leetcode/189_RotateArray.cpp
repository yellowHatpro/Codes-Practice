#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void swapper(vector<int>& v, int start, int end){
		while(start<end){
			swap(v[start],v[end]);
			start++;
			end--;
		}
	}
    void rotate(vector<int>& nums, int k) {
       
        int d = nums.size()-(k%nums.size());
         if (nums.size()<d) return;
        swapper(nums,0,d-1);
        swapper(nums,d,nums.size()-1);
        swapper(nums,0,nums.size()-1);
    }
};