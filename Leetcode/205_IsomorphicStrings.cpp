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
    bool isIsomorphic(string s, string t) {
        if (s.size()!=t.size())
        {
            return false;
        }
        map<char, int> m;
        string a = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (m.find(s[i])!=m.end())
            {
                a+=m[s[i]];
            } else {
                a+=i;
                m[s[i]] = i;
            }
            a+=" ";
        }
        a = a.substr(0,a.size()-1);

        string b = "";
         map<char, int> x;
        for (int i = 0; i < t.size(); ++i)
        {
            if (x.find(t[i])!=x.end())
            {
                b+=x[t[i]];
            } else {
                b+=i;
                x[t[i]] = i;
            }
            b+=" ";
        }
        b = b.substr(0,b.size()-1);

        return a==b;

    }
};
