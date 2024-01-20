#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> PreviousSmallerIndex(vector<int> &heights) {
    vector<int> res;
    stack<int> s;
    for (int i = 0; i < heights.size(); i++) {
      while (!s.empty() and heights[s.top()] >= heights[i])
        s.pop();
      if (s.empty())
        res.push_back(-1);
      else
        res.push_back(s.top());
      s.push(i);
    }
    return res;
  }

  vector<int> NextSmallerIndex(vector<int> &heights) {
    vector<int> res;
    stack<int> s;
    for (int i = heights.size() - 1; i >= 0; i--) {
      while (!s.empty() and heights[s.top()] >= heights[i])
        s.pop();
      if (s.empty())
        res.push_back(heights.size());
      else
        res.push_back(s.top());
      s.push(i);
    }
    reverse(res.begin(), res.end());
    return res;
  }

  int largestRectangleArea(vector<int> &heights) {
    vector<int> prevSmallerIndex = PreviousSmallerIndex(heights);
    vector<int> nextSmallerIndex = NextSmallerIndex(heights);
    int maxi = 0;
    for (int i = 0; i < heights.size(); ++i) {
      maxi = max(maxi,
                 (nextSmallerIndex[i] - prevSmallerIndex[i] - 1) * heights[i]);
    }
    return maxi;
  }
};
