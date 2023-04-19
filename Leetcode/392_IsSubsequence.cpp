#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i]==s[m]){
                m++;
            }
        }
        return m==s.size();
    }
};