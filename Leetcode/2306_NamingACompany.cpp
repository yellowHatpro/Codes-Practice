#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_map<char, unordered_set<string>> m;
        for (int i = 0; i < ideas.size(); ++i) {
            m[ideas[i][0]].insert(ideas[i].substr(1));
        }
        for (auto i: m) {
            for (auto j: m) {
                if (i==j) continue;
                int dups = 0;
                for (string x: j.second)
                    if (i.second.count(x)!=0){
                        dups++;
                    }
                ans+=(i.second.size() - dups) * (j.second.size() - dups);

            }
        }
        return ans;
    }
};