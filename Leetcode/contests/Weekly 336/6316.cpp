#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<long long int> newnums(nums.begin(), nums.end());
        sort(newnums.begin(), newnums.end(), greater<int>());
        for (int i = 1; i < nums.size(); ++i)
        {
        	newnums[i]+=newnums[i-1];	
        }
        long long int cnt = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (newnums[i]>0) cnt++;
        }
        return cnt;
    }
};