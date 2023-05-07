#include <bits/stdc++.h>
using namespace std;
int findMinDiff(int n, int m, vector<int> chocolates) {
    sort(chocolates.begin(), chocolates.end());
    int minDiff = INT_MAX;
    for (int i = 0; i <= n-m; ++i)
    {
    	minDiff = min(minDiff, (chocolates[i+m-1] - chocolates[i]));
    }
    return minDiff;
}