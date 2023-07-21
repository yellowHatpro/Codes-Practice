#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string a, int l, int r){
    while(l<r){
      if (a[l++]!=a[r--]) return false;
    }
    return true;
  }

    void f(vector<vector<string>> &res, vector<string> &v, string s, int i){
      if (i>=s.size()){
        res.push_back(v);
        return;
      }
      for(int j = i; j < s.size(); j++){
        if (isPalindrome(s, i, j)){
          v.push_back(s.substr(i,j-i+1));
          f(res,v,s,j+1);
          v.pop_back();
      }
    }
  }

    vector<vector<string>> partition(string s) {
      vector<vector<string>> res;
      vector<string> v;
      f(res,v,s,0);
      return res;
    }
};
