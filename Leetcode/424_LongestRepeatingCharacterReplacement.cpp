#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        set<char> st;
        for (int i = 0; i < s.size(); ++i)
        {
        	st.insert(s[i]);
        }
        int maxlen = 0;
        for (auto letter: st){
        	int l = 0;
        	int cnt = 0;
        	for (int r = 0; r < s.size(); ++r)
        	{
        		if (s[r] == letter){
        			cnt++;
        		}
        		while( r + 1 - l - cnt > k){
        			if (s[l]==letter) cnt--;
        			l++;
        		}
        		maxlen = max(r-l+1,maxlen);
        	}
        }
        return maxlen;

    }
};