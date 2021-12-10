using namespace std;
#include <set>
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int res = 0;
       set<char> check;
       int l = 0;
        int r=0;
      while(r<s.size()){
          if(check.find(s[r])==check.end()){
              check.insert(s[r]);
              r++;
          }
          else{
              res = max(res , r-l);
              check.erase(s[l]);
              l++;
          }
      }
        res=max(res, r-l);
    return res;
}};