#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = n - (k%n);
        reverse(nums.begin()+i,nums.end());
        reverse(nums.begin(), nums.begin()+i);
        reverse(nums.begin(), nums.end());
       
    }
};