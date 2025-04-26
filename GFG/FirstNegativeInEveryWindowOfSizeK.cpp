#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> firstNegInt(vector<int> &arr, int k) {
    queue<int> q;
    vector<int> v;
    for (int i = 0; i < k; i++) {
      if (arr[i] < 0)
        q.push(i);
    }

    if (!q.empty()) {
      v.push_back(arr[q.front()]);
    } else {
      v.push_back(0);
    }
    for (int i = k; i < arr.size(); i++) {
      while (!q.empty() and q.front() <= i - k) {
        q.pop();
      }
      if (arr[i] < 0) {
        q.push(i);
      }
      if (!q.empty()) {
        v.push_back(arr[q.front()]);
      } else {
        v.push_back(0);
      }
    }
    return v;
  }
};
