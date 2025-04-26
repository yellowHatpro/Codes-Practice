#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int cst = 0;
    int idx = -1;
    if (accumulate(gas.begin(), gas.end(), 0) <
        accumulate(cost.begin(), cost.end(), 0)) {
      return -1;
    }
    vector<int> diff;
    for (int i = 0; i < cost.size(); i++) {
      diff.push_back(gas[i] - cost[i]);
    }
    for (int i = 0; i < cost.size(); i++) {
      cst += diff[i];
      if (cst < 0) {
        cst = 0;
        idx = -1;
      } else {
        if (idx == -1) {
          idx = i;
        }
      }
    }
    return idx;
  }
  int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
    if (accumulate(gas.begin(), gas.end(), 0) <
        accumulate(cost.begin(), cost.end(), 0)) {
      return -1;
    }
    // now we sure there exists an answer
    int cst = 0;
    int idx = 0;
    for (int i = 0; i < gas.size(); i++) {
      cst += (gas[i] - cost[i]);
      if (cst < 0) {
        cst = 0;
        idx = i + 1;
      }
    }
    return idx;
  }
};
