#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool buddyStrings(string s, string goal) {
      if (s.size()!=goal.size()) return false;
      if (s==goal){
        vector<int> freq(26);
        for(auto itr: s){
          freq[itr-'a']++;
          if (freq[itr-'a'] ==2 ) return true;
        }
        return false;
    } else {
        vector<int> v;  
        for(int i = 0; i< s.size(); i++){
        if (s[i]!=goal[i]){
          v.push_back(i);
        }
        if (v.size()>2) return false;
      }
      return (v.size()==2 && s[v[0]]==goal[v[1]] && s[v[1]]==goal[v[0]]);
    }
  }
};
