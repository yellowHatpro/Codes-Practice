#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> mp;
        int n = s.size();
        int m = p.size();
        for (int i = 0; i < m; ++i)
        {
        	mp[p[i]]++;
        }
        map<char, int> ogm = mp;
        int st = 0;
        int en = 0;
        int cnt = 0;
        vector<int> res;
        while(en<n){
        	if (mp[s[en++]]-->0){
        		cnt++;
        	}
        	if (cnt == m){
        		res.push_back(st);
        	}
        	if (en-st==m && mp[s[st++]]++>=0){
        			cnt--;
        	}
        	
        }
        return res;
    }
};