#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int> m;
        for (int i = 0; i < s.length(); ++i)
        {
        	m[s[i]]++;
        }
       int diff =  m[s[0]] - 
    }
};