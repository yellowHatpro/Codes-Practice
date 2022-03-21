#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::map<int, int> m;
        int ans=0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	m[nums[i]]++;
        }
        for (int i = 0; i < m.size(); ++i)
        {
        	ans+=(m[i]*(m[i]-1)/2);
        }
        return ans;
    }
};

//Alternate easy:

class Solution2 {
public:
    int numIdenticalPairs(vector<int>& nums) {
       int ans=0;
       for (int i = 0; i < nums.size(); ++i)
       {
       	for (int j = i+1; j < nums.size(); ++j)
       	{
       		if (nums[i]==nums[j]){
       			ans++;
       		}	
       	}
       }
       return ans;
    }
};