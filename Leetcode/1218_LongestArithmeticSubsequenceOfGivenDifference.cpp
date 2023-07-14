#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
      map<int,int> lengths;
      int las = 1;
      for (auto itr  : arr) {
        las = max(las, lengths[itr] =  1 + lengths[itr-difference]);
      }
      return las;
    }
};
