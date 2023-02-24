#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
                set<pair<ll, ll>> s; // num -> [min_possible, max_possible]
        for (int i: nums) {
            ll lo = (i >> __builtin_ctz(i));
            ll hi = i;
            if (hi & 1) hi <<= 1;
            s.insert({lo, hi});
        }
        if (s.size() == 1) return 0;
        ll ans = INT_MAX;
        while (s.size() > 1) { // num *= 2 if num <= max_possible
            auto it = s.begin();
            ll top = s.rbegin()->first;
            ll lo = it->first;
            ll hi = it->second;
            s.erase(it);
            ans = min(ans, top - lo);
            if (lo == hi) return ans;
            s.insert({lo * 2, hi});
        }
        return ans;
    }
};