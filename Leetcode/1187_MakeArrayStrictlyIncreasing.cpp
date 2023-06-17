#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(vector<int> &arr1, vector<int> &arr2, map<pair<int, int>, int> &dp, int i, int prev)
    {
        if (i == arr1.size())
            return 0;
        if (dp[{i, prev}] != 0)
            return dp[{i, prev}];
        int x = 1e6, y = 1e6;
        if (arr1[i] > prev)
            x = f(arr1, arr2, dp, i + 1, arr1[i]);
        int idxOfNextGreater = upper_bound(arr2.begin(), arr2.end(), arr1[prev]) - arr2.begin();
        int val = (idxOfNextGreater == arr2.size()) ? -1 : arr2[idxOfNextGreater];
        if (val != -1)
        {
            y = 1 + f(arr1, arr2, dp, i + 1, val);
        }
        return dp[{i, prev}] = min(x, y);
    }
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int res = f(arr1, arr2, dp, 0, INT_MIN);
        return res == 1e6 ? -1 : res;
    }
};