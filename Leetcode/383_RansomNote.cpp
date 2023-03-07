#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        for (int i = 0; i < magazine.size(); ++i)
        {
        	m[magazine[i]]++;
        }
        for (auto itr: ransomNote){
        	if (m[itr]==0) return false;
        	else m[itr]--;
        }
        return true;
    }
};