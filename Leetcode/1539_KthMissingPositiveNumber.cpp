#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        
        int ans = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int missingElements = arr[mid] - (mid + 1);
            if (missingElements >= k)
                end = mid - 1;
            else {
                ans = mid;
                start = mid + 1;   
            }
        }
        return ans != -1 ? arr[ans] + (k - (arr[ans] - (ans + 1))) : k;
    }
};  