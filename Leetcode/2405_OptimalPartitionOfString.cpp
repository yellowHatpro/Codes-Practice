#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionString(string s) {
        set<char> se;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
        {
        	if (se.count(s[i])){
        		cnt++;
        		se.clear();
        	}
        	se.insert(s[i]);

        }
        if (!se.empty()) cnt++;
        return cnt;
    }
};