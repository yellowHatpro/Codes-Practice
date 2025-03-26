#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    vector<pair<int, int>> startToIndexMapping;
    for (int i = 0; i < intervals.size(); i++) {
      startToIndexMapping.push_back({intervals[i][0], i});
    }
    sort(startToIndexMapping.begin(), startToIndexMapping.end());
    vector<int> rightIntervalRes(intervals.size(), -1);
    for (int i = 0; i < intervals.size(); i++) {
      int target = intervals[i][1];
      int l = 0;
      int r = intervals.size() - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (target <= startToIndexMapping[mid].first) {
          rightIntervalRes[i] = startToIndexMapping[mid].second;
          r = mid - 1;
        } else if (target > startToIndexMapping[mid].first) {
          l = mid + 1;
        }
      }
    }
    return rightIntervalRes;
  }
};
