#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> runningSum(vector<int>& nums) {
        int x = 0;
        for(int i=0;i<nums.size();i++){
            nums[i]+=x;
            x= nums[i];
        }
        return nums;
        
    }
};


//Another Solution
class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {

		for(int i=1;i<nums.size();i++) {
            nums[i] += nums[i-1];
        }
		return nums;

	}
};