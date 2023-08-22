#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
      string ans = "";
      while(columnNumber){
        columnNumber--;
        char last = (char)((columnNumber)%26 + 'A');
        ans+=last;
        columnNumber/=26;
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};
