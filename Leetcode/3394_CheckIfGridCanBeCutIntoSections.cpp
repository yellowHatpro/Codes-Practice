#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
    // once vertical, once horizontal
    return checkValidCutsWithDir(n, rectangles, 0) ||
           checkValidCutsWithDir(n, rectangles, 1);
  }

  bool checkValidCutsWithDir(int n, vector<vector<int>> &rectangles, bool dir) {
    // dir = 1 means cut row-wise
    // dir = 0 means cut column-wise
    // rect[i] = [sx,sy,ex,ey]
    // either we sort on the basis of y axis (sx, 0 index, since partition will
    // be drawn on x axis if we move along y axis), or x-axis(sy, 1 index)
    int partitions = 0;
    sort(begin(rectangles), end(rectangles),
         [dir](const vector<int> &a, const vector<int> &b) {
           return a[dir] < b[dir];
         });
    int maxEnd = rectangles[0][dir + 2]; // dir is either sx, or sy, +2 will
                                         // give ex and ey respectively
    for (int i = 0; i < rectangles.size(); i++) {
      if (rectangles[i][dir] >= maxEnd)
        partitions++;

      maxEnd = max(maxEnd, rectangles[i][dir + 2]);
    }
    return partitions >= 2;
  }
};
