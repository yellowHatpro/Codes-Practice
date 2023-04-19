#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,char> hmap;
        vector<int> count(256,0);
        for(int i=0;i<s.size();i++)
        {
            if(hmap.find(t[i])!=hmap.end())
            {
                if(hmap[t[i]]!=s[i])
                    return false;
            }
            else
            {
                hmap[t[i]]=s[i];
                count[s[i]]++;
            }
        }
        
        for(int i=0;i<256;i++)
        {
            if(count[i]>1)
                return false;
        }
        return true;
    }
};

// A better approach
class SolutionBetter {
public:
    bool f(string s, string t){
        if (s.size()!=t.size()) return false;
        map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i])==m.end()){
                m[s[i]] = s[i]-t[i];
            } else {
                if (m[s[i]]!=(s[i]-t[i])) return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return f(s,t)&&f(t,s);
    }
};