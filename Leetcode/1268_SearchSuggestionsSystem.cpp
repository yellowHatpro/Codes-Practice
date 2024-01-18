#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> res;
    int i = 0, j = 0, n = products.size();
    string prefix;
    for (char &ch : searchWord) {
      prefix += ch;
      i = lower_bound(products.begin() + j, products.end(), prefix) -
          products.begin();
      res.push_back({});
      for (int st = i; st < min(n, i + 3) and
                       !products[st].compare(0, prefix.size(), prefix);
           st++) {
        res.back().push_back(products[st]);
      }
      j = i;
    }
    return res;
  }
};
