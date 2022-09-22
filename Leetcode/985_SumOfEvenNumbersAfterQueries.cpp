#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0 ;
        vector<int> res;
        int n = nums.size();
        int m = queries.size();
        for (int i = 0; i < n; ++i)
        {
        	if (nums[i]%2==0) sum+=nums[i];
        }
        for (int i = 0; i < m; ++i)
        {
        	int index = queries[i][1];
        	int val = queries[i][0];
        	if (nums[index]%2==0 && val%2==0) {
                nums[index]+=val;
        		sum+=val;
        		res.push_back(sum);
        	}
        	else if (nums[index]%2!=0 && val%2!=0){
                nums[index]+=val;
        		sum+=nums[index];
        		res.push_back(sum);
        	}
        	else if (nums[index]%2==0 && val%2!=0){
        		sum-=nums[index];
                nums[index]+=val;
        		res.push_back(sum);
        	}
        	else {
                nums[index]+=val;
                res.push_back(sum);
            };
        }
        return res;
    }
};