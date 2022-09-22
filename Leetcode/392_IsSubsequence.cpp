#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int m = s.size();
        int idx = 0;
        for (int i = 0; i < n; ++i)
        {
        	if (m==0)
        	{
        		return true;
        	}
        	if (t[i]==s[idx]){
        		idx++;
        		m--;
        	}
        }
            if (m==0) return true;
        else return false;
    }
};