#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
      map<char,int> m;
      int maxFreq = 0;
      int n = s.size();
      char letter = 'a'; 
      for(auto i: s){
        m[i]++;
        if (m[i]>maxFreq){
          maxFreq = m[i];
          letter = i;
      }
      }
      string ans = s;
      int ind = 0;
      if (maxFreq <= (n+1)/2){
        while(m[letter]!=0){
          ans[ind] = letter;
          ind+=2;
          m[letter]--;
        }
        for(auto itr: m){
          while(m[itr.first]>0){
            if (ind>=n) ind = 1;
            ans[ind]=itr.first;
            ind+=2;
            m[itr.first]--;
          }  
        }
      } else return "";
      return ans;
    }
};
