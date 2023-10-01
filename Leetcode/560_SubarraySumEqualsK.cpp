#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int cnt = 0;
        int res = 0;
        m[0]++;
        for(auto itr: nums){
        	cnt+=itr;
        	if (m[cnt-k]!=0){
        		res+=m[cnt-k];
        	}
            m[cnt]++;
        }
        return res;
    }
};
