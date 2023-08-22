#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxLen(vector<int>&v, int n) {   
      map<int,int> m;
      int ans = 0;
      int sum = 0;
      for(int i = 0; i < n; i++){
        sum+=v[i];
        if (sum==0) ans = i+1;
        else {
          if (m.find(sum)!=m.end()){
            ans = max(ans,i-m[sum]);
          } else m[sum] = i;
        }
      }
      return ans;
    }
};
